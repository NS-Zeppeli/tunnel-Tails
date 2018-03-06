////////////////////////////////////////////////
///////       Bibliotecas para uso       ///////
////////////////////////////////////////////////

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

////////////////////////////////////////////////
///////    Constantes para uso geral     ///////
////////////////////////////////////////////////

	int i;
	char nome[50], opcao, destino, escolha, feito, pick, morrer, caminho , corrida, quase;
	char ask_dis[] = "[DESABILITADO]";
	char ask_menu[] = "[Menu Principal]";
	char ask_continuar[] = "Clique em qualquer tecla para continuar.";
	char ask_select[] = "Selecione umas das op��es";
	char ask_fazer[] = "O que deseja fazer?";
	char ask_voltar[] = "Clique em qualquer tecla para voltar...";
	char ask_erro[] = "ERROR:      Entrada Inv�lida ou indisponivel";
	char ask_seguir[] = "Qual caminho deseja seguir?";

////////////////////////////////////////////////
///////      Fuctions de utilit�rios     ///////
////////////////////////////////////////////////

printTime() // tempo de print entre caracteres
{
	usleep(1); /// 25000 good | 15000 | FAST 1
}

pularlinha()
{
	printf("\n");
}

kit_completo()
{
	system("cls");
	fflush(stdin);
}
////////////////////////////////////////////////
///////    Fuctions de Linhas das UI     ///////
////////////////////////////////////////////////

ui_header(int i) // Cabe��rio
{
	printTime();
	for(i = 0; i<=2; i++)
	{
		putchar('+');
	}
	for(i = 0; i<=60; i++)
	{
		putchar('-');
	}
	for(i = 0; i<=2; i++)
	{
		putchar('+');
	}
	 
	pularlinha();
}

ui_mid(int linhas) // Mid varias linhas 
{
	int i, x;
	
	for(x = 0; x<9-linhas; x++)
	{
		printTime();
		for(i = 0; i<=2; i++)
		{
			putchar('�');
		}
		for(i = 0; i<=60; i++)
		{
			putchar(' ');
		}
		for(i = 0; i<=2; i++)
		{
			putchar('�');
		}
		pularlinha();
	}
}

ui_mid_custom(int i) // linha do mid customizada
{
		printTime();
		for(i = 0; i<=2; i++)
		{
			putchar('�');
		}
		for(i = 0; i<=60; i++)
		{
			putchar(' ');
		}
		for(i = 0; i<=2; i++)
		{
			putchar('�');
		}
		pularlinha();
}

////////////////////////////////////////////////
///////   Fuctions de interface basica   ///////
////////////////////////////////////////////////

ui_start(int i) // come�a nova linha
{
	for(i = 0; i<=2; i++)
	{
		putchar('�');
	}
	for(i = 0; i<=4; i++)
	{
		putchar(' ');
	}
}

ui_end(int i) // finaliza linha
{
	for(i = 0; i<=4; i++)
	{
		putchar(' ');
	}
	for(i = 0; i<=2; i++)
	{
		putchar('�');
	}
	pularlinha();
}

ui_end_q(int i) // finaliza linha
{
	for(i = 0; i<=3; i++)
	{
		putchar(' ');
	}
	for(i = 0; i<=2; i++)
	{
		putchar('�');
	}
	pularlinha();
}

ui_start_q(int i) // come�a nova linha
{
	for(i = 0; i<=2; i++)
	{
		putchar('�');
	}
	for(i = 0; i<=11; i++)
	{
		putchar(' ');
	}
}

ui_center(int i) // come�a nova linha
{
	for(i = 0; i<=15; i++)
	{
		putchar(' ');
	}
}

////////////////////////////////////////////////
///////  Fuctions de interface Avan�ada  ///////
////////////////////////////////////////////////

