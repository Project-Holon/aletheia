/*
 * function: NAMEIN_SETUP_StepLandAnim
 * address:  0x0216C270
 * packet:   pkt_ov010_0216C270
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ICA_ANIME_IncFrameLoop  0x02011590  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Work {
    u8 pad00[0x10];
    void *anim;         /* 0x10 */
} Work;

typedef signed int     s32;
struct IcaAnime;
extern u32 ICA_ANIME_IncFrameLoop(struct IcaAnime *p, s32 v);

int NAMEIN_SETUP_StepLandAnim(Work *w)
{
    return ICA_ANIME_IncFrameLoop(w->anim, 0x1000);
}
