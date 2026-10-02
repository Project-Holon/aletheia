/*
 * function: func_021BB628
 * address: 0x021BB628
 * packet: pkt_ov093_021BB628
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * interface: func_021BB650's matched source declares void and an integer
 * fourth payload. Its original forwards that full word into EE96C r2;
 * EE96C stores the output count through r2 only on its nonzero return path
 * (021EE998), returns base+4 or zero, and BB650 leaves that r0 live.
 * This caller passes &n in r3 and reads r0, so its extern preserves both.
 * symbols:
 *   func_021BB650 0x021BB650 thumb ov093
 *   func_021BB724 0x021BB724 thumb ov093
 */

typedef unsigned char u8;
extern int func_021BB650(u8 *, int, int, int *);
extern void func_021BB724(u8 *, int, int, int);
int func_021BB628(u8 *p, int a, int b)
{
 int n;
 int r;
 r = func_021BB650(p, a, b, &n);
 if (r != 0) {
  func_021BB724(p, 10, r, n);
  return 1;
 }
 return 0;
}
