/*
 * file:     unit_02064D70_p10.c
 * unit:     yes
 * function: func_02065C78, func_02065CE4, func_02065D4C
 * address:  0x02065C78
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_02147B88    0x02147B88  data
 *   func_02067CB0 0x02067CB0  arm
 *   func_02066E20  0x02066E20  arm
 *   func_02066DEC  0x02066DEC  arm
 *   func_02066E10  0x02066E10  arm
 *   func_02066DFC  0x02066DFC  arm
 *   func_02065438  0x02065438  arm
 *   func_02065878  0x02065878  arm
 */
struct Obj02065878;
typedef unsigned char u8;

typedef unsigned int  u32;

struct Obj {
    u8  pad_00[0x74];
    u32 unk_74;       /* 0x74 */
    u8  pad_78[4];
    u32 unk_7c;       /* 0x7c */
};

struct Bank {
    u32         unk_00;
    u32         unk_04;
    struct Obj *obj;   /* 0x08 */
};

typedef struct
{
    unsigned char pad[0x80];
    int f80;
} Inner;

typedef struct
{
    unsigned char pad[8];
    Inner *f8;
} Ctx;

extern void func_02067CB0(void);
extern int func_02066E20(void);
extern void func_02066DEC(int);
extern void func_02066E10(int);
extern void func_02066DFC(void);
extern void func_02065438(void *);
extern void func_02065878(struct Obj02065878 *c);
void func_02065C78(u32 a);
void func_02065CE4(void *a0);
void func_02065D4C(void *a0);
extern struct Bank g_02147B88;


/*
 * Teardown tail of the cell-actor / OAM manager: raises the capture-enable
 * bit at 0x04000448, then, if the attached object still carries work bits at
 * +0x7c, clears the two per-bit slots and drops the object pointer.
 *
 * Decompiled as a leaf so that it becomes a `matched` witness for the call at
 * 0x0204CB44+0x64 (src/pending/func_0204CB44.c); it reads no argument, the r0
 * the caller passes is a leftover.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02065C78.c \
 *       --func func_02065C78 --addr 0x02065C78 --cc 1.1p1 --arm
 */
void func_02065C78(u32 a)
{
    u32 f;
    struct Obj *o;

    *(volatile u32 *)0x04000448 = 1;

    o = g_02147B88.obj;
    f = o->unk_7c;
    if (f != 0) {
        if (f & 1)
            g_02147B88.unk_04 = 0;
        if (f & 2) {
            o->unk_74 = 0;
            func_02067CB0();
        }
        g_02147B88.obj->unk_7c = 0;
    }
    g_02147B88.obj = 0;
}



/*
 * Draws one cell actor.  Exact twin of src/matched/func_02065D4C.c with
 * func_02065438 in place of func_02065878: the bank at 0x02147B88 carries an
 * object pointer at +0x08 whose secondary render surface is at +0x80.  With
 * no secondary surface the body is the plain draw; with one, the draw is
 * bracketed save / switch / bind / draw / switch back / rebind / close.
 *
 * Pinned to ../2.0/sp2 on the same "kept constants" tell its twin carries:
 * the image loads the &g_02147B88 pool word TWICE (r1 at 0x02065CE8, r0 again
 * at 0x02065D10) and so spends only two callee-saved registers, padding the
 * frame with r3 (push {r3, r4, r5, lr}); dsi/1.1p1 -O4,p CSEs the two reads,
 * holds the base in a third callee-saved register and comes out 96 bytes
 * against the original 100 of code.  docs/notes/func_02065CE4.c.txt records
 * that four-byte residue and asks what makes mwccarm emit two separate
 * materialisations of one extern address; the answer is the front end, not
 * the C.  The `volatile` cast on each read is what keeps 2.0 from folding
 * them back together.  See docs/FRONTEND-PINS.md.
 */
void func_02065CE4(void *a0)
{
    int saved;

    if (((volatile Ctx *)&g_02147B88)->f8->f80 != 0)
    {
        saved = func_02066E20();
        func_02066DEC(1);
        func_02066E10(((volatile Ctx *)&g_02147B88)->f8->f80);
        func_02065438(a0);
        func_02066DEC(0);
        func_02066E10(saved);
        func_02066DFC();
    }
    else
    {
        func_02065438(a0);
    }
}



void func_02065D4C(void *a0)
{
    int saved;

    if (((volatile Ctx *)&g_02147B88)->f8->f80 != 0)
    {
        saved = func_02066E20();
        func_02066DEC(1);
        func_02066E10(((volatile Ctx *)&g_02147B88)->f8->f80);
        func_02065878(a0);
        func_02066DEC(0);
        func_02066E10(saved);
        func_02066DFC();
    }
    else
    {
        func_02065878(a0);
    }
}
