/*
 * function: func_021BF280
 * address: 0x021BF280
 * packet: pkt_ov208_021BF280
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 021BF306..021BF308 is two-byte zero alignment padding.
 * symbols:
 *   func_021BF4FC 0x021BF4FC thumb ov208
 *   func_021BA6B0 0x021BA6B0 thumb ov206
 *   func_021BA814 0x021BA814 thumb ov206
 *   func_021BA64C 0x021BA64C thumb ov206
 *   func_021BF63C 0x021BF63C thumb ov208
 *   func_021BF620 0x021BF620 thumb ov208
 * Third helper arguments are explicitly live in the original caller.
 */
#include "../include/Obj00442.h"
typedef unsigned short u16;
struct Params {u16 a,b,c,d; unsigned x,y,arr[6];};
extern void func_021BF4FC(void *,char *,void *,u16 *,u16 *,u16 *,u16 *,unsigned *,unsigned *,unsigned *);
extern void func_021BA6B0(char *p, u16 a1, u16 a2, u16 a3, u16 a4, int a5, int a6, int a7);
extern void func_021BA814(void *);
extern void func_021BA64C(char *p, int mode);
extern void func_021BF63C(void *,char *,void *);
extern void func_021BF620(void *,char *,void *);
void func_021BF280(void *first,char *q,void *third,int next)
{
    struct Params p;
    int current=((struct Obj00442 *)q)->f98;
    if(current!=next) {
        if(current==6) {
            func_021BF4FC(first,q,third,&p.d,&p.c,&p.b,&p.a,&p.y,&p.x,p.arr);
            func_021BA6B0(((struct Obj00442 *)q)->f8,p.d,p.c,p.b,p.a,p.y,p.x,next);
            func_021BA814(((struct Obj00442 *)q)->f8);
        } else func_021BA64C(((struct Obj00442 *)q)->f8,next);
        func_021BF63C(first,q,third);((struct Obj00442 *)q)->f98=next;
        func_021BF620(first,q,third);
    }
}
