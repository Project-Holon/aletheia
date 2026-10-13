/*
 * function: MUSICAL_EVENT_ShowMessage
 * address:  0x02156888
 * packet:   pkt_02156888
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Build a four-argument request out of the second argument's word and pass
 * the two handles the overlay looked up to the arm9 side.
 *
 * symbols:
 *   SCRIPT_SYS_CreateScriptEventSimple   0x02158768  thumb  ov010
 *   SCRIPT_SYS_GetEventScriptWork   0x021589D0  thumb  ov010
 *   GAME_EVENT_CallEvent   0x02012374  thumb
 */
#include "../include/Obj17617.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Desc;
struct Evt;
extern struct Desc *SCRIPT_SYS_CreateScriptEventSimple(int a0, int a1, int a2, int a3);
extern int SCRIPT_SYS_GetEventScriptWork(int a0);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);

void MUSICAL_EVENT_ShowMessage(void *a0, void *a1, int a2)
{
    void *r4 = SCRIPT_SYS_CreateScriptEventSimple(((struct Obj17617 *)a1)->f0, a2, 0, 0x15);

    SCRIPT_SYS_GetEventScriptWork((int)r4);
    GAME_EVENT_CallEvent(a0, r4);
}

