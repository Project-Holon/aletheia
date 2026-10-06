/*
 * file:     net_state_p62.c
 * unit:     yes
 * function: func_0203DC4C, func_0203DC68
 * address:  0x0203DC4C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021469F0     0x021469F0  data
 */
typedef unsigned char u8;

struct Ctx_0203DC4C {
    u8 pad_00[0x103];
    u8 f103;
};

struct Ctx_0203DC68 {
    u8 pad_00[0x109];
    u8 state;
};

void func_0203DC4C(void);
extern struct Ctx_0203DC4C *g_021469F0;


/*
 * net_irc_wireless.c.  Callback installed at +0x2C by func_0203D8F0 and
 * by states 4 and 14 of func_0203DC70: flags +0x103 of the live context.
 * An unlabelled ARM leaf.
 */
void func_0203DC4C(void)
{
    struct Ctx_0203DC4C *p = g_021469F0;

    if (p != 0)
        p->f103 = 1;
}


/*
 * net_irc_wireless.c.  The state setter of the wireless state machine
 * func_0203DC70: stores the new state at +0x109.  An unlabelled ARM leaf
 * (no lr save), filed as the `matched` witness for func_0203DC70's 27 calls.
 */
void func_0203DC68(struct Ctx_0203DC68 *p, int state)
{
    p->state = state;
}
