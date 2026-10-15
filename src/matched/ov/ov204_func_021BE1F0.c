/*
 * function: INTRO_GRAPHIC_CmdRunHandler
 * address: 0x021BE1F0
 * packet: pkt_ov204_021BE1F0
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   INTRO_CMD_GetScenarioRow 0x021BF094 thumb ov204
 *   INTRO_CMD_AddCommand 0x021BF00C thumb ov204
 *   gIntroGraphicHandlerTable 0x021C09D0 data a4
 */
#include "../include/Obj10872.h"
typedef struct Row { unsigned tag; char data[20]; } Row;
extern Row *INTRO_CMD_GetScenarioRow(unsigned);
struct Q021BF00C;
struct S021BF00C;
extern int INTRO_CMD_AddCommand(struct S021BF00C *p, struct Q021BF00C *q);
extern int (*const gIntroGraphicHandlerTable[])(void *);
int INTRO_GRAPHIC_CmdRunHandler(char *p, int unused, unsigned *q)
{
    Row *row = INTRO_CMD_GetScenarioRow(((struct Obj10872 *)p)->f1C) + ((struct Obj10872 *)p)->fA0;
    if (!gIntroGraphicHandlerTable[*q](p)) row++;
    if (row) INTRO_CMD_AddCommand((struct S021BF00C *)p, (struct Q021BF00C *)row);
    ((struct Obj10872 *)p)->fA0 += 2;
    return 1;
}
