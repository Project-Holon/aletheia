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
 *   TOUCHBAR_GetPressedButtonIdIfDone 0x021B6448 thumb ov067
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 */
#include "../include/Obj05552.h"
#include "../include/Obj25768.h"
extern void func_021BC3DC(void *);
extern int TOUCHBAR_GetPressedButtonIdIfDone(unsigned char *);
extern void FADE_Start(unsigned,int,int,int);
extern int FADE_IsActive(void);
int func_021BBF98(char *p)
{
    switch (((struct Obj05552 *)p)->f4) {
    case 0:
        if (((struct Obj25768 *)(*(char * *)&((struct Obj05552 *)p)->f14))->f9==0) {
            func_021BC3DC(((struct Obj05552 *)p)->f124);
            if (TOUCHBAR_GetPressedButtonIdIfDone(*(unsigned char * *)&((struct Obj05552 *)p)->f124)!=1) break;
        }
        FADE_Start(3,0,16,0);
        (((struct Obj05552 *)p)->f4)++;
        break;
    case 1:
        if (FADE_IsActive()==0) {
            ((struct Obj05552 *)p)->f4=0;
            return 5;
        }
        break;
    }
    return 4;
}
