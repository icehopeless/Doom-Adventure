# Doom Adventure 

![background](/assets/Background/Doom.png)

Recriação do jogo Mini Doom em c++.

## Indice 
- <a href="https://github.com/icehopeless/Doom-Adventure/blob/main/README.md#contextualização-do-projeto-">Contextualização do Projeto</a>
- <a href="https://github.com/icehopeless/Doom-Adventure/blob/main/README.md#principais-tecnologias-destacadas-">Principais Tecnologias Destacada</a>
- <a href="https://github.com/icehopeless/Doom-Adventure/blob/main/README.md#demonstração">Objetos no jogo</a>
- <a href="https://github.com/icehopeless/Doom-Adventure/blob/main/README.md#como-rodar-">Como Rodar?</a>
- <a href="https://github.com/icehopeless/Doom-Adventure/blob/main/README.md#autores">Autores</a>

## Contextualização do Projeto 
O projeto <i>Doom Adventure</i> consiste em uma recriação do jogo Mini Doom, onde é desenvolvido por meio da linguagem C++ e a das bibliotecas Simple and Fast Multimedia Library (SFML) e tmxlite. O jogo tem o proposito de sobreviver a fim de chegar na ultima fase para ganhar.



## Principais Tecnologias Destacadas 
-  [SFML lib](https://www.sfml-dev.org/index.php) 
-  [tmxlite](https://github.com/fallahn/tmxlite) 


A presente biblioteca "Simple and Fast Multimedia Library (SFML)" é utilizada para introduiz a parte gráfica no desenvolvimento do jogo, possibilitando assim, a interação visual do usuário.

A biblioteca tmxlite é usada para incluir e manipular mapas nos formatos de tiled. Responsável por ler os arquivos de configuração do mapa, seja ela xml, tmx entre outros...

## Objetos no jogo
<img src = "./assets/PowerUps/frame%201.png" width = 50 alt = powerups/> <br>
As esferas avermelhadas espalhadas pelo mapas tem a função de restaurar a vida ao máximo e restaurar um cartucho de tiros.

<img src = "./assets/PowerUps/Portion.png" width = 50 alt = powerups/> <br>

Os frascos avermelhados espalhados pelo mapa como os powerups, têm a função de fornecer 1 barra de vida.

## Como Rodar? 
Diante do exposto, foi ultilizado a biblioteca Gráfica para a construção do jogo, e para rodar, é preciso utilizar a versão correta em função do seu compilador minGW instalado, caso não tenha instalado, obtenha o <a href="https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/7.3.0/">MinGW</a>.

1. Ao instalar o mingw, abra seu terminal e use o comando: "g++ -v" para verficar se o compilador está instalado.

2. adicione nas variaveis do sistema o PATH do compilador mingw, o caminho por padrão é: \mingw64\bin

 O jogo foi desenvolvido no <a href="https://code.visualstudio.com/">vsCode</a> e no <a href="https://www.eclipse.org/">Eclipse IDE</a>. Caso utilize outra IDE, certifique-se que a Biblioteca SFML e a TMX esteja incluida da maneira correta, caso contrário, o código não será compilado.

 <b>Dependências para Windows: </b> <br>
 - Instale as bibliotecas [SFML lib](https://www.sfml-dev.org/index.php) e
 [tmxlite](https://github.com/fallahn/tmxlite);<br>
 - Instale o  <a href="https://www.gnu.org/software/make/">GNU Make</a> para compilar o código;


<b>Para rodar: </b><br>
Ápos instalar a pasta raiz do jogo, por padrão, virá um arquivo <i>makefile</i>, modifique os locais das bibliotecas colocando o local instalado no seu computador. O arquivo virá com os locais por padrões em /C:. <br>
Por fim, rode o comando: 

```bash
mingw32-make
```
Caso não compile, abra em uma IDE de sua preferência, e atualize os includes (procure suporte para incluir bibliotecas externas em sua IDE). Ou então coloque as DLLs da sfml e da tmxlite na pasta raiz do jogo.


## Autores
Desenvolvido por discentes da instituição CEFET-MG Campus Contagem - 03/09/2023

### Autoria: 

Gabriel Agostinho da Silva
gabrielagostinhodasilva@hotmail.com


Isaque de Sousa Almeida
senhaisaque@gmail.com


Isabelle Tavares Mol Araujo
isabelle.tavares.mol13@gmail.com
