#include<stdlib.h>
#include"hc05.h"
#include"uart_print.h"
void at_mode(UART_HandleTypeDef *huart,UART_HandleTypeDef *bluetooth){
	char *str;
	while(1){
		scan_str(huart,str);
		print_str(bluetooth,str);
		free(str);
	}
}


