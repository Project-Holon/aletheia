/*
 * function: func_021EED90
 * address:  0x021EED90
 * packet:   pkt_ov093_021EED90
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9F70  0x021B9F70  thumb  ov093
 *   func_021B86B8  0x021B86B8  thumb  ov093
 *   func_021BA004  0x021BA004  thumb  ov093
 *   func_021B9FAC  0x021B9FAC  thumb  ov093
 *   func_021BA064  0x021BA064  thumb  ov093
 *   func_021BA080  0x021BA080  thumb  ov093
 *   func_0202A3CC  0x0202A3CC  thumb
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F134  0x0201F134  thumb
 *   d_021F6398     0x021F6398  data  ov093  a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

struct WordSet;
extern int func_021B9F70(u8 *p, int i);
extern void *func_021B86B8(void ***p);
extern u16 func_021BA004(char *p, int i);
extern u32 func_021B9FAC(u8 *p, int i, u32 *out);
extern int func_021BA064(char *p, int i);
extern int func_021BA080(void *battle);
extern u8 func_0202A3CC(u32 cls);
extern void func_0201EE0C(void *win, u32 slot, void *str, u32 a, u32 b, u32 c);
extern void func_0201F02C(void *win, u32 slot, int v);
extern void func_0201F134(struct WordSet *p, u32 i, u32 v);
extern void *d_021F6398;

void func_021EED90(void *win, u32 slot, int k)
{
    u32 t;
    int v;

    if (k != 4) {
        if (func_021B9F70(d_021F6398, k) != 0) {
            if ((int)func_021B86B8(d_021F6398) == 1) {
                v = func_021BA004(d_021F6398, k);
                if (v != 0)
                    func_0201F134(win, slot, v);
            } else {
                v = func_021B9FAC(d_021F6398, k, &t);
                func_0201EE0C(win, slot, (void *)v, func_0202A3CC(t), 1, 2);
            }
        } else {
            func_0201F02C(win, slot, func_021BA064(d_021F6398, k));
        }
    } else {
        func_0201F02C(win, slot, func_021BA080(d_021F6398));
    }
}
