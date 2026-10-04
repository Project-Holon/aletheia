/*
 * function: func_021B7560
 * address: 0x021B7560
 * packet: pkt_ov104_021B7560
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Preserve the visible seventh heap argument to 021B8030 despite its legacy six-argument declaration.
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021B78EC 0x021B78EC thumb ov104
 *   func_021B7D28 0x021B7D28 thumb ov104
 *   func_02012138 0x02012138 thumb
 *   func_021B7DF0 0x021B7DF0 thumb ov104
 *   func_0201F73C 0x0201F73C thumb
 *   func_021B8E90 0x021B8E90 thumb ov104
 *   func_021B8030 0x021B8030 thumb ov104
 *   func_021B7F1C 0x021B7F1C thumb ov104
 *   func_021B80D4 0x021B80D4 thumb ov104
 *   func_021B7E58 0x021B7E58 thumb ov104
 *   func_021B7F80 0x021B7F80 thumb ov104
 *   func_02041F6C 0x02041F6C arm
 *   func_02041FB0 0x02041FB0 arm
 *   func_021B8724 0x021B8724 thumb ov104
 *   func_021B85D8 0x021B85D8 thumb ov104
 *   func_021B8A88 0x021B8A88 thumb ov104
 *   func_021B7974 0x021B7974 thumb ov104
 *   func_021B7DE0 0x021B7DE0 thumb ov104
 *   func_021B7DE4 0x021B7DE4 thumb ov104
 *   func_021B70DC 0x021B70DC thumb ov101
 *   func_021B63CC 0x021B63CC thumb ov101
 *   func_0207D658 0x0207D658 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021B8F08 0x021B8F08 thumb ov104
 *   func_021B817C 0x021B817C thumb ov104
 *   func_021B8198 0x021B8198 thumb ov104
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Obj0203159C;
struct Ctx;
extern void func_0203064C(u32,u32,u32);
extern void *func_0203159C(struct Obj0203159C *,u32,u32);
extern void func_02082BCC(void *,int,int);
extern void func_021B78EC(u8 *,int);
extern void func_021B7D28(u8 *,int,u32);
extern u32 func_02012138(const struct Ctx *);
extern void func_021B7DF0(u8 *,u32,u32,u8,u8,u8,u8,u16);
extern void func_0201F73C(void *,int,u16,int);
extern void func_021B8E90(u8 *,int);
extern void func_021B8030(u8 *,void *,int,u8 *,s16,s16,u16);
extern void func_021B7F1C(u8 *,void *,int,int,s16);
extern void func_021B80D4(u8 *,void *,int);
extern void func_021B7E58(u8 *,u32,u32,u8,u8,u8,u8,u16,u8,u16);
extern void func_021B7F80(u8 *,void *,int);
extern void func_02041F6C(u32,u32,u16);
extern void func_02041FB0(u32,u32,u16);
extern void func_021B8724(u8 *,void *);
extern void func_021B85D8(void *p);
extern void func_021B8A88(u8 *,void *,int,int,int);
extern u32 func_021B7974(u8 *);
extern int func_021B7DE0(void *);
extern int func_021B7DE4(void *);
extern void *func_021B70DC(u32,u32,u16,u16,u8,u32,u32,u32,u16);
extern void func_021B63CC(int *,int);
extern void func_0207D658(u32,int,int);
extern void *func_020056A0(u32,u32,u32);
extern void func_021B8F08(void *,u8 *);
extern void func_021B817C(u8 *,void (*)(u8 *,u16 *));
extern void func_021B8198(u8 *,u16 *);
#define CTX(p) (*(u8 **)((p)+0x8b0))
int func_021B7560(struct Obj0203159C *obj,void *state,u8 *context) {
 u8 *p; u32 bank; int tag; int font;
 func_0203064C(1,0x38,0x20000);
 p=func_0203159C(obj,0x8b4,0x38);
 func_02082BCC(p,0,0x8b4);
 CTX(p)=context;
 func_021B78EC(p,0x38);
 func_021B7D28(p+0xbc,0,0x38);
 if(*(void **)CTX(p)) func_02012138(*(struct Ctx **)CTX(p));
 func_021B7DF0(p+0xcc,5,1,18,30,5,8,0x38);
 func_0201F73C(*(void **)(p+0xcc),0,*(u32 *)p,6);
 func_021B8E90(p+0x7cc,0x38);
 if(*(void **)CTX(p)) func_021B8030(p+0xcc,p+0xbc,0,*(u8 **)(CTX(p)+8),0,0,0x38);
 else func_021B7F1C(p+0xcc,p+0xbc,0,0,0);
 func_021B80D4(p+0x7b0,p,0x38);
 func_021B7E58(p+0x7dc,7,6,3,20,5,8,1,1,0x38);
 func_021B7F80(p+0x7dc,p+0xbc,7);
 func_02041F6C(7,3,0x1000);
 func_02041F6C(7,6,0x1000);
 func_02041FB0(7,9,0x80);
 func_02041FB0(7,12,0x28);
 func_021B7E58(p+0x7f0,2,8,10,16,2,13,0,0,0x38);
 func_021B8724(p+0xe0,*(void **)(CTX(p)+4));
 func_021B85D8(p+0x814);
 func_021B8A88(p+0x278,p,1,0,0);
 bank=func_021B7974(p);
 tag=func_021B7DE0(p+0xbc);
 font=func_021B7DE4(p+0xbc);
 *(void **)(p+0x7ac)=func_021B70DC(2,bank,0,14,13,2,tag,font,0x38);
 func_021B63CC(*(int **)(CTX(p)+4),1);
 func_0207D658(0x04000050,0x22,-8);
 *(void **)(p+0x8a4)=func_020056A0((u32)func_021B8F08,(u32)p,0);
 func_021B817C(p,func_021B8198);
 return 1;
}
