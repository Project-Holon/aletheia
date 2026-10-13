/*
 * function: func_021E101C
 * address:  0x021E101C
 * packet:   pkt_ov093_021E101C
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
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
typedef unsigned int   u32;
struct Unk021D62A8;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void func_021E101C(int a, int b, int c)
{
    int n;

    if (c != BTL_EVENT_GetVar(3))
        return;
    n = (unsigned char)BTL_EVENT_GetVar(4);
    if (BTL_POKEPARAM_HasSick(func_021C7CF4((int *)b, n), 2) == 0)
        BTL_EVENT_OverwriteVar(64, 1);
}
