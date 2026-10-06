/*
 * function: func_021E324C
 * address: 0x021E324C
 * packet: pkt_ov119_021E324C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02047E88 0x02047E88 arm
 *   func_02048A18 0x02048A18 arm
 *   func_0204779C 0x0204779C arm
 *   func_020477A4 0x020477A4 arm
 *   d_021E7B3C 0x021E7B3C data a4
 */
#include "../include/Obj03779.h"
typedef unsigned short u16;
typedef struct {int a,b,c; u16 d,e;} Entry;
extern const Entry d_021E7B3C[];
extern u16 func_02047E88(void *,const Entry *);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_02048A18(u8 *a0, int i);
extern int func_0204779C(int *p);
struct G3dSys;
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
void func_021E324C(char *p,int n) {
    void *q;
    int i,count;
    if(d_021E7B3C[n].d) ((struct Obj03779 *)p)->f824=func_02047E88(((struct Obj03779 *)p)->f820,&d_021E7B3C[n]);
    else ((struct Obj03779 *)p)->f824=0xffff;
    if(((struct Obj03779 *)p)->f824!=0xffff) {
        q=(void *)func_02048A18(((struct Obj03779 *)p)->f820,((struct Obj03779 *)p)->f824);
        count=func_0204779C(q);
        for(i=0;i<count;i++) func_020477A4(q,(u16)i);
    }
    *(int *)&((struct Obj03779 *)p)->f109C=n;
}
