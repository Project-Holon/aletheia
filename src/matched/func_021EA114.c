/*
 * function: func_021EA114
 * address:  0x021EA114
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EC768  0x021EC768  thumb  ov170
 *   func_021ED594  0x021ED594  thumb  ov170
 *   func_021EE038  0x021EE038  thumb  ov170
 *   func_021E8FC0  0x021E8FC0  thumb  ov170
 *
 * Arm the flag, store the state byte, zero the 0x24 queue entry,
 *   re-stage it, publish (2,1,0) and set selector 0x021E0779.
 */


extern void func_021EC768(int, int, int);
extern void func_021ED594(char *, int);
extern void func_021EE038(char *, int, int, int);
extern void func_021E8FC0(char *, int, int);
void func_021EA114(char *p, int a)
{
    *(unsigned char *)(p + 0x18) = 1;
    *(unsigned char *)(p + 0x16) = a;
    func_021EC768(*(int *)(p + 0x2c), 0x24, 0);
    func_021ED594(p, 0x24);
    func_021EE038(p, 2, 1, 0);
    func_021E8FC0(p, 0x021E0779, 0x15);
}
