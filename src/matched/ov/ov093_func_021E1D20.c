/*
 * function: func_021E1D20
 * address:  0x021E1D20
 * packet:   pkt_ov093_021E1D20
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021C804C  0x021C804C  thumb  ov093
 *   func_021C8010  0x021C8010  thumb  ov093
 *   func_021C8290  0x021C8290  thumb  ov093
 *   func_021C831C  0x021C831C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern int func_021B9A24(unsigned int a, unsigned int b);
extern int func_021C804C(int a, int b, u32 *out);
extern int func_021C8010(u8 *p, unsigned int v);
extern int func_021C8290(u8 *p, int a, int b, void *item);
extern void func_021C831C(u8 *p, int v);

void func_021E1D20(int u, int a, int b)
{
    u32 x;
    u8 k;

    if (func_021C804C(a, b, &x) != 0) {
        k = BTL_EVENT_GetVar(6);
        if (func_021B9A24(k, b) == 0) {
            func_021C8010((u8 *)a, k);
            func_021C8010((u8 *)a, b);
            if (func_021C8290((u8 *)a, b, k, 0) == 0)
                func_021C831C((u8 *)a, b);
        }
    }
}
