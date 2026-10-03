/*
 * function: func_021DDC28
 * address: 0x021DDC28
 * packet: pkt_ov171_021DDC28
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
 *   func_0201EE60 0x0201EE60 thumb
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_0201EF34 0x0201EF34 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_021B6AE4 0x021B6AE4 thumb ov067
 *   func_021DD94C 0x021DD94C thumb ov171
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
struct RowBits { u8 pad[0x13]; unsigned char low:6; unsigned char kind:2; };
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct StrObj;
struct U16Vec;
struct WordSet;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201EE60(struct WordSet *p, u32 i, u16 v);
extern void func_0201EE0C(void *,u32,u32,u32,u32,u32);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_021B6AE4(u8 *,u32,u16,u16,u32,u32,u16,u32);
extern void func_021DD94C(int *);
void func_021DDC28(u8 *p)
{
    u8 *row;
    void *s0,*s1,*s2,*s3,*s4,*s5,*s6,*s7;
    u32 width,i;
    row=p+0xc+*(s8 *)(p+0xc5e)*0xbc+*(s8 *)(p+0xc5c)*0x1c;
    func_02043B5C(func_02045770(*(void **)(p+0xb50)),0);
    s0=func_02045EC0(*(void **)(p+0xb60),5);
    func_0201EE60(*(void **)(p+0xb64),0,*(u16 *)(row+0x10));
    func_0201F250(*(void **)(p+0xb64),*(void **)(p+0xb68),s0);
    func_021B6AE4(p+0xb50,*(u32 *)(p+0xb6c),0,0,*(u32 *)(p+0xb68),*(u32 *)(p+0xb58),0x440,0);
    func_02045808(s0);
    if(((struct RowBits *)row)->kind==0) {
      if(*(u16 *)(row+0x10)!=32) {
        s1=func_02045EC0(*(void **)(p+0xb60),6);
        func_021B6AE4(p+0xb50,*(u32 *)(p+0xb6c),64,0,(u32)s1,*(u32 *)(p+0xb58),0xc80,0);
        func_02045808(s1);
      }
    } else if(((struct RowBits *)row)->kind==1) {
      if(*(u16 *)(row+0x10)!=29) {
        s2=func_02045EC0(*(void **)(p+0xb60),7);
        func_021B6AE4(p+0xb50,*(u32 *)(p+0xb6c),64,0,(u32)s2,*(u32 *)(p+0xb58),0x14c0,0);
        func_02045808(s2);
      }
    }
    s3=func_02045EC0(*(void **)(p+0xb60),11);
    width=func_0201D304(s3,*(u32 *)(p+0xb5c),0);
    func_021B6AE4(p+0xb50,*(u32 *)(p+0xb6c),80,4,(u32)s3,*(u32 *)(p+0xb5c),0x440,0);
    func_02045808(s3);
    s4=func_02045EC0(*(void **)(p+0xb60),8);
    func_0201EFA4(*(void **)(p+0xb64),0,row[0x12],3,0,1);
    func_0201F250(*(void **)(p+0xb64),*(void **)(p+0xb68),s4);
    func_021B6AE4(p+0xb50,*(u32 *)(p+0xb6c),width+80,0,*(u32 *)(p+0xb68),*(u32 *)(p+0xb58),0x440,0);
    func_02045808(s4);
    s5=func_02045EC0(*(void **)(p+0xb60),9);
    func_0201EE0C(*(void **)(p+0xb64),0,*(u32 *)row,0,1,2);
    func_0201F250(*(void **)(p+0xb64),*(void **)(p+0xb68),s5);
    func_021B6AE4(p+0xb50,*(u32 *)(p+0xb6c),0,24,*(u32 *)(p+0xb68),*(u32 *)(p+0xb58),0x440,0);
    func_02045808(s5);
    s6=func_02045EC0(*(void **)(p+0xb60),10);
    func_0201EE0C(*(void **)(p+0xb64),0,*(u32 *)(row+4),0,1,2);
    func_0201F250(*(void **)(p+0xb64),*(void **)(p+0xb68),s6);
    func_021B6AE4(p+0xb50,*(u32 *)(p+0xb6c),0,48,*(u32 *)(p+0xb68),*(u32 *)(p+0xb58),0x440,0);
    func_02045808(s6);
    for(i=0;i<4;i++) {
        s7=func_02045EC0(*(void **)(p+0xb60),i+12);
        func_0201EF34(*(void **)(p+0xb64),0,*(u16 *)(row+i*2+0x14));
        func_0201F250(*(void **)(p+0xb64),*(void **)(p+0xb68),s7);
        func_021B6AE4(p+0xb50,*(u32 *)(p+0xb6c),(i&1)*96,(i>>1)*16+88,*(u32 *)(p+0xb68),*(u32 *)(p+0xb58),0x440,0);
        func_02045808(s7);
    }
    func_021DD94C((int *)(p+0xb50));
}
