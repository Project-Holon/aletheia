/*
 * function: func_022102BC
 * address:  0x022102BC
 * packet:   pkt_022102BC
 * region:   ov198
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203630C  0x0203630C  arm
 *   func_020362DC  0x020362DC  arm
 *   func_02035C60  0x02035C60  arm
 *   func_02211984  0x02211984  thumb  ov198
 */

typedef unsigned int u32;

struct S {
    unsigned char pad[0x1eb0];
    int f1eb0;
    int f1eb4;
};

extern u32 func_0201CE30(u32);
extern u32 func_0201CE48(u32);
extern u32 func_0201CE5C(u32, int);
extern u32 func_0201CE38(u32);
extern u32 func_02035C60(void);
extern u32 func_0203630C(void);
extern u32 func_020362DC(void);
extern u32 func_02211984(struct S *, int);

int func_022102BC(struct S *a)
{
    switch (func_0201CE30(a->f1eb0)) {
    case 0:
        if (func_02035C60() == 1 || (func_0203630C() & 3) != 0)
            func_0201CE5C(a->f1eb0, 0);
        a->f1eb4 = 0;
        break;
    case 1:
        if (a->f1eb4 != 0)
            break;
        if (func_02035C60() == 1 || (func_020362DC() & 3) != 0) {
            func_02211984(a, 0x547);
            func_0201CE38(a->f1eb0);
            a->f1eb4 = 1;
        }
        break;
    case 2:
        func_0201CE48(a->f1eb0);
        a->f1eb0 = 0;
        a->f1eb4 = 0;
        return 0x18;
    }
    return 0x17;
}