ui_texto(int i, char texto[200])	//inicia o construtor
{
	int x, lines = 0, y , z;
	x = strlen(texto);
	ui_start(i);
	for(i = 0; i<=x; i++)
	{
		if(i<51)
		{
			printTime(); 
			printf("%c", texto[i]);
			z =  (50 - i)-1;		
		}
		else if(i == 51) // pula primeira linha
		{
			lines = 1;
			if(texto[i] == ' ')
			{
				ui_end(i);
			}
			else
			{
				putchar('-');
				ui_end_q(i);
			}
			ui_start(i);
			printTime(); 
			printf("%c", texto[i]);	
			z =  (100 - i);
		}
		else if(i >51 && i <101) // printa na segunda linha
		{
			printTime(); 
			printf("%c", texto[i]);
			z =  (100 - i);
		}
		else if(i == 101) // pula segunda linha
		{
			lines = 2; // utilizado depois para contagem de linhas ^v^
			if(texto[i] == ' ')
			{
				putchar(' ');
				ui_end(i);
			}
			else
			{
				putchar('-');
				putchar(' ');
				ui_end_q(i);
			}
			ui_start(i);
			printTime();
			printf("%c", texto[i]);	
			z =  (150 - i);
		}
		else if(i >101 && i < 151) // pula terceira linha
		{
			printTime(); 
			printf("%c", texto[i]);
			z =  (150 - i);
		}
		else if(i == 151)  // pula terceira linha
		{
			lines = 3; // utilizado depois para contagem de linhas ^v^
			if(texto[i] == ' ')
			{
				putchar(' ');
				ui_end(i);
			}
			else
			{
				putchar('-');
				putchar(' ');
				ui_end_q(i);
			}
			ui_start(i);
			printTime();
			printf("%c", texto[i]);	
			z =  (201 - i)-1;
		}
		else if(i >151 )  // pula printa quarta linha
		{
			printTime(); 
			printf("%c", texto[i]);
			z =  (201 - i)-1;
		}
			
	}
	//finaliza arrumando o texto
	for(y= 0; y <= z ; y++ )
	{
		putchar(' ');
	}	
	ui_end(i);
	return lines;
}

////////////////////////////////////////////////
///////       Fuctions de question       ///////
////////////////////////////////////////////////

ui_question(int i, char question[30])
{
	int x, z;
	x = strlen(question);
	z =  (43 - x);
	ui_mid_custom(i);
	ui_start_q(i);
	printTime();
	printf("%s", question);
	for(i= 0; i <= z ; i++ )
	{
		putchar(' ');
	}
	i=0;
	ui_end(i);
}

////////////////////////////////////////////////
///////        Fuction de op��es         ///////
////////////////////////////////////////////////
// op��o 1 e 2
ui_options(int i, char op1[20],char op2[20])
{
	int z, x;
	x = strlen(op1);
	z =  (18 - x);
	ui_start_q(i);
	printTime();
	printf("1. %s", op1 );
	for(i= 0; i <= z ; i++ )
	{
		putchar(' ');
	}
	x = strlen(op2);
	z =  (18 - x);
	printTime();
	printf("2. %s", op2 );
	for(i= 0; i <= z ; i++ )
	{
		putchar(' ');
	}
	ui_end(i);
}
// op��o 3 e 4
ui_options_2(int i, char op1[20],char op2[20]) 
{
	int z, x;
	x = strlen(op1);
	z =  (18 - x);
	ui_start_q(i);
	printTime();
	printf("3. %s", op1 );
	for(i= 0; i <= z ; i++ )
	{
		putchar(' ');
	}
	x = strlen(op2);
	z =  (18 - x);
	printTime();
	printf("4. %s", op2 );
	for(i= 0; i <= z ; i++ )
	{
		putchar(' ');
	}
	ui_end(i);
}

ui_options_big(int i, char op1[20],char op2[20])
{
	int z, x;
	x = strlen(op1);
	z =  (25 - x);
	ui_start(i);
	printTime();
	printf("1. %s", op1 );
	for(i= 0; i <= z ; i++ )
	{
		putchar(' ');
	}
	x = strlen(op2);
	z =  (18 - x);
	printTime();
	printf("2. %s", op2 );
	for(i= 0; i <= z ; i++ )
	{
		putchar(' ');
	}
	ui_end(i);
}

