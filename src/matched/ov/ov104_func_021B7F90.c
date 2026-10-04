/*
 * function: func_021B7F90
 * address: 0x021B7F90
 * packet: pkt_ov104_021B7F90
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B7DE0 0x021B7DE0 thumb ov104
 *   func_021B7DE4 0x021B7DE4 thumb ov104
 *   func_021B7DE8 0x021B7DE8 thumb ov104
 *   func_021B7DEC 0x021B7DEC thumb ov104
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201C6FC 0x0201C6FC thumb
 *   func_02045738 0x02045738 arm
 *   func_02045740 0x02045740 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201D42C 0x0201D42C thumb
 *   func_0201C724 0x0201C724 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int func_021B7DE0(void *);
extern int func_021B7DE4(void *);
extern int func_021B7DE8(void *);
extern int func_021B7DEC(void *);
struct CharBuf;
struct Descriptor;
struct PrintSys;
struct StrObj;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern u8 func_02045738(struct Descriptor *p);
extern u8 func_02045740(struct Descriptor *p);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern void func_0201C724(int,void *,s16,s16,void *,int,u16);
void func_021B7F90(u8 *p,void *a,int b,u16 c) { int bank; int font; int tag; u16 x; u16 y; bank=func_021B7DE8(a); font=func_021B7DE4(a); tag=func_021B7DE0(a); func_02043B5C(func_02045770(*(void **)p),*(u16 *)(p+0x10)); func_02045CAC((struct MsgBank *)bank,b,*(void **)(p+0xc)); x=func_02045738(*(void **)p)*4; y=func_02045740(*(void **)p)*4; x-=(u16)(func_0201D304(*(void **)(p+0xc),tag,0)/2); y-=(u16)(func_0201D42C(*(void **)(p+0xc),(void *)tag)/2); func_0201C724(font,func_02045770(*(void **)(p+4)),(s16)x,(s16)y,*(void **)(p+0xc),tag,c); p[8]=1; }
