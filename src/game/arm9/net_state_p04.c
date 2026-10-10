/*
 * file:     net_state_p04.c
 * unit:     yes
 * function: func_0203B018, func_0203B01C, func_0203B038, func_0203B084, func_0203B0C4, func_0203B16C, func_0203B170, func_0203B1B0, func_0203B1D8, func_0203B224, func_0203B228, func_0203B22C, func_0203B258, func_0203B2A8, func_0203B2D0, func_0203B2FC, func_0203B344, func_0203B390, func_0203B448, func_0203B48C, func_0203B4DC, func_0203B52C
 * address:  0x0203B018
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
 *   g_021469DC  0x021469DC  data
 *   func_02037A6C  0x02037A6C  arm
 *   func_0203AD80  0x0203AD80  arm
 *   unk_0203B018   0x0203B018  arm
 *   unk_0203B01C   0x0203B01C  arm
 *   s_020A7BA8     0x020A7BA8  data
 *   s_020A7BC8     0x020A7BC8  data
 *   func_02034714  0x02034714  arm
 *   func_02082D44  0x02082D44  arm
 *   func_0203C934  0x0203C934  arm
 *   func_0203D798  0x0203D798  arm
 *   func_02037894  0x02037894  arm
 *   unk_0203B228   0x0203B228  data
 *   unk_0203B22C   0x0203B22C  arm
 *   func_0203D788  0x0203D788  arm
 *   func_02037928  0x02037928  arm
 *   str_0203B950   0x0203B950  data
 *   func_020393D0  0x020393D0  arm
 *   func_020393A8  0x020393A8  arm
 *   func_020399EC  0x020399EC  arm
 *   func_02039ACC  0x02039ACC  arm
 *   func_0203D650  0x0203D650  arm
 *   func_0203C00C  0x0203C00C  arm
 */
struct NetState_0203B018;
typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int  u32;

typedef signed char s8;

typedef unsigned long long u64;

typedef struct {
    u64 x;
    u64 mul;
    u64 add;
} MATHRandContext64;

struct NetState_0203B018 {
    u32  f00;
    u32  f04;
    void (*f08)(struct NetState_0203B018 *s);
    MATHRandContext64 rng;
    u32  f24;
    void (*f28)(void);
    void (*f2C)(u32 a);
    u32  err[4];
    u8   mac[6];
    u16  f46;
    s8   flag;
    u8   pad49;
    u8   f4A;
    u8   f4B;
    u8   f4C;
    u8   f4D;
    u8   f4E;
    u8   f4F;
    u8   f50;
    u8   f51;
    u8   pad52;
    u8   f53;
    u8   pad54[2];
    u8   f56;
    u8   addr[6];
    u8   pad5D[7];
};

struct NetState_0203B2FC {
    u32  f00;
    u32  f04;
    void (*f08)(struct NetState_0203B2FC *s);
    MATHRandContext64 rng;
    u32  f24;
    void (*f28)(void);
    void (*f2C)(u32 a);
    u32  err[4];
    u8   mac[6];
    u16  f46;
    s8   flag;
    u8   pad49;
    u8   f4A;
    u8   f4B;
    u8   f4C;
    u8   f4D;
    u8   pad4E;
    u8   f4F;
    u8   f50;
    u8   f51;
    u8   pad52;
    u8   f53;
    u8   pad54[2];
    u8   f56;
    u8   addr[6];
    u8   pad5D[7];
};

struct Vt {
    u8  pad_00[0x78];
    u32 (*f78)(void);
};

struct Obj {
    u8         pad_00[0x340];
    struct Vt *f340;
};

extern u32  func_02037A6C(int a0, int a1, int a2, int a3);
extern void func_0203AD80(struct NetState_0203B018 *s, void *p, u32 v, int line);
extern void *func_0203D798(void);
extern u32 func_02037928(u32 a0, u16 a1);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02082D44(int a0, int a1, int a2);
extern void func_0203C934(void);
extern u32   func_02037894(int a0, int a1, int a2, int a3);
extern void *func_0203D788(void);
extern void func_0203C00C(void);
extern int func_020393D0(void);
extern int func_020393A8(void);
extern int func_020399EC(void);
extern int func_02039ACC(void);
extern u32   func_0203D650(void);
void func_0203B018(void);
void func_0203B01C(void);
void func_0203B038(struct NetState_0203B018 *a0);
void func_0203B084(void);
void func_0203B0C4(int a0, int a1);
void func_0203B16C(void);
void func_0203B170(void);
void func_0203B1B0(void);
u32 func_0203B1D8(void);
void func_0203B224(void);
void func_0203B228(void);
int func_0203B22C(void);
void func_0203B258(void);
void func_0203B2A8(int a0);
void func_0203B2D0(u32 val);
u32 func_0203B2FC(struct NetState_0203B2FC *p);
u32 func_0203B344(struct NetState_0203B2FC *p);
void func_0203B390(struct NetState_0203B2FC *p);
void func_0203B448(void);
void func_0203B48C(void);
void func_0203B4DC(void);
void func_0203B52C(struct NetState_0203B2FC *p);
extern struct NetState_0203B018 *g_021469DC;
extern char unk_0203B018[];
extern char unk_0203B01C[];
extern char s_020A7BA8[];
extern char s_020A7BC8[];
extern char  unk_0203B228[];
extern char  unk_0203B22C[];
extern char str_0203B950[];







