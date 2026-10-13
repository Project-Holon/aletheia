/*
 * function: SCRCMD_AddOtherOtId
 * address:  0x021CFA04
 * packet:   pkt_ov021_021CFA04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_AddUniqueOtId  0x021CFA1C  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct IdList021CFA1C;
extern int SCRCMD_AddUniqueOtId(int v, struct IdList021CFA1C *l);

int SCRCMD_AddOtherOtId(int a, int v, void *l)
{
    int r = 0;

    if (a != v) {
        r = SCRCMD_AddUniqueOtId(v, l);
    }
    return r;
}
