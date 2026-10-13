/*
 * function: func_021E71E4
 * address:  0x021E71E4
 * packet:   pkt_ov093_021E71E4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The decrement inside the call argument (`i--`) is what puts the `subs`
 * before the result test; a `for (...; i--)` step lands it after the branch.
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C812C  0x021C812C  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   func_021C8138  0x021C8138  thumb  ov093
 *   func_021E7260  0x021E7260  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
struct Q7;
extern u8 *func_021C812C(u8 *p);
struct QQ;
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern u16 func_021C8138(struct Q7 *p);
extern int func_021E7260(int a, int b, int c);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void func_021E71E4(int a, int b, int c)
{
    int x, y, i, v;
    u32 n;

    if (c == BTL_EVENT_GetVar(3)) {
        x = (int)func_021C812C((u8 *)b);
        y = BTL_EVENT_GetFactorKey((void *)a);
        i = func_021C8138((struct Q7 *)b) - 1;
        n = 0;
        for (; i >= 0;) {
            if (func_021E7260(x, y, i--) == 0)
                break;
            n++;
        }
        switch (n) {
        case 0: v = 0x28; break;
        case 1: v = 0x50; break;
        case 2: v = 0x78; break;
        case 3: v = 0xa0; break;
        default: v = 0xc8; break;
        }
        BTL_EVENT_OverwriteVar(0x30, v);
    }
}
