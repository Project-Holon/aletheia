/*
 * function: BTL_SICK_ForceGroundedByTrap
 * address: 0x0689C68C
 * packet: pkt_ov095_0689C68C
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0689C6B4 0x0689C6B4 thumb ov095
 *   func_0689C6C4 0x0689C6C4 thumb ov095
 *   func_0689C6D4 0x0689C6D4 thumb ov095
 */
extern int func_0689C6B4(void *, int);
extern int func_0689C6C4(void *, int);
extern void func_0689C6D4(int, int);
void BTL_SICK_ForceGroundedByTrap(int unused, void *p)
{
 if (func_0689C6B4(p, 0x16) != 0 || func_0689C6C4(p, 8) != 0) {
  func_0689C6D4(0x41, 1);
 }
}
