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
 *   g_021797A4     0x021797A4  data   a4
 *   func_02178E4C  0x02178E4C  thumb  ov014
 *   func_0217945C  0x0217945C  thumb  ov014
 *   func_0217727C  0x0217727C  thumb  ov014
 *   func_02177614  0x02177614  thumb  ov014
 */

typedef unsigned char u8;

extern u8 *g_021797A4;
extern int func_02178E4C(void);
extern void func_0217945C(void);
typedef unsigned int   u32;
extern void func_0217727C(u32 *p, u32 v);
extern void func_02177614(u8 *p);

void func_02177660(u8 *p)
{
    p[0xCF5]--;
    if (func_02178E4C() == 0 || func_02178E4C() == 1) {
        func_0217727C((u32 *)g_021797A4, 0);
        return;
    }
    if (func_02178E4C() == 9) {
        func_0217945C();
        func_0217727C((u32 *)g_021797A4, (u32)func_02177614);
        return;
    }
    if (p[0xCF5] == 0) {
        func_0217945C();
        func_0217727C((u32 *)g_021797A4, (u32)func_02177614);
    }
}
