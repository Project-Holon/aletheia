/*
 * function: INTRO_CMD_CmdBrightnessWait
 * address: 0x021BE398
 * packet: pkt_ov204_021BE398
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BRIGHTNESS_IsFinished 0x02024004 thumb
 */
extern int BRIGHTNESS_IsFinished(int a);
int INTRO_CMD_CmdBrightnessWait(void) {BRIGHTNESS_IsFinished(1);return 1;}
