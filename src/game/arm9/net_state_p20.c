/*
 * file:     net_state_p20.c
 * unit:     yes
 * function: func_0203B2FC, func_0203B344, func_0203B390, func_0203B448, func_0203B48C, func_0203B4DC, func_0203B52C
 * address:  0x0203B2FC
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
 *   func_0203D788  0x0203D788  arm
 *   func_02037A6C  0x02037A6C  arm
 *   func_02037928  0x02037928  arm
 *   func_0203AD80  0x0203AD80  arm
 *   func_0203B01C  0x0203B01C  arm
 *   g_021469DC     0x021469DC  data
 *   str_0203B950   0x0203B950  data
 *   func_0203D798  0x0203D798  arm
 *   func_020393D0  0x020393D0  arm
 *   func_020393A8  0x020393A8  arm
 *   func_020399EC  0x020399EC  arm
 *   func_02039ACC  0x02039ACC  arm
 *   func_0203D650  0x0203D650  arm
 *   func_0203C00C  0x0203C00C  arm
 */
struct NetState;
typedef unsigned int u32;

typedef unsigned long long u64;

typedef unsigned char  u8;

typedef unsigned short u16;

struct Vt {
    u8  pad_00[0x78];
    u32 (*f78)(void);
};

struct Obj {
    u8         pad_00[0x340];
    struct Vt *f340;
};

struct Slot_0203B2FC {
    u8  pad_00[0x53];
    u8  f53;
    u8  pad_54[2];
    u8  f56;
    u8  f57;
};

struct Slot_0203B448 {
    u8  pad_00[0x2c];
    u32 f2c;
};

extern void func_0203B01C(void);
extern void *func_0203D788(void);
extern u32   func_02037A6C(u32 a, u32 b, u32 c, u32 d);
extern u32 func_02037928(u32 a0, u16 a1);
extern void  func_0203AD80(u32 ctx, void *tag, u32 val, u32 line);
extern void func_0203C00C(void);
extern void *func_0203D798(void);
extern int func_020393D0(void);
extern int func_020393A8(void);
extern int func_020399EC(void);
extern int func_02039ACC(void);
extern u32   func_0203D650(void);
u32 func_0203B2FC(char *p);
u32 func_0203B344(char *p);
void func_0203B390(struct Slot_0203B2FC *p);
void func_0203B448(void);
void func_0203B48C(void);
void func_0203B4DC(void);
void func_0203B52C(struct Slot_0203B448 *p);
extern u32  g_021469DC;
extern char str_0203B950[];



u32 func_0203B2FC(char *p)
{
    u32 hi;
    u64 acc = *(u64 *)(p + 0x14) * *(u64 *)(p + 0xc) + *(u64 *)(p + 0x1c);
    *(u64 *)(p + 0xc) = acc;
    hi = (u32)(acc >> 32);
    return (u32)(((u64)hi * 40) >> 32) + 0x3c;
}



u32 func_0203B344(char *p)
{
    u32 hi;
    u64 acc = *(u64 *)(p + 0x14) * *(u64 *)(p + 0xc) + *(u64 *)(p + 0x1c);
    *(u64 *)(p + 0xc) = acc;
    hi = (u32)(acc >> 32);
    return (u32)(((u64)hi * 32) >> 32) + 0xb4;
}



/*
 * Closes the residue docs/notes/pkt_0203B390.c.txt recorded ("DIFF, one
 * instruction": `mov r0, #1` hoisted above the `beq` in the original but
 * left inside the alt block in every spelling that note tried).  The note
 * was looking at the wrong constant.  What the original hoists is not the
 * `1`, it is the 0x200 -- `mov r4, #0x200` at +0x24, before the compare
 * chain -- and r4 then serves FOUR uses: the length argument of
 * func_02037A6C, the second argument of func_02037928 on the alt path, and
 * the base of both line numbers (`add r3, r4, #0x45` = 0x245 and
 * `add r3, r4, #0x4a` = 0x24A).  Binding it to ONE local `u32 n = 0x200;`
 * declared before the guards gives it a live range that spans both arms,
 * which is what pins it in r4 and frees r0 for the literal `1` to be
 * materialised in the pre-branch block.  The note's experiment of making
 * `one` a local was the right technique applied to the wrong value.
 *
 * EXACT on the first compile with that change; no permuter search needed.
 */
