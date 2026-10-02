/*
 * function: func_021BA6A8
 * address: 0x021BA6A8
 * packet: pkt_ov072_021BA6A8
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BA638 0x021BA638 thumb ov072
 */
extern void func_021BA638(void *p, int *in);
void func_021BA6A8(char *p, const int *in) { *(int *)(p+16) = in[0] + *(int *)(p+16); *(int *)(p+20) = *(int *)(p+20) + in[1]; func_021BA638(p,(int *)(p+16)); }
