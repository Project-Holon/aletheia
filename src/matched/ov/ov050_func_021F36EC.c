/*
 * function: func_021F36EC
 * address: 0x021F36EC
 * packet: pkt_ov050_021F36EC
 * region: ov050
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: two-byte alignment padding at 0x021F3706 follows the return.
 * symbols:
 *   func_021897BC 0x021897BC thumb ov021
 *   func_021F3894 0x021F3894 thumb ov050
 *   func_021897A0 0x021897A0 thumb ov021
 */

extern int *func_021897BC(char *, int);
extern void func_021F3894(int *, char *);
extern void func_021897A0(unsigned char *, int);
void func_021F36EC(char *p) { func_021F3894(func_021897BC(p,1),p); func_021897A0((unsigned char *)p,1); }
