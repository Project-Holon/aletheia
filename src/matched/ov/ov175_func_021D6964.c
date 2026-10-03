/*
 * function: func_021D6964
 * address: 0x021D6964
 * packet: pkt_ov175_021D6964
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * func_0203159C's r0 is read after the call, requiring a returning declaration.
 * symbols:
 *   ov067_id 0x00000043 data
 *   ov114_id 0x00000072 data
 *   func_02034AC4 0x02034AC4 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200B358 0x0200B358 thumb
 *   func_0200B1D4 0x0200B1D4 thumb
 *   func_021E5440 0x021E5440 thumb ov177
 *   func_021E5548 0x021E5548 thumb ov177
 *   func_021E567C 0x021E567C thumb ov177
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC74 0x0201EC74 thumb
 *   func_021D9DC8 0x021D9DC8 thumb ov175
 *   func_021E8568 0x021E8568 thumb ov177
 *   func_021E8A3C 0x021E8A3C thumb ov177
 *   func_021D6BF4 0x021D6BF4 thumb ov175
 *   func_021E7D20 0x021E7D20 thumb ov177
 *   func_021E7E0C 0x021E7E0C thumb ov177
 *   func_0201A920 0x0201A920 thumb
 *   func_021DD008 0x021DD008 thumb ov175
 */
typedef unsigned int u32;
extern const char ov067_id[],ov114_id[];
typedef signed int     s32;
typedef unsigned char  u8;
struct GfFont;
struct MsgBank;
struct WordSet;
extern int func_02034AC4(s32 handle);
extern void func_0203064C(u32,u32,u32);
extern u32 *func_0203159C(void *,u32,u32);
extern void func_02082BCC(void *,int,u32);
extern u32 func_02012EBC(u32);
extern u32 func_0200B358(u32);
extern u32 func_0200B1D4(u32,int);
extern int *func_021E5440(unsigned,int);
extern int func_021E5548(int *);
extern u32 func_021E567C(int,int,int);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(int);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC74(u32 n, u32 size, u8 heap);
extern u32 func_021D9DC8(u32,u32,u32,int);
extern u32 func_021E8568(int,int,int,int,u32,u32,int);
extern int *func_021E8A3C(int,int,int);
extern void func_021D6BF4(u32,void *,char *);
extern void **func_021E7D20(void *,void *,unsigned);
extern void func_021E7E0C(u32,u32);
extern u32 func_0201A920(int);
extern void func_021DD008(char *,int);
int func_021D6964(void *sys,int unused,u32 *ctx)
{
    u32 *p;
    func_02034AC4((int)ov067_id); func_02034AC4((int)ov114_id);
    func_0203064C(1,87,0x30000);
    p=func_0203159C(sys,0x270,87); func_02082BCC(p,0,0x270);
    p[0x104/4]=(u32)ctx;
    p[0x108/4]=func_0200B1D4(func_0200B358(func_02012EBC(*(u32 *)ctx[2])),0);
    p[0]=(u32)func_021E5440(1,87);
    p[1]=func_021E567C(func_021E5548((int *)p[0]),0,87);
    p[2]=(u32)func_0201D7EC(0x17,0,0,0,87);
    p[3]=(u32)func_0201D7EC(0x17,3,0,0,87);
    p[4]=func_0201C440(87); p[5]=(u32)func_02045B38(0,2,0xd2,87);
    p[6]=(u32)func_0201EC74(8,0x40,87);
    p[0x34/4]=func_021D9DC8(((u32 *)p[0x104/4])[0xf],*(u32 *)ctx[2],ctx[7],87);
    p[0x2c/4]=func_021E8568(0,15,14,10,p[4],p[2],87);
    p[0x38/4]=(u32)func_021E8A3C((int)p,(int)func_021D6BF4,87);
    p[0x3c/4]=(u32)func_021E8A3C((int)p,0,87);
    p[0x28/4]=(u32)func_021E7D20((void *)func_021E5548((int *)p[0]),(void *)p[1],87);
    func_021E7E0C(p[0x28/4],0);
    p[0xfc/4]=func_0201A920(87); func_021DD008((char *)p[0x34/4],1);
    return 1;
}
