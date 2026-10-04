/*
 * function: func_021F2624
 * address:  0x021F2624
 * packet:   pkt_ov032_021F2624
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F2624 0x021F2624 thumb
 *   func_0202822C 0x0202822C thumb
 *   func_02028178 0x02028178 thumb
 *   func_02028230 0x02028230 thumb
 *   func_020282A4 0x020282A4 thumb
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Obj;
extern void func_0202822C(char *p, int v);
extern void func_02028178(u8 *p);
extern u32 func_02028230(u8 *p);
extern void func_020282A4(struct Obj *obj);

int func_021F2624(int a0, int *st)
{
    int h = st[6];

    switch (st[0]) {
    case 0:
        func_0202822C((char *)h, 1);
        st[0]++;
        break;
    case 1:
        func_02028178((u8 *)h);
        if (func_02028230((u8 *)h)) {
            func_020282A4((struct Obj *)h);
            return 1;
        }
        break;
    }
    return 0;
}
