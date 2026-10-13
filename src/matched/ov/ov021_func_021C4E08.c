/*
 * function: SOUND_OBJ_SetAnimeFrame
 * address:  0x021C4E08
 * packet:   pkt_ov021_021C4E08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Stops the record's task and syncs the final position (EXACT*: pad).
 *
 * symbols:
 *   SOUND_OBJ_ApplyPosition  0x021C4E34  thumb  ov021
 *   ICA_ANIME_SetFrame  0x020115EC  thumb  arm9
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { int x, y, z; } V3;

typedef struct {
    u16 heap;
    u16 pad;
    void *owner;
    u32 f8;
    u32 fC;
    u32 task;
    V3 *pos;
} R;

struct IcaAnime;
extern void ICA_ANIME_SetFrame(struct IcaAnime *p, s32 v);
extern void SOUND_OBJ_ApplyPosition(R *r);

void SOUND_OBJ_SetAnimeFrame(R *r, s32 frame)
{
    if (r->task != 0) {
        ICA_ANIME_SetFrame((struct IcaAnime *)r->task, frame);
        SOUND_OBJ_ApplyPosition(r);
    }
}
