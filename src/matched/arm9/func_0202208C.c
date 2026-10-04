/*
 * unit:     no
 * address:  0x0202208C
 * packet:   pkt_02021444
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0202208C
 *
 * symbols:
 *   g_021467A4                0x021467A4  data
 *   CARD_GetBackupSectorSize  0x0204E6E0  arm
 *   _s32_div_f                0x0209C0A4  arm
 *   func_020226A0             0x020226A0  thumb
 *   func_020223C0             0x020223C0  thumb
 *   func_02022458             0x02022458  thumb
 *   func_020225F4             0x020225F4  thumb
 *   func_02022430             0x02022430  thumb
 *   func_02022390             0x02022390  thumb
 *   func_02022640             0x02022640  thumb
 *
 * The setup entry point of the dual-screen window/text cluster whose object
 * lives at 0x021467A4, the same fixed object func_020226A0 zero-fills in five
 * sub-ranges (0x00/0x14, 0x14/0x30, 0x44/0x30, 0x74/0x18, 0x8C/0xC0) and the
 * one func_0202223C/func_02022268 read the sentinel colour out of at +0x150.
 * It divides its sixth argument by CARD_GetBackupSectorSize(), clears the
 * object, runs two configuration calls, then builds the two screens with the
 * same eleven-argument builder func_02022430: sub-object +0x14 with the
 * second argument and mode 0, sub-object +0x44 with the third argument and
 * mode 1, both sharing the buffers at +0x8C and +0x74 and the object the
 * fifth call returned.  It then publishes the two sub-objects through the
 * slots at +0x04 and +0x08, and for each of the two delegate pointers at
 * +0x0C and +0x10 that is non-null it runs func_02022640 on the matching
 * sub-object and sets the byte flag at +0x14E / +0x14F.
 *
 * Graduated in wave 20B.  It was parked at MATCH only because five of its
 * callees had no branch reference anywhere in the image except the ones in
 * this function, so the `label` class had no witness outside the compared
 * range.  All five are now EXACT manifest entries in pkt_02022174
 * (func_020223C0, func_02022458, func_020225F4, func_02022430,
 * func_02022640), and every one of those sites resolves on the `matched`
 * class.  g_021467A4 resolves on `literal`, CARD_GetBackupSectorSize,
 * _s32_div_f, func_020226A0 and func_02022390 on `label`.
 *
 * Near miss worth keeping: the division had to be written as a self-recompute,
 *   n = (s32)p6;  n = n / (s32)CARD_GetBackupSectorSize();
 * The single-expression form `(s32)p6 / (s32)CARD_GetBackupSectorSize()`
 * compiles the call first and then rematerialises p6 out of its incoming
 * stack slot into r0, two bytes shorter and a whole-function shift; the
 * original loads p6 into a callee-saved register in the prologue shuffle and
 * only then calls.  See
 * docs/idioms/a-self-recompute-pins-an-operand-before-the-other-side-calls.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202208C.c  *       --func func_0202208C --addr 0x0202208C --cc 1.1p1 --thumb
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Sub {
    u8 pad[0x30];
};

struct G {
    u8          pad00[4];
    void       *f04;
    void       *f08;
    void       *f0C;
    void       *f10;
    struct Sub  f14;
    struct Sub  f44;
    u8          f74[0x18];
    u8          f8C[0xC0];
    u16         f14C;
    u8          f14E;
    u8          f14F;
};

extern struct G g_021467A4;

extern u32   CARD_GetBackupSectorSize(void);
extern void  func_020226A0(struct G *p);
struct Mode;
struct TextObj;
extern void func_020223C0(u32 mode, struct Mode *p);
extern void  func_02022458(void *p);
extern u32 func_020225F4(struct TextObj *obj, u32 value);
extern void  func_02022430(void *sub, u32 a, u32 b, s32 c, u32 d, u32 e,
                           u32 f, void *g, void *h, u32 i, void *j);
extern void  func_02022390(void **slot, struct Sub *s);
extern void  func_02022640(struct Sub *s);

void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7)
{
    s32    n;
    struct G *g;
    void  *obj;

    n = (s32)p6;
    n = n / (s32)CARD_GetBackupSectorSize();
    g = &g_021467A4;
    func_020226A0(g);
    func_020223C0((u32)p1, (struct Mode *)g);
    func_02022458(g->f74);
    obj = (void *)func_020225F4((struct TextObj *)g, p4);
    func_02022430(&g->f14, p2, p5, n, 0, 0, 0,
                  g->f8C, g->f74, p7, obj);
    func_02022430(&g->f44, p3, p5, n, 0, 0, 1,
                  g->f8C, g->f74, p7, obj);
    g->f14C = 1;
    func_02022390(&g->f04, &g->f14);
    func_02022390(&g->f08, &g->f44);
    if (g->f0C != 0) {
        func_02022640(&g->f14);
        g->f14E = 1;
    }
    if (g->f10 != 0) {
        func_02022640(&g->f44);
        g->f14F = 1;
    }
}
