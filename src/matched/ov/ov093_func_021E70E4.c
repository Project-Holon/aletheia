/*
 * function: func_021E70E4
 * address:  0x021E70E4
 * packet:   pkt_ov093_021E70E4
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
 *   func_021C83A0  0x021C83A0  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
extern u32 func_021C83A0(u8 *p, int i);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void func_021E70E4(int x, int a, int c)
{
    void *m;
    int p;
    int q;
    int r;
    int v;

    if (c == BTL_EVENT_GetVar(3)) {
        func_021C7CF4((int *)a, c);
        m = func_021C7CF4((int *)a, (u8)BTL_EVENT_GetVar(4));
        p = func_021C83A0((u8 *)a, c);
        q = func_021C83A0((u8 *)a, BTL_POKEPARAM_GetPokeId(m));
        r = p / q;
        if (r >= 5) {
            v = 0x78;
        } else if (r == 4) {
            v = 0x64;
        } else if (r == 3) {
            v = 0x50;
        } else {
            v = 0x3c;
            if (r != 2) {
                v = 0x28;
            }
        }
        BTL_EVENT_OverwriteVar(0x30, v);
    }
}
