#include <stdio.h>
#include <stdlib.h>  //serve pra várias coisas, mas no contexto do jogo da cobrinha, geralmente é usado para: 
//rand() e srand() ? gerar números aleatórios, tipo pra posicionar a comida da cobrinha em locais aleatórios. entre outros.

#include <windows.h> //Esse cabeçalho é específico do Windows. Ele te dá acesso a funções do sistema operacional, tipo:
//Sleep(ms) ? pausa o programa por "ms" milissegundos (usado pra dar ritmo ao jogo).
//SetConsoleCursorPosition() ? posicionar o cursor do terminal onde você quiser, tipo pra desenhar a cobrinha em um ponto específico da tela.







//Atualizar a tela do jogo (reimprimir tudo no mesmo lugar) sem usar system("cls"), o que evita que a tela fique piscando. e chama ela antes da estrtura int.
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}











int main (){
	
	int i, j, tela = 32, parede = 219, cobra = 219, comida = 190;     //caractere da cobrinha, o numero é de uma tabela do video
	int vMtela [25] [50];
	int vcobrinhay = 5 , vcobrinhax = 4;    //variavel da cobrinha, o primeiro põe ela linha e o outro na coluna
	char vtecla ;
	int raboy[5000] , rabox[5000] ;
	int vtamanho = 2;
	int controleo = 0 , comid = 0, comiday, comidax;
	int rastrox, rastroy ;
	
	
	
	
	for (i=0;i<25;i++){
		
			for (j=0; j<50; j++){
				vMtela [i] [j] = tela ;
							}
	                                 }
	
	
	               				
	 //para criar parede do jogo de cima e em baixo usa o for do j
		//parede de cima
		
    	    for (j=0; j<50; j++){
	    	i=0;
			vMtela [i] [j] = parede ;      
}
	
	//parede de baixo
	
		for (j=0; j<50; j++){
		i=24;
		vMtela [i] [j] = parede ;       				
                                 }




      //para criar as parede do lado é o for do i
	
	  // parede da esquerda
		for (i=0;i<25;i++){                 // tem q ser 0 pra começar no incio a parede
			j=0;
		vMtela [i] [j] = parede ; 
	                             }
	
	 // parede da direita
		for (i=0;i<25;i++){                  // 50 é o tamanho maximo (de largura da minha tela ent pego sempre um menor 
			j=49;
		vMtela [i] [j] = parede ; 
	                              }
	
	
	
	
	
	
	while (1) {
	
	
	
	
	
	
	        if (kbhit()){
	        	
	        vtecla = getch() ;
	        	
	        	
			}
	
	
	
	        raboy[controleo] = vcobrinhay ;
	        rabox [controleo]= vcobrinhax ;
	        controleo ++ ;
	        
	        
	        if ( comid == 0){
	        	comiday = 1 + rand() %23;        //pra gerar um numero aleatorio, na linha e coluna onde vai aparece a comida
	        	
				comidax = 1 + rand () %48;      //vai ser 48 e 23 pq vai ter um + 1 antes, e tbm pra n nascer na parede
	        	
				vMtela[comiday][comidax] = comida ;			
	            comid = 1;
	            
	
	
	
                                  }
                                  
            if (vcobrinhax == comidax && vcobrinhay == comiday){
            	comid = 0 ;
            	vtamanho ++ ;
            	
			}
	        
	        else {
	        	
	        	rastroy = raboy [controleo-vtamanho];
	        	rastrox = rabox [controleo-vtamanho];
	        	
	        	
			}
	
	
	     	for (i=0; i<25; i++){
			for (j=0; j<50; j++){
			printf ("%c",vMtela [i] [j] );
				
				
				
				
			}
			printf ("\n");
		
	}
	
	

	
	
	if (vcobrinhax == 0 || vcobrinhax == 49 || vcobrinhay == 0 || vcobrinhay == 24){   //quando a cobra bater na parede de cima ou nos lado
		system ("cls");
		printf ("GAME OVER \n\n\n");
		system ("pause");
		exit (0);
	}
	
	
		vMtela [vcobrinhay] [vcobrinhax] = cobra;
	
	
	//movimento da cobrinha
	
	if (vtecla ==97){    //97 é tecla A,  vai pra esquerda
	vcobrinhax -- ;
	
	}	
	   if (vtecla ==100 ){ //100 é tecla d, vai pra direita
	vcobrinhax ++ ;
	
	}
		if (vtecla ==119 ){ //119 é tecla w, vai pra cima
	vcobrinhay -- ;
	
	}
		if (vtecla ==115){ //115 é tecla s, vai pra baixo
	vcobrinhay ++ ;
	}
	
	
	
	
	
	if (vcobrinhax != rastrox || vcobrinhay != rastroy){    //!= sinifica diferente
	
	vMtela [rastroy][rastrox] = tela;
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	Sleep (100);  // Pausa o programa por 200 (exemplo) milissegundos, Dá um tempo entre cada movimento da cobrinha,
	 //senão o jogo rodaria rápido demais
	
	
	gotoxy(0, 0);  //Essa função é usada para redesenhar a tela sem limpá-la, ajudando a evitar o "piscar" do terminal, comum com system("cls").


    }
	
}