void func_0203B390(struct Slot_0203B2FC *p)
{
    struct Obj *q = (struct Obj *)func_0203D788();
    u32 n = 0x200;

    if (q->f340->f78() == 0)
        return;
    if (p->f53 == 0 || p->f56 == 1)
        goto alt;

    if (func_02037A6C(1, (u32)&p->f57, n, (u32)func_0203B01C) == 0)
        return;
    func_0203AD80(g_021469DC, str_0203B950, func_0203B2FC((char *)p), n + 0x45);
    return;

alt:
    if (func_02037928(1, n) == 0)
        return;
    func_0203AD80(g_021469DC, str_0203B950, func_0203B344((char *)p), n + 0x4a);
}




/*
 * Reports at line 0x25D (605) when the transport's +0x78 virtual answers
 * non-zero.  The condition is the negated guard - the `pop` is on the equal
 * arm - so the C is the report inside a `!= 0` if, not a return.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B448.c \
 *       --func func_0203B448 --addr 0x0203B448 --cc 1.1p1 --arm
 */
void func_0203B448(void)
{
    if (((u32 (*)(void))*(u32 *)(*(u32 *)((char *)func_0203D788() + 0x340) + 0x78))() != 0)
        func_0203AD80((u32)((struct NetState *)((int)*(int *)((char *)(0x21469DC)))), (void *)0x203B390, 0, (int)0x25D);
}




/*
 * The same +0x10 virtual call as func_0203B4DC, reporting at line 0x265
 * (613).  Both the first call argument and the reported line derive from the
 * single 1 that the function materialises, which is what makes the line come
 * out as `add r3, r5, #0x264`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B48C.c \
 *       --func func_0203B48C --addr 0x0203B48C --cc 1.1p1 --arm
 */
void func_0203B48C(void)
{
    if (((u32 (*)(u32, u32))*(u32 *)(*(u32 *)((char *)func_0203D788() + 0x340) + 0x10))(1, 0) != 0)
        func_0203AD80((u32)((struct NetState *)((int)*(int *)((char *)(0x21469DC)))), (void *)0x203B448, 0, 0x265);
}




/*
 * Calls the transport's +0x10 virtual with (1, 0) and reports at line 0x282
 * (642) when it answers non-zero.  The zero argument and the report's third
 * argument are the same `mov r4, #0` local, which is what puts the two
 * together in one register.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B4DC.c \
 *       --func func_0203B4DC --addr 0x0203B4DC --cc 1.1p1 --arm
 */
void func_0203B4DC(void)
{
    if (((u32 (*)(u32, u32))*(u32 *)(*(u32 *)((char *)func_0203D788() + 0x340) + 0x10))(1, 0) != 0)
        func_0203AD80((u32)((struct NetState *)((int)*(int *)((char *)(0x21469DC)))), (void *)0x203B390, 0, (int)0x282);
}



/*
 * Wave 14: the "unresolvable" second tag site was a misread.  The pool word
 * at 0x0203B5CC (+0xA0) is 0x0203C00C (bytes 0c c0 03 02), not 0x0203B40C;
 * 0x0203C00C is the same tag func_0203AF40 passes and resolves `literal`.
 * The first tag, 0x0203B4DC, resolves `matched` (src/matched/func_0203B4DC.c).
 * The callback takes func_0203D650's result in r0, which is why the
 * function pointer is loaded into r1 (docs/families/net_state.h, THE
 * CALLBACK ARITY RULE).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B52C.c \
 *       --func func_0203B52C --addr 0x0203B52C --cc 1.1p1 --arm
 */
void func_0203B52C(struct Slot_0203B448 *p)
{
    func_0203D798();
    if (func_020393D0() != 0)
        return;
    if (func_020393A8() == 0) {
        func_0203AD80((u32)((struct NetState *)g_021469DC), (void *)func_0203B4DC, 0, 0x297);
        return;
    }
    if (func_020399EC() == 0)
        return;
    if (func_02039ACC() == 0)
        return;
    if (p->f2c != 0) {
        ((void (*)(u32))p->f2c)(func_0203D650());
        p->f2c = 0;
    }
    func_0203AD80((u32)((struct NetState *)g_021469DC), (void *)func_0203C00C, 0, 0x2a6);
}
