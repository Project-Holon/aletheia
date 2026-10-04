/*
 * function: func_021BF0A0
 * address: 0x021BF0A0
 * packet: pkt_ov204_021BF0A0
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   site 0x021C0AE4 data a1
 *   func_02030734 0x02030734 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_0203101C 0x0203101C arm
 *   func_02049B40 0x02049B40 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_020457B0 0x020457B0 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02028590 0x02028590 thumb
 *   func_0202EF60 0x0202EF60 thumb
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern const char site[];
extern void *func_02030734(u32,u32,int,const char *,u16);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct GfFont;
struct Obj;
struct Tcbl;
struct U16Vec;
struct WordSet;
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_0201C440(void *p);
extern struct Tcbl *func_0203101C(u32 heap, u16 tag, u32 count, u32 workSize);
extern void func_02049B40(u32,u32,u32,u32,u32,u32);
extern void func_0201F5BC(u32,u32,u32,u32,u32);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern void *func_02028590(u32,u32,u32,u32);
extern struct Obj *func_0202EF60(u32 heap);
char *func_021BF0A0(u32 heap)
{
    char *p;
    void *obj;
    p=func_02030734(heap,72,1,site,129);
    *(u16 *)p=heap;
    *(void **)(p+8)=func_0201EC64(heap);
    *(void **)(p+4)=(void *)func_0201C440((void *)heap);
    *(void **)(p+24)=func_0203101C(*(u16 *)p,*(u16 *)p,2,0);
    func_02049B40(23,5,0,320,32,heap);
    func_0201F5BC(1,7,9,0,heap);
    func_0201F5BC(1,16,8,1,heap);
    *(void **)(p+16)=func_0201D7EC(23,0,1,0,*(u16 *)p);
    *(void **)(p+60)=func_020457B0(1600,*(u16 *)p);
    *(void **)(p+64)=func_020457B0(1600,*(u16 *)p);
    *(void **)(p+56)=(void *)func_020450F0(1,22,13,9,4,10,1);
    func_02043B5C(func_02045770(*(void **)(p+56)),0);
    obj=*(void **)(p+56);
    func_02045334(obj);func_02045374(obj);func_02041B6C(func_02045730(obj));
    *(void **)(p+28)=(void *)func_020450F0(1,1,19,30,4,10,1);
    *(void **)(p+32)=func_02028590(15,1,1,*(u16 *)p);
    *(void **)(p+68)=func_0202EF60(*(u16 *)p);
    return p;
}
