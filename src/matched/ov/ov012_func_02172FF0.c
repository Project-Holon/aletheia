/*
 * function: UNION_COMM_SendEntryReplies
 * address:  0x02172FF0
 * packet:   pkt_ov012_02172FF0
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0203D1B4  0x0203D1B4  arm
 *   UNION_COMMAND_SendAppEntryRefused  0x02173D88  thumb  ov012
 *   UNION_COMMAND_SendAppEntryAccepted  0x02173DBC  thumb  ov012
 */

typedef unsigned char u8;

extern int func_0203D1B4(void);
typedef unsigned int   u32;
extern int UNION_COMMAND_SendAppEntryRefused(u32 a);
extern int UNION_COMMAND_SendAppEntryAccepted(int a);

void UNION_COMM_SendEntryReplies(u8 *w)
{
    if (func_0203D1B4() > 1) {
        if (w[0x282D] != 0 && UNION_COMMAND_SendAppEntryRefused(w[0x282D]) == 1) {
            w[0x282D] = 0;
        }
        if (w[0x282C] != 0 && UNION_COMMAND_SendAppEntryAccepted(w[0x282C]) == 1) {
            w[0x282C] = 0;
        }
    } else {
        w[0x282D] = 0;
        w[0x282C] = 0;
    }
}
