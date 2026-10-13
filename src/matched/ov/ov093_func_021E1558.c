/*
 * function: func_021E1558
 * address:  0x021E1558
 * packet:   pkt_ov093_021E1558
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

void func_021E1558(int a, void *p, int id)
{
    void *x;
    int d;
    if (id == BTL_EVENT_GetVar(3)) {
        x = func_021C7CF4(p, id);
        d = func_021D59B4(func_021C7CF4(p, (u8)BTL_EVENT_GetVar(4)), 13) - func_021D59B4(x, 13);
        if (d < 0) d = 1;
        BTL_EVENT_OverwriteVar(0x37, d);
    }
}
