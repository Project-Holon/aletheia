/*
 * function: func_02011510
 * address:  0x02011510
 * packet:   pkt_02011510
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

 * ica_anime.c, the third constructor of the group: same prologue, same
 * 0x38-byte allocation (a different source line), but the class
 * initialiser is func_02011770 and the result is not tested - it always
 * runs the shared teardown initialiser and returns the object.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02011510.c \
 *       --func func_02011510 --addr 0x02011510 --cc 1.1p1 --thumb
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
extern void  func_020116E0(u8 *p, u32 a, u32 b, u32 c);
extern void  func_02011770(u8 *p, int n);
extern int func_020117D8(u8 *a0, int a1, u8 *a2, int a3);
extern void func_0201183C(struct IcaAnime *s, s32 q);
extern u8    sIcaAnimeFile;


void *func_02011510(u32 heap, u32 a1, u32 a2, u32 a3)
{
    struct IcaAnime *p = func_02030734(heap, 0x38, 0, (const char *)&sIcaAnimeFile, 0xae);

    func_020116C0(p);
    func_020116E0((u8 *)p, a1, a2, heap);
    func_02011770((u8 *)p, a3);
    func_0201183C(p, 0);
    return p;
}
