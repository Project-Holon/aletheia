/*
 * function: func_021F36C0
 * address: 0x021F36C0
 * packet: pkt_ov050_021F36C0
 * region: ov050
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: two-byte alignment padding at 0x021F36EA follows the return.
 * symbols:
 *   func_02188C84 0x02188C84 thumb ov021
 *   func_02189764 0x02189764 thumb ov021
 *   func_021F383C 0x021F383C thumb ov050
 *   func_021F3890 0x021F3890 thumb ov050
 */

extern unsigned short func_02188C84(unsigned char *);
extern void *func_02189764(unsigned char *, int, int, int);
extern void func_021F383C(int, int);
extern void func_021F3890(void *, unsigned char *);
void func_021F36C0(unsigned char *p) { unsigned short h; void *q; h=func_02188C84(p); q=func_02189764(p,1,h,2); *(unsigned short *)q=h; func_021F383C((int)q,(int)p); func_021F3890(q,p); }
