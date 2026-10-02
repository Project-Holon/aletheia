/*
 * function: func_021F38EC
 * address: 0x021F38EC
 * packet: pkt_ov048_021F38EC
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021F39A8 0x021F39A8 thumb ov048
 *   func_021F3C14 0x021F3C14 thumb ov048
 *   func_021897A0 0x021897A0 thumb ov021
 */
extern void func_021F39A8(void **p);
extern void func_021F3C14(char *p);
extern void func_021897A0(int a,int b);
void func_021F38EC(int *p) { if(p) {func_021F39A8((void **)p);func_021F3C14((char *)p);func_021897A0(p[1],0);} }
