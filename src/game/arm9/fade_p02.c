/*
 * file:     fade_p02.c
 * unit:     yes
 * function: func_0204E6E0, func_0204E6F4, func_0204E708, func_0204E720
 * address:  0x0204E6E0
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
 *   g_02146A7C 0x02146A7C data
 *   func_0209C0A4  0x0209C0A4  arm
 *   func_0204E824  0x0204E824  arm
 */
typedef signed int   s32;

typedef unsigned int u32;

struct Run0204E720 {
    u32 unk00; /* 0x00 */
    s32 unk04; /* 0x04 */
    s32 unk08; /* 0x08 */
    s32 unk0c; /* 0x0c */
    s32 unk10; /* 0x10 */
    s32 unk14; /* 0x14 */
    s32 unk18; /* 0x18 */
    s32 unk1c; /* 0x1c */
};

extern s32  func_0209C0A4(s32 a, s32 b);
extern void func_0204E824(void);
asm void func_0204E6E0(void);
void func_0204E6F4(s32 a);
void func_0204E708(void);
void func_0204E720(u32 a, s32 b, s32 c, s32 d);
int func_0204E804(void);
extern struct Run0204E720 *g_02146A7C;



asm void func_0204E6E0(void)
{
    ldr r0, =g_02146A7C
    ldr	r0, [r0]
    ldr	r0, [r0, #0x1c]
    bx	lr
}



/*
 * Setter for +0x1c of the singleton reached through the pointer at
 * 0x02146A7C.  Same object as src/matched/unit_0204E720.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204E6F4.c \
 *       --func func_0204E6F4 --addr 0x0204E6F4 --cc 1.1p1 --arm
 */
void func_0204E6F4(s32 a)
{
    g_02146A7C->unk1c = a;
}



/*
 * Arms +0x1c of the singleton reached through the pointer at 0x02146A7C:
 * the same field func_0204E6F4 sets from an argument, here forced to 1.
 * Same object as src/matched/unit_0204E720.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204E708.c \
 *       --func func_0204E708 --addr 0x0204E708 --cc 1.1p1 --arm
 */
void func_0204E708(void)
{
    g_02146A7C->unk1c = 1;
}



/*
 * Set up the singleton at 0x02146A7C for a new run.  The object is reached
 * through a pointer variable, so every store to a field is followed by a
 * fresh load of the pointer: the compiler cannot prove a store through it
 * does not overwrite the pointer itself.  Where two fields are read and one
 * written (the +0x18 * +0x1c product) one load of the pointer serves all
 * three accesses.
 *
 * The sign of the fourth argument is tested once, on the `movs` that parks
 * it in r4, and the `rsb`/`cmp`/`movge` triple inside the negative arm is
 * an absolute value written in the source: the compiler does not propagate
 * the branch condition into it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204E720.c \
 *       --func func_0204E720 --addr 0x0204E720 --cc 1.1p1 --arm
 */
void func_0204E720(u32 a, s32 b, s32 c, s32 d)
{
    g_02146A7C->unk00 = a;
    g_02146A7C->unk04 = b;
    g_02146A7C->unk0c = c;

    if (d < 0) {
        g_02146A7C->unk18 = (d < 0 ? -d : d) + 1;
        g_02146A7C->unk10 = 0;
        g_02146A7C->unk14 = 0;
    } else {
        g_02146A7C->unk18 = 1;
        g_02146A7C->unk10 = d;
        g_02146A7C->unk14 = d;
    }

    g_02146A7C->unk18 = g_02146A7C->unk18 * g_02146A7C->unk1c;

    if (d > 0) {
        struct Run0204E720 *p = g_02146A7C;

        p->unk10 = func_0209C0A4(p->unk10, p->unk1c);
        g_02146A7C->unk14 = d;
    }

    if (g_02146A7C->unk04 > g_02146A7C->unk0c)
        g_02146A7C->unk18 = g_02146A7C->unk18 * 0xffffffff;

    g_02146A7C->unk08 = g_02146A7C->unk04;

    func_0204E824();
}



int func_0204E804(void)
{
    return g_02146A7C->unk00 != 0;
}
