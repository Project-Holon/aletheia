/*
 * function: func_021DC218
 * address:  0x021DC218
 * packet:   pkt_ov093_021DC218
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
struct Unk021D62A8;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern void BTL_EVENT_MultiplyVar(int a, int b);

void func_021DC218(int u, int a, int b)
{
    if (b == BTL_EVENT_GetVar(3) && BTL_POKEPARAM_HasSick(func_021C7CF4((int *)a, b), 5) != 0
        && BTL_EVENT_GetVar(0x1a) == 1) {
        BTL_EVENT_MultiplyVar(0x31, 3 << 11);
    }
}
