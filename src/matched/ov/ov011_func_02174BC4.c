/*
 * function: INTRUDE_COMM_UpdatePendingNotices
 * address:  0x02174BC4
 * packet:   pkt_ov011_02174BC4
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203D1C0  0x0203D1C0  arm
 *   func_02173AE0  0x02173AE0  thumb ov011
 *   INTRUDE_COMM_SendNotice  0x02173B44  thumb ov011
 */

typedef unsigned int   u32;
u32 func_0203D1C0(u32 index);
int func_02173AE0(int a, int b, int c, int d);
int INTRUDE_COMM_SendNotice(void *p, int i, int v);

void INTRUDE_COMM_UpdatePendingNotices(unsigned char *p)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (p[i + 0x945] != 0) {
            if ((int)func_0203D1C0((unsigned char)i) == 1) {
                if (func_02173AE0((int)p, i, 2, p[i + 0x945]) == 1) {
                    p[i + 0x945] = 0;
                }
            } else {
                p[i + 0x945] = 0;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        if (p[i + 0x948] != 0) {
            if ((int)func_0203D1C0((unsigned char)i) == 1) {
                if (INTRUDE_COMM_SendNotice(p, i, p[i + 0x948]) == 1) {
                    p[i + 0x948] = 0;
                }
            } else {
                p[i + 0x948] = 0;
            }
        }
    }
}
