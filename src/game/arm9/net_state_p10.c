/*
 * file:     net_state_p10.c
 * unit:     yes
 * function: func_02037F48, func_0203802C, func_020380E4, func_020381D8, func_02038298, func_02038340
 * address:  0x02037F48
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
 *   lbl_021469D0   0x021469D0  data
 *   d_020A7A20     0x020A7A20  data
 *   func_0203D788  0x0203D788  arm
 *   func_0203D6BC  0x0203D6BC  arm
 *   func_0203D680  0x0203D680  arm
 *   func_02037D98  0x02037D98  arm
 *   func_020387A0  0x020387A0  arm
 *   g_021469D0     0x021469D0  data
 *   func_020366A8  0x020366A8  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_0203D798  0x0203D798  arm
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_02036428  0x02036428  arm
 *   func_02034714  0x02034714  arm
 *   func_02037224  0x02037224  arm
 *   d_020A7A24     0x020A7A24  data
 *   d_020A7A50     0x020A7A50  data
 *   func_02038AE0  0x02038AE0  arm
 *   func_02039338  0x02039338  arm
 *   func_02039160  0x02039160  arm
 *   func_02037E60  0x02037E60  arm
 */
#include "../../matched/include/Obj15934.h"

struct Entry;
struct Conn;
struct Hdr;
typedef unsigned char u8;

typedef unsigned int u32;

typedef signed int s32;

typedef unsigned short u16;

extern void *func_0203D788(void);
extern u32 func_0203D6BC(void);
extern u32 func_0203D680(void);
extern int func_02037D98(int a);
extern int func_020387A0(u32 i, u8 *p, s32 n);
extern int func_020366A8(struct Conn *p);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern struct Entry *func_020399A8(void);
extern void *func_0203D798(void);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern void func_02036428(u8 *p, u8 *q, u32 v);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02037224(u8 v, int b);
extern s32 func_02038AE0(struct Hdr *h, struct Conn *c, s32 len, u8 a3);
extern unsigned short func_02039338(void);
extern int   func_02039160(unsigned int mode);
extern void  func_02037E60(void);
void func_02037F48(void);
void func_0203802C(void);
u32 func_020380E4(u32 a0, u8 *rec, u32 len);
void func_020381D8(u32 a0, u32 a1);
void func_02038298(void);
void func_02038340(void);
extern u8 *lbl_021469D0;
extern u8 d_020A7A20[];
extern u8 *g_021469D0;
extern u8 d_020A7A24[];
extern u8 d_020A7A50[];



/*
 * Declaration order is what closes this one: p must be declared LAST of the
 * four locals so it takes r6 and the loop index takes r4 (see
 * docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 * The failure arm of the +0x5C poll is an out-of-line `goto`, not an
 * if-converted tail; the (u16) truncation of v happens after the n>0 test
 * and the index is zeroed before it.
 */
void func_02037F48(void)
{
    s32 i;
    s32 n;
    u32 v;
    u8 *p;

    p = func_0203D788();

    if (((u32 (*)(void)) * (u32 *)(*(u32 *)(p + 0x340) + 0x58))() == 0)
        return;

    if (*(u8 *)(lbl_021469D0 + 0x1EB) != 0)
        func_02037D98(1);

    if (((u32 (*)(u32)) * (u32 *)(*(u32 *)(p + 0x340) + 0x5C))(*(u32 *)lbl_021469D0) != 1)
        goto fail;

    *(u8 *)(d_020A7A20 + 1) = 4;
    *(u8 *)(lbl_021469D0 + 0x1EB) = 1;

    v = func_0203D6BC();
    n = func_0203D680();
    i = 0;
    if (n > 0) {
        v = (unsigned short)v;
        do {
        func_020387A0((unsigned short)i,
                      (u8 *)(((u32 (*)(u32))
                           * (u32 *)(*(u32 *)(p + 0x340) + 0x60))(i)), v);
            i++;
        } while (i < n);
    }
    return;

fail:
    *(u8 *)(lbl_021469D0 + 0x1EB) = 0;
}



