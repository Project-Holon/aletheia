/*
 * file:     net_whpipe_p06.c
 * unit:     yes
 * function: func_02177660, func_021776C4
 * address:  0x02177660
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021797A4     0x021797A4  data   a4
 *   func_02178E4C  0x02178E4C  thumb  ov014
 *   func_0217945C  0x0217945C  thumb  ov014
 *   func_0217727C  0x0217727C  thumb  ov014
 *   func_02177614  0x02177614  thumb  ov014
 *   func_02179498  0x02179498  thumb  ov014
 */
#include "../../matched/include/G_W.h"

typedef unsigned char u8;

typedef unsigned int   u32;

extern int func_02178E4C(void);
extern void func_0217945C(void);
extern void func_0217727C(u32 *p, u32 v);
extern void func_02177614(u8 *p);
extern int func_02179498(void);
void func_02177660(u8 *p);
int func_021776C4(void);
extern struct W *g_021797A4;


void func_02177660(u8 *p)
{
    p[0xCF5]--;
    if (func_02178E4C() == 0 || func_02178E4C() == 1) {
        func_0217727C((u32 *)((u8 *)g_021797A4), 0);
        return;
    }
    if (func_02178E4C() == 9) {
        func_0217945C();
        func_0217727C((u32 *)((u8 *)g_021797A4), (u32)func_02177614);
        return;
    }
    if (p[0xCF5] == 0) {
        func_0217945C();
        func_0217727C((u32 *)((u8 *)g_021797A4), (u32)func_02177614);
    }
}


int func_021776C4(void)
{
    u8 *w = ((u8 *)g_021797A4);

    if (w == 0)
        return 1;
    if (w[0xCE7] == 0 && func_02179498() != 0) {
        w[0xCF5] = 0xFF;
        func_0217727C((u32 *)((u8 *)g_021797A4), (u32)func_02177660);
        return 1;
    }
    return 0;
}
