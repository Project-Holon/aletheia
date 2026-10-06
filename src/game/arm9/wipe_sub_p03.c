/*
 * file:     wipe_sub_p03.c
 * unit:     yes
 * function: func_02022004, func_02022040, func_0202208C
 * address:  0x02022004
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
 */
struct Screen;
struct Slots;
struct Mode;
struct TextObj;
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

extern void func_02021FD8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
extern u32   CARD_GetBackupSectorSize(void);
extern void func_020226A0(u8 *p);
extern void func_020223C0(u32 mode, struct Mode *p);
extern void func_02022458(struct Slots *p);
extern u32 func_020225F4(struct TextObj *obj, u32 value);
extern void  func_02022430(void *sub, u32 a, u32 b, s32 c, u32 d, u32 e,
                           u32 f, void *g, void *h, u32 i, void *j);
extern void func_02022390(u32 *obj, void *arg);
extern void func_02022640(struct Screen *s);
void func_02022004(u32 a0, u32 a1, u16 m, u32 a3, u32 a4);
void func_02022040(u16 *pal, int n, const u8 *table);
void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern struct G g_021467A4;


void func_02022004(u32 a0, u32 a1, u16 m, u32 a3, u32 a4)
{
    u32 i = 0;

    if (m == 0) {
        return;
    }
    do {
        if (m & 1) {
            func_02021FD8(a0, a1, (u16)i, 0x10, a3, a4);
        }
        m = (u16)(m >> 1);
        i += 0x10;
    } while (m != 0);
}


void func_02022040(u16 *pal, int n, const u8 *table)
{
    int i;
    int r, g, b;
    u8 v;

    for (i = 0; i < n; i++) {
        r = *pal & 0x1f;
        g = (*pal >> 5) & 0x1f;
        b = (*pal >> 10) & 0x1f;
        v = table[(r * 76 + g * 151 + b * 29) >> 8];
        *pal = (v << 10) | (v << 5) | v;
        pal++;
    }
}


/*
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
void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7)
{
    s32    n;
    struct G *g;
    void  *obj;

    n = (s32)p6;
    n = n / (s32)CARD_GetBackupSectorSize();
    g = &g_021467A4;
    func_020226A0((u8 *)g);
    func_020223C0((u32)p1, (struct Mode *)g);
    func_02022458((struct Slots *)g->f74);
    obj = (void *)func_020225F4((struct TextObj *)g, p4);
    func_02022430(&g->f14, p2, p5, n, 0, 0, 0,
                  g->f8C, g->f74, p7, obj);
    func_02022430(&g->f44, p3, p5, n, 0, 0, 1,
                  g->f8C, g->f74, p7, obj);
    g->f14C = 1;
    func_02022390((u32 *)(&g->f04), &g->f14);
    func_02022390((u32 *)(&g->f08), &g->f44);
    if (g->f0C != 0) {
        func_02022640((struct Screen *)(&g->f14));
        g->f14E = 1;
    }
    if (g->f10 != 0) {
        func_02022640((struct Screen *)(&g->f44));
        g->f14F = 1;
    }
}
