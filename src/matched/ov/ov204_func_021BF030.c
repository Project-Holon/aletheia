/*
 * function: INTRO_CMD_RunCommands
 * address: 0x021BF030
 * packet: pkt_ov204_021BF030
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   INTRO_CMD_ClearCommand 0x021BF080 thumb ov204
 *   gIntroCmdCommandTable 0x021C09D8 data a4
 */
typedef struct Command { unsigned tag; unsigned data[5]; } Command;
typedef struct Slot { unsigned data[3]; } Slot;
typedef struct State { char pad[0x20]; Command *commands[8]; Slot slots[8]; } State;
extern int (*const gIntroCmdCommandTable[])(void *, Slot *, void *);
extern void INTRO_CMD_ClearCommand(char *, unsigned char);
int INTRO_CMD_RunCommands(State *p)
{
    int result = 0;
    int i;
    for (i = 0; i < 8; i++) {
        Command *q = p->commands[i];
        if (q) {
            if (!gIntroCmdCommandTable[q->tag](p, &p->slots[i], q->data)) result = 1;
            else INTRO_CMD_ClearCommand((char *)p, i);
        }
    }
    return result;
}
