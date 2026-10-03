/*
 * function: func_021FA27C
 * address: 0x021FA27C
 * packet: pkt_ov132_021FA27C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Lever: keep the declared base but expand p+0x204 at the call; named base left a four-byte r5/r6 swap.
 * trailing: Two zero alignment bytes.
 * symbols:
 *   func_021FA2A0 0x021FA2A0 thumb ov132
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021FA2A0(char *, u8 *);
void func_021FA27C(char *p)
{
  u8 i = 0;
  u8 *base = (u8 *) (p + 0x204);
  for (; i < 60; i++)
    func_021FA2A0(p, ((u8 *) (p + 0x204)) + (i * 8));

}
