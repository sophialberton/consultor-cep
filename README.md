# Sistema-Web-para-Consulta-e-Armazenamento-de-Endere-os
Para processo seletivo de estágio em desenvolvimento de sistema da Ultra Lims
Sistema Web para Consulta e Armazenamento de Endereços
Objetivo:
Desenvolver um sistema web que permita ao usuário consultar um endereço pelo CEP,
armazenar os registros consultados e exibir a lista de registros com opções de ordenação.
Requisitos Funcionais:
1. O usuário poderá digitar um CEP e buscar as informações do endereço através da
API pública ViaCEP.
2. Os dados retornados devem ser armazenados para consulta posterior. O formato de
armazenamento pode ser escolhido pelo candidato (banco de dados, localStorage,
JSON, etc.).
3. Deve haver uma interface para listar os endereços armazenados, permitindo que o
usuário veja as informações salvas.
4. O usuário poderá ordenar a lista de endereços de forma crescente ou decrescente
pelos seguintes campos:
○ Cidade
○ Bairro
○ Estado
Requisitos Técnicos:
✅ A busca do endereço deve ser realizada via backend, fazendo uma requisição HTTP
para a API do ViaCEP.
✅ A aplicação deve exibir mensagens de erro para CEPs inválidos ou falhas na requisição.
✅ A interface deve ser intuitiva, podendo ser desenvolvida com HTML, CSS e JavaScript
puro ou frameworks como React/Vue/Angular.
✅ A ordenação dos registros deve ser implementada no backend.
✅ O candidato pode utilizar qualquer tecnologia para armazenar os dados (Ex:
localStorage, IndexedDB, banco de dados relacional ou NoSQL).
