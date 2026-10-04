/*
 * function: func_02177614
 * address:  0x02177614
 * packet:   pkt_ov014_02177614
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_021797A4     0x021797A4  data   a4
 *   func_02178E4C  0x02178E4C  thumb  ov014
 *   func_02179498  0x02179498  thumb  ov014
 *   func_0217727C  0x0217727C  thumb  ov014
 *   func_02177660  0x02177660  thumb  ov014
 */

typedef unsigned char u8;

extern u8 *g_021797A4;
extern int func_02178E4C(void);
extern int func_02179498(void);
typedef unsigned int   u32;
extern void func_0217727C(u32 *p, u32 v);
extern void func_02177660(u8 *p);

void func_02177614(u8 *p)
{
    if (func_02178E4C() == 1 && func_02179498() != 0) {
        p[0xCF5] = 0xFF;
        func_0217727C((u32 *)g_021797A4, (u32)func_02177660);
    }
    if (func_02178E4C() == 9) {
        p[0xCF5] = 0xFF;
        func_0217727C((u32 *)g_021797A4, (u32)func_02177660);
    }
}
