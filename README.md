# 🧮 Computational Linear Algebra Methods

> Uma implementação prática de álgebra linear computacional construída do zero, unindo o desempenho do C++ com a versatilidade do Python.

## 📖 Sobre o Projeto

Este projeto tem como objetivo construir do zero uma biblioteca para manipulação de matrizes e resolução de sistemas lineares. A principal motivação por trás deste repositório é puramente educacional: **transpor a barreira entre a teoria matemática e a implementação prática**. 

Muitas vezes, o estudo de algoritmos de decomposição e álgebra linear fica restrito ao campo teórico. Aqui, o objetivo é sujar as mãos com código, entendendo a fundo como essas operações funcionam "por baixo dos panos" antes de utilizar bibliotecas prontas.

## ✨ Funcionalidades (Roadmap)

O projeto é dividido em três grandes pilares:

### 1. Núcleo em C++ (Matrizes e Operações)
- [ ] Estrutura base de dados para representação de Matrizes.
- [ ] Operações aritméticas básicas (adição, subtração, multiplicação).
- [ ] Funções de manipulação (Transposta, Identidade, etc.).
- [ ] Cálculo de características da matriz (Determinante, Traço, etc.).

### 2. Algoritmos de Resolução de Sistemas Lineares
Implementação de métodos diretos e iterativos para a solução de sistemas:
- [ ] Decomposição LU.
- [ ] Decomposição QR.
- [ ] *(Adicione aqui outros métodos que planeja fazer, como Cholesky, Jacobi, Gauss-Seidel, etc.)*

### 3. Integração com Python (Bindings)
- [ ] Empacotamento do código C++ em uma biblioteca consumível via Python.
- [ ] Interface simples para chamar os métodos de decomposição escritos em C++ diretamente de scripts Python.

## 🛠️ Tecnologias Utilizadas

* **C++23**: Linguagem principal do núcleo. O uso do padrão C++23 é essencial pois o projeto faz uso de features modernas, como a sobrecarga multidimensional do `operator[]` para acessar os elementos da matriz de forma intuitiva (`matriz[i, j]`).
* **Python 3.x**: Para criação da interface de uso e testes.
* **Make**: Ferramenta de automação de build para compilar o código C++ facilmente.

## 📂 Estrutura do Repositório (Exemplo)

\`\`\`text
computational-linear-algebra/
├── cpp/                  # Código-fonte principal em C++
│   ├── src/              # Implementações (.cpp)
│   └── include/          # Headers (.h / .hpp)
├── python_bindings/      # Código para fazer a ponte C++ -> Python
├── tests/                # Testes unitários para garantir a precisão matemática
└── README.md
\`\`\`

## 🚀 Como Compilar e Executar

### Pré-requisitos
Antes de começar, você precisará ter instalado em sua máquina:
* Um compilador C++ com suporte ao padrão **C++23** (GCC 13+ ou Clang 16+ recomendados).
* Utilitário `make` instalado.
* Python 3.x (para a etapa de bindings).

### Compilando o projeto C++
Graças ao arquivo `Makefile` incluso no projeto, a compilação é muito simples.

1. Clone o repositório:
   ```bash
   git clone [https://github.com/AlortCraft/Computational-Linear-Algebra-Methods.git](https://github.com/AlortCraft/Computational-Linear-Algebra-Methods.git)
   cd Computational-Linear-Algebra-Methods

---
*Este projeto está sendo desenvolvido como uma ferramenta de estudo prático sobre Álgebra Linear Computacional.*