/*
 * Fourth entry of this packet's chain, and the one the lane table expected to
 * need two callees filed: it calls func_020381D8, whose own entry is in this
 * shard, so that site resolves through `matched`; 0x020366A8 and 0x0203D3A8,
 * the other two the table named, turn out to have outside witnesses
 * (0x02038B48 and 0x02039AAC) once the compared range is this one function
 * rather than the whole packet.
 *
 * The two literals in the tail are different objects: the first argument to
 * func_020381D8 is one dereference of the 0x021469D0 pointer word, and the
 * final store is into the byte at 0x020A7A20 + 1.  Reading them as the same
 * symbol makes the compiler pool the address once and spend a second
 * callee-saved register on the transfer value.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203802C.c \
 *       --func func_0203802C --addr 0x0203802C --cc 1.1p1 --arm
 */
void func_0203802C(void)
{
    u8 *p;
    u32 v;

    p = func_0203D788();

    if (func_020366A8((struct Conn *)(g_021469D0 + 0xCC)) != 0)
        func_0203D3A8(func_020399A8(), 0x10, 0, 0);

    v = *(u32 *)(((struct Obj15934 *)p)->f340 + 0x9C);
    if (v != 0)
        ((void (*)(void))v)();
    if (((u32 (*)(void)) * (u32 *)(*(u32 *)(p + 0x340) + 0x6C))() != 1)
        return;

    v = func_0203D6BC();
    if (((u32 (*)(void)) * (u32 *)(*(u32 *)(p + 0x340) + 0xA0))() != 1)
        return;
    if (func_02037D98(0) == 0)
        return;

    func_020381D8(*(u32 *)g_021469D0, v);
    *(u8 *)(d_020A7A20 + 1) = 4;
}



/*
 * Validates one incoming record against the per-slot table reached through
 * 0x021469D0: the byte at +4 of the record is a presence/state tag (0xFF is
 * "locked out", bit 1 is the "no free slot" rejection), then the two-byte
 * header of the body is checked against the result of 0x0203F1FC, then the
 * slot's own counter byte at 0x1D7+slot is compared with rec[5]-1 before
 * being overwritten with rec[5].  Slot `a0` lives at 0x54 + (a0 << 4), so the
 * per-slot block is 16 bytes and the counter table is a byte array.
 *
 * The +8 bit of rec[4] biases the third argument by 0xFF; both the globals are
 * re-read from the pointer word after every call, which is why the C indexes
 * g_021469D0 directly instead of caching it in a local.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020380E4.c \
 *       --func func_020380E4 --addr 0x020380E4 --cc 1.1p1 --arm
 */
u32 func_020380E4(u32 a0, u8 *rec, u32 len)
{
    int v;
    u32 n;

    func_0203D798();
    func_0203D6BC();

    if (rec[4] == 0xFF)
        return 0;
    if (*(u32 *)(g_021469D0 + (a0 << 4) + 0x54) == 0 && (rec[4] & 2))
        return 0;

    v = func_0203F1FC(rec + 2, len - 2);
    if (rec[0] != (u8)v || ((v & 0xFF00) >> 8) != rec[1])
        return 0;
    if (*(u8 *)(g_021469D0 + 0x1D7 + a0) != 0 &&
        (u8)(rec[5] - 1) != *(u8 *)(g_021469D0 + 0x1D7 + a0))
        return 0;

    *(u8 *)(g_021469D0 + 0x1D7 + a0) = rec[5];
    n = rec[2];
    if (rec[4] & 8)
        n += 0xFF;
    func_02036428(g_021469D0 + 0x4C + (a0 << 4), rec + 7, n);
    *(u32 *)(g_021469D0 + (a0 << 4) + 0x54) = 1;
    return 1;
}



/*
 * Second half of this packet's chain: it calls func_020380E4, whose own entry
 * is in this shard, so the call site is attested by `matched` rather than by
 * the single in-range witness the lane table saw.
 *
 * The flow: two global locks are set up, then the interface object reached
 * through *(p + 0x340) is asked twice (its +0xA4 and +0xAC entries); only if
 * both answer non-zero does the transfer run - otherwise the two literals at
 * 0x020A7A24/0x020A7A50 go to 0x02034714 with 0x400.  The transfer calls the
 * object's +0x64 entry with the two arguments and zeroed r2/r3, reads the
 * +0x80 entry for the record number, and hands (u16)record-number, first
 * argument and (u16)second argument to func_020380E4 before the fixed 4 /
 * 0x40C delay through 0x02037224.
 *
 * The guards' polarity is the `bne` / `beq` pair at +0x2C and +0x38: the two
 * object calls are one conjunction whose false arm is the failure block
 * written first, which is the if/else spelling and not a guard chain.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020381D8.c \
 *       --func func_020381D8 --addr 0x020381D8 --cc 1.1p1 --arm
 */
