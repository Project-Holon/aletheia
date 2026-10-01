/*
 * function: func_021D614C
 * address: 0x021D614C
 * packet: pkt_ov131_021D614C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 */
extern void *func_02045EC0(void *, int);
extern void func_02045808(void *);
extern void func_0201C724(void *,int,short,short,void *,int,unsigned short);
void func_021D614C(unsigned char *p,int a,int b,int c,short d,unsigned short e) {
 void *t=func_02045EC0(*(void **)(p+124),b);
 func_0201C724(*(void **)(p+132),a,(short)c,d,t,*(int *)(p+128),e);
 func_02045808(t);
}
