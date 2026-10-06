/*
 * function: func_021BF1D0
 * address: 0x021BF1D0
 * packet: pkt_ov208_021BF1D0
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * matching: initialize the flag after the output-producing call to keep its zero-cost schedule.
 * symbols:
 *   func_021BF4FC 0x021BF4FC thumb ov208
 *   func_021BA550 0x021BA550 thumb ov206
 *   func_021BF63C 0x021BF63C thumb ov208
 *   func_021BA7C8 0x021BA7C8 thumb ov206
 *   func_021BA6B0 0x021BA6B0 thumb ov206
 *   func_021BF4C4 0x021BF4C4 thumb ov208
 * Third helper arguments are explicitly live in the original caller.
 */
#include "../include/Obj00442.h"
typedef unsigned short u16;
struct Params {u16 a,b,c,d; unsigned x,y,arr[6];};
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021BF4FC(const u16 *heap, u8 *p, int key, u16 *out1, u16 *out2, u16 *out3, u16 *out4, u32 *out5, u32 *out6, u32 *out7);
extern void func_021BA550(char *p, u16 a1, u16 a2, u16 a3, u16 a4, int a5, int a6);
extern void func_021BF63C(void *,char *,void *);
extern void func_021BA7C8(void *);
extern void func_021BA6B0(char *p, u16 a1, u16 a2, u16 a3, u16 a4, int a5, int a6, int a7);
extern void func_021BF4C4(int unused, char *q, int c, int *tbl);
void func_021BF1D0(void *first,char *q,void *third)
{
    struct Params p;
    int okay,index;
    func_021BF4FC(first,(u8 *)q,(int)third,&p.d,&p.c,&p.b,&p.a,&p.y,&p.x,p.arr);
    okay=1;
    func_021BA550(((struct Obj00442 *)q)->f4,p.d,p.c,p.b,p.a,p.y,p.x);
    index=((struct Obj00442 *)q)->f98;
    if(index!=6) {
        if(p.arr[index]!=0) okay=0;
        else {func_021BF63C(first,q,third);((struct Obj00442 *)q)->f98=6;}
    }
    if(okay) func_021BA7C8(((struct Obj00442 *)q)->f8);
    else func_021BA6B0(((struct Obj00442 *)q)->f8,p.d,p.c,p.b,p.a,p.y,p.x,((struct Obj00442 *)q)->f98);
    func_021BF4C4((int)first,q,(int)third,(int *)p.arr);
}
