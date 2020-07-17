# Simulador de Cache
O trabalho realizado tem o intuito de simular a execução de uma memória cache. Tal projeto foi desenvolvido na linguagem de programação C, na cadeira de Arquitetura e Organização de Computadores 2. Partindo dessa ideia, objetivo final do projeto tem como verificar a quantidade de *miss* e *hit* que se dá na cache a partir de uma determinada configuração e de um dataset de entrada. 

## Execução do código:
Para executar o código, utilize os seguintes passos:

1. Download e extração do diretório atual.
2. Abertura do terminal na pasta que estão os arquivos descompactados.
3. Para executar o código, digita-se *make* no terminal.
4. Após o comando, insere-se a configuração da cache da seguinte maneira:

<pre>
<code>"<"nconjuntos">""<"tbloco">""<"associatividade">""<"logica_substituição">"
</code>
</pre>

**OBS:** eliminar os todos "" para configurar a cache.

Onde:
* nconjuntos: (2, 4, 8…) - número de conjuntos;
* tbloco: (2, 4, 8…) - número de blocos;
* associatividade: (2, 4, 8…) - número de associatividade;
* logica_substituição (R ou F) - lógica de substituição, onde R é para *random* e F para *FIFO*.

**OBS:** os dados de entrada estão no arquivo Teste.txt, que pode ser modificado. Os dados
de entrada contidos nele devem ser em binário e conter 32 caracteres.