ui_options_big2(int i, char op1[20],char op2[20]) 
{
	int z, x;
	x = strlen(op1);
	z =  (25 - x);
	ui_start(i);
	printTime();
	printf("3. %s", op1 );
	for(i= 0; i <= z ; i++ )
	{
		putchar(' ');
	}
	x = strlen(op2);
	z =  (18 - x);
	printTime();
	printf("4. %s", op2 );
	for(i= 0; i <= z ; i++ )
	{
		putchar(' ');
	}
	ui_end(i);
}


////////////////////////////////////////////////
///////  Fuctions do Construtor inicial  ///////
////////////////////////////////////////////////	

ui_builder(int i,char texto[200], char question[20], char opcao1[20], char opcao2[20], char opcao3[20], char opcao4[20]){ //entra variavel para loop sempre
	kit_completo();
	int linhas;
	ui_header(i);
	linhas = ui_texto(i,texto);
	ui_header(i);
	ui_mid(linhas);
	ui_header(i);
	ui_question(i, question);
	ui_mid_custom(i);
	ui_header(i);
	ui_options(i, opcao1, opcao2);
	ui_mid_custom(i);
	ui_options_2(i, opcao3, opcao4);
	ui_header(i);
	ui_center(i);
}

ui_builder_2(int i,char texto[200], char question[20], char opcao1[20], char opcao2[20]){ //entra variavel para loop sempre
	kit_completo();
	int linhas;
	ui_header(i);
	linhas = ui_texto(i,texto);
	ui_header(i);
	ui_mid(linhas);
	ui_header(i);
	ui_question(i, question);
	ui_mid_custom(i);
	ui_header(i);
	ui_options(i, opcao1, opcao2);
	ui_mid_custom(i);
	ui_mid_custom(i);
	ui_header(i);
	ui_center(i);
}

ui_builder_big(int i,char texto[200], char question[20], char opcao1[20], char opcao2[20], char opcao3[20], char opcao4[20]){ //entra variavel para loop sempre
	kit_completo();
	int linhas;
	ui_header(i);
	linhas = ui_texto(i,texto);
	ui_header(i);
	ui_mid(linhas);
	ui_header(i);
	ui_question(i, question);
	ui_mid_custom(i);
	ui_header(i);
	ui_options_big(i, opcao1, opcao2);
	ui_mid_custom(i);
	ui_options_big2(i, opcao3, opcao4);
	ui_header(i);
	ui_center(i);
}

ui_builder_ask(int i,char texto[200], char question[30]){ //entra variavel para loop sempre
	kit_completo();
	int linhas;
	ui_header(i);
	linhas = ui_texto(i,texto);
	ui_header(i);
	ui_mid(linhas);
	ui_header(i);
	ui_mid_custom(i);
	ui_mid_custom(i);
	ui_header(i);
	ui_question(i, question);
	ui_mid_custom(i);
	ui_mid_custom(i);
	ui_header(i);
	ui_center(i);
}


////////////////////////////////////////////////
///////         MAIN do programa         ///////
////////////////////////////////////////////////

