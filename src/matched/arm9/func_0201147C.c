/*
 * function: func_0201147C
 * address:  0x0201147C
 * packet:   pkt_02011428
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734   0x02030734  arm
 *   func_020116C0  0x020116C0  thumb
 *   func_020116E0  0x020116E0  thumb
 *   func_02011770  0x02011770  thumb
 *   func_020117D8  0x020117D8  thumb
 *   func_0201183C  0x0201183C  thumb
 *   sIcaAnimeFile  0x020A7270  data
 *

 * The 0x74-byte sibling of func_02011428 in the same original file: same
 * allocation, shared init and class initialiser, but the load call forwards
 * the two stacked arguments rather than a field.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201147C.c \
 *       --func func_0201147C --addr 0x0201147C --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct IcaAnime {
    u8  pad00[0x08];
    u32 f08;            /* +0x08 */
    u32 f0c;            /* +0x0C */
    u32 pad10;
    u32 pad14;
    u32 f18;            /* +0x18 */
    u32 f1c;            /* +0x1C */
};

typedef signed int     s32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  func_020116C0(struct IcaAnime *p);
extern void  func_020116E0(struct IcaAnime *p, u32 a, u32 b, u32 c);
extern void func_02011770(u8 *p, int n);
extern u32   func_020117D8(struct IcaAnime *p, u32 v1, u32 v2, u32 v3);
extern void func_0201183C(struct IcaAnime *s, s32 q);
extern u8    sIcaAnimeFile;


void *func_0201147C(u32 heap, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5)
{
    struct IcaAnime *p = func_02030734(heap, 0x38, 0, (const char *)&sIcaAnimeFile, 0x74);

    func_020116C0(p);
    func_020116E0(p, a1, a2, heap);
    if (func_020117D8(p, a3, a4, a5) == 0) {
        return 0;
    }
    func_0201183C(p, 0);
    return p;
}
