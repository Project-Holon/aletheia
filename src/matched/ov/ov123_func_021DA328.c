/*
 * function: func_021DA328
 * address: 0x021DA328
 * packet: pkt_ov123_021DA328
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203CD98 0x0203CD98 arm
 *   func_021B99DC 0x021B99DC thumb ov114
 *   func_021B9790 0x021B9790 thumb ov114
 *   func_021B97F4 0x021B97F4 thumb ov114
 *   func_021D9FD4 0x021D9FD4 thumb ov123
 *   func_021D9634 0x021D9634 thumb ov123
 *   func_021DA034 0x021DA034 thumb ov123
 *   func_021DA1A0 0x021DA1A0 thumb ov123
 *   func_021DA1EC 0x021DA1EC thumb ov123
 */
#include "../include/Obj03804.h"
extern int func_0203CD98(void);
typedef unsigned char  u8;
extern int func_021B99DC(u8 *p);
extern int func_021B9790(u8 *p);
extern int *func_021B97F4(void *);
extern int func_021D9FD4(char *,int);
extern void func_021D9634(char *p);
extern void func_021DA034(char *p, int n, int unused);
extern void func_021DA1A0(char *p);
extern void func_021DA1EC(char *p);
void func_021DA328(char *p)
{
    int *q;
    if (func_0203CD98() && !func_021D9FD4(p,func_021B99DC(((struct Obj03804 *)p)->f8)) && !func_021B9790(((struct Obj03804 *)p)->f8)) {
        q = func_021B97F4(((struct Obj03804 *)p)->f8);
        func_021D9634(((struct Obj03804 *)p)->f10);
        if (*q == 2) { func_021DA034(p,(int)func_021DA1A0,0x1d4); return; }
        if (*q == 0) { func_021DA034(p,(int)func_021DA1A0,0x1d7); return; }
        ((struct Obj03804 *)p)->f70 = *q;
        func_021DA034(p,(int)func_021DA1EC,0x1db);
    }
}
