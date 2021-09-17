# TP2-Estrutura-de-dados

<h2>Introdução</h2>

<p>Atrav´es dos servi¸cos da Rellocator CO., no ano de 2076, uma pessoa pode fazer upload de sua mente
para corpos sint´eticos. No entanto, um dos grandes problemas era o fato de que 27% das consciˆencias
que faziam parte de um processo de upload eram roubadas por hackers. Dessa forma, a Rellocator
CO. contratou uma equipe para desenvolver v´arios prot´otipos de um sistema de controle e detec¸c˜ao
de anomalias no fluxo dos dados referentes as consciˆencias a serem transferidas atrav´es de diversos
servidores. Por´em, houve uma redu¸c˜ao de apenas 17% nos roubos das mesmas durante um processo de
transferˆencia. Dessa forma, o time de cientistas da Rellocator CO. deseja investigar outra medida de
seguran¸ca para prevenir futuros roubos.
A nova medida de seguran¸ca visa ordenar as consciˆencias em uma configura¸c˜ao para que os servidores
possam trabalhar de forma mais otimizada. Dessa forma, o tempo de envio das consciˆencias ser´a
reduzido. Ao reduzir o tempo de envio, espera-se que tamb´em seja reduzido o tempo de visibilidade das
mesmas por hackers e reduzir ainda mais o n´umero de roubos.
Dentre as caracter´ısticas dos dados a serem ordenados, deve-se notar o fato de que os mesmos s˜ao
compostos por dois campos. O primeiro campo representa o nome pessoa/consciˆencia a ser realocada e o
segundo campo representa a consciˆencia a ser transferida. Por esse motivo, a Rellocator CO. gostaria de
investigar duas hip´oteses relativas a estabilidade e tempo de execu¸c˜ao ao aplicar determinados m´etodos
para organizar e otimizar as informa¸c˜oes.
A primeira hip´otese a ser investigada pela Rellocator CO. pretende verificar se os campos realmente
ir˜ao manter a configura¸c˜ao desejada ap´os ordenados utilizando algoritmos est´aveis. J´a a segunda hip´otese, visa avaliar se o tempo de execu¸c˜ao dos m´etodos de ordena¸c˜ao ir˜ao causar impacto no desempenho
dos servidores de envio.
Para conseguir responder as duas hip´oteses, a Rellocator CO. contratou v´arios programadores (incluindo vocˆe). Consequentemente, seu objetivo neste trabalho ´e implementar os m´etodos de ordena¸c˜ao
e seguir uma metodologia de testes rigorosa estabelecida pela Rellocator CO.. Para facilitar o seu trabalho, a companhia disponibilizou dados utilizados apenas para homologa¸c˜ao que s˜ao provenientes de
um ambiente de simula¸c˜ao. Por fim, vocˆe deve apresentar todos os resultados (sem altera¸c˜ao) como
especificado pela Rellocator CO. e entregar o seu parecer t´ecnico.</p>

<h2>Especificações</h2>

<h2>Configuração Experimental</h2>

<p>Dentre as poss´ıveis abordagens para ordenar as informa¸c˜oes em cada campo, foram considerados os
algoritmos descritos na Tabela 1</p>

![image](https://user-images.githubusercontent.com/51410946/133828489-120e4340-4db0-4449-a35a-86025811a3dd.png)


<p>Tabela 1: Algoritmos considerados vi´aveis para a ordena¸c˜ao.</p>
<p>com o intuito de avaliar o desempenho de qual combina¸c˜ao dos mesmos ´e mais apropriada em termos de
Tempo de Execu¸c˜ao e Estabilidade. Foram propostas quatro configura¸c˜oes de teste que s˜ao apresentadas
na Tabela 2</p>

![image](https://user-images.githubusercontent.com/51410946/133821912-46828315-837a-4a0c-bcba-3b9a7ffe54e1.png)

<p>Tabela 2: Combina¸c˜ao de algoritmos que deve ser utilizada durante a avalia¸c˜ao.</p>
<p>Al´em das configura¸c˜oes para avalia¸c˜ao descritas na Tabela 2, tamb´em foi criado um arquivo para
homologa¸c˜ao de qual configura¸c˜ao ser´a utilizada no sistema real. O arquivo utilizado para avaliar as
configura¸c˜oes cont´em 200 mil linhas. A avalia¸c˜ao das configura¸c˜oes descritas na Tabela 2, deve ser feita
variando o tamanho N da entrada deste arquivo. O valor de N ´e a quantidade de linhas a serem lidas
e consideradas durante as ordena¸c˜oes. A quantidade de linhas lidas, ou a vari´avel N, deve seguir a
seguinte sequˆencia</p>

<li> 1.000, 10.000, 50.000, 100.000 e 200.000</li>
<p>ou seja, vocˆe deve testar CADA UMA das configura¸c˜oes de algoritmos da Tabela 2, lendo inicialmente
os 1.000 (mil) primeiros elementos; Depois, em um outro teste, os 10.000 (dez mil) primeiros elementos
incluindo os anteriores; depois, em mais um teste os 50.000 (cinquenta mil) primeiros elementos, e assim
por diante, at´e que se alcance N = 200.000 (duzentos mil).</p>

<h2>Execução, Entradas e Saídas</h2>

<p>O execut´avel do seu programa deve receber trˆes argumentos de linha de comando. O primeiro argumento representa o arquivo para homologa¸c˜ao. J´a o segundo argumento, representa qual configuração
de teste deve ser executada. O terceiro argumento representa a quantidade de linhas a serem consideradas durante o teste. Por exemplo, considere a seguinte chamada ao seu programa atrav´es de um
terminal,</p>

![image](https://user-images.githubusercontent.com/51410946/133828383-ea84aa38-2399-46eb-b841-d922a9e2114e.png)


<p>onde, ‘run.out’ ´e o execut´avel do seu programa, ‘homologacao.txt’ ´e o arquivo que cont´em as 200 mil
linhas para avalia¸c˜ao das configura¸c˜oes descritas na Tabela 2, o argumento ‘1’ ´e a configura¸c˜ao a ser
executada (Quicksort para o campo ‘NOME’ e Heapsort para o campo ‘DADOS’), e ‘50000’ representa a
quantidade de linhas a serem avaliadas</p>
