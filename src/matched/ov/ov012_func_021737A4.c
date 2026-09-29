/*
 * function: func_021737A4
 * address:  0x021737A4
 * packet:   pkt_ov012_021737A4
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02026454  0x02026454  thumb
 *   func_02026474  0x02026474  thumb
 *   func_02034714  0x02034714  arm
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_0201212C  0x0201212C  thumb
 *   func_020123C4  0x020123C4  thumb
 *   func_02173840  0x02173840  thumb  ov012
 *   func_02174268  0x02174268  thumb  ov012
 *   func_0217B840  0x0217B840  thumb  ov019
 *   func_0217B75C  0x0217B75C  thumb  ov019
 *   func_0217B264  0x0217B264  thumb  ov019
 */

typedef unsigned char u8;

extern int func_02026454(int a);
extern u8 *func_02026474(int a);
extern void func_02034714(void *file, int line, void *msg);
extern void func_02188C80(int b);
extern int func_0201212C(void);
extern int func_020123C4(int v);
extern int func_02173840(u8 *p);
extern int func_02174268(u8 *p);
extern void func_0217B840(u8 *p, int b);
extern void func_0217B75C(u8 *p);
extern void func_0217B264(u8 *p, int v, int b);

void func_021737A4(int a, int b)
{
    u8 *r4;
    u8 s;

    if (func_02026454(a) != 3) {
        return;
    }
    r4 = func_02026474(a);
    if (r4 == 0) {
        func_02034714((void *)0x02175610, 0, (void *)0x02175610);
    }
    func_02188C80(b);
    if (func_0201212C() == 1) {
        return;
    }
    if (func_020123C4(*(int *)(*(u8 **)r4 + 0xc)) == 1) {
        return;
    }
    if (func_02173840(r4) != 1) {
        return;
    }
    s = r4[0x2830];
    if (s >= 4 && s <= 0x17) {
        if (func_02174268(r4) != 0) {
            return;
        }
        func_0217B840(r4, b);
        return;
    }
    if (s != 0 && s != 1) {
        return;
    }
    if (func_02174268(r4) != 0) {
        return;
    }
    func_0217B75C(r4);
    func_0217B840(r4, b);
    func_0217B264(r4, *(int *)(*(u8 **)r4 + 8), b);
}
