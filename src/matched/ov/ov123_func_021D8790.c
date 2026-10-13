/*
 * function: func_021D8790
 * address: 0x021D8790
 * packet: pkt_ov123_021D8790
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   func_021B99DC 0x021B99DC thumb ov114
 *   func_021B9790 0x021B9790 thumb ov114
 *   func_021B97F4 0x021B97F4 thumb ov114
 *   func_02082D44 0x02082D44 arm
 *   func_021D6E08 0x021D6E08 thumb ov123
 *   func_021D8650 0x021D8650 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D83A4 0x021D83A4 thumb ov123
 */
#include "../include/Obj00063.h"
#include "../include/Obj22974.h"
#include "../include/Obj22975.h"
extern int GFL_NET_GetRunState(void);
typedef unsigned char  u8;
extern int func_021B99DC(u8 *p);
extern int func_021B9790(u8 *p);
extern char *func_021B97F4(void *);
extern void func_02082D44(const void *,void *,unsigned int);
extern int func_021D6E08(char *,int);
typedef unsigned int   u32;
extern void func_021D8650(char *p, int x, int *q);
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D83A4(char *p);
void func_021D8790(char *p)
{
    char *q;
    if (GFL_NET_GetRunState()) {
        if (func_021D6E08(p,func_021B99DC(((struct Obj00063 *)p)->f10))) return;
        if (func_021B9790(((struct Obj00063 *)p)->f10)) return;
        q=func_021B97F4(((struct Obj00063 *)p)->f10);
        func_02082D44(q+0x80,*(char * *)&((struct Obj00063 *)p)->f20+0xc,0x44);
        ((struct Obj22975 *)(*(char * *)&((struct Obj00063 *)p)->f20))->f50=1;
        func_021D8650(p,((struct Obj22974 *)q)->f80,(int *)q);
    } else {
        func_021D6EE0((u8 *)p,(int)func_021D83A4,0x7d4);
    }
}
