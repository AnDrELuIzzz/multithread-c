# Programas Multithread em C

Este repositório contém programas em C que demonstram o uso de multithreading para realizar tarefas de forma paralela.

## Descrição

A programação multithread é uma técnica importante para melhorar o desempenho e a eficiência de programas, especialmente em sistemas multicore. Este repositório contém implementações de programas multithread em C, juntamente com explicações sobre como eles funcionam.

## Conteúdo

1. **Soma de Vetor (Vector Sum):** Este programa divide um vetor em partes iguais e atribui cada parte a uma thread. Cada thread calcula a soma dos elementos na parte atribuída e armazena o resultado em uma variável global compartilhada. Após a conclusão de todas as threads, a soma total de todos os elementos no vetor é calculada a partir dos resultados individuais de cada thread.

2. **Contagem de Fatores (Factor Counting):** Este programa calcula o número de fatores de um dado número usando programação paralela com threads pthread. Duas threads são criadas para contar os fatores de forma independente, cada uma verificando uma metade do intervalo de números possíveis. Após a conclusão das threads, os resultados são somados para obter o número total de fatores.

## Como usar

1. Clone este repositório para o seu ambiente local:

```
git clone https://github.com/seu-usuario/programas-multithread-c.git
```

2. Compile os programas usando um compilador C compatível, por exemplo:

```
gcc -o vector_sum vector_sum.c -pthread
gcc -o factor_count factor_count.c -pthread
```

3. Execute os programas compilados:

```
./vector_sum
./factor_count
```

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir problemas relatando bugs ou sugerindo melhorias, e também para enviar pull requests com suas próprias adições ou correções.

## Créditos

Este repositório foi inspirado e baseado nos conceitos apresentados no livro **"Programação em Baixo Nível: C, Assembly e Execução de Programas na arquitetura Intel 64"**.