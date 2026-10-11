/*
 * file:     unit_0689C68C.c
 * function: func_0689C68C
 * address: 0x0689C68C
 * packet: pkt_ov095_0689C68C
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D62C4  0x021D62C4  thumb
 *   func_021D76BC  0x021D76BC  thumb
 */
extern int func_021D62C4(void *, int);
extern void func_021D76BC(int, int);
void func_0689C68C(int unused, void *p)
{
 if (func_021D62C4(p, 0x16) != 0 || func_021D62C4(p, 8) != 0) {
  func_021D76BC(0x41, 1);
 }
}
