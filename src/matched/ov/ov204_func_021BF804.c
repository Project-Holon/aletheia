/*
 * function: INTRO_G3D_MoveSlot
 * address: 0x021BF804
 * packet: pkt_ov204_021BF804
 * region: ov204
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MCSS_GetPosition 0x02015C30 thumb
 *   MCSS_SetPosition 0x02015C48 thumb
 *   MCSS_SetAnmStopFlag 0x02015E04 thumb

 */

struct Vec { int v[3]; };
typedef unsigned int   u32;
extern void MCSS_GetPosition(void *p, u32 *out);
extern void MCSS_SetPosition(void *p, u32 *src);
extern void MCSS_SetAnmStopFlag(void *);

int INTRO_G3D_MoveSlot(char *p, unsigned int i, int step, int limit)
{
    struct Vec pos;
    char *base = p + 8;
    unsigned int off = i * 12;
    int done;
    MCSS_GetPosition(*(void **)(base + off), (u32 *)(&pos));
    done = 1;
    pos.v[0] += step;
    if (pos.v[0] != limit)
    {
        if ((step > 0 && pos.v[0] > limit) || (step < 0 && pos.v[0] < limit))
            pos.v[0] = limit;
        else
            done = 0;
    }
    MCSS_SetPosition(*(void **)(base + off), (u32 *)(&pos));
    if (*(unsigned int *)(p + off + 12) == 1)
        MCSS_SetAnmStopFlag(*(void **)(base + off));
    return done;
}
