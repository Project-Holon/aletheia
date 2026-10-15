/*
 * function: INTRO_GRAPHIC_DrawMenuEntry
 * address: 0x021BE138
 * packet: pkt_ov204_021BE138
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021BE17A..021BE17C is two zero alignment bytes.
 * symbols:
 *   INTRO_CMD_GetScenarioRow 0x021BF094 thumb ov204
 *   INTRO_MSG_DrawMenuList 0x021BF4E8 thumb ov204
 *   INTRO_CMD_AddCommand 0x021BF00C thumb ov204
 */
#include "../include/Obj04608.h"
struct S021BF00C; struct Q021BF00C;
extern char *INTRO_CMD_GetScenarioRow(int);
extern void INTRO_MSG_DrawMenuList(char *);
extern int INTRO_CMD_AddCommand(struct S021BF00C *, struct Q021BF00C *);
void INTRO_GRAPHIC_DrawMenuEntry(char *p, int which)
{
    char *q = INTRO_CMD_GetScenarioRow(((struct Obj04608 *)p)->f1C) + 24 * ((struct Obj04608 *)p)->fA0;
    INTRO_MSG_DrawMenuList(*(char * *)&((struct Obj04608 *)p)->f18);
    if (which == 0) {
        if (q) INTRO_CMD_AddCommand((struct S021BF00C *)p, (struct Q021BF00C *)q);
    } else {
        q += 24;
        if (q) INTRO_CMD_AddCommand((struct S021BF00C *)p, (struct Q021BF00C *)q);
    }
    ((struct Obj04608 *)p)->fA0 += 2;
}
