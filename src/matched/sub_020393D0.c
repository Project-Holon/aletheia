/*
 * function: sub_020393D0
 * address:  0x020393D0
 * packet:   pkt_020393A8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203D788  0x0203D788  arm
 *   unk_021469D0   0x021469D0  data
 *
 * Is the link busy?  The +0x1e9 flag on the link state forces a yes, and
 * otherwise the driver's own predicate at +0x88 decides.
 *
 * The two halves of the flag test share one `ne` chain and a single `popne`,
 * so they are one `&&` rather than nested `if`s.  func_0203D788 is called
 * before the flag is even read because its result is needed on the fall
 * through path, and the compiler will not sink a call past a branch.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020393D0.c \n *       --func sub_020393D0 --addr 0x020393D0 --cc 1.1p1 --arm
 */

typedef unsigned char u8;

struct LinkState {
    u8 pad000[0x1e9];
    u8 unk_1e9;
};

struct LinkDriver {
    u8 pad00[0x88];
    int (*busy)(void);
};

struct LinkRoot {
    u8 pad000[0x340];
    struct LinkDriver *driver;
};

extern struct LinkState *unk_021469D0;
extern struct LinkRoot *func_0203D788(void);

int sub_020393D0(void)
{
    struct LinkRoot *root;

    root = func_0203D788();

    if (unk_021469D0 != 0 && unk_021469D0->unk_1e9 != 0) {
        return 1;
    }
    return root->driver->busy() != 0;
}
