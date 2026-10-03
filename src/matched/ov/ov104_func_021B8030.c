/*
 * function: func_021B8030
 * address: 0x021B8030
 * packet: pkt_ov104_021B8030
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
 *   func_0201F02C 0x0201F02C thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02045808 0x02045808 arm
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
struct MsgBank;
struct U16Vec;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201C6FC(int,void *,s16,s16,void *,int);
extern void func_0201F02C(int,int,void *);
extern void *func_02045EC0(int,int);
extern void func_0201F250(int,void *,void *);
extern void func_02045808(struct U16Vec *vec);
void func_021B8030(u8 *p,void *a,int b,u8 *c,s16 x,s16 y) { int set; int bank; void *text; int font; int tag; func_02043B5C(func_02045770(*(void **)p),*(u16 *)(p+0x10)); set=func_021B7DEC(a); bank=func_021B7DE8(a); func_0201F02C(set,0,c+0xc); text=func_02045EC0(bank,b); func_0201F250(set,*(void **)(p+0xc),text); func_02045808(text); font=func_021B7DE4(a); tag=func_021B7DE0(a); func_0201C6FC(font,func_02045770(*(void **)(p+4)),x,y,*(void **)(p+0xc),tag); p[8]=1; }
