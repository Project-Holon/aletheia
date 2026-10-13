/*
 * function: EVENT_ENTRANCE_OUT_RunCamera
 * address:  0x021BDB5C
 * packet:   pkt_ov021_021BDB5C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   func_021A7B20  0x021A7B20  thumb  ov021
 *   EVENT_ENTRANCE_OUT_ShowPlaceName  0x021BDC80  thumb  ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Args;
struct Evt;
extern void *FIELDMAP_GetCamera(void *p);
extern void *func_021A7B20(struct Args *a);
extern void EVENT_ENTRANCE_OUT_ShowPlaceName(u32 *);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);

u32 EVENT_ENTRANCE_OUT_RunCamera(u32 a, int *st, u32 *ctx)
{
    u32 *p = (u32 *)ctx[0];

    FIELDMAP_GetCamera((void *)p[3]);
    switch (*st) {
    case 0:
        GAME_EVENT_CallEvent((struct Evt *)a, func_021A7B20((struct Args *)((u32)p)));
        (*st)++;
        break;
    case 1:
        EVENT_ENTRANCE_OUT_ShowPlaceName(ctx);
        return 1;
    }
    return 0;
}
