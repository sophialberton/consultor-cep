// Aguarda o conteúdo do DOM ser totalmente carregado antes de executar o script
document.addEventListener('DOMContentLoaded', () => {

    // --- 1. SELEÇÃO DE ELEMENTOS DO DOM ---
    // Centralizamos a seleção de todos os elementos que serão manipulados.
    // Isso melhora a performance e a organização.
    const cepInput = document.getElementById('cep');
    const consultarBtn = document.getElementById('consultar-cep');
    const resultadoDiv = document.getElementById('resultado');
    const listaEnderecosTbody = document.getElementById('lista-enderecos');
    const ordemSelect = document.getElementById('ordem');
    
    // Botões de Ordenação
    const ordenarLogradouroBtn = document.getElementById('ordenar-logradouro');
    const ordenarBairroBtn = document.getElementById('ordenar-bairro');
    const ordenarLocalidadeBtn = document.getElementById('ordenar-localidade');
    const ordenarUfBtn = document.getElementById('ordenar-uf');

    // Botão de Tema
    const themeSwitcherBtn = document.getElementById('theme-switcher');
    const body = document.body;

    // --- 2. ESTADO DA APLICAÇÃO ---
    // A lista de endereços é o "estado" da nossa aplicação.
    // Carregamos os dados do localStorage assim que o script inicia.
    let listaEnderecos = carregarDoLocalStorage();

    // --- 3. FUNÇÕES DE MANIPULAÇÃO DE DADOS (localStorage) ---

    /**
     * Salva a lista de endereços no localStorage.
     */
    function salvarNoLocalStorage() {
        localStorage.setItem('enderecos', JSON.stringify(listaEnderecos));
    }

    /**
     * Carrega a lista de endereços do localStorage.
     * @returns {Array} A lista de endereços ou um array vazio.
     */
    function carregarDoLocalStorage() {
        const enderecosSalvos = localStorage.getItem('enderecos');
        return enderecosSalvos ? JSON.parse(enderecosSalvos) : [];
    }
    
    // --- 4. FUNÇÕES DE RENDERIZAÇÃO E MANIPULAÇÃO DO DOM ---

    /**
     * Atualiza a tabela na tela com os endereços da lista.
     */
    function atualizarTabela() {
        // Limpa a tabela antes de adicionar os novos dados
        listaEnderecosTbody.innerHTML = '';

        listaEnderecos.forEach((endereco, index) => {
            const tr = document.createElement('tr');
            tr.innerHTML = `
                <td>${endereco.logradouro || ''}</td>
                <td>${endereco.bairro || ''}</td>
                <td>${endereco.localidade || ''}</td>
                <td class="celula-acao">
                    ${endereco.uf || ''}
                    <span class="lixeira" data-index="${index}"></span>
                </td>
            `;
            listaEnderecosTbody.appendChild(tr);
        });
    }
    
    /**
     * Exibe uma mensagem de erro ou sucesso na área de resultado.
     * @param {string} mensagem - O texto a ser exibido.
     * @param {boolean} isError - Se a mensagem é de erro (true) ou não (false).
     */
    function exibirMensagem(mensagem, isError = false) {
        resultadoDiv.innerHTML = `<p class="${isError ? 'mensagem-erro' : ''}">${mensagem}</p>`;
    }
    
    /**
     * Exibe os detalhes de um endereço consultado.
     * @param {object} data - O objeto com os dados do endereço.
     */
    function exibirResultado(data) {
        resultadoDiv.innerHTML = `
            <p><strong>Endereço:</strong> ${data.logradouro}</p>
            <p><strong>Bairro:</strong> ${data.bairro}</p>
            <p><strong>Cidade:</strong> ${data.localidade}</p>
            <p><strong>Estado:</strong> ${data.uf}</p>
        `;
    }

    // --- 5. FUNÇÕES DE LÓGICA DA APLICAÇÃO ---

    /**
     * Consulta o CEP na API do ViaCEP.
     */
    async function consultarCEP() {
        const cep = cepInput.value.replace(/\D/g, '');

        if (cep.length !== 8) {
            exibirMensagem('CEP inválido! Por favor, insira um CEP de 8 dígitos.', true);
            return;
        }

        try {
            const response = await fetch(`https://viacep.com.br/ws/${cep}/json/`);
            const data = await response.json();

            if (data.erro) {
                exibirMensagem('CEP não encontrado.', true);
            } else {
                exibirResultado(data);
                listaEnderecos.push(data);
                salvarNoLocalStorage();
                atualizarTabela();
            }
        } catch (error) {
            exibirMensagem('Erro ao consultar o CEP. Tente novamente.', true);
            console.error(error);
        }
    }

    /**
     * Exclui um endereço da lista.
     * @param {number} index - O índice do endereço a ser excluído.
     */
    function excluirEndereco(index) {
        listaEnderecos.splice(index, 1);
        salvarNoLocalStorage();
        atualizarTabela();
    }
    
    /**
     * Ordena a tabela por um campo específico.
     * @param {string} campo - O campo pelo qual ordenar (ex: 'logradouro').
     */
    function ordenarTabela(campo) {
        const ordem = ordemSelect.value; // 'asc' ou 'desc'

        listaEnderecos.sort((a, b) => {
            const valorA = (a[campo] || '').toLowerCase();
            const valorB = (b[campo] || '').toLowerCase();

            if (valorA < valorB) return ordem === 'asc' ? -1 : 1;
            if (valorA > valorB) return ordem === 'asc' ? 1 : -1;
            return 0;
        });

        atualizarTabela();
    }
    
    // --- 6. LÓGICA PARA ALTERNAR TEMA (MODO CLARO/ESCURO) ---

    /**
     * Aplica o tema (claro ou escuro) na página.
     * @param {string} theme - O tema a ser aplicado ('dark' ou 'light').
     */
    const applyTheme = (theme) => {
        if (theme === 'dark') {
            body.classList.add('dark-mode');
            themeSwitcherBtn.textContent = 'Alternar para Modo Claro';
        } else {
            body.classList.remove('dark-mode');
            themeSwitcherBtn.textContent = 'Alternar para Modo Escuro';
        }
    };
    
    /**
     * Alterna entre o tema claro e escuro.
     */
    function toggleTheme() {
        const currentTheme = body.classList.contains('dark-mode') ? 'light' : 'dark';
        localStorage.setItem('theme', currentTheme);
        applyTheme(currentTheme);
    }
    
    // --- 7. ADIÇÃO DE EVENT LISTENERS ---
    // Centralizamos todos os ouvintes de eventos aqui.

    consultarBtn.addEventListener('click', consultarCEP);
    
    ordenarLogradouroBtn.addEventListener('click', () => ordenarTabela('logradouro'));
    ordenarBairroBtn.addEventListener('click', () => ordenarTabela('bairro'));
    ordenarLocalidadeBtn.addEventListener('click', () => ordenarTabela('localidade'));
    ordenarUfBtn.addEventListener('click', () => ordenarTabela('uf'));
    
    // Delegação de evento para os ícones de lixeira
    listaEnderecosTbody.addEventListener('click', (event) => {
        if (event.target.classList.contains('lixeira')) {
            const index = event.target.getAttribute('data-index');
            excluirEndereco(index);
        }
    });
    
    themeSwitcherBtn.addEventListener('click', toggleTheme);
    
    // --- 8. INICIALIZAÇÃO ---
    // Funções que devem ser executadas quando a página carrega.
    
    function init() {
        atualizarTabela();
        const savedTheme = localStorage.getItem('theme') || 'light';
        applyTheme(savedTheme);
    }

    init();
});