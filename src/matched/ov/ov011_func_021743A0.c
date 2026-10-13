/*
 * function: INTRUDE_CMD_RecvTallyWord
 * address: 0x021743A0
 * packet: pkt_ov011_021743A0
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov011/unit_02173CB0.c and filed here.
 *
 * symbols:
 *   MI_CpuCopy8 0x02082D44 arm
 */

typedef unsigned char u8;
void MI_CpuCopy8(void *d, void *s, int n);

void INTRUDE_CMD_RecvTallyWord(int a, int b, void *dst, u8 *p)
{
    MI_CpuCopy8(dst, p + 0x358, 4);
}
