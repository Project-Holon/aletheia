/*
 * function: INTRUDE_COMM_UpdateMemberJoin
 * address:  0x02174B2C
 * packet:   pkt_ov011_02174B2C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203D1C0  0x0203D1C0  arm
 *   INTRUDE_COMM_SendRecordRequest  0x021737A8  thumb ov011
 */

typedef unsigned int   u32;
u32 func_0203D1C0(u32 index);
int INTRUDE_COMM_SendRecordRequest(void);

void INTRUDE_COMM_UpdateMemberJoin(unsigned char *p)
{
    int i;

    if (p[0x8FF] != 0) {
        p[0x8FF]--;
        return;
    }
    for (i = 0; i < p[0x902]; i++) {
        if ((int)func_0203D1C0((unsigned char)i) == 1 && !(p[0x8FB] & (1 << i))) {
            INTRUDE_COMM_SendRecordRequest();
            p[0x8FF] = 30;
            return;
        }
    }
}
