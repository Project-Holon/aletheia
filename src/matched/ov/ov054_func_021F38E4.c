/*
 * function: func_021F38E4
 * address: 0x021F38E4
 * packet: pkt_ov054_021F38E4
 * region: ov054
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02188C80 0x02188C80 thumb ov021
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   func_021C4E08 0x021C4E08 thumb ov021
 */

extern int func_02188C80(int);
extern int func_020120F4(int);
extern int func_02012EC4(int);
extern int *func_0200B3A4(int,int);
extern int func_021C4E08(void *,int);
void func_021F38E4(char *p,int a) { int *q=func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(a))),11); int i; for(i=0;i<2;i++) func_021C4E08(*(void **)(p+8+4*i),(int)((unsigned)q[i]<<12)); }
