/*
 * function: EVENT_ENTRANCE_IN_RunGroundAnime
 * address:  0x021BD704
 * packet:   pkt_ov021_021BD704
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_GROUND_ANIME_CreateB  0x021A7E3C  thumb  ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 */

typedef unsigned int   u32;

struct Args;
struct Evt;
extern void *FIELD_GROUND_ANIME_CreateB(struct Args *a);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);

int EVENT_ENTRANCE_IN_RunGroundAnime(u32 a, int *st, u32 *ctx)
{
    u32 p = ctx[2];

    switch (*st) {
    case 0:
        GAME_EVENT_CallEvent((struct Evt *)a, FIELD_GROUND_ANIME_CreateB((struct Args *)p));
        (*st)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}