/*
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0203B018.c \
 *       --addr 0x0203B018 --arm
 *
 * net_state.c.  func_0203B018 is the 4-byte `bx lr` no-op that
 * func_0203B038 hands to func_02037A6C as its completion callback (the
 * pool word at 0x0203B080 is its only referrer).  func_0203B01C is the
 * unlabelled leaf that bumps the state record's +0x46 countdown by 0x3C;
 * func_0203B390 names it through a pool word.  Filing both here gives the
 * `matched` class a witness for each (docs/families/net_state.h, THE REPORT
 * TAG RULE, "the two genuine exceptions").
 *
 * Integrator: seed 0x0203B01C arm (member of this unit, no label).
 */
void func_0203B018(void)
{
}







void func_0203B01C(void)
{
    g_021469DC->f46 += 0x3c;
}







/*
 *           resolved.  Adding the symbols: block (it had none) let
 *           0x0203B01C resolve as `literal x8, e.g. 0203B43C`; previously it
 *           reported "no address for 'unk_0203B01C'".  The ONE remaining
 *           site is 0x0203B018.
 * PARKED AT MATCH.  Every concrete byte is right (76 of 76) and the file is
 * the right size; the one open site is the ABS32 to 0x0203B018, the bare
 * `bx lr` filler word that sits between func_0203AFCC's literal pool and the
 * unlabelled leaf at 0x0203B01C.  That address has no label (a prologue that
 * saves no `lr` is never auto-labelled) and the word appears in exactly one
 * literal pool image-wide - this function's own - so neither `label` nor
 * `literal` can attest it.
 *           referenced by exactly ONE word image-wide, the pool word at
 *           0x0203B080 (grep of asm/ finds it in main.s and the four unit
 *           listings, all the same address), and 0x0203B080 lies inside this
 *           function's own compared range 0203B038..0203B084.  `label`
 *           refuses (a `bx lr` saves no lr so disasm.py never labels it),
 *           `literal` refuses (no second occurrence outside the range) and
 *           `sole-ref/code` refuses (not a traced function start).  Blocking
 *           class: none available, own-pool-only code.  It would unstick if a
 *           future EXACT entry covered 0x0203B018 itself, but that address is
 *           outside pkt_0203B038's range (0x0203B038..0x0203B084).
 *
 * Both 0x0203B018 and 0x0203B01C must be declared in the symbols: block:
 * written as plain integer literals the pair folds into one pool word plus a
 * `sub r1, r4, #4`, which is four bytes short of the original's two words.
 * 0x0203B01C resolves as `literal x10`; only the no-op word does not.
 *
 * The call's completion callback is the leaf at 0x0203B01C (bumps the +0x46
 * halfword by 0x3C); the report's identifier is the no-op at 0x0203B018.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0203B038.c \
 *       --func func_0203B038 --addr 0x0203B038 --cc 1.1p1 --arm
 */
void func_0203B038(struct NetState_0203B018 *a0)
{
    if (func_02037A6C(0, (int)a0->mac, 0x200, (int)unk_0203B01C) != 0)
        func_0203AD80(g_021469DC, (void *)unk_0203B018, 0xA, 0x169);
}






/*
 * Starts a 0x200-byte transfer over channel 1 and reports at line 0x17C
 * (380) when it answers zero.  The report site names func_0203B038, the
 * sibling entry that put the read in flight.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B084.c \
 *       --func func_0203B084 --addr 0x0203B084 --cc 1.1p1 --arm
 */
void func_0203B084(void)
{
    func_0203D798();
    if (func_02037928(1, 0x200) != 0)
        func_0203AD80(g_021469DC, (void *)0x203B038, 0, (int)0x17C);
}






void func_0203B0C4(int a0, int a1)
{
    if ((int)g_021469DC->mac & 1) {
        func_02034714(s_020A7BA8, 395, s_020A7BC8);
    }
    if (a0 != 0) {
        func_02082D44(a0, (int)g_021469DC->mac, 6);
    }
    if (a1 != 0) {
        func_0203AD80(g_021469DC, (void *)func_0203B084, 0, 400);
    } else {
        func_0203AD80(g_021469DC, (void *)func_0203B038, 0, 403);
    }
}






void func_0203B16C(void)
{
}







