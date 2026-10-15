/*
 * function: PARTY_STATUS_ExitSubWork
 * address:  0x021E5B1C
 * packet:   pkt_021E5B1C
 * region:   ov178
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ov176_id        0x000000B0  data
 *   LIVEBATTLEMATCH_IRC_Delete   0x0217E058  thumb
 *   func_02034A5C   0x02034A5C  arm
 *
 * Release the handle at *p, then tear down channel ov176_id.
 */


extern unsigned char ov176_id[];
extern void LIVEBATTLEMATCH_IRC_Delete(int);
extern void func_02034A5C(int);

void PARTY_STATUS_ExitSubWork(int *p, void *c)
{
    LIVEBATTLEMATCH_IRC_Delete(*p);
    func_02034A5C((int)ov176_id);
}
