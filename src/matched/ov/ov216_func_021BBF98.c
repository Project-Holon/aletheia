/*
 * function: func_021BBF98
 * address: 0x021BBF98
 * packet: pkt_ov216_021BBF98
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BC3DC 0x021BC3DC thumb ov216
 *   func_021B6448 0x021B6448 thumb ov067
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 */
#include "../include/Obj05552.h"
#include "../include/Obj25768.h"
extern void func_021BC3DC(void *);
extern int func_021B6448(unsigned char *);
extern void func_0204E720(unsigned,int,int,int);
extern int func_0204E804(void);
int func_021BBF98(char *p)
{
    switch (((struct Obj05552 *)p)->f4) {
    case 0:
        if (((struct Obj25768 *)(*(char * *)&((struct Obj05552 *)p)->f14))->f9==0) {
            func_021BC3DC(((struct Obj05552 *)p)->f124);
            if (func_021B6448(*(unsigned char * *)&((struct Obj05552 *)p)->f124)!=1) break;
        }
        func_0204E720(3,0,16,0);
        (((struct Obj05552 *)p)->f4)++;
        break;
    case 1:
        if (func_0204E804()==0) {
            ((struct Obj05552 *)p)->f4=0;
            return 5;
        }
        break;
    }
    return 4;
}
