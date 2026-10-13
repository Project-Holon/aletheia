/*
 * function: FIELD_CAMERA_ClearTargetTrace
 * address: 0x0218E5F4
 * packet: pkt_ov021_0218E5F4
 * region: ov021
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 *
 * Function with no listing label, matched inside src/game/ov021/field_msgbg.c and filed here.
 */

typedef unsigned char  u8;
void FIELD_CAMERA_ClearTargetTrace(u8 *p);

void FIELD_CAMERA_ClearTargetTrace(u8 *p)
{
    *(int *)(p + 0x1C) = 0;
}
