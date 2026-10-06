/*
 * unit: yes
 * function: func_021B7A60, func_021B7AAC
 * address: 0x021B7A60
 * packet: pkt_ov102_021B7A60
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: Packed word supplies low/high halfwords, not duplicate low halves. Includes tail-call follower 021B7AAC.
 * symbols:
 * func_02030EAC 0x02030EAC arm
 * func_0203FB44 0x0203FB44 arm
 * func_02040DA8 0x02040DA8 arm
 * func_020403F4 0x020403F4 arm
 * func_020450C8 0x020450C8 arm
 * func_0203F9B4 0x0203F9B4 arm
 * func_020419E4 0x020419E4 arm
 * d_021B8AEC 0x021B8AEC data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
struct Node;
extern void func_02030EAC(struct Node *n);
typedef unsigned int   u32;
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_02040DA8(unsigned,unsigned,unsigned);
extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_020419E4(void);
extern unsigned d_021B8AEC[];
void func_021B7A60(unsigned *p) {
 int i;
 unsigned q;
 func_02030EAC((struct Node *)p[1]);
 q=p[0];
 func_0203FB44(5,(u16)q,(u16)(q>>16));
 func_02040DA8(5,1,0);
 for(i=0;i<8;i++) func_020403F4((u8)d_021B8AEC[i]);
 func_020450C8();
 func_0203F9B4();
}
void func_021B7AAC(void) { func_020419E4(); }
