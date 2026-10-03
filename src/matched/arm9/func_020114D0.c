/*
 * function: func_020114D0
 * address:  0x020114D0
 * packet:   pkt_020113F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sIcaAnimeFile     0x020A7270  data
 *   func_02030734     0x02030734  arm
 *   func_020116C0     0x020116C0  thumb
 *   func_020116E0     0x020116E0  thumb
 *   func_02011770     0x02011770  thumb
 *   func_0201183C     0x0201183C  thumb
 *
 * ica_anime.c: the third constructor (line 0x90 of "ica_anime.c").  The
 * object is 0x38 bytes and the four-argument initialiser gets the heap back
 * as its last argument, which is where r3 = r5 comes from.  func_020116C0 gets
 * the object straight from the allocator, which is why no move precedes it.
 *
 * The tail is the pair every one of these constructors ends with -
 * func_02011770(p, p->f0c) and func_0201183C(p, 0).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020114D0.c \
 *       --func func_020114D0 --addr 0x020114D0 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef signed int     s32;
typedef unsigned int   u32;

struct IcaAnime {
    u8  pad00[0x0C];
    u32 f0c;        /* +0x0C */
    s32 f10;        /* +0x10 */
    s32 f14;        /* +0x14 */
    s32 f18;        /* +0x18 */
    s32 f1c;        /* +0x1C */
    s32 f20;        /* +0x20 */
    s32 f24;        /* +0x24 */
    s32 f28;        /* +0x28 */
    s32 f2c;        /* +0x2C */
    s32 f30;        /* +0x30 */
    s32 f34;        /* +0x34 */
};

extern u8 sIcaAnimeFile;

extern void *func_02030734(u32 heap, u32 size, int clear, const char *file, unsigned short line);
extern void   func_020116C0(struct IcaAnime *p);
extern void   func_020116E0(struct IcaAnime *p, u32 a1, u32 a2, u32 heap);
extern void   func_02011770(struct IcaAnime *p, u32 v);
extern void   func_0201183C(struct IcaAnime *p, s32 v);

void *func_020114D0(u32 heap, u32 a1, u32 a2)
{
    struct IcaAnime *p;

    p = func_02030734(heap, 0x38, 0, (const char *)&sIcaAnimeFile, 0x90);
    func_020116C0(p);
    func_020116E0(p, a1, a2, heap);
    func_02011770(p, p->f0c);
    func_0201183C(p, 0);
    return p;
}
