/*
 * function: func_021F07AC
 * address:  0x021F07AC
 * packet:   pkt_ov029_021F07AC
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     one local v carries every step (narrowed, index, table byte); computing the
 *           table byte into v as its own statement keeps the argument copies after it.
 *
 * symbols:
 *   func_021F07AC  0x021F07AC  thumb  ov029
 *   func_021F0D08  0x021F0D08  thumb  ov029
 *   func_021F08BC  0x021F08BC  thumb  ov029
 *   d_021F3255     0x021F3255  data  ov029  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern unsigned short func_021F0D08(unsigned short *p, int i);
extern void func_021F08BC(u8 *p, int i, int j, int k);
extern u8 d_021F3255[];

void func_021F07AC(u8 *p, int i, u16 *e)
{
    unsigned int v = func_021F0D08(e, i);
    if (v > 0x24 || v < 4) return;
    v = (u16)(v - 4);
    v = (unsigned)(((int)v % 8) * 28) >> 3;
    v = d_021F3255[v];
    func_021F08BC(p, i, v, 0x1f);
}
