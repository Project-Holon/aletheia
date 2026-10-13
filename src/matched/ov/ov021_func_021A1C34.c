/*
 * function: WEATHER_StartTransition
 * address:  0x021A1C34
 * packet:   pkt_ov021_021A1C34
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_GetTransitionMode  0x021A1D78  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 pad0;
    u32 pad4;
    u16 result;
    u16 busy;
    u16 cur;
    u16 next;
    u32 flag;
    u16 queued;
} Obj021A1C34;

int WEATHER_GetTransitionMode(u16 a, u16 b);

int WEATHER_StartTransition(Obj021A1C34 *p, u16 x)
{
    if (p->busy != 0) {
        p->queued = x;
        return 0;
    }
    if (p->cur == x && x != 0)
        return 0;
    p->next = x;
    p->flag = 1;
    p->result = WEATHER_GetTransitionMode(p->cur, p->next);
    p->busy = 1;
    return 1;
}
