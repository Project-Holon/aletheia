/*
 * function: func_02011428
 * address:  0x02011428
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

 * ica_anime.c's 0x38-byte-object constructor: allocate, shared init, the
 * class-specific initialiser, then the load call.  Only the load call's
 * result is tested, so the failure path is the plain `return 0` and the
 * success path stores through the sibling and returns the object.  The
 * +0x0c field is re-read after func_020116E0 because the callee sets it.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02011428.c \
 *       --func func_02011428 --addr 0x02011428 --cc 1.1p1 --thumb
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

extern void *func_02030734(u32 heap, u32 size, u32 flags, const char *file,
                           u32 line);
extern void  func_020116C0(struct IcaAnime *p);
extern void  func_020116E0(struct IcaAnime *p, u32 a, u32 b, u32 c);
extern u32   func_02011770(struct IcaAnime *p, u32 v);
extern u32   func_020117D8(struct IcaAnime *p, u32 v1, u32 v2, u32 v3);
extern void  func_0201183C(struct IcaAnime *p, u32 v);
extern u8    sIcaAnimeFile;


void *func_02011428(u32 heap, u32 a1, u32 a2, u32 a3, u32 a4)
{
    struct IcaAnime *p = func_02030734(heap, 0x38, 0, (const char *)&sIcaAnimeFile, 0x54);

    func_020116C0(p);
    func_020116E0(p, a1, a2, heap);
    if (func_020117D8(p, p->f0c, a3, a4) == 0) {
        return 0;
    }
    func_0201183C(p, 0);
    return p;
}
