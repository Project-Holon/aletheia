/*
 * function: func_021B7B2C
 * address: 0x021B7B2C
 * packet: pkt_ov104_021B7B2C
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: ABF0 forwards AC18's index; B294 forwards CFDC's pointer live in r0.
 * symbols:
 *   d_020A1448 0x020A1448 data
 *   func_02082BCC 0x02082BCC arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_020490F4 0x020490F4 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_02049238 0x02049238 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B84C 0x0204B84C arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B6F4 0x0204B6F4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cfg;
struct Bank;
struct Obj;
typedef struct { char pad[0x60]; u32 f60; } S;
extern const struct Cfg d_020A1448;
extern void func_02082BCC(void *,int,int);
extern void func_0204A48C(const struct Cfg *,u32,u32);
extern struct Bank *func_0204B100(int,u8,u32);
extern void func_0204B270(struct Bank *);
extern void func_020434DC(u32,u32);
extern void func_02043598(u32,u32);
extern void *func_020490F4(unsigned int id, u16 heap);
extern int func_0204ABF0(u32,u32,u32,u32,u16);
extern int func_0204A6C8(u32,u32,u32,u32,u16);
extern int func_0204AF28(u32,u32,u32,u32);
extern int func_0204AC18(u32,u32,u32,u32,u16,u16,u16);
extern void func_02049238(void *);
extern struct Obj *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,unsigned short,unsigned short);
extern void func_0204B3DC(struct Obj *,u32);
extern void func_0204B84C(S *,u32);
extern void func_0204B92C(struct Obj *,u32);
extern void func_0204B878(struct Obj *,u16);
extern void func_0204B6F4(struct Obj *,u32,u32);
typedef struct { u16 x,y,z,w; } Desc;
void func_021B7B2C(u32 *p,const void *config,u16 heap) {
 void *archive; int i; Desc desc;
 func_02082BCC(p,0,0xb4);
 func_0204A48C(&d_020A1448,(u32)config,heap);
 p[0]=(u32)func_0204B100(0x80,0,heap);
 func_0204B270((struct Bank *)p[0]);
 func_020434DC(0x10,1);
 func_02043598(0x10,1);
 archive=func_020490F4(0x5e,heap);
 p[1]=func_0204ABF0((u32)archive,0x23,0,0,heap);
 p[2]=func_0204A6C8((u32)archive,0x22,0,0,heap);
 p[3]=func_0204AF28((u32)archive,0x21,0x20,heap);
 p[7]=func_0204AC18((u32)archive,0xc,0,0xe0,0xc,1,heap);
 p[8]=func_0204A6C8((u32)archive,0xb,0,0,heap);
 p[9]=func_0204AF28((u32)archive,0xa,9,heap);
 p[4]=func_0204ABF0((u32)archive,0x23,1,0,heap);
 p[5]=func_0204A6C8((u32)archive,0x22,0,1,heap);
 p[6]=func_0204AF28((u32)archive,0x21,0x20,heap);
 func_02049238(archive);
 func_02082BCC(&desc,0,8);
 for(i=0;i<30;i++) {
  p[i+10]=(u32)func_0204B294((void *)p[0],p[2],p[1],p[3],&desc,0,heap);
  func_0204B3DC((struct Obj *)p[i+10],0);
  func_0204B84C((S *)p[i+10],3);
  func_0204B92C((struct Obj *)p[i+10],1);
  func_0204B878((struct Obj *)p[i+10],0);
 }
 desc.x=128; desc.y=96;
 for(i=31;i<34;i++) {
  desc.z=i-30;
  p[i+10]=(u32)func_0204B294((void *)p[0],p[8],p[7],p[9],&desc,0,heap);
  func_0204B3DC((struct Obj *)p[i+10],0);
  func_0204B6F4((struct Obj *)p[i+10],0,1);
 }
}
