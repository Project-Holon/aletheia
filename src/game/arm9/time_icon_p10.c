/*
 * file:     time_icon_p10.c
 * unit:     yes
 * function: func_0202F738, func_0202F768, func_0202F774, func_0202F788, func_0202F7C4, func_0202F870
 * address:  0x0202F738
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02017E88  0x02017E88  thumb
 *   func_020212E4  0x020212E4  thumb
 *   func_02007084  0x02007084  thumb
 *   func_0203CD98  0x0203CD98  arm
 *   func_0203CF04  0x0203CF04  arm
 *   func_0203CEAC  0x0203CEAC  arm
 *   func_0203D0D0  0x0203D0D0  arm
 *   func_0203CF5C  0x0203CF5C  arm
 *   func_0203CDBC  0x0203CDBC  arm
 *   func_020351A0  0x020351A0  arm
 *   func_020053EC  0x020053EC  thumb
 *   func_0207D534    0x0207D534  arm
 *   func_0207D3AC    0x0207D3AC  arm
 *   func_0207D3E4    0x0207D3E4  arm
 *   func_020808F4    0x020808F4  arm
 *   func_020809A0    0x020809A0  arm
 *   func_0207FDCC    0x0207FDCC  arm
 *   func_0207D4B0    0x0207D4B0  arm
 *   func_0202F940    0x0202F940  thumb
 *   func_0207E24C    0x0207E24C  arm
 *   func_02082A7C    0x02082A7C  arm
 *   func_0204A1BC    0x0204A1BC  arm
 *   func_02062A4C    0x02062A4C  arm
 *   func_020862F0    0x020862F0  arm
 *   func_02082A60    0x02082A60  arm
 *   func_020307B0    0x020307B0  arm
 *   func_02062B30    0x02062B30  arm
 *   func_0207DFB4    0x0207DFB4  arm
 *   func_02062AD4    0x02062AD4  arm
 *   func_02062A98    0x02062A98  arm
 */
struct NitroFileHeader;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef signed int     s32;

extern u32 func_02017E88(void *p, u32 id, u32 v);
extern u32 func_020212E4(u16 v);
extern void func_02007084(void);
extern int  func_0203CD98(void);
extern void func_0203CF04(void);
extern int func_0203CEAC(int a0);
extern void func_0203D0D0(void);
extern u32 func_0203CF5C(void);
extern int  func_0203CDBC(void);
extern int func_020351A0(u32 v);
extern void func_020053EC(void);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern long func_0207D3AC(int enable);
extern long func_0207D3E4(int enable);
extern int func_020808F4(void);
extern int func_020809A0(void);
extern void func_0207FDCC(u32 a);
extern void func_0207D4B0(int dispMode, int bgMode, int bg0_2d3d);
extern void func_0202F940(u32 a);
extern void *func_0207E24C(void);
extern void func_02082A7C(u32 a, u32 b, u32 c);
extern int func_0204A1BC(int a0, int a1, int a2, int a3);
extern s32 func_02062A4C(struct NitroFileHeader *file, void **out);
extern void func_020862F0(u32 a, u32 b);
extern void func_02082A60(u32 a, u32 b, u32 c);
extern u32 func_020307B0(void *p);
extern int func_02062B30(void *file, void **out);
extern void *func_0207DFB4(void);
extern s32 func_02062AD4(struct NitroFileHeader *file, void **out);
extern s32 func_02062A98(struct NitroFileHeader *file, void **out);
int func_0202F738(void *p, int a1);
void func_0202F768(void);
void func_0202F774(u32 on);
void func_0202F788(u32 mode);
void func_0202F7C4(u32 a0);
void func_0202F870(void);



int func_0202F738(void *p, int a1)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (func_020212E4((u16)func_02017E88(p, i + 0x36, 0)) != 0) {
            return 0;
        }
    }
    return 1;
}




/*
 * time_icon.c.  An unlabelled tail-call leaf (it saves nothing, so
 * disasm.py prints it as .word data): func_0202F788(0).  With
 * func_0202F774 it is the callback pair sub_0200545C (gfl_use.c boot)
 * hands to func_020316C8(7, ...).  Filed apart from func_0202F774 on
 * purpose: the only pool words naming 0x0202F789 that are outside a
 * two-function range are each other's, so as one unit neither site has a
 * witness (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md).
 * Seed 0x0202F768 in layout/function_starts.txt.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F768.c \
 *       --func func_0202F768 --addr 0x0202F768 --cc 1.1p1 --thumb
 */
void func_0202F768(void)
{
    func_0202F788(0);
}




/*
 * time_icon.c.  The second unlabelled tail-call leaf of the callback pair
 * sub_0200545C hands to func_020316C8: a flag mapped to mode 2 (clear) or
 * 1 (set) for func_0202F788.  Filed apart from func_0202F768 so each pool
 * word witnesses the other (see that file).  Seed 0x0202F774.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F774.c \
 *       --func func_0202F774 --addr 0x0202F774 --cc 1.1p1 --thumb
 */
void func_0202F774(u32 on)
{
    u32 mode;

    if (on == 0) {
        mode = 2;
    } else {
        mode = 1;
    }
    func_0202F788(mode);
}




/*
 * time_icon.c: the power callback reached from func_0202F768 as
 * func_0202F788(0) (and registered through the pool word 0x0202F789 at
 * 0x0202F784).  disasm.py carried it as .word data until it was seeded in
 * layout/function_starts.txt.  It never returns: after the shutdown work it
 * spins on func_020053EC.
 */
