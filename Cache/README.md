## Divisão do código:
Para melhor entendimento do código, o trabalho foi dividido em *headers*, onde:

**Simulador.c:** contém a chamada de todas as *headers* para a simulação.
Faz a chamada para a captação dos dados do usuário sobre as dimensões da cache, os
cálculos da tag, indice e offset (faz as operaões necessárias de conversão), e a
instanciação da cache dos dados solicitados pelo processador.

**Cache.c:** faz a parte de instânciar a cache. Tem como finalidade, inicializar-la com valores que
sejam diferentes para qualquer dado processado (Exemplo: índice “-1”), realizar a impressão dos
dados contidos na cache, inserir/buscar os dados no cache e  realizar toda a verificação de
*miss* e *hit* dada na cache. Na inserção/busca dos dados no cache, o código é divido em duas
partes: na primeira parte é feito o Mapeamento Direto (associatividade igual a 1) e a segunda
parte o Mapemanto Associativo por Conjuntos e Mapeamento Totalmente
Associativo (associatividade maior que 1).

**LeituraArquivo.c:** realiza a leitura de um arquivo contendo todos os dados solicitados pelo processador.

**LeituraInformação.c:** realiza a leitura das configurações da cache solicitadas pelas usuário.

**ConversorBinario.c:** realiza a converção do dado processado para seu valor em inteiro.

**Tag.c:** realiza a seleção dos bits da tag do dado.

**Indice.c:** realiza a seleção dos bits do índice do dado.

**Cálculo.c:** realiza o calculo do endereço do dado na cache.

**CálculoBits.c:** realiza o calculo de quantos bits o offset ou índice utilizam.

**PalavrasBloco.c:** realiza o calculo de quantas palavras tem cada bloco da cache.

**TabelaDeDados.c:** realiza a amostragem dos dados de *miss* e *hit*.

**Random.c:** função randômica para o calculo de posições aleatórias na cache.

## Funcionamento da cache:
É instanciado um vetor de x posições (nconjuntos) onde cada posição contém
tamanho y (tbloco). O tamanho da posição interfere diretamente na quantidade de dados
que poderão ser inseridos no endereço mapeado. Sendo assim, quando houver uma
inserção deu um dado em uma posição x, a posição será carregada com um bloco de y
dados pré-definidos. Ou seja, se a posição tem tamanho para 4 dados, estando ela vazia,
quando houver a inserção de um dado, será carregado para a posição mais 3 dados.

* Associatividade:
  * **Direto:**
Após um dado ser solicitado pelo processador, ele é procurado no cache, se não
houver esse dado, o mesmo é inserido na posição que foi mapeado. Se a posição
mapeada estiver vazia o dado é simplesmente inserido, caso contrário, substitui-se o
bloco.
  * **N-vias e Completamente Associativo:**
O vetor inicialmente contem n (nconjuntos) posições. Assim, se houver um
aumento na associatividade as posições serão dividas em N conjuntos. Ou seja, em uma
cache com 4 conjuntos e associatividade 2, o vetor será dividido em 8 conjuntos com
duas posições cada conjunto.

Exemplo:


Agora o endereço não será mais mapeado por posição e sim por conjunto. Como
pode ser verificado no header “Calculo.c”.

<pre>
<code>
Endereco = (indice % (NConjuntos/Associatividade)) * Associatividade;
</code>
</pre>

Após isso, é verificado em qual posição do conjunto está o dado solicitado pelo
processador. Caso não houver, será necessário inseri-lo, assim, verifica-se qual das
posições está vazia. Se não houver posição vazia, utiliza-se de uma das politicas de
substituição para saber em qual posição deve-se substituir o dado pelo mais recente
solicitado.

## Políticas de substituição

O código utiliza de duas políticas de substituição: 
* RANDOM: a partir do header *Random*, realiza o cálculo para obterção da posição aleatória que deverá ser substituída e o retorna.
* FIFO (First in – First Out): verifica qual foi o primeiro dado utilizado e o substitui pelo dado requisitado mais recentemente. 

**OBS:** A implementação da FIFO não foi feita em um header separado por motivos de choque de função. Pode-se verificar que sua
implementação é feita no header “Cache.c” na parte de substituição no bloco cheio.
