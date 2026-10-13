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
 *   ICA_ANIME_Clear  0x020116C0  thumb
 *   ICA_ANIME_LoadHeader  0x020116E0  thumb
 *   ICA_ANIME_AllocBuffer  0x02011770  thumb
 *   ICA_ANIME_SetBuffer  0x020117D8  thumb
 *   ICA_ANIME_LoadFrames  0x0201183C  thumb
 *   _IcaAnimeFileName  0x020A7270  data
 *

 * ica_anime.c, the third constructor of the group: same prologue, same
 * 0x38-byte allocation (a different source line), but the class
 * initialiser is ICA_ANIME_AllocBuffer and the result is not tested - it always
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
extern void  ICA_ANIME_Clear(struct IcaAnime *p);
extern void  ICA_ANIME_LoadHeader(u8 *p, u32 a, u32 b, u32 c);
extern void  ICA_ANIME_AllocBuffer(u8 *p, int n);
extern int ICA_ANIME_SetBuffer(u8 *a0, int a1, u8 *a2, int a3);
extern void ICA_ANIME_LoadFrames(struct IcaAnime *s, s32 q);
extern u8    _IcaAnimeFileName;


void *func_02011510(u32 heap, u32 a1, u32 a2, u32 a3)
{
    struct IcaAnime *p = func_02030734(heap, 0x38, 0, (const char *)&_IcaAnimeFileName, 0xae);

    ICA_ANIME_Clear(p);
    ICA_ANIME_LoadHeader((u8 *)p, a1, a2, heap);
    ICA_ANIME_AllocBuffer((u8 *)p, a3);
    ICA_ANIME_LoadFrames(p, 0);
    return p;
}
