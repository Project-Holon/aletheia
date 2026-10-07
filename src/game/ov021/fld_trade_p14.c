/*
 * file:     fld_trade_p14.c
 * unit:     yes
 * function: func_021CE724, func_021CE73C, func_021CE760
 * address:  0x021CE724
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203D7BC  0x0203D7BC  arm
 */
typedef unsigned char u8;

typedef unsigned int   u32;

typedef struct {
    u8 state;
    u8 pad1[0x2b];
} Entry;

typedef struct {
    u8 pad0[0x70];
    Entry ent[4];
} Mgr;

typedef unsigned short u16;

extern void func_0203D7BC(u8 a);
void func_021CE724(u8 *p);
int func_021CE73C(Mgr *m);
u32 func_021CE760(u8 *p);


/*
 * Unlabelled leaf (a `.word` run in the listing); filed as the witness for
 * the tail-call stub func_021CF2E4 in ov021_func_021CF288.c.
 *
 * Addresses are Black-image addresses.
 */
void func_021CE724(u8 *p)
{
    p[0x576] = 1;
    p[0x577] = 1;
    func_0203D7BC(1);
}


/*
 * Counts the entries among the four 0x2C-byte entries at +0x70 whose state is 4.
 *
 * Addresses are Black-image addresses.
 */
int func_021CE73C(Mgr *m)
{
    int i;
    int n = 0;

    for (i = 0; i < 4; i++) {
        if (m->ent[i].state == 4)
            n++;
    }
    return n;
}


u32 func_021CE760(u8 *p)
{
    u32 mask = 0;
    int i;

    for (i = 0; i < 4; i++) {
        if (p[0x70 + i * 0x2c] == 4) {
            mask |= 1 << i;
        }
    }
    return mask;
}