int main(void)
{
	setlocale(LC_ALL, "");
	ui_builder_ask(i, "Ol�, qual seu nome de Foragido?", "Digite seu nome abaixo:");
	scanf("%s", nome);
	char bemvindo[80] =  "Bem vindo ao Jogo Tunnel tails, ";
	strcat(bemvindo, nome );
	strcat(bemvindo,"      Um Jogo de uma fuga de pris�o...");
	for(;;){
			menu_principal: opcao = "", escolha ="", caminho = "", pick = ""; // zera todas variaveis
			ui_builder(i,bemvindo, ask_select, "Jogar?", "Op��es", "Sobre", "Sair ...");
			scanf("%c", &opcao);
			if(opcao == '1'){ // para iniciar
				ui_builder_ask(i, "Bem Vindo, Esse jogo se passa em uma pris�o de alta seguran�a em 10 de maio de 1968, voc� ser� um foragido que cavou um burado em sua sela e fugiu por tuneis dos esgotos ...", ask_continuar);
				getch();
				ui_builder_ask(i, "Fa�a oque achar melhor, e suas escolhas te levar�o ou para a fuga, ou para a sua morte ...", ask_continuar);
				getch();
				escolha: ui_builder_ask(i, "Sabendo disso, tenha boa sorte Foragido,  lembrando que seu progresso n�o � salvo.                   O JOGO IR� INICIAR", ask_continuar);
				getch();
				escolha = 'i';
				break;
			}
			else if(opcao == '2'){ // Op��es
				ui_builder_ask(i,"Op��o ainda n�o desenvolvida, pois o desenvolvedor ou n�o teve muito tempo para fazer algo mais      complexo, ou � muito vagabundo.", ask_continuar);
				getch();
			}
			else if(opcao == '3') {// Sobre
				ui_builder_ask(i,"Jogo para Aula do Professor Andr� feito especialmente ajuda a aplicar e aprender conhecimentos de    aula. Desenvolvido por F�bio Molliet Segundo ano  de engenharia da Computa��o. Projeto no GitHub...", ask_continuar);
				getch();
			}
			else if(opcao == '4'){ // sai do programa e finaliza
				kit_completo();
				ui_builder_ask(i, "Obrigado por jogar/testar. Espero que tenha se     Divertido.", ask_continuar);
				getch();
				return EXIT_SUCCESS;
			}
			else{ // caso invalida
				kit_completo();
				ui_builder_ask(i, ask_erro, ask_voltar);
				getch();
				goto menu_principal;
			}
		}
		for(;;)
		{
			if(escolha == 'i') {
				ui_builder_ask(i, "Voc� acorda ainda sonolento v� seus parceiros est�o escapando por um buraco no ch�o da cela...", ask_continuar);
				getch();
				inicio: ui_builder(i, "Ao tentar se levantar voc� fica meio desequilibrado...", ask_fazer, "Pular Junto?", "Chamar o guarda?", ask_dis, ask_menu);
				scanf("%c", &escolha);
			}
			else if(escolha == '1'){
				ui_builder_big(i, "Ao cair voc� percebe que o buraco est� lotado de entulhos", ask_fazer, "tentar descer segurando", "descer com tudo...", ask_dis, ask_menu);
				scanf("%c", &pick);
				break;
			}
			else if(escolha == '2'){
				ui_builder_ask(i, "Os Guardas chegam e te pegam no flagram no buraco pe culpando, Dia Seguinte grande noticia do jornal 'Grande rebeli�o Todos os Prisoneiros foram executados ...'", ask_continuar);
				getch();
				goto morreu;
			}
			else if(escolha == '4'){
				goto menu_principal;
			}
			else{
				kit_completo();
				ui_builder_ask(i, ask_erro, ask_voltar);
				getch();
				goto inicio;
			}					
		}
		
		for(;;)
		{
			 if(pick == '1'){
				ui_builder_ask(i, "Voc� acaba cortando suas m�os com algumas pedras mas cai em seguran�a", ask_continuar);
				getch();
				ui_builder_ask(i, "Apesar de seus ferimentos, voc� olha para o breu ao seu redor e encontra 2 caminhos...", ask_continuar);
				getch();	
				inicio2: ui_builder(i, "... Voc� escuta algums sons vindos da direita e muitos outros vindo da esquerda...", ask_seguir, "direita", "esquerda", ask_dis, ask_menu);
				scanf("%c", &caminho);
				break;
			}
			else if(pick == '2'){
				ui_builder_ask(i, "Voc� Cai com tudo bate os bra�os e fratura uma das pernas e se levanta sentindo muita dor... voc� come�a a mancar com a perna direita", ask_continuar);
				getch();
				ui_builder_ask(i, "Apesar de seus ferimentos, voc� olha para o breu ao seu redor e encontra 2 caminhos...", ask_continuar);
				getch();
				ui_builder(i, "... Voc� escuta algums sons vindos da direita e muitos outros vindo da esquerda...", ask_seguir, "direita", "esquerda", ask_dis, ask_menu);
				scanf("%c", &caminho);
				break;
			}
			else if(pick == '4'){
				goto menu_principal;
			}
			else{
				kit_completo();
				ui_builder_ask(i, ask_erro, ask_voltar);
				getch();
				goto inicio;
			}					
		}
		
		for(;;)
		{
			 if(caminho == '1'){
			    ui_builder_ask(i, "Ao ir para direita voc� encontra alguns prisioneiros tentando abrir um port�o enorme, ent�o voc� se aproxima ...", ask_continuar);
				getch();	
				inicio3: ui_builder_big(i, "Eles falam que precisam de sua ajuda, para abrir o port�o enorme port�o...", ask_fazer, "Ajudar", "Ignorar e correr", ask_dis, ask_menu);
				scanf("%c", &feito);
				break;
			}
			else if(caminho == '2' ){
				ui_builder_ask(i, "Ao ir para esquerda voc� os guardas procurando prendendo e massacrando os fugitivosos...", ask_continuar);
				getch();
				ui_builder_ask(i, "Voc� tenta fugir mas � tarde de mais, um guarda rapidamente chega em voc� e te derruba com uma coronhada fazendo voc� ficar inconsciente...",  ask_continuar);
				getch();
				goto morreu;
			}
			else if(caminho == '4'){
				goto menu_principal;
			}
			else{
				kit_completo();
				ui_builder_ask(i, ask_erro, ask_voltar);
				getch();
				goto inicio2;
			}					
		}
		
		for(;;)
		{
			 if(feito == '1'){
			    ui_builder_ask(i, "Voc�s conseguem abrir o port�o facilmente com sua ajudo e voc�s correm em dire��o a uma forte luz ...", ask_continuar);
				getch();	
				ui_builder_ask(i, "Voc� fica sem ver nada de t�o forte que a luz est�, e voc� come�a a sentir a brisa fria em seu rosto...", ask_continuar);
				getch();
				ui_builder_ask(i, "Os foragidos juntos a voc� come�a a dar gritos de felicidade ... e voc� pensa ... 'Acho que n�o' ...", ask_continuar);
				getch();
				ui_builder_ask(i, "Ao sair do tunel com a luz intensa voc� cai em uma area aberta junto aos outros ... era uma emboscada dos guardas.", ask_continuar);
				getch();
				goto morreu;
			}
			else if(feito == '2' ){
				ui_builder_ask(i, "Voc� se afasta deles e come�a a correr por um longo tunel escuro e umido, com cheiro intenso de secre��es humanas", ask_continuar);
				getch();
				ui_builder_ask(i, "Voc� continua seguindo o caminho escuro, nisso voc� escuta sons de cachorros vindo de onde voc� estava anteriormente...",  ask_continuar);
				getch();
				inicio4: ui_builder_big(i, "Os barulhos aumentam, voc� olha na imensid�o do breu e nota pelo som dos latidos ecoar mais forte a aproxima��o deles", ask_fazer, "Tentar Lutar?", "Correr deles!", ask_dis, ask_menu);
				scanf("%c", &corrida);
				break;
			}
			else if(feito == '4'){
				goto menu_principal;
			}
			else{
				kit_completo();
				ui_builder_ask(i, ask_erro, ask_voltar);
				getch();
				goto inicio3;
			}					
		}
		
		for(;;)
		{
			 if(corrida == '1'){
			    ui_builder_ask(i, "Ao tentar lutar contra eles, sem ver nada por causa da escurid�o, voc� � mordido tendo seu bra�o mutilado", ask_continuar);
				getch();	
				ui_builder_ask(i, "Os cachorros s�o fortes e treinados para a situa��o ... e voc� acaba notando os guardas chegando pelas lanternas no fim do tunel.", ask_continuar);
				getch();
				ui_builder_ask(i, "Ent�o ao conseguir se livrar dos cachorros j� � tarde de mais e os guardas te capturam...", ask_continuar);
				getch();
				goto morreu;
			}
			else if(corrida == '2' ){
				ui_builder_ask(i, "Ent�o voc� tenta correr como se n�o houvesse amanh� ... porem seus ferimentos te limitam ...",  ask_continuar);
				getch();
				inicio5: ui_builder_big(i, "Logo a frente voc� nota uma pequena ilumina��o em outro fim do corredor, e por estar se guiando pela parede no escuro voc� encontra um pequeno v�o ...", ask_fazer, "Tenta entrar no v�o", "Vai para a luz", ask_dis, ask_menu);
				scanf("%c", &quase);
				break;
			}
			else if(corrida == '4'){
				goto menu_principal;
			}
			else{
				kit_completo();
				ui_builder_ask(i, ask_erro, ask_voltar);
				getch();
				goto inicio4;
			}					
		}
		
		for(;;)
		{
			 if(quase == '1'){
			 	ui_builder_ask(i, "O v�o � apertado como se fosse uma rachadura, voc� via se esgueirando pelo mesmo ...",  ask_continuar);
				getch();
				ui_builder_ask(i, "Voc� percebe que os cachorros passam direto e voc� respira aliviado ...",  ask_continuar);
				getch();
			 	ui_builder_ask(i, "Nesse pequeno v�o fica um quente pois voc� estava correndo e o ambiente fechado fazendo ficar mais quente ...", ask_continuar);
			 	getch();
			 	ui_builder_ask(i, "Voc� continua se esgueirando e sente uma brisa fria bater em sua cabe�a, um buraco antigo cavado a muito tempo",  ask_continuar);
				getch();
				ui_builder_ask(i, "Ent�o voc� se aperta e cai ao lado de fora dos muros em uma area n�o visivel pelas torres da pris�o ...",  ask_continuar);
				getch();
				goto viveu;
			}
			else if(quase == '2' ){
				ui_builder_ask(i, "Voc� corre at� a area iluminada dando uma curna acentuada no tunel...",  ask_continuar);
				getch();
				ui_builder_ask(i, "Quando voc� vira ela voc� se d� de frente com uma grade, de metal fundido, a qual fechada ... � o seu fim ",  ask_continuar);
				getch();
				ui_builder_ask(i, "Os cachorros se aproxima e te prendem sendo bastante agressivos, enquanto os guardas chegam ...",  ask_continuar);
				getch();
				ui_builder_ask(i, "Aos guardas chegam e te apagam com uma coronhada te capturando e te deixando inconsciente",  ask_continuar);
				getch();
				goto morreu;
			}
			else if(quase == '4'){
				goto menu_principal;
			}
			else{
				kit_completo();
				ui_builder_ask(i, ask_erro, ask_voltar);
				getch();
				goto inicio5;
			}					
		}
		
		if(morrer == 's')
		{
			morreu: kit_completo();
			ui_builder_ask(i, "Voc� morreu, executado pelos guardas dia 12 de maio de 1968, em uma parede de fuzilamento...", "Clique para voltar para o menu principal...");
			getch();
			goto menu_principal;
		}
		else if(morrer == 'n')
		{
			viveu: kit_completo();
			ui_builder_ask(i, "Voc� sobreviveu ... e conseguiu escapar da pris�o, parab�ns voc� venceu o jogo ...", "Clique para voltar para o menu principal...");
			getch();
			goto menu_principal;
		}
	// variavles  ask_dis, ask_menu, ask_erro, ask_voltar, ask_continuar
	///////// Functions dos builders	
	/*
	Proposta:
	-Prision break em tunels 
	-persoangem  an�o  (D&D)
-Stealth ? 
-Loud
- Algum personagem ao longo do caminho para ser sacrificio 
- "combate"
- monstro perseguindo o prisioneiro, talvez um "stalker"(criatura invisivel) 
- tunels trancados
-todos os finais terminam com a morte do personagem de alguma forma tragica 
A morte � inevitavel (EDGE BOY)
-Oportunidade da fuga: Personagem � um "badass" e gra�as a sua caracteristica racial (resilencia) ele consegue matar um guarda e se armar com os equip dele (Ao menos as armas KKJ)*/
	// ui_builder(i, texto, pergunta, op1, op 2, op 3 , op 4)  /// ask_fazer ask_select
	// ui_builder_2(i, texto, pergunta, op1, op 2 )            /// ask_fazer ask_select
	//ui_builder_big(i, texto, pergunta, op1, op 2 ) 
	// ui_builder_ask(i, texto, pergunta)                      /// ask_continuar
}
