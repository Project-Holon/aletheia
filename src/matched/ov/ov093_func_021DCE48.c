/*
 * function: BTL_HANDLER_TOKUSEI_IllusionBreak
 * address:  0x021DCE48
 * packet:   pkt_ov093_021DCE48
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_IsIllusionActive  0x021D6C24  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void *func_021C7CF4(int *p, int i);
struct R4;
extern int BTL_POKEPARAM_IsIllusionActive(struct R4 *p);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *l, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);

void BTL_HANDLER_TOKUSEI_IllusionBreak(int a, u8 *b, int c)
{
    u8 *p;
    if (BTL_POKEPARAM_IsIllusionActive(func_021C7CF4((int *)b, c))) {
        p = func_021C88A4((char *)b, 0x34, c);
        p[4] = c;
        func_021C8838(p + 8, 2, 478);
        func_021C8860((struct S *)(p + 8), c);
        func_021C88C8(b, p);
    }
}
