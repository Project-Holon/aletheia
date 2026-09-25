/*
 * function: func_021E5B1C
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
 *   ov178_id        0x000000B0  data
 *   func_0217E058   0x0217E058  thumb
 *   func_02034A5C   0x02034A5C  arm
 *
 * Release the handle at *p, then tear down channel ov178_id.
 */


extern unsigned char ov178_id[];
extern void func_0217E058(int);
extern void func_02034A5C(int);

void func_021E5B1C(int *p)
{
    func_0217E058(*p);
    func_02034A5C((int)ov178_id);
}
