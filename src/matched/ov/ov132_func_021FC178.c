/*
 * function: func_021FC178
 * address: 0x021FC178
 * packet: pkt_ov132_021FC178
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FAEE8 0x021FAEE8 thumb ov132
 *   func_021FADF8 0x021FADF8 thumb ov132
 *   func_021F9F74 0x021F9F74 thumb ov132
 */
#include "../include/Obj02851.h"
typedef unsigned int u32;
typedef unsigned short u16;
extern int func_021FAEE8(char *p);
extern void func_021FADF8(char *p, char *q);
extern u32 func_02005728(u32 range);
extern void func_021F9F74(void *, u16, void *);
void func_021FC178(int a, char *p)
{
    u32 v[3];
    int s;
    s=func_021FAEE8(p);
    if(s==2) {
        func_021FADF8(((struct Obj02851 *)p)->f30,((struct Obj02851 *)p)->f34);
        return;
    }
    if(s==1) {
        v[0]=(((struct Obj02851 *)p)->f14+func_02005728((u32)(((struct Obj02851 *)p)->f20)))>>4;
        v[1]=(0xc0000-(((struct Obj02851 *)p)->f18+func_02005728((u32)(((struct Obj02851 *)p)->f24))))>>4;
        v[2]=((struct Obj02851 *)p)->f1C+func_02005728((u32)(((struct Obj02851 *)p)->f28));
        func_021F9F74(((struct Obj02851 *)p)->f10,((struct Obj02851 *)p)->f2C,v);
    }
}
