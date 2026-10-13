/*
 * function: BTL_ABILITY_RivalryScalePower
 * address:  0x021D9070
 * packet:   pkt_ov093_021D9070
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
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern void BTL_EVENT_MultiplyVar(int a, int b);

void BTL_ABILITY_RivalryScalePower(int u, int a, int b)
{
    void *p;
    void *q;
    u8 x;
    u8 y;

    if (b == BTL_EVENT_GetVar(3)) {
        p = func_021C7CF4((int *)a, b);
        q = func_021C7CF4((int *)a, (u8)BTL_EVENT_GetVar(4));
        x = func_021D59B4(p, 0x12);
        y = func_021D59B4(q, 0x12);
        if (x != 2 && y != 2) {
            if (x == y) {
                BTL_EVENT_MultiplyVar(0x31, 5 << 10);
                return;
            }
            BTL_EVENT_MultiplyVar(0x31, 3 << 10);
        }
    }
}
