/*
 * function: INTRO_CMD_CmdSub
 * address: 0x021BE460
 * packet: pkt_ov204_021BE460
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gIntroCmdHandlerTable 0x021C09D4 data a4
 */
extern int (*const gIntroCmdHandlerTable[])(char *,int);
int INTRO_CMD_CmdSub(char *p,int *state,int *q){gIntroCmdHandlerTable[q[0]](p,q[1]);return 1;}
