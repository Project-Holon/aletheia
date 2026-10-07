/*
 * file:     unit_021B7560_p04.c
 * unit:     yes
 * function: func_021B7980, func_021B7994, func_021B7AD4, func_021B7B24, func_021B7B2C, func_021B7CA4, func_021B7D0C, func_021B7D14, func_021B7D1C
 * address:  0x021B7980
 * region:   ov104
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02040C14 0x02040C14 arm
 *   func_02049740 0x02049740 arm
 *   func_02049238 0x02049238 arm
 *   func_02049B40 0x02049B40 arm
 *   d_021B8F30 0x021B8F30 data ov104
 *   d_021B8F5C 0x021B8F5C data
 *   d_021B8FB4 0x021B8FB4 data
 *   d_021B8F40 0x021B8F40 data ov104
 *   func_02040DA8 0x02040DA8 arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   d_020A1448 0x020A1448 data
 *   func_02082BCC 0x02082BCC arm
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B84C 0x0204B84C arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_0204A600  0x0204A600  arm
 *   func_0204A648 0x0204A648 arm
 */
#include "../../matched/include/Obj22217.h"

struct DispConfig;
struct Cfg;
struct Bank;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef enum { BG0=0 } BgId;

struct BgTemplate { u8 bytes[32]; };

typedef short s16;

typedef signed char s8;

typedef int s32_021B7B24;

typedef struct { char pad[0x60]; u32 f60; } S;

typedef signed int     s32_021B7B2C;

typedef struct { u16 x,y,z,w; } Desc;

extern void func_0203F8F4(u16);
extern void func_02045088(u16);
extern void func_0203FC28(struct DispConfig *);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02040C14(u32,u32,u32,u32);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern void func_02049238(void *);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern void func_02040DA8(u32,u32,u32);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_020419E4(void);
extern void func_02082BCC(void *,int,int);
extern void func_0204A48C(const struct Cfg *,u32,u32);
extern struct Bank *func_0204B100(int,u8,u32);
extern void func_0204B270(struct Bank *);
extern void func_020434DC(u32,u32);
extern void func_02043598(u32,u32);
extern signed int func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32_021B7B2C func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32_021B7B2C func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern s32_021B7B2C func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern struct Obj *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,unsigned short,unsigned short);
extern void func_0204B3DC(struct Obj *,u32);
extern void func_0204B84C(S *,u32);
extern void func_0204B92C(struct Obj *,u32);
extern void func_0204B878(struct Obj *,u16);
extern void func_0204B6F4(struct Obj *,u32,u32);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_0204A600(int);
extern void func_0204A648(void);
void func_021B7980(u32 unused,u8 *p);
void func_021B7994(void *p,u16 heap);
void func_021B7AD4(u32 *p);
void func_021B7B24(void *a0);
void func_021B7B2C(u32 *p,const void *config,u16 heap);
void func_021B7CA4(void **p);
void func_021B7D0C(int x);
void func_021B7D14(void *p);
int func_021B7D1C(unsigned char *p, int i);
extern struct DispConfig d_021B8F30;
extern const u32 d_021B8F5C[];
extern const struct BgTemplate d_021B8FB4[];
extern const u32 d_021B8F40[];
extern const struct Cfg d_020A1448;

/*
 * extent: two zero alignment bytes follow compiled code.
 */
void func_021B7980(u32 unused,u8 *p) { func_021B7B24(p); func_021B7D14(p+4); }

