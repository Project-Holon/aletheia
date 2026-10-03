/*
 * function: func_0202F870
 * address:  0x0202F870
 * packet:   pkt_0202F7C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
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
 *
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

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32  func_0207E24C(void);
extern void func_02082A7C(u32 a, u32 b, u32 c);
extern int func_0204A1BC(int a0, int a1, int a2, int a3);
extern int  func_02062A4C(u32 h, u32 **out);
extern void func_020862F0(u32 a, u32 b);
extern void func_02082A60(u32 a, u32 b, u32 c);
extern void func_020307B0(u32 a);
extern int  func_02062B30(u32 h, u32 **out);
extern u32  func_0207DFB4(void);
extern int  func_02062AD4(u32 h, u32 **out);
extern int  func_02062A98(u32 h, u32 **out);

void func_0202F870(void)
{
    u32 *p1;
    u32 *p2;
    u32 *p3;
    u32 *p4;
    u32 h;
    u32 v1;
    u32 v2;

    func_02082A7C(0, func_0207E24C(), 0x4000);
    h = func_0204A1BC(0x16, 1, 0, 7);
    if (func_02062A4C(h, &p1) != 0) {
        func_020862F0(p1[5], p1[4]);
        func_02082A60(p1[5], func_0207E24C(), v1 = p1[4]);
    }
    func_020307B0(h);
    h = func_0204A1BC(0x16, 2, 0, 7);
    if (func_02062B30(h, &p2) != 0) {
        func_020862F0((u32)p2 + 0xc, p2[2]);
        func_02082A60((u32)p2 + 0xc, func_0207DFB4(), v2 = p2[2]);
    }
    func_020307B0(h);
    h = func_0204A1BC(0x16, 0, 0, 7);
    func_02062AD4(h, &p4);
    if (func_02062A98(h, &p3) != 0) {
        func_020862F0(p3[3], 0x20);
        func_02082A60(p3[3], 0x05000000, 0x20);
    }
    func_020307B0(h);
}
