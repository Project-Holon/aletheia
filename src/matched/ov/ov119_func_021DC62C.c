/*
 * function: func_021DC62C
 * address: 0x021DC62C
 * packet: pkt_ov119_021DC62C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: output pointer declared before scalar locals; counter zero before base assignment.
 * arithmetic: signed n guard/callee argument; unsigned base/index preserve low-word MUL/ADD wrapping at 021DC6A6/021DC6A8/021DC6B2.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021D8DD0 0x021D8DD0 thumb ov119
 *   func_02017E88 0x02017E88 thumb
 */
#include "../include/Obj00001.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct Record {u16 value;u8 a,b;} Record;
extern void func_02082BCC(void *,int,int);
typedef unsigned int   u32;
extern void *func_021D8DD0(void *a, int b, int c, char *p);
extern u32 func_02017E88(void *p, u32 id, u32 v);
void func_021DC62C(char *p,int n)
{
    Record *out=(Record *)(p+0x11fc);
    int i,mon,v;
    unsigned index,base;
    if(n==0) {
        func_02082BCC(out,0,0xb58);
        for(i=0;i<6;i++) {
            mon=(int)func_021D8DD0((void *)(*(int *)&((struct Obj00001 *)p)->f828),((struct Obj00001 *)p)->f630,i,p);
            if(mon && func_02017E88((void *)mon,0xa9,0)) {
                v=func_02017E88((void *)mon,0xab,0);
                if(v) {
                    out[i].value=v;
                    out[i].a=func_02017E88((void *)mon,0x6f,0);
                    out[i].b=func_02017E88((void *)mon,0x6e,0);
                }
            }
        }
    }
    while(n<24) {
        i=0;
        base=(unsigned)n*30u+6u;
        for(;i<30;i++) {
            index=(unsigned)i+base;
            mon=(int)func_021D8DD0((void *)(*(int *)&((struct Obj00001 *)p)->f828),n,i,p);
            if(mon && func_02017E88((void *)mon,0xa9,0)) {
                v=func_02017E88((void *)mon,0xab,0);
                if(v) {
                    out[index].value=v;
                    out[index].a=func_02017E88((void *)mon,0x6f,0);
                    out[index].b=func_02017E88((void *)mon,0x6e,0);
                }
            }
        }
        return;
    }
}
