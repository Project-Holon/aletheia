/*
 * function: func_021BF810
 * address: 0x021BF810
 * packet: pkt_ov203_021BF810
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BE9A4 0x021BE9A4 thumb ov203
 *   func_021BF9B8 0x021BF9B8 thumb ov203
 *   TCBL_Main 0x020310C4 arm
 *   func_021BF924 0x021BF924 thumb ov203
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj02250.h"
typedef struct { int kind;int values[9]; } Record;
typedef unsigned int   u32;
struct Tcbl;
extern u32 func_021BE9A4(u32 id);
extern void func_021BF9B8(unsigned a, unsigned b, char *p);
extern void TCBL_Main(struct Tcbl *p);
extern void func_021BF924(char *);
extern u32 func_020307B0(void *p);
void func_021BF810(char *p)
{
    Record *r;
    int owner,i;
    owner=((struct Obj02250 *)p)->f1C;r=(Record *)func_021BE9A4(((struct Obj02250 *)p)->f4);
    for(i=0;i<9999;i++,r++) {
        if(r->kind==18) break;
        func_021BF9B8((unsigned int)p,owner,(char *)r);
    }
    ((struct Obj02250 *)p)->fC=1;
    TCBL_Main(((struct Obj02250 *)p)->f20);func_021BF924(p);func_020307B0(p);
}
