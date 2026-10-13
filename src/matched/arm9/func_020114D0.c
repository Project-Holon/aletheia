/*
 * function: ICA_ANIME_CreateFull
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
 *   _IcaAnimeFileName     0x020A7270  data
 *   func_02030734     0x02030734  arm
 *   ICA_ANIME_Clear     0x020116C0  thumb
 *   ICA_ANIME_LoadHeader     0x020116E0  thumb
 *   ICA_ANIME_AllocBuffer     0x02011770  thumb
 *   ICA_ANIME_LoadFrames     0x0201183C  thumb
 *
 * ica_anime.c: the third constructor (line 0x90 of "ica_anime.c").  The
 * object is 0x38 bytes and the four-argument initialiser gets the heap back
 * as its last argument, which is where r3 = r5 comes from.  ICA_ANIME_Clear gets
 * the object straight from the allocator, which is why no move precedes it.
 *
 * The tail is the pair every one of these constructors ends with -
 * ICA_ANIME_AllocBuffer(p, p->f0c) and ICA_ANIME_LoadFrames(p, 0).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ICA_ANIME_CreateFull.c \
 *       --func ICA_ANIME_CreateFull --addr 0x020114D0 --cc 1.1p1 --thumb
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

extern u8 _IcaAnimeFileName;

extern void *func_02030734(u32 heap, u32 size, int clear, const char *file, unsigned short line);
extern void   ICA_ANIME_Clear(struct IcaAnime *p);
extern void   ICA_ANIME_LoadHeader(u8 *p, u32 a1, u32 a2, u32 heap);
extern void   ICA_ANIME_AllocBuffer(u8 *p, int v);
extern void   ICA_ANIME_LoadFrames(struct IcaAnime *p, s32 v);

void *ICA_ANIME_CreateFull(u32 heap, u32 a1, u32 a2)
{
    struct IcaAnime *p;

    p = func_02030734(heap, 0x38, 0, (const char *)&_IcaAnimeFileName, 0x90);
    ICA_ANIME_Clear(p);
    ICA_ANIME_LoadHeader((u8 *)p, a1, a2, heap);
    ICA_ANIME_AllocBuffer((u8 *)p, p->f0c);
    ICA_ANIME_LoadFrames(p, 0);
    return p;
}
