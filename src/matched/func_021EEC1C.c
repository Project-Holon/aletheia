/*
 * function: func_021EEC1C
 * address:  0x021EEC1C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EE408  0x021EE408  thumb  ov170
 *
 * Queue the byte-narrowed index, then re-run the frame update.
 */


extern void func_020260E4(int, int);
extern void func_021EE408(char *, int);
void func_021EEC1C(char *p, unsigned int a)
{
    func_020260E4(*(int *)(*(int *)(p + 0x2c) + 0x70), (unsigned char)a);
    func_021EE408(p, a);
}
