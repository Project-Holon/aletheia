/*
 * function: EVENT_FIELD_PROCLINK_StartConfigEvent
 * address:  0x02161350
 * packet:   pkt_02161350
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Five arguments to the overlay builder: the two words of the descriptor,
 * the object's halfword, the descriptor's classification and a pointer to
 * the object's tail; the result goes to the arm9 call with the
 * object's word at +0x14.
 *
 * symbols:
 *   EVENT_FIELD_PROCLINK_CreateFreeEvent   0x021616A4  thumb  ov010
 *   FIELDMAP_GetMsgBg   0x02188C54  thumb
 *   GAME_EVENT_CallEvent   0x02012374  thumb
 */
#include "../include/Obj09158.h"
#include "../include/Obj09159.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *EVENT_FIELD_PROCLINK_CreateFreeEvent(void *p, int a1, int a2, int a3, int a4);
extern void *FIELDMAP_GetMsgBg(void *);
struct Evt;
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);

void EVENT_FIELD_PROCLINK_StartConfigEvent(void *a0)
{
    char *r4 = *(char * *)&((struct Obj09158 *)a0)->f18;
    void *t = FIELDMAP_GetMsgBg(((struct Obj09159 *)r4)->f4);

    GAME_EVENT_CallEvent(((struct Obj09158 *)a0)->f14,
                  EVENT_FIELD_PROCLINK_CreateFreeEvent(((struct Obj09159 *)r4)->f0, (int)(((struct Obj09159 *)r4)->f4),
                                ((struct Obj09158 *)a0)->f0, (int)t, (int)((char *)a0 + 0x10)));
}

