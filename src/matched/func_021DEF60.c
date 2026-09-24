/*
 * function: func_021DEF60
 * address:  0x021DEF60
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ECCCC  0x021ECCCC  thumb  ov170
 *   func_021ED028  0x021ED028  thumb  ov170
 *   func_021EB2A4  0x021EB2A4  thumb  ov170
 *   func_021DF11C  0x021DF11C  thumb  ov170
 *   func_021DF144  0x021DF144  thumb  ov170
 *
 * Six-step handover: stage 0xb, rebuild, refresh, push the 0x10
 *   tag word, re-tag, then release handle 3.
 */


extern void func_021ECCCC(char *, int, int);
extern void func_021ED028(int, int);
extern void func_021EB2A4(char *, int);
extern void func_021DF11C(char *, int);
extern void func_021DF144(int, int);
extern void func_02041EE4(int, int, int);
void func_021DEF60(char *p, int a)
{
    func_021ECCCC(p, a, 0xb);
    func_021ED028(*(int *)(p + 0x2c), a);
    func_021EB2A4(p, a);
    func_021DF11C(p, *(unsigned short *)(a + 0x10));
    func_021DF144(*(int *)(p + 0x2c), a);
    func_02041EE4(5, 3, 0);
}
