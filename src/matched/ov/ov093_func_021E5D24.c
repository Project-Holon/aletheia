/*
 * function: func_021E5D24
 * address:  0x021E5D24
 * packet:   pkt_ov093_021E5D24
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
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   BTL_CALC_GetMonParamWithHeap  0x021D805C  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
struct QI;
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern u32 BTL_CALC_GetMonParamWithHeap(void *p, u32 n);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void func_021E5D24(int a, void *b, int c)
{
    if (c == BTL_EVENT_GetVar(3)) {
        u16 n = (int)BTL_POKEPARAM_GetItem(func_021C7CF4(b, c));
        BTL_EVENT_OverwriteVar(0x30, BTL_CALC_GetMonParamWithHeap((void *)n, 10));
    }
}
