/*
 * function: func_021E163C
 * address:  0x021E163C
 * packet:   pkt_ov093_021E163C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetCounter  0x021D69AC  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
typedef unsigned int   u32;
extern unsigned char BTL_POKEPARAM_GetCounter(unsigned char *base, int idx);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void func_021E163C(int a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(2) && BTL_POKEPARAM_GetCounter(func_021C7CF4((int *)b, c), 0) >= 3)
        BTL_EVENT_OverwriteVar(34, 26);
}
