#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <string.h>
#include "uartapi.h"

int main() {
    printf("Xin chao uart\n");
    int status_open = serial_open(1,  115200,  8,  4, 0 );
    if(status_open < 0)
    {
        printf("Open uart 1 failed\n");
        return -1;
    }
    int led_read, led_write;
    char buf[255] = {0};
    while(1)
    {
        led_read = serial_read(1 , buf,  255);
        if(led_read > 0)
        {
            printf("Dung luong data da nhan %d byte \n", led_read);
            led_write = serial_write(1 , buf,  led_read);
            if(led_write > 0)
            {
                printf("Da gui thanh cong %d byte\n", led_write);
            }
            else
            {
                printf("Loi gui du lieu\n");
                break;
            }
        }
    }
    serial_close(1);
    return 0;
}