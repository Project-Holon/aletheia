/*
 * function: ICA_ANIME_CreateWithFullBuffer
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
 *   ICA_ANIME_Clear  0x020116C0  thumb
 *   ICA_ANIME_LoadHeader  0x020116E0  thumb
 *   ICA_ANIME_AllocBuffer  0x02011770  thumb
 *   ICA_ANIME_SetBuffer  0x020117D8  thumb
 *   ICA_ANIME_LoadFrames  0x0201183C  thumb
 *   _IcaAnimeFileName  0x020A7270  data
 *

 * ica_anime.c's 0x38-byte-object constructor: allocate, shared init, the
 * class-specific initialiser, then the load call.  Only the load call's
 * result is tested, so the failure path is the plain `return 0` and the
 * success path stores through the sibling and returns the object.  The
 * +0x0c field is re-read after ICA_ANIME_LoadHeader because the callee sets it.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ICA_ANIME_CreateWithFullBuffer.c \
 *       --func ICA_ANIME_CreateWithFullBuffer --addr 0x02011428 --cc 1.1p1 --thumb
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
extern void ICA_ANIME_AllocBuffer(u8 *p, int n);
extern int   ICA_ANIME_SetBuffer(u8 *p, int v1, u8 *v2, int v3);
extern void ICA_ANIME_LoadFrames(struct IcaAnime *s, s32 q);
extern u8    _IcaAnimeFileName;


void *ICA_ANIME_CreateWithFullBuffer(u32 heap, u32 a1, u32 a2, u32 a3, u32 a4)
{
    struct IcaAnime *p = func_02030734(heap, 0x38, 0, (const char *)&_IcaAnimeFileName, 0x54);

    ICA_ANIME_Clear(p);
    ICA_ANIME_LoadHeader((u8 *)p, a1, a2, heap);
    if (ICA_ANIME_SetBuffer((u8 *)p, p->f0c, (u8 *)a3, a4) == 0) {
        return 0;
    }
    ICA_ANIME_LoadFrames(p, 0);
    return p;
}
