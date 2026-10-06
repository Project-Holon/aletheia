/*
 * function: func_021BAB04
 * address: 0x021BAB04
 * packet: pkt_ov099_021BAB04
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA8D4 0x021BA8D4 thumb ov099
 *   func_021BA8BC 0x021BA8BC thumb ov099
 *   func_020450F0 0x020450F0 arm
 *   func_02049B40 0x02049B40 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_020456F8 0x020456F8 arm
 *   func_02045374 0x02045374 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   func_0201DD68 0x0201DD68 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045334 0x02045334 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Descriptor;
struct Cfg;
struct CharBuf;
struct MsgBank;
struct WordSet;
extern void func_021BA8D4(void *);
extern int func_021BA8BC(void *);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *,u8);
extern void func_020456F8(struct Descriptor *);
extern void func_02045374(struct Cfg *);
extern void func_0201F73C(void *,int,int,int);
extern void func_02045CAC(struct MsgBank *,u32,void *);
extern void func_0201F250(struct WordSet *,void *,void *);
extern void func_0201DD68(void);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
extern void func_02045334(struct Descriptor *);
#define P(k) (*(void **)((u8 *)p+(k)))
void func_021BAB04(void *p, int message)
{
    func_021BA8D4(p);
    P(0x19c)=(void *)func_021BA8BC(P(0x19c));
    P(0x190)=(void *)func_021BA8BC(P(0x190));
    P(0x19c)=(void *)func_020450F0(2,4,4,23,16,15,1);
    func_02049B40(23,5,0,480,32,33);
    func_02043B5C(func_02045770(P(0x19c)),255);
    func_020456F8(P(0x19c));
    func_02045374(P(0x19c));
    func_0201F73C(P(0x19c),1,(u16)*(u32 *)((u8 *)p+0x1334),14);
    func_02045CAC(P(0xe4),message,P(0xf0));
    func_0201F250(P(0xdc),P(0xf4),P(0xf0));
    func_0201DD68();
    func_0201C7A4(func_02045770(P(0x19c)),4,4,P(0xf4),P(0xe8));
    func_02045334(P(0x19c));
}
