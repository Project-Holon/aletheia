/*
 * function: INTRO_CMD_Main
 * address: 0x021BEF88
 * packet: pkt_ov204_021BEF88
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   INTRO_MSG_Main 0x021BF228 thumb ov204
 *   INTRO_CMD_RunCommands 0x021BF030 thumb ov204
 *   INTRO_CMD_GetScenarioRow 0x021BF094 thumb ov204
 *   INTRO_CMD_AddCommand 0x021BF00C thumb ov204
 *   gIntroCmdCommandTable 0x021C09D8 data a4
 */
#include "../include/Obj06673.h"
typedef struct Row { unsigned tag; unsigned data[5]; } Row;
typedef unsigned char  u8;
extern void INTRO_MSG_Main(u8 *p);
struct Q021BF00C;
struct S021BF00C;
struct State;
extern int INTRO_CMD_RunCommands(struct State *p);
extern Row *INTRO_CMD_GetScenarioRow(unsigned);
extern int INTRO_CMD_AddCommand(struct S021BF00C *p, struct Q021BF00C *q);
extern int (*const gIntroCmdCommandTable[])(void *, void *, void *);
int INTRO_CMD_Main(char *p)
{
    INTRO_MSG_Main(((struct Obj06673 *)p)->f18);
    if (INTRO_CMD_RunCommands((struct State *)p) == 0) {
        char *base = p;
        int i;
        base += 0x40;
        for (i = 0; i < 9; i++) {
            Row *row = INTRO_CMD_GetScenarioRow(((struct Obj06673 *)p)->f1C) + ((struct Obj06673 *)p)->fA0;
            if (row->tag == 1) {
                gIntroCmdCommandTable[row->tag](p, base + i * 12, row->data);
                row = INTRO_CMD_GetScenarioRow(((struct Obj06673 *)p)->f1C);
            }
            if (row->tag == 0x34)
                return 0;
            ++((struct Obj06673 *)p)->fA0;
            if (!INTRO_CMD_AddCommand((struct S021BF00C *)p, (struct Q021BF00C *)row))
                break;
        }
    }
    return 1;
}
