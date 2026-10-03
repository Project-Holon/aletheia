/*
 * function: func_021DD964
 * address: 0x021DD964
 * packet: pkt_ov171_021DD964
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02045748 0x02045748 arm
 *   func_021B6AE4 0x021B6AE4 thumb ov067
 *   func_021DD94C 0x021DD94C thumb ov171
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u8 func_02045748(struct Descriptor *p);
extern void func_021B6AE4(u8 *,u32,u16,u16,u32,u32,u16,u32);
extern void func_021DD94C(int *);
void func_021DD964(u8 *p)
{
    u32 offset;
    u8 *group;
    void *s0,*s1,*s2;
    u32 width;
    offset=*(s8 *)(p+0xc5e)*0xbc;
    group=p+0xc;
    func_02043B5C(func_02045770(*(void **)(p+0xb48)),0);
    if(*(u16 *)(*(u8 **)p+4)==0) {
        s0=func_02045EC0(*(void **)(p+0xb60),0);
        func_021B6AE4(p+0xb48,*(u32 *)(p+0xb6c),0,0,(u32)s0,*(u32 *)(p+0xb58),0x440,0);
        func_02045808(s0);
    } else {
        s1=func_02045EC0(*(void **)(p+0xb60),1);
        func_0201EFA4(*(void **)(p+0xb64),0,*(u16 *)(group+offset+0xba),4,0,1);
        func_0201F250(*(void **)(p+0xb64),*(void **)(p+0xb68),s1);
        func_021B6AE4(p+0xb48,*(u32 *)(p+0xb6c),0,0,*(u32 *)(p+0xb68),*(u32 *)(p+0xb58),0x440,0);
        func_02045808(s1);
    }
    s2=func_02045EC0(*(void **)(p+0xb60),2);
    func_0201EFA4(*(void **)(p+0xb64),0,*(u32 *)(group+offset+0xa8),2,2,1);
    func_0201EFA4(*(void **)(p+0xb64),1,*(u32 *)(group+offset+0xac),2,2,1);
    func_0201EFA4(*(void **)(p+0xb64),2,*(u32 *)(group+offset+0xb0),2,2,1);
    func_0201F250(*(void **)(p+0xb64),*(void **)(p+0xb68),s2);
    width=func_02045748(*(void **)(p+0xb48));
    func_021B6AE4(p+0xb48,*(u32 *)(p+0xb6c),width<<3,0,*(u32 *)(p+0xb68),*(u32 *)(p+0xb58),0x14c0,1);
    func_02045808(s2);
    func_021DD94C((int *)(p+0xb48));
}