void func_021B7994(void *p,u16 heap) {
 int i; BgId bg; void *archive;
 func_0203F8F4(heap);
 func_02045088(heap);
 func_0203FC28(&d_021B8F30);
 for(i=0;i<7;i++) {
  bg=d_021B8F5C[i];
  func_0203FCA0((u8)bg,&d_021B8FB4[i],(u8)d_021B8F40[i]);
  func_020414AC(bg);
  func_02040588(bg,1);
 }
 archive=func_020490F4(0x5e,heap);
 func_02049B68((void *)((u32)archive),1,0,0,0,heap);
 func_02049B68((void *)((u32)archive),1,4,0,0,heap);
 func_02049658((void *)((u32)archive),0x24,1,0,0,0,heap);
 func_02049658((void *)((u32)archive),0,6,0,0,0,heap);
 func_02049658((void *)((u32)archive),0x30,4,0,0,0,heap);
 func_020498F4((void *)((u32)archive),0x25,1,0,0,0,heap);
 func_020498F4((void *)((u32)archive),4,6,0,0,0,heap);
 func_020498F4((void *)((u32)archive),0x2f,4,0,0,0,heap);
 func_02040C14(5,0,1,0);
 ((struct Obj22217 *)p)->f0=func_02049740((void *)((u32)archive),0x31,5,0,0,heap);
 func_02049238(archive);
 func_02049B40(0x17,5,0,0x1a0,0x20,heap);
 func_02040C14(2,0,1,0);
}

void func_021B7AD4(u32 *p) { int i; func_02040DA8(2,1,0); func_0203FB44(5,(u16)(*p),(u16)(*p>>16)); func_02040DA8(5,1,0); for(i=0;i<7;i++) func_020403F4((u8)d_021B8F5C[i]); func_020450C8(); func_0203F9B4(); }

void func_021B7B24(void *a0) { func_020419E4(); }

/*
 * prototype: ABF0 forwards AC18's index; B294 forwards CFDC's pointer live in r0.
 */
void func_021B7B2C(u32 *p,const void *config,u16 heap) {
 void *archive; int i; Desc desc;
 func_02082BCC(p,0,0xb4);
 func_0204A48C(&d_020A1448,(u32)config,heap);
 p[0]=(u32)func_0204B100(0x80,0,heap);
 func_0204B270((struct Bank *)p[0]);
 func_020434DC(0x10,1);
 func_02043598(0x10,1);
 archive=func_020490F4(0x5e,heap);
 p[1]=func_0204ABF0((void *)archive,0x23,0,0,heap);
 p[2]=func_0204A6C8((void *)((u32)archive),0x22,0,0,heap);
 p[3]=func_0204AF28((void *)((u32)archive),0x21,0x20,heap);
 p[7]=func_0204AC18((void *)((u32)archive),0xc,0,0xe0,0xc,1,heap);
 p[8]=func_0204A6C8((void *)((u32)archive),0xb,0,0,heap);
 p[9]=func_0204AF28((void *)((u32)archive),0xa,9,heap);
 p[4]=func_0204ABF0((void *)archive,0x23,1,0,heap);
 p[5]=func_0204A6C8((void *)((u32)archive),0x22,0,1,heap);
 p[6]=func_0204AF28((void *)((u32)archive),0x21,0x20,heap);
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

void func_021B7CA4(void **p) { int i; for(i=0;i<35;i++) if(p[i+10]) func_0204B3B4(p[i+10]); func_0204ADA4((u32)p[1]); func_0204A8D4((u32)p[2]); func_0204AFD8((u32)p[3]); func_0204ADA4((u32)p[4]); func_0204A8D4((u32)p[5]); func_0204AFD8((u32)p[6]); func_0204ADA4((u32)p[7]); func_0204A8D4((u32)p[8]); func_0204AFD8((u32)p[9]); func_0204B1CC(p[0]); func_0204A5AC(); func_02082BCC(p,0,0xb4); }


/*
 * Thumb long-branch veneer in a .word run:
 *   ldr r3,[pc,#0]; bx r3; .word 0x0204A600
 * Declared as an ordinary tail-call extern at the veneer address.
 */
void func_021B7D0C(int x)
{
    func_0204A600(x);
}

void func_021B7D14(void *p) { func_0204A648(); }

/*
 * Unlabelled leaf accessor, witness for the thunk func_021B7968.
 */
int func_021B7D1C(unsigned char *p, int i)
{
    return *(int *)(p + i * 4 + 0x28);
}
