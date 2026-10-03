/*
 * unit:     yes
 * address:  0x0201CA2C
 * packet:   pkt_0201C8BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0201CA2C
 *
 * symbols:
 *   g_02146558   0x02146558  data
 *
 * One of the two printsys.c glyph blitters, both of which forward the caller's
 * pen record to func_0201DB04 and then hand the result to a renderer reached
 * through the module object at 0x02146558.  The pair is cut here rather than
 * matched as one range because func_0201DB04 is reached from exactly two places
 * in the image, 0x0201CA4C and 0x0201CA98, one in each function: matched
 * together neither site has a witness, matched apart each is the other's `label`
 * witness.  That is
 * docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md.
 *
 * Its sibling at 0x0201CA78 stays parked (src/pending/sub_0201CA78.c): it calls
 * 0x02043AAC, and 0x0201CABC is the only branch to that address anywhere in the
 * image, so no cut reaches it.
 *
 * f is a four-byte pen record: f[0] is an x bias added to the caller's x, f[1]
 * and f[3] are passed straight through.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201CA2C.c \
 *       --addr 0x0201CA2C --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void *g_02146558;

struct Bmp;
extern void *func_020437D4(const struct Bmp *bmp);
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern void  func_0201DB04(u32 a, u16 b, void *c, const u8 *d);

void sub_0201CA2C(void *a, s32 b, u32 c, u32 d, u16 e, const u8 *f)
{
    func_0201DB04(d, e, func_020437D4(g_02146558), f);
    func_020439A0(g_02146558, a, 0, 0, b + f[0], c, f[1], f[3], 0);
}

