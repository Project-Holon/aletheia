/*
 * function: func_021D61B8
 * address: 0x021D61B8
 * packet: pkt_ov131_021D61B8
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_020457B0 0x020457B0 arm
 */
extern void *func_020457B0(int,int);
extern void *func_02045EC0(void *,int);
extern void func_0201F250(void *,void *,void *);
extern void func_02045808(void *);
extern void func_0201C724(void *,int,short,short,void *,int,unsigned short);
void func_021D61B8(unsigned char *p,int a,void *b,int c,short d,short e,unsigned short f) {
 void *t=func_020457B0(16,*(unsigned short *)p);
 void *s=func_02045EC0(*(void **)(p+124),c);
 func_0201F250(b,t,s);
 func_0201C724(*(void **)(p+132),a,d,e,t,*(int *)(p+128),f);
 func_02045808(s);
 func_02045808(t);
}
