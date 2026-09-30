/*
 * function: func_021D8F60
 * address: 0x021D8F60
 * packet: pkt_ov119_021D8F60
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 */
extern int func_021D8A24(void *, int, int);
extern unsigned func_020399A8(unsigned);
extern unsigned func_0203D1A4(unsigned);
void func_021D8F60(void *p,int idx,int x) {
 unsigned v=func_021D8A24(p,idx,x);
 if(v==0) { *(int *)((char *)p+idx*4+0x5e4)=x; return; }
 if(func_0203D1A4(func_020399A8(v))==0) { *(int *)((char *)p+idx*4+0x5e4)=x; return; }
 *(int *)((char *)p+(1-idx)*4+0x5e4)=x;
}
