# Algoritmos de Ordenação

## Comparação de Algoritmos de Ordenação

| **Algoritmo**      | **Complexidade de Tempo**        | **Estável** | **Adaptativo** | **In-place** |
|---------------------|----------------------------------|-------------|----------------|--------------|
| **Bubble Sort**     | Melhor caso: O(n)               | Sim         | Sim            | Sim          |
|                     | Caso médio/pior caso: O(n<sup>2</sup>)    |             |                |              |
| **Insertion Sort**  | Melhor caso: O(n)               | Sim         | Sim            | Sim          |
|                     | Caso médio/pior caso: O(n<sup>2</sup>)    |             |                |              |
| **Selection Sort**  | O(n<sup>2</sup>)                          | Não         | Não            | Sim          |
| **Shell Sort**      | Melhor caso: O(n log n)         | Não         | Sim           | Sim          |
|                     | Caso médio/pior caso: Depende   |             |                |              |
| **Merge Sort**      | O(n log n)                      | Sim         | Não            | Não          |
| **Quick Sort**      | Melhor caso: O(n log n)         | Não         | Não            | Sim          |
|                     | Caso médio: O(n log n)          |             |                |              |
|                     | Pior caso: O(n<sup>2</sup>)              |             |                |              |
| **Heap Sort**       | O(n log n)                      | Não         | Não            | Sim          |
| **Intro Sort**      | O(n log n)                      | Não         | Não            | Sim          |
| **Counting Sort**   | O(n + k)                        | Sim         | Não            | Não          |
| **Radix Sort**      | O(nk)                           | Sim         | Não            | Não          |

## Explicação dos Campos

- **Complexidade de Tempo:** Estimativa de desempenho em diferentes cenários:
  - **Melhor caso:** Quando os dados estão completamente ou parcialmente ordenados.
  - **Caso médio:** Desempenho típico para entradas aleatórias.
  - **Pior caso:** Entrada mais desfavorável possível.

- **Estável:** Indica se o algoritmo preserva a ordem relativa de elementos iguais.

- **Adaptativo:** Se o algoritmo ajusta seu desempenho baseado no nível de ordenação inicial dos dados.

- **In-place:** Determina se o algoritmo utiliza memória adicional constante (O(1)).

## Observações Importantes

1. **Counting Sort** e **Radix Sort** são algoritmos de ordenação não baseados em comparação, sendo úteis para dados que possuem um intervalo limitado ou podem ser representados por dígitos.
2. **Intro Sort** combina a eficiência do Quick Sort com a robustez do Heap Sort para evitar o pior caso.
3. Escolha do algoritmo ideal depende do caso de uso, volume de dados e requisitos específicos (como estabilidade ou restrição de memória).
