/*
 * function: func_021BFF68
 * address:  0x021BFF68
 * packet:   pkt_ov210_021BFF68
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02025DE8 0x02025DE8 thumb
 *   func_020362DC 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   func_020355C4 0x020355C4 arm
 *   func_020260F4 0x020260F4 thumb
 *   func_021C003C 0x021C003C thumb ov210
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
struct Sound;
struct Struct_02025CD0;
extern int func_02025DE8(struct Sound *obj);
extern unsigned func_020362DC(void);
typedef unsigned char  u8;
extern void func_020355D8(u8 v);
extern u8 func_020355C4(void);
extern void func_020260F4(struct Struct_02025CD0 *obj, u32 state);
extern void func_021C003C(int p, unsigned b);

int func_021BFF68(int p)
{
    int *q = (int *)p;
    int r = func_02025DE8((struct Sound *)q[0xac]);
    unsigned k;

    if (r != -1)
        return r;
    k = func_020362DC();
    if (k & 0x400) {
        func_020355D8(0);
        return 8;
    }
    k = func_020362DC();
    if (k & 0x800) {
        if (func_020355C4() == 1)
            func_020260F4((struct Struct_02025CD0 *)q[0xac], 1);
        func_020355D8(0);
        return 7;
    }
    k = func_020362DC();
    if (k & 8) {
        if (func_020355C4() == 1)
            func_020260F4((struct Struct_02025CD0 *)q[0xac], 1);
        func_020355D8(0);
        func_021C003C(p, 5);
        return 5;
    }
    k = func_020362DC();
    if (k & 4) {
        if (func_020355C4() == 1)
            func_020260F4((struct Struct_02025CD0 *)q[0xac], 1);
        func_020355D8(0);
        func_021C003C(p, 6);
        return 6;
    }
    if (func_020362DC() != 0 && func_020355C4() == 1) {
        func_020355D8(0);
        func_020260F4((struct Struct_02025CD0 *)q[0xac], 1);
        return -4;
    }
    return r;
}
