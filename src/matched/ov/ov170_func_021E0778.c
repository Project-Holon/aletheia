/*
 * function: func_021E0778
 * address: 0x021E0778
 * packet: pkt_ov170_021E0778
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021ED544 0x021ED544 thumb ov170
 *   func_021EC0B0 0x021EC0B0 thumb ov170
 *   func_021EC08C 0x021EC08C thumb ov170
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021ED7C4 0x021ED7C4 thumb ov170
 */
#include "../include/Obj02502.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021ED544(char *p, int b);
extern void func_021EC0B0(char *,int,short *,short *,u16);
extern void func_021EC08C(char *p, int i, int a, int b, unsigned short c);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
extern void func_021ED7C4(char *,int);
#define W(p) (*(char **)((p)+0x2C))
int func_021E0778(u8 *p)
{
    char *s=W(p)+0x58;
    short xy[2];
    int k;
    switch(((struct Obj02502 *)s)->fC) {
    case 0:
        func_021ED544((char *)p,7);
        (((struct Obj02502 *)s)->fC)++;
    case 1:
        if(((struct Obj02502 *)s)->fE==4) {
            ((struct Obj02502 *)s)->fE=0;
            (((struct Obj02502 *)s)->fC)++;
            break;
        }
        func_021EC0B0(W(p),4,&xy[1],&xy[0],0);
        func_021EC08C(W(p),4,(short)xy[1],(short)(xy[0]+2),(short)0);
        (((struct Obj02502 *)s)->fE)++;
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x666);
        func_021ED544((char *)p,8);
        (((struct Obj02502 *)s)->fC)++;
    case 3:
        if(((struct Obj02502 *)s)->fE==4) {
            ((struct Obj02502 *)s)->fE=0;
            ((struct Obj02502 *)s)->fC=0;
            return 0;
        }
        func_021EC0B0(W(p),4,&xy[1],&xy[0],0);
        func_021EC08C(W(p),4,(short)xy[1],(short)(xy[0]-2),(short)0);
        k=*(u8 *)(W(p)+0x3DF6);
        func_021EC0B0(W(p),k,&xy[1],&xy[0],0);
        func_021EC08C(W(p),k,(short)xy[1],(short)(xy[0]-2),(short)0);
        func_021ED7C4(W(p),0x24);
        (((struct Obj02502 *)s)->fE)++;
        break;
    }
    return 1;
}
