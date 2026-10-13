/*
 * function: SOUND_OBJ_AdvanceAnime
 * address:  0x021C4DE4
 * packet:   pkt_ov021_021C4DE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Finishes the record's task and tears the record down.
 *
 * symbols:
 *   SOUND_OBJ_ApplyPosition  0x021C4E34  thumb  ov021
 *   SOUND_OBJ_ApplyRotation  0x021C4E6C  thumb  ov021
 *   ICA_ANIME_IncFrameLoop  0x02011590  thumb  arm9
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u16 heap;
    u16 pad;
    void *owner;
    u32 f8;
    u32 fC;
    u32 task;
    u32 f14;
} R;

struct IcaAnime;
extern u32 ICA_ANIME_IncFrameLoop(struct IcaAnime *p, s32 v);
extern void SOUND_OBJ_ApplyPosition(R *r);
extern void SOUND_OBJ_ApplyRotation(char *p);

u32 SOUND_OBJ_AdvanceAnime(R *r, s32 dv)
{
    u32 v;

    if (r->task == 0)
        return 0;
    v = ICA_ANIME_IncFrameLoop((struct IcaAnime *)r->task, dv);
    SOUND_OBJ_ApplyPosition(r);
    SOUND_OBJ_ApplyRotation((char *)r);
    return v;
}
