/*
 * file:     net_state_p20.c
 * unit:     yes
 * function: func_020394DC, func_020394F0, func_02039548, sub_02039560, sub_02039578
 * address:  0x020394DC
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
 *   unk_021469D0   0x021469D0  data
 *   g_021469D0     0x021469D0  data
 *   func_0203D798  0x0203D798  arm
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct LinkState {
    u8 pad000[0x1e7];
    u8 unk_1e7;
    u8 pad1e8;
    u8 unk_1e9;
    u8 unk_1ea;
};

typedef struct {
    u8 pad_000[0x65];
    u8 f065;
} T_0203D798;

typedef struct {
    u8 pad_000[0x1ac];
    u32 f1ac;
    u32 f1b0;
    u32 f1b4;
    u32 f1b8;
} T_020394F0;

extern T_0203D798 *func_0203D798(void);
void sub_020394DC(u8 v);
void func_020394F0(u32 a);
void sub_02039548(void);
void sub_02039560(void);
void sub_02039578(void);
extern struct LinkState *unk_021469D0;
extern T_020394F0 *g_021469D0;



/*
 * A leaf setter on the link state: store the argument byte at +0x1e7.  It
 * saves no registers, so disasm.py gives it no label and it prints as a run
 * of `.word`s between two pools
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020394DC.c \n *       --func sub_020394DC --addr 0x020394DC --cc 1.1p1 --arm
 */
void sub_020394DC(u8 v)
{
    unk_021469D0->unk_1e7 = v;
}



void func_020394F0(u32 a)
{
    u8 v = func_0203D798()->f065;

    if ((u8)(v + 0xff) > 1) {
        return;
    }
    g_021469D0->f1ac = a;
    if (a == 0) {
        return;
    }
    g_021469D0->f1b0 = 0;
    g_021469D0->f1b4 = 0;
    g_021469D0->f1b8 = 0;
}



/*
 * Set the +0x1e9 flag on the link state.  sub_02039560 is the clearing half;
 * the two are byte-for-byte the same but for the stored constant.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02039548.c \n *       --func sub_02039548 --addr 0x02039548 --cc 1.1p1 --arm
 */
void sub_02039548(void)
{
    unk_021469D0->unk_1e9 = 1;
}


/*
 * Clear the +0x1e9 flag sub_02039548 sets.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02039560.c \n *       --func sub_02039560 --addr 0x02039560 --cc 1.1p1 --arm
 */
void sub_02039560(void)
{
    unk_021469D0->unk_1e9 = 0;
}


/*
 * Set the +0x1ea flag, but only when the link state has been constructed.
 * The guard and the store share one `ne` predication rather than a branch,
 * and the stored 1 is materialised into r0, the register the pool address
 * was loaded into, because that register is dead by then.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02039578.c \n *       --func sub_02039578 --addr 0x02039578 --cc 1.1p1 --arm
 */
void sub_02039578(void)
{
    if (unk_021469D0 != 0) {
        unk_021469D0->unk_1ea = 1;
    }
}