void func_020381D8(u32 a0, u32 a1)
{
    u8 *p;
    u32 v;

    func_0203D798();
    p = func_0203D788();

    if (((u32 (*)(void)) * (u32 *)(*(u32 *)(p + 0x340) + 0xA4))() == 0 ||
        ((u32 (*)(void)) * (u32 *)(*(u32 *)(p + 0x340) + 0xAC))() == 0) {
        func_02034714((const char *)d_020A7A24, 0x400, (const char *)d_020A7A50);
        return;
    }

    if (*(u8 *)(d_020A7A20 + 1) != 0)
        return;
    ((void (*)(u32, u32, u32, u32))
         * (u32 *)(*(u32 *)(p + 0x340) + 0x64))(a0, a1, 0, 0);
    v = ((u32 (*)(void)) * (u32 *)(*(u32 *)(p + 0x340) + 0x80))();
    func_020380E4((u16)v, (u8 *)a0, (u16)a1);
    func_02037224(4, 0x40C);
}



/*
 * Third entry of this packet's chain, and the one that shows why the object
 * word has to be re-read rather than cached: 0x021469D0 is a pointer word and
 * every use of the object it points at goes back through the pool address, so
 * the C indexes g_021469D0 directly each time.
 *
 * The state machine is three bytes of the object (0x1E7 = "armed", 0x1ED =
 * "in flight", 0x1D5 = a mode byte feeding 0x02038AE0): returning early
 * unless armed, arming the in-flight flag once 0x02038AE0 agrees, and only
 * then running the object's +0x64 entry, which clears the flag when it
 * returns non-zero.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02038298.c \
 *       --func func_02038298 --addr 0x02038298 --cc 1.1p1 --arm
 */
void func_02038298(void)
{
    u8 *p;
    u32 v;

    func_0203D798();
    p = func_0203D788();
    v = func_0203D6BC();

    if (*(u8 *)(g_021469D0 + 0x1E7) == 0)
        return;
    if (*(u8 *)(g_021469D0 + 0x1ED) == 0) {
        if (func_02038AE0((struct Hdr *)(*(u32 *)g_021469D0), (struct Conn *)(g_021469D0 + 0xCC),
                          func_0203D6BC(),
                          *(u8 *)(g_021469D0 + 0x1D5)) != 0)
            *(u8 *)(g_021469D0 + 0x1ED) = 1;
    }

    if (*(u8 *)(g_021469D0 + 0x1ED) != 1)
        return;
    if (((u32 (*)(u32, u32, u32, u32))
             * (u32 *)(*(u32 *)(p + 0x340) + 0x64))(*(u32 *)g_021469D0, v,
                                                    0, 0) == 0)
        return;
    *(u8 *)(g_021469D0 + 0x1ED) = 0;
}


/*
 * Promoted from src/pending/ on lane 1.  All 64 concrete bytes are right; the
 * one open site was the PC24 at +0x0038, the `bl` to func_02037E60, which had
 * exactly one branch reference in the whole image (this one) and so no
 * `label` witness.  With src/matched/func_02037E60.c filed EXACT the site
 * resolves through the `matched` class and the file prints EXACT with no
 * change to its C.
 *
 * The reading: refresh the UI object, ask its +0x340 owner's +0x70 virtual
 * whether the session is still up, then let the two teardown probes decide
 * whether func_02037D98(1) and func_02037E60 are reached.  The first
 * func_0203D798() result is discarded - the image overwrites r0 with
 * func_0203D788()'s answer immediately - which is why the call stands on its
 * own statement rather than as an initialiser.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02038340.c \
 *       --func func_02038340 --addr 0x02038340 --cc 1.1p1 --arm
 */
void func_02038340(void)
{
    void *p;

    func_0203D798();
    p = func_0203D788();
    if (((int (*)(void))*(unsigned int *)(*(unsigned int *)((char *)p + 0x340) + 0x70))() == 0)
        return;
    if (func_02039160(func_02039338()) == 0)
        return;
    func_02037D98(1);
    func_02037E60();
}
