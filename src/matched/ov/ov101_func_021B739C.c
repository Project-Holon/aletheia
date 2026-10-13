/*
 * function: IRC_APPBAR_CreateActor
 * address: 0x021B739C
 * packet: pkt_ov101_021B739C
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 * MI_CpuFill8 0x02082BCC arm
 * CLACT_CreateActor 0x0204B294 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u16 x,y,z; u8 pad,n; } Desc;
extern void MI_CpuFill8(void *,int,unsigned);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *,unsigned int,unsigned int,unsigned int,const void *,u16,u16);
void IRC_APPBAR_CreateActor(unsigned *p,unsigned b,int c,unsigned d,u8 e,u16 f) {
 Desc t;
 MI_CpuFill8(&t,0,8);
 t.x=128; t.y=96; t.z=0; t.n=e+1;
 p[2]=(unsigned)CLACT_CreateActor((void *)b,p[13],p[12],p[14],&t,d,f);
}
