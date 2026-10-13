/*
 * function: func_021E4564
 * address:  0x021E4564
 * packet:   pkt_ov093_021E4564
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
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void func_021E4564(int a0, u8 *s, int k)
{
    u8 *a;
    u8 *b;
    u8 x;
    u8 y;

    if (k == BTL_EVENT_GetVar(3)) {
        a = func_021C7CF4((int *)s, k);
        b = func_021C7CF4((int *)s, (u8)BTL_EVENT_GetVar(4));
        x = func_021D59B4(a, 0x12);
        y = func_021D59B4(b, 0x12);
        if (x == 2 || y == 2 || x == y)
            BTL_EVENT_OverwriteVar(0x40, 1);
    }
}
