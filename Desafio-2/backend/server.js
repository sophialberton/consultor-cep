// Importação das dependências necessárias
const express = require('express'); // Importa o framework Express para criar o servidor
const axios = require('axios');     // Importa a biblioteca Axios para fazer requisições HTTP
const path = require('path');       // Importa o módulo path para manipulação de caminhos de arquivos

// Criação de uma instância do servidor Express
const app = express();
// Definição da porta do servidor
const port = 3000;

// Middleware para interpretar requisições com JSON no corpo
app.use(express.json());

// Servir arquivos estáticos do frontend (como HTML, CSS, JS)
app.use(express.static(path.join(__dirname, '../frontend')));
// A função `express.static()` serve arquivos estáticos da pasta "frontend", 
// o que significa que qualquer arquivo dentro dela pode ser acessado diretamente através da URL

// Rota principal para servir o arquivo index.html
app.get('/', (req, res) => {
    // Quando a URL raíz ("/") é acessada, o servidor responde com o arquivo index.html
    res.sendFile(path.join(__dirname, '../frontend/index.html'));
});

// Rota para a consulta de CEP
app.get('/consulta/:cep', async (req, res) => {
    // O parâmetro :cep da URL é extraído de `req.params.cep`
    // O método `replace(/\D/g, '')` remove qualquer caractere não numérico (somente os números do CEP são necessários)
    const cep = req.params.cep.replace(/\D/g, '');

    try {
        // Realiza uma requisição para a API do ViaCEP para obter os dados do CEP
        const response = await axios.get(`https://viacep.com.br/ws/${cep}/json/`);
        
        // Se a resposta da API contiver a chave `erro`, significa que o CEP não foi encontrado
        if (response.data.erro) {
            // Se o CEP não for encontrado, retorna um erro 404
            return res.status(404).json({ error: "CEP não encontrado." });
        }
        
        // Caso o CEP seja válido, responde com os dados do CEP em formato JSON
        res.json(response.data);
    } catch (error) {
        // Se ocorrer algum erro durante a requisição à API, retorna um erro 500
        res.status(500).json({ error: "Erro ao consultar o CEP." });
    }
});

// Configuração do servidor para escutar a porta definida (3000)
app.listen(port, () => {
    // Quando o servidor for iniciado, imprime no console que ele está rodando na porta 3000
    console.log(`Servidor rodando na porta ${port}`);
});