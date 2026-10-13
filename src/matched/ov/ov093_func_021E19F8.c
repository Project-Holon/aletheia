/*
 * function: func_021E19F8
 * address:  0x021E19F8
 * packet:   pkt_ov093_021E19F8
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
 *   func_021E1AE4  0x021E1AE4  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */

typedef struct Ent { unsigned short a; unsigned short b; unsigned char c, d, e, f; } Ent;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021E1AE4(void *m, int x, Ent *out);
typedef unsigned int   u32;
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void func_021E19F8(int a, int b, int c, int d)
{
    Ent e;

    if (b == BTL_EVENT_GetVar(2) && func_021E1AE4(func_021C7CF4((int *)a, b), d, &e) == 0)
        BTL_EVENT_OverwriteVar(34, 26);
}
