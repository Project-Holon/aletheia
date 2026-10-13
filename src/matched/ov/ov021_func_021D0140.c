/*
 * function: FLDEFF_BTRAIN_Create
 * address:  0x021D0140
 * packet:   pkt_ov021_021D0140
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sFldeffBtrainFileName     0x021DE608  data  ov021  a4
 *   func_02030734  0x02030734  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern char sFldeffBtrainFileName[];

void *FLDEFF_BTRAIN_Create(u32 v, u32 heap)
{
    u32 *p = func_02030734(heap, 0x54, 1, sFldeffBtrainFileName, 0x5f);

    p[0] = v;
    return p;
}
