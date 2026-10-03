/*
 * function: func_021E7C3C
 * address: 0x021E7C3C
 * packet: pkt_ov177_021E7C3C
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021E7CF0 0x021E7CF0 thumb ov177
 *   func_021E5978 0x021E5978 thumb ov177
 *   func_02082BCC 0x02082BCC arm
 *   func_0204B294 0x0204B294 arm
 */
extern unsigned func_021E7CF0(unsigned,unsigned,unsigned);
extern int func_021E5978(int *p, int i);
extern void func_02082BCC(void *,int,int);
extern void *func_0204B294(void *,int,int,int,short *,int,unsigned);
void func_021E7C3C(char *p,char *q,void *x,void *data,unsigned heap)
{
 unsigned i,n;
 short b[4];
 n=func_021E7CF0(*(unsigned *)(q+0x30),*(unsigned *)(q+0x28),*(unsigned *)(q+0x2C));
 func_02082BCC(b,0,8);
 b[0]=0x100;b[1]=0x10;
 for(i=0;i<n;i++) {
 int a,c,d;
 b[0]+=0x10;b[2]=i+2;
 a=func_021E5978(data,2);c=func_021E5978(data,0);d=func_021E5978(data,4);
 *(void **)(p+i*4+0x68)=func_0204B294(x,a,c,d,b,0,heap);
 }
}
