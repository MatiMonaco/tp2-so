#include <shell.h>
#include <stdio.h>
#include <string.h>
#include <commands.h>

static void clearBuffer(char * buffer);
static void scanEntry(char * buffer);
static void commandDispacher(char* buffer);
static void commandNotFound();
static int64_t getCommandId(char * buffer);
static void help();

static struct commandStruct commands[] = {{EXIT,"exit","Exits shell"},
										{TIME,"time","Displays current time"},
										{PRINTMEM,"printmem address","Performs a 32-byte memory dump from the address received as an argument"},
										{INFOREG,"inforeg","Prints the value of all the registers"},
										{ARACNOID,"aracnoid","Iniciates aracnoid, press 'space' to leave"},
										{OPCODEEX,"opcodeex","Executes Invalid OP Code Interruption"},
										{ZERODIVEX,"zerodivex","Executes Zero Division Interruption"},
										{0,"",""}};

void initShell(){

	char entry[COMMAND_MAX_LENGHT] ={0};
	char parameter[COMMAND_MAX_LENGHT] = {0};
 printf("\nTerminal:\n\nPlease type 'help' to find out about our commands\n\n\n");
 
	while(1){
		printf("$> ");
		clearBuffer(entry);
		scanf("%s %s",entry,parameter);
		printf("%s\n",entry);
		//commandDispacher(entry);
	}
		
}

static void commandDispacher(char* buffer){
	char  command[COMMAND_MAX_LENGHT];
	

	
	

	uint64_t id = getCommandId(command);
	switch(id){

		case HELP:
			help();
		break;

		case EXIT:
			exit();
		break;

		case TIME:
			time();
		break;

		case PRINTMEM:
			
		break;

		case INFOREG:
			infoReg();
		break;

		case ARACNOID:
			aracnoid();
		break;

		case OPCODEEX:
			invalidopCodeException();
		break;

		case ZERODIVEX:
			zeroDivException();
		break;

		default:
		commandNotFound();
		break;
		
		
	}
	
	
}

static int64_t getCommandId(char * buffer){
	
	for(int i = 0; strcmp(commands[i].name,"") != 0;i++){
		if(strcmp(commands[i].name,buffer) == 0){
			return commands[i].id;

		}
	}
	return -1;
	
}	

static void help(){
	
}


static void commandNotFound(){
	perror("shell: command not found\n");
}

static void clearBuffer(char * buffer){
	while(*buffer){
		*buffer = 0;
		buffer++;
	}
}
