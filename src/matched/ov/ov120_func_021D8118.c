/*
 * function: func_021D8118
 * address: 0x021D8118
 * packet: pkt_ov120_021D8118
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: the allocator's first argument is 6, not the 1 its ov120 twins pass:
 *       021D813A `movs r0, #6` is both the multiplier for n*6+1 and r0 at the
 *       blx. The caller narrows n*6+1 to a byte (021D8140/021D8144), so the
 *       allocator's parameters are the u8 of the ov120_func_021D7F5C twin.
 * symbols:
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0204581C 0x0204581C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
extern void *func_020450F0(u8,u8,u8,u8,u8,u8,u8);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Sub0200852CObj;
struct U16Vec;
struct WordSet;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0204581C(struct U16Vec *vec);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern u16 func_02008534(const struct Sub0200852CObj *obj);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F048(struct WordSet *p, u32 i, u32 n);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201DD78(u32,u32,u32);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
int func_021D8118(char *p,void *r,u32 n)
{
    void **t=(void **)(p+0x6c);
    void *q;
    if(!t[n]) t[n]=func_020450F0(6,6,n*6+1,24,4,11,1);
    q=t[n];
    func_02043B5C(func_02045770(q),0);
    func_0204581C(*(void **)(p+0x20));
    func_0204581C(*(void **)(p+0x18));
    func_0201F02C(*(void **)(p+0x10),0,r);
    func_0201EFA4(*(void **)(p+0x10),1,func_02008534(r),5,2,1);
    func_0201F048(*(void **)(p+0x10),2,func_0200856C(r));
    func_02045CAC(*(void **)(p+0xc),28,*(void **)(p+0x20));
    func_0201F250(*(void **)(p+0x10),*(void **)(p+0x18),*(void **)(p+0x20));
    func_0201DD78(15,2,0);
    func_0201C7A4(func_02045770(q),0,0,*(void **)(p+0x18),*(void **)(p+0x14));
    func_02045334(q);
    func_02045374(q);
    return 0;
}
