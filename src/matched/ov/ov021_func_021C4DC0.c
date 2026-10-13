/*
 * function: SOUND_OBJ_SetAnime
 * address:  0x021C4DC0
 * packet:   pkt_ov021_021C4DC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Restarts the record's task with new arguments.
 *
 * symbols:
 *   ICA_ANIME_CreateStream  0x02011510  thumb  arm9
 *   ICA_ANIME_Delete  0x02011558  thumb  arm9
 */

typedef unsigned short u16;
typedef unsigned int u32;

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
extern void ICA_ANIME_Delete(struct IcaAnime *p);
extern void *ICA_ANIME_CreateStream(u32 heap, u32 a1, u32 a2, u32 a3);

void SOUND_OBJ_SetAnime(R *r, u32 a, u32 b, u32 c)
{
    if (r->task != 0)
        ICA_ANIME_Delete((struct IcaAnime *)r->task);
    r->task = (u32)ICA_ANIME_CreateStream(r->heap, a, b, c);
}