void func_0202F788(u32 mode)
{
    func_02007084();
    func_0202F7C4(mode);
    if (func_0203CD98()) {
        func_0203CF04();
        func_0203CEAC(0);
        func_0203D0D0();
        do {
            func_0203CF5C();
        } while (!func_0203CDBC());
    }
    func_020351A0(2);
    for (;;)
        func_020053EC();
}



#define REG32(a) (*(volatile u32 *)(a))


#define REG16(a) (*(volatile u16 *)(a))



/*
 * The two calls to this packet's own followers (0x0202F870 at +0x7A and
 * 0x0202F940 at +0x80) are the only sites that need the `matched` class:
 * their compared range was their only `label` witness until those two files
 * existed, and they resolve the moment this shard carries them
 * (`manifest --verify --shard pkt_0202F7C4`, then re-run `one`).  Everything
 * else is `label`.
 *
 * A display/VCOUNT init: two func_0207D534 writes of 0xFFFFFFF0 to the
 * 0x0400006C and 0x0400106C registers, the engine setup calls, then three
 * read-modify-write pairs on the hardware registers at 0x04000000 (clear bits
 * 8-12, set bit 9; then clear 0xE000), 0x0400000A (clear all but 0x43, set 2),
 * 0x04000014 and 0x04000050 (both zeroed), the two packet-local sub-inits, and
 * the two registers released again.
 *
 * Note the compiler derives 0x0400000A and 0x04000014 from the pooled
 * 0x0400006C with `subs r0, #0x62` / `#0x58`, and reuses the value 4 in r6 as
 * `lsls r0, r6, #0x18` for the 0x04000000 base; both fall out of writing the
 * plain literals, so no symbol for the registers is needed.
 */
void func_0202F7C4(u32 a0)
{
    func_0207D534((volatile u16 *)0x0400006C, 0xFFFFFFF0);
    func_0207D534((volatile u16 *)0x0400106C, 0xFFFFFFF0);
    func_0207D3AC(0);
    func_0207D3E4(0);
    func_020808F4();
    func_020809A0();
    func_0207FDCC(4);
    func_0207D4B0(1, 0, 0);
    REG32(0x04000000) = (REG32(0x04000000) & 0xFFFFE0FF) | 0x200;
    REG32(0x04000000) = REG32(0x04000000) & 0xFFFF1FFF;
    REG16(0x0400000A) = (REG16(0x0400000A) & 0x43) | 4;
    REG16(0x0400000A) = REG16(0x0400000A) & 0xFFBF;
    REG32(0x04000014) = 0;
    REG16(0x04000050) = 0;
    func_0202F870();
    func_0202F940(a0);
    func_0207D534((volatile u16 *)0x0400006C, 0);
    func_0207D534((volatile u16 *)0x0400106C, 0x10);
}



/*
 * Three copies of one block: register a handle with func_0204A1BC(0x16, i, 0, 7),
 * probe it (func_02062A4C / 02062B30 / 02062A98 with a stack out-pointer), and
 * on success clear 0x20 bytes of the record's buffer through func_020862F0 and
 * fill it back through func_02082A60 with the current frame-tick from the
 * getter (func_0207E24C / func_0207DFB4).  The handle is released with
 * func_020307B0 after each block.
 *
 * The idiom that makes this EXACT: the word each block reads twice (p[4],
 * p[2]) is written as an ASSIGNMENT INSIDE the third argument of the second
 * call -- `func_02082A60(p[5], getter(), v1 = p[4])`.  mwcc evaluates the
 * arguments of a call right-to-left, so the assignment's load lands before
 * the getter call, and the value it produces is live across that call, which
 * is what puts it in r5 and forces the original's
 * `push {r3, r4, r5, lr}` frame.  Spelling the same value as a statement
 * before the call puts the load one statement early; spelling it inline in
 * both calls leaves the load where it is scheduled and loses r5 (6 bytes
 * short).  See docs/idioms/
 * an-assignment-inside-a-call-argument-pins-the-load-in-a-callee-saved-register.md
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F870.c \
 *       --func func_0202F870 --addr 0x0202F870 --cc 1.1p1 --thumb
 *   -> EXACT, 208 bytes, 20/20 relocation sites resolved (all `label`)
 */
void func_0202F870(void)
{
    u32 *p1;
    u32 *p2;
    u32 *p3;
    u32 *p4;
    u32 h;
    u32 v1;
    u32 v2;

    func_02082A7C(0, (u32)func_0207E24C(), 0x4000);
    h = func_0204A1BC(0x16, 1, 0, 7);
    if (func_02062A4C((struct NitroFileHeader *)h, (void **)(&p1)) != 0) {
        func_020862F0(p1[5], p1[4]);
        func_02082A60(p1[5], (u32)func_0207E24C(), v1 = p1[4]);
    }
    func_020307B0((void *)h);
    h = func_0204A1BC(0x16, 2, 0, 7);
    if (func_02062B30((void *)h, (void **)(&p2)) != 0) {
        func_020862F0((u32)p2 + 0xc, p2[2]);
        func_02082A60((u32)p2 + 0xc, (u32)func_0207DFB4(), v2 = p2[2]);
    }
    func_020307B0((void *)h);
    h = func_0204A1BC(0x16, 0, 0, 7);
    func_02062AD4((struct NitroFileHeader *)h, (void **)(&p4));
    if (func_02062A98((struct NitroFileHeader *)h, (void **)(&p3)) != 0) {
        func_020862F0(p3[3], 0x20);
        func_02082A60(p3[3], 0x05000000, 0x20);
    }
    func_020307B0((void *)h);
}
