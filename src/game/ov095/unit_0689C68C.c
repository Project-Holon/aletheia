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
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb
 */
extern int BTL_POKEPARAM_HasSick(void *, int);
extern void BTL_EVENT_OverwriteVar(int, int);
void func_0689C68C(int unused, void *p)
{
 if (BTL_POKEPARAM_HasSick(p, 0x16) != 0 || BTL_POKEPARAM_HasSick(p, 8) != 0) {
  BTL_EVENT_OverwriteVar(0x41, 1);
 }
}
