/*
 * function: func_021F4784
 * address: 0x021F4784
 * packet: pkt_ov048_021F4784
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F4B7C 0x021F4B7C thumb ov048
 */
extern void func_021F4B7C(int *a,int *b,int c);
void func_021F4784(unsigned char *p,int c) { int i; for(i=0;i<p[2];i++) func_021F4B7C((int *)p,((int **)*(void **)(p+8))[i],c); *(int *)(p+24)+=c; }
