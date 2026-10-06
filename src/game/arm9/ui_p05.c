/*
 * file:     ui_p05.c
 * unit:     yes
 * function: func_02035138, func_0203515C, func_0203516C, func_02035188, func_020351A0, func_020351BC, func_020351D0, func_020351EC, func_020351F8, func_0203521C, func_02035224
 * address:  0x02035138
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
 *   g_021469BC    0x021469BC  data
 *   func_0203512C 0x0203512C  arm
 *   func_0203515C 0x0203515C arm
 *   d_021469BC   0x021469BC  data  a4
 *   func_02035188 0x02035188  arm
 *   func_020351BC 0x020351BC arm
 *   sub_020351EC  0x020351EC  arm
 *   unk_021469BC  0x021469BC  data
 *   OS_Terminate  0x02088234  arm
 */
struct Obj02035120;
struct Obj0203515C;
struct Obj020351EC;
struct UiCtx;
typedef unsigned int u32;

typedef unsigned char u8;

struct Obj0203515C {
    unsigned char pad[0x39];
    u8 unk39;
};

struct Obj020351EC {
    unsigned char pad[8];
    u32 unk08;
    u32 unk0C;
};

extern void func_0203512C(struct Obj02035120 *p, u32 a, u32 b);
extern void func_0203515C(struct Obj0203515C *p, u8 mask);
extern int func_02035188(void *p, u32 v);
extern u32 func_020351BC(struct Obj0203515C *p, u32 mask);
int func_020351A0(u32 v);
asm void func_020351D0(void);
asm void func_0203516C(void);
extern void sub_020351EC(struct Obj020351EC *p, u32 a, u32 b);
extern void OS_Terminate(void);
void sub_020351F8(u32 a, u32 b);
u32 sub_0203521C(u32 *p);
struct UiCtx *sub_02035224(void);
void func_02035138(void *fn, u32 arg);
extern void *g_021469BC;
extern u32 d_021469BC[];
extern struct UiCtx *unk_021469BC;




/*
 * Tail call: func_0203512C(*g_021469BC, fn, arg).  Called from func_02012248
 * and func_02012258.
 */
void func_02035138(void *fn, u32 arg)
{
    func_0203512C(g_021469BC, (u32)fn, arg);
}




/*
 * The set half of a set/clear pair on the flag byte at +0x39, right after
 * the two tail-call veneers in the same block; no lr push, so disasm.py
 * never labels it. Twin of sub_02035188 (clear).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0203515C.c \
 *       --func sub_0203515C --addr 0x0203515C --cc 1.1p1 --arm
 */
void sub_0203515C(struct Obj0203515C *p, u8 mask)
{
    p->unk39 |= mask;
}



asm void func_0203516C(void)
{
    ldr r2, =g_021469BC
    mov	r1, r0
    ldr	r0, [r2]
    ldr ip, =func_0203515C
    bx	ip
}



/*
 * The clear half of the set/clear pair on the flag byte at +0x39. No lr
 * push, so disasm.py never labels it. Twin of sub_0203515C (set).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02035188.c \
 *       --func sub_02035188 --addr 0x02035188 --cc 1.1p1 --arm
 */
void sub_02035188(struct Obj0203515C *p, u8 mask)
{
    p->unk39 &= ~mask;
}


int func_020351A0(u32 v)
{
    return func_02035188((void *)d_021469BC[0], v);
}


/*
 * The test half of the set/clear/test trio on the flag byte at +0x39.
 * No lr push, so disasm.py never labels it.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_020351BC.c \
 *       --func sub_020351BC --addr 0x020351BC --cc 1.1p1 --arm
 */
u32 sub_020351BC(struct Obj0203515C *p, u32 mask)
{
    return (p->unk39 & mask) != 0;
}


asm void func_020351D0(void)
{
    ldr r2, =g_021469BC
    mov	r1, r0
    ldr	r0, [r2]
    ldr ip, =func_020351BC
    bx	ip
}



/*
 * A plain two-field setter, same shape as sub_02035080/sub_02035120: "str
 * r1,[r0,#8]; str r2,[r0,#0xc]; bx lr", twelve bytes, no relocations. No lr
 * push, so disasm.py never labels it.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_020351EC.c \
 *       --func sub_020351EC --addr 0x020351EC --cc 1.1p1 --arm
 */
void sub_020351EC(struct Obj020351EC *p, u32 a, u32 b)
{
    p->unk08 = a;
    p->unk0C = b;
}


/*
 * Forwards both arguments to the setter sub_020351EC on the object held in
 * g_021469BC (a tail call through ip).  No lr push, so disasm.py never
 * labels it; filed so its ov088/ov172 callers can resolve the BLX.
 */
void sub_020351F8(u32 a, u32 b)
{
    sub_020351EC(g_021469BC, a, b);
}


/*
 * A trivial pointer-dereference getter: "ldr r0,[r0]; bx lr", eight bytes,
 * no relocations. No lr push, so disasm.py never labels it.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0203521C.c \
 *       --func sub_0203521C --addr 0x0203521C --cc 1.1p1 --arm
 */
u32 sub_0203521C(u32 *p)
{
    return *p;
}


/*
 * The singleton accessor for the UI context sub_02034E24 publishes: stop the
 * machine if it has not been constructed yet, otherwise hand it back.  The
 * pointer is loaded twice off the one pool word because OS_Terminate is an
 * ordinary extern as far as the compiler is concerned, so the global has to
 * be re-read after the call.
 *
 * This is the most-called function in the 0x02035000 block: a hundred-odd
 * branches reach it image-wide.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02035224.c \
 *       --func sub_02035224 --addr 0x02035224 --cc 1.1p1 --arm
 */
struct UiCtx *sub_02035224(void)
{
    if (unk_021469BC == 0) {
        OS_Terminate();
    }
    return unk_021469BC;
}
