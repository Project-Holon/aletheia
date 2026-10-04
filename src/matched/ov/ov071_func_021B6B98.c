/*
 * function: func_021B6B98
 * address:  0x021B6B98
 * packet:   pkt_ov071_021B6B98
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_021B6DB4  0x021B6DB4  thumb  ov071
 */

typedef unsigned int   u32;
struct Obj;
void func_021B6B98(void *p, int *tbl, int n, int sel, int c)
{
    void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
    void func_021B6DB4(int *p, int a, int idx);
    int i;

    for (i = 0; i < n; i++) {
        if (i == sel) {
            func_0204B6F4((struct Obj *)tbl[i * 4], 1, 1);
            func_021B6DB4(p, 1, c);
        } else {
            func_0204B6F4((struct Obj *)tbl[i * 4], 0, 1);
        }
    }
    if (sel == 0xff) {
        func_021B6DB4(p, 0, c);
    }
}
