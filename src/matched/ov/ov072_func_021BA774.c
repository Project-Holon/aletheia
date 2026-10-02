/*
 * function: func_021BA774
 * address: 0x021BA774
 * packet: pkt_ov072_021BA774
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BBB3C 0x021BBB3C thumb ov072
 * call width: r1 is explicitly narrowed before the call, so extern takes u16.
 */
typedef unsigned short u16;
extern u16 func_021BBB3C(char *p, u16 a, int b);
int func_021BA774(char *p, int i) {
 if (i>=2 && i<=10) return *(int *)((unsigned int)p+(i-2)*4+12);
 if (i==12) return *(int *)(p+60);
 return func_021BBB3C(*(char **)(p+4),*(int *)(p+8),i);
}
