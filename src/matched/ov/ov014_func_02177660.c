/*
 * function: func_02177660
 * address:  0x02177660
 * packet:   pkt_ov014_02177660
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_pWhPipeWork     0x021797A4  data   a4
 *   func_02178E4C  0x02178E4C  thumb  ov014
 *   DWCi_MOV_WH_StateInEndKeyShare  0x0217945C  thumb  ov014
 *   func_0217727C  0x0217727C  thumb  ov014
 *   func_02177614  0x02177614  thumb  ov014
 */

#include "../include/G_W.h"

typedef unsigned char u8;

extern struct W *g_pWhPipeWork;
extern int func_02178E4C(void);
extern void DWCi_MOV_WH_StateInEndKeyShare(void);
typedef unsigned int   u32;
extern void func_0217727C(u32 *p, u32 v);
extern void func_02177614(u8 *p);

void func_02177660(u8 *p)
{
    p[0xCF5]--;
    if (func_02178E4C() == 0 || func_02178E4C() == 1) {
        func_0217727C((u32 *)((u8 *)g_pWhPipeWork), 0);
        return;
    }
    if (func_02178E4C() == 9) {
        DWCi_MOV_WH_StateInEndKeyShare();
        func_0217727C((u32 *)((u8 *)g_pWhPipeWork), (u32)func_02177614);
        return;
    }
    if (p[0xCF5] == 0) {
        DWCi_MOV_WH_StateInEndKeyShare();
        func_0217727C((u32 *)((u8 *)g_pWhPipeWork), (u32)func_02177614);
    }
}
