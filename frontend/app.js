// Função para salvar os endereços no localStorage
function salvarNoLocalStorage() {
    localStorage.setItem('enderecos', JSON.stringify(listaEnderecos));
}

let listaEnderecos = [];

// Função para carregar os endereços do localStorage
function carregarDoLocalStorage() {
    const enderecosSalvos = localStorage.getItem('enderecos');
    if (enderecosSalvos) {
        listaEnderecos = JSON.parse(enderecosSalvos);
    }
    atualizarTabela();
}

// Função para consultar o CEP e buscar as informações do endereço
function consultarCEP() {
    const cep = document.getElementById('cep').value.replace(/\D/g, ''); // Limpa qualquer caractere não numérico
    const resultadoDiv = document.getElementById('resultado');

    // Verifica se o CEP é válido
    if (cep.length !== 8 || isNaN(cep)) {
        resultadoDiv.innerHTML = '<p class="mensagem-erro">CEP inválido! Por favor, insira um CEP válido.</p>';
        return;
    }

    // Faz a consulta ao CEP (Aqui pode ser a API ViaCEP ou a sua implementação)
    fetch(`https://viacep.com.br/ws/${cep}/json/`) // Usando o ViaCEP como exemplo
        .then(response => response.json())
        .then(data => {
            if (data.erro) {
                resultadoDiv.innerHTML = '<p class="mensagem-erro">CEP não encontrado.</p>';
            } else {
                // Exibe o resultado
                resultadoDiv.innerHTML = `
                    <p><strong>Endereço:</strong> ${data.logradouro}</p>
                    <p><strong>Bairro:</strong> ${data.bairro}</p>
                    <p><strong>Cidade:</strong> ${data.localidade}</p>
                    <p><strong>Estado:</strong> ${data.uf}</p>
                `;

                // Adiciona o endereço à lista
                listaEnderecos.push(data);
                salvarNoLocalStorage(); // Salva no localStorage após adicionar o endereço
                atualizarTabela(); // Atualiza a tabela de endereços
                ordenarTabela('localidade'); // Ordena os dados por cidade, por exemplo
            }
        })
        .catch(error => {
            resultadoDiv.innerHTML = '<p class="mensagem-erro">Erro ao consultar o CEP. Tente novamente.</p>';
            console.error(error);
        });
}

// Função para atualizar a tabela exibindo os endereços armazenados
function atualizarTabela() {
    const tabela = document.getElementById('lista-enderecos');
    tabela.innerHTML = ''; // Limpa a tabela antes de adicionar os dados

    listaEnderecos.forEach((endereco, index) => {
        const tr = document.createElement('tr');
        tr.innerHTML = `
            <td>${endereco.logradouro}</td>
            <td>${endereco.bairro}</td>
            <td>${endereco.localidade}</td>
            <td class="estado">
                ${endereco.uf}
                <span class="lixeira" onclick="excluirEndereco(${index})"></span>
            </td>
        `;
        tabela.appendChild(tr);
    });
}

// Função para excluir um endereço da lista
function excluirEndereco(index) {
    // Remove o endereço da lista
    listaEnderecos.splice(index, 1);
    salvarNoLocalStorage(); // Atualiza o localStorage após a exclusão
    atualizarTabela(); // Atualiza a tabela de endereços
}

// Função para ordenar a tabela por um campo específico
function ordenarTabela(campo) {
    const ordemSelecionada = document.getElementById('ordem').value;

    listaEnderecos.sort((a, b) => {
        let valorA = a[campo].toLowerCase();
        let valorB = b[campo].toLowerCase();

        if (valorA < valorB) return ordemSelecionada === 'asc' ? -1 : 1;
        if (valorA > valorB) return ordemSelecionada === 'asc' ? 1 : -1;
        return 0;
    });

    atualizarTabela(); // Atualiza a tabela após ordenar
}

// Carrega os endereços do localStorage quando a página é carregada
window.onload = function() {
    carregarDoLocalStorage();
};