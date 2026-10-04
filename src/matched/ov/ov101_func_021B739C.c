/*
 * function: func_021B739C
 * address: 0x021B739C
 * packet: pkt_ov101_021B739C
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 * func_02082BCC 0x02082BCC arm
 * func_0204B294 0x0204B294 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u16 x,y,z; u8 pad,n; } Desc;
extern void func_02082BCC(void *,int,unsigned);
struct Obj;
extern struct Obj *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,u16,u16);
void func_021B739C(unsigned *p,unsigned b,int c,unsigned d,u8 e,u16 f) {
 Desc t;
 func_02082BCC(&t,0,8);
 t.x=128; t.y=96; t.z=0; t.n=e+1;
 p[2]=(unsigned)func_0204B294((void *)b,p[13],p[12],p[14],&t,d,f);
}
