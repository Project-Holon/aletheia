/*
 * function: INTRO_CMD_CmdBrightnessChange
 * address:  0x021BE374
 * packet:   pkt_021BE374
 * region:   ov204
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BRIGHTNESS_ChangeRequest 0x02023EF4 thumb
 */

extern void BRIGHTNESS_ChangeRequest(int, int, int, int, int);

int INTRO_CMD_CmdBrightnessChange(int a0, int a1, int *src)
{
    BRIGHTNESS_ChangeRequest((unsigned char)src[0], (short)src[1], (short)src[2], 0x1d, 1);
    return 1;
}