/*
 * The same 0x200-byte channel-1 start as func_0203B084 with no context
 * refresh, reporting at line 0x1AE (430).  0x1AE is not ARM-encodable, so the
 * constant is materialised off the 0x200 argument register as
 * `sub r3, r4, #0x52`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B170.c \
 *       --func func_0203B170 --addr 0x0203B170 --cc 1.1p1 --arm
 */
void func_0203B170(void)
{
    if (func_02037928(1, 0x200) != 0)
        func_0203AD80(g_021469DC, (void *)0x203B16C, 0, 0x1AE);
}







/*
 * Tail-call wrapper over func_0203AD80 (the object at 0x021469DC, the
 * callback func_0203B170, 0, 0x1BC).  An unlabelled ARM leaf, filed as the
 * witness chain for func_0203D010 (state 10 of func_0203DC70).
 */
void func_0203B1B0(void)
{
    func_0203AD80(g_021469DC, func_0203B170, 0, 0x1BC);
}





u32 func_0203B1D8(void)
{
    struct NetState_0203B018 *s = g_021469DC;

    if (s == 0)
        return 1;
    if (s->f08 != 0)
        s->f08(s);
    if (g_021469DC == 0)
        return 1;
    func_0203C934();
    return 0;
}





void func_0203B224(void)
{
}





void func_0203B228(void)
{
}




int func_0203B22C(void)
{
    func_0203AD80(g_021469DC, func_0203B224, 0, 0x1f4);
    return 1;
}




/*
 * Starts a 0x200-entry transfer over channel 1 and reports through
 * func_0203AD80 at line 517 when the start call answers zero.  The line comes
 * out as `add r3, r4, #5` because r4 already holds the 0x200 argument, the
 * same constant-rematerialisation the consecutive-`__LINE__` idiom records.
 *
 * Both callback addresses (0x0203B22C and 0x0203B228, the two `bx lr` filler
 * words in the pool of func_0203B1D8) are declared as symbols: written as
 * plain integer literals this compiler folds the pair into one pool word plus
 * a `sub r1, r4, #4`, which is four bytes short of the original's two pool
 * words.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B258.c \
 *       --func func_0203B258 --addr 0x0203B258 --cc 1.1p1 --arm
 */
void func_0203B258(void)
{
    func_0203D798();
    if (func_02037894(1, 0x200, 1, (int)unk_0203B22C) != 0)
        func_0203AD80(g_021469DC, (void *)unk_0203B228, 0, 0x205);
}



void func_0203B2A8(int a0)
{
    func_0203AD80(g_021469DC, (void *)0x203B228, 0, 0x214);
}




void func_0203B2D0(u32 val)
{
    func_0203AD80(g_021469DC, func_0203B258, 0, 0x222);
}




u32 func_0203B2FC(struct NetState_0203B2FC *p)
{
    u32 hi;
    u64 acc = p->rng.mul * p->rng.x + p->rng.add;
    p->rng.x = acc;
    hi = (u32)(acc >> 32);
    return (u32)(((u64)hi * 40) >> 32) + 0x3c;
}




u32 func_0203B344(struct NetState_0203B2FC *p)
{
    u32 hi;
    u64 acc = p->rng.mul * p->rng.x + p->rng.add;
    p->rng.x = acc;
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
void func_0203B390(struct NetState_0203B2FC *p)
{
    struct Obj *q = (struct Obj *)func_0203D788();
    u32 n = 0x200;

    if (q->f340->f78() == 0)
        return;
    if (p->f53 == 0 || p->f56 == 1)
        goto alt;

    if (func_02037A6C(1, (u32)p->addr, n, (u32)func_0203B01C) == 0)
        return;
    func_0203AD80(g_021469DC, str_0203B950, func_0203B2FC(p), n + 0x45);
    return;

alt:
    if (func_02037928(1, n) == 0)
        return;
    func_0203AD80(g_021469DC, str_0203B950, func_0203B344(p), n + 0x4a);
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
        func_0203AD80(g_021469DC, (void *)0x203B390, 0, (int)0x25D);
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
        func_0203AD80(g_021469DC, (void *)0x203B448, 0, 0x265);
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
        func_0203AD80(g_021469DC, (void *)0x203B390, 0, (int)0x282);
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
void func_0203B52C(struct NetState_0203B2FC *p)
{
    func_0203D798();
    if (func_020393D0() != 0)
        return;
    if (func_020393A8() == 0) {
        func_0203AD80(g_021469DC, (void *)func_0203B4DC, 0, 0x297);
        return;
    }
    if (func_020399EC() == 0)
        return;
    if (func_02039ACC() == 0)
        return;
    if (p->f2C != 0) {
        p->f2C(func_0203D650());
        p->f2C = 0;
    }
    func_0203AD80(g_021469DC, (void *)func_0203C00C, 0, 0x2a6);
}
