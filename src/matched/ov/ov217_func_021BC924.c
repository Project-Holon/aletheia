/*
 * function: RESEARCH_LIST_DeleteMessages
 * address:  0x021BC924
 * packet:   pkt_021BC924
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MSGDATA_Delete  0x02045C04  arm
 *
 * Addresses are Black-image addresses.
 */

struct Rec;
typedef unsigned int   u32;
extern u32 MSGDATA_Delete(struct Rec *rec);

void RESEARCH_LIST_DeleteMessages(int *p)
{
    int i;
    for (i = 0; i < 2; i++)
        MSGDATA_Delete((struct Rec *)p[i + 4]);
}
