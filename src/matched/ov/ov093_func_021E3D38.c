/*
 * function: func_021E3D38
 * address:  0x021E3D38
 * packet:   pkt_ov093_021E3D38
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */

extern int BTL_EVENT_GetVar(int);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, unsigned int a);
typedef unsigned int   u32;
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void func_021E3D38(int u, int v, int c, int *w)
{
    int p;

    if (c == BTL_EVENT_GetVar(2)) {
        p = BTL_EVENT_GetVar(0x3f);
        switch (w[0]) {
        case 1:
            func_021C8838((void *)p, 2, 0x2e9);
            func_021C8860((struct S *)p, c);
            BTL_EVENT_OverwriteVar(0x51, 1);
            break;
        case 2:
            func_021C8838((void *)p, 2, 0x2ec);
            func_021C8860((struct S *)p, c);
            BTL_EVENT_OverwriteVar(0x51, 1);
            break;
        }
    }
}
