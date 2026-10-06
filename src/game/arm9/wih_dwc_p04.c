/*
 * file:     wih_dwc_p04.c
 * unit:     yes
 * function: func_02010794, func_020107CC
 * address:  0x02010794
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
 *   g_021461E0        0x021461E0  data
 *   sWihDwc           0x020A7240  data
 *   sWihDwcFile       0x020A7244  data
 *   func_02034714     0x02034714  arm
 *   func_0203D7C8     0x0203D7C8  arm
 *   func_0205FAA8     0x0205FAA8  arm
 */
typedef unsigned char u8;

typedef unsigned int  u32;

struct WihCtx {
    u8 *f0;         /* +0x00 */
    u8 *f4;         /* +0x04 */
};

extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_0203D7C8(u32 heap, u32 a, const char *file, unsigned short line);
extern void func_0205FAA8(u8 *p, u32 v);
void func_02010794(u32 heap);
void func_020107CC(void);
extern struct WihCtx g_021461E0;
extern u8 sWihDwc;
extern u8 sWihDwcFile[];


/*
 * wih_dwc.c: (re)build the second field of the object at 0x021461E0.  The
 * guard is the same file-name call the rest of this file makes - here the
 * polarity is inverted, so it fires when the pointer is ALREADY set (a
 * re-initialisation warning rather than an uninitialised one).
 *
 * The tail calls func_0203D7C8(heap, 0xA00, "wih_dwc.c", 0x1C0), which is the
 * debug/allocator shape this SDK uses: a heap ID, a size, a __FILE__
 * string and a line number.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010794.c \
 *       --func func_02010794 --addr 0x02010794 --cc 1.1p1 --thumb
 */
void func_02010794(u32 heap)
{
    if (g_021461E0.f4 != 0) {
        func_02034714((const char *)(&sWihDwc), 0, (const char *)(&sWihDwc));
    }
    g_021461E0.f4 = func_0203D7C8(heap, 0xA00, (const char *)sWihDwcFile, 0x1C0);
}


/*
 * wih_dwc.c: the sibling of func_02010794 in the same packet - same guard on
 * the +0x04 field of the object at 0x021461E0, same file-name call, and the
 * field is re-read afterwards (a second pool load), so the callee is allowed
 * to have set it.  The tail is func_0205FAA8(f4 + 0x600, 0).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020107CC.c \
 *       --func func_020107CC --addr 0x020107CC --cc 1.1p1 --thumb
 *
 *           and no branch anywhere else in the image reaches that address -
 *           this function is its only caller - so the site has no witness
 *           outside the compared range and no cut can give it one (shrinking
 *           the range to this one function keeps the call inside it).  The
 *           target is not in an EXACT manifest entry either, so the `matched`
 *           class does not reach it.  Byte-correct as it stands.
 */
void func_020107CC(void)
{
    if (g_021461E0.f4 == 0) {
        func_02034714((const char *)(&sWihDwc), 0, (const char *)(&sWihDwc));
    }
    func_0205FAA8(g_021461E0.f4 + 0x600, 0);
}
