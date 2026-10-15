/*
 * function: EVENT_NAMEIN_StoreResult
 * address:  0x021CD3A4
 * packet:   pkt_ov021_021CD3A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Callee witnesses filed in wave A1 (witness lane).
 *
 * symbols:
 *   BEACON_SetGreetMessage  0x0200C1F8  thumb
 *   GAME_BEACON_UpdateGreeting  0x02027198  thumb
 *   BEACON_SetThanksMessage  0x0200C210  thumb
 *   BEACON_STATUS_GetMessage  0x020275C4  thumb
 *   STRBUF_Copy  0x02045838  arm
 *   GAME_BEACON_SEARCH_SetFreeText  0x02165844  thumb  ov010
 */
#include "../include/Obj03150.h"
#include "../include/Obj06099.h"

typedef unsigned char u8;
typedef unsigned short u16;

struct Blk34;
struct U16Vec;
extern void BEACON_SetGreetMessage(struct Blk34 *p, const u16 *src);
extern void GAME_BEACON_UpdateGreeting(void);
extern void BEACON_SetThanksMessage(struct Blk34 *p, const u16 *src);
extern int BEACON_STATUS_GetMessage(void *p);
extern void STRBUF_Copy(struct U16Vec *dst, struct U16Vec *src);
extern void GAME_BEACON_SEARCH_SetFreeText(void *v);

void EVENT_NAMEIN_StoreResult(u8 *a, u8 *b)
{
    u16 *q = *(u16 * *)&((struct Obj03150 *)a)->f18;

    if (q) {
        if (((struct Obj06099 *)b)->f1C == 0)
            *q = 1;
        else
            *q = 0;
    }
    if (((struct Obj06099 *)b)->f1C == 1)
        return;
    switch (((struct Obj03150 *)a)->f4C) {
    case 5:
        BEACON_SetGreetMessage((struct Blk34 *)(((struct Obj03150 *)a)->f8), (const u16 *)(((struct Obj06099 *)b)->f20));
        GAME_BEACON_UpdateGreeting();
        return;
    case 6:
        BEACON_SetThanksMessage((struct Blk34 *)(((struct Obj03150 *)a)->f8), (const u16 *)(((struct Obj06099 *)b)->f20));
        return;
    case 7:
        STRBUF_Copy((struct U16Vec *)BEACON_STATUS_GetMessage((void *)(((struct Obj03150 *)a)->f14)), (struct U16Vec *)(((struct Obj03150 *)a)->f3C));
        GAME_BEACON_SEARCH_SetFreeText((void *)(((struct Obj06099 *)b)->f20));
        return;
    }
}
