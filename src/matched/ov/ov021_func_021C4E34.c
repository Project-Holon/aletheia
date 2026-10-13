/*
 * function: SOUND_OBJ_ApplyPosition
 * address:  0x021C4E34
 * packet:   pkt_ov021_021C4E34
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Syncs the task's current position into the target and its map object.
 *
 * symbols:
 *   ISS_3DS_SYS_SetSourcePos  0x0202B934  thumb
 *   ICA_ANIME_GetTranslate  0x02011610  thumb  arm9
 */

typedef unsigned short u16;
typedef unsigned int u32;

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
struct Rec12;
extern u32 ICA_ANIME_GetTranslate(struct IcaAnime *t, struct Rec12 *v);
extern void ISS_3DS_SYS_SetSourcePos(u32 a, u32 b, V3 *v);

static inline void V3_Set(V3 *d, int x, int y, int z)
{
    d->x = x;
    d->y = y;
    d->z = z;
}

void SOUND_OBJ_ApplyPosition(R *r)
{
    V3 t;

    if (r->task != 0 && ICA_ANIME_GetTranslate((struct IcaAnime *)r->task, (struct Rec12 *)&t) == 1) {
        V3_Set(r->pos, t.x, t.y, t.z);
        if (r->f8 != 0)
            ISS_3DS_SYS_SetSourcePos(r->f8, r->fC, &t);
    }
}
