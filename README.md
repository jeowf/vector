# Vector
Implemetação do std::vector

**Desenvolvido por:**

 - Alison Hedigliranes da Silva
 - Felipe Morais da Silva

# Objetivos
 
- [x] Special members;

- [x] Iterator methods;

- [x] Capacity methods;

- [x] Modifiers methods;

- [x] Element access methods; and,

- [x] Iterator classes.

## Descrição

O projeto tem por objetivo o desenvolvimento do vetor dinâmico da biblioteca vector do C++. Básicamento o projeto se divide em duas classes principais : Iterador e Vector, onde o iterador é responsável por acessar e percorrer os elementos do vetor. Já o Vector é a classe que possui todos os métodos de gerenciamento dos elementos como inserts e erases.  

## Execução

Para gerar o executavel do programa rode dentro da pasta do programa:

```
make
```
Assim será gerado um executável nomeado "vector".

Para executar o programa use:

```
./vector
```

Para apagar o executável:

```
make clean
```

## Tratamento de Erros

Atualmente o programa trata os seguintes erros:

- Impede ações com vetores vazios;

## Arquivos do projeto

A seguir descreveremos de forma rápida alguns arquivos que estão no projeto. 

### Iterador.inl

Responsável por acessar e percorrer os elementos contidos no vector.

### Vector.inl

Gerencia os elementos dentro do vetor podendo fazer ações como inserir e deletar elementos, além de criar ou destruir vetores.
