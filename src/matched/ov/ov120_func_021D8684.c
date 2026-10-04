/*
 * function: func_021D8684
 * address: 0x021D8684
 * packet: pkt_ov120_021D8684
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two zero padding bytes at 021D8782.
 * symbols:
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct WordSet;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
void func_021D8684(char *p,int unused,u32 n)
{
    void *q;
    func_02045CAC(*(void **)(p+12),40,*(void **)(p+24));
    if(!*(void **)(p+0x8c)) *(void **)(p+0x8c)=(void *)func_020450F0(1,21,4,10,2,4,1);
    q=*(void **)(p+0x8c);
    func_02043B5C(func_02045770(q),0);
    func_0201DD78(15,14,0);
    func_0201C7A4(func_02045770(q),0,3,*(void **)(p+24),*(void **)(p+20));
    func_02045334(q);
    func_02045374(q);
    func_0201EFA4(*(void **)(p+16),0,n,5,1,1);
    func_02045CAC(*(void **)(p+12),36,*(void **)(p+32));
    func_0201F250(*(void **)(p+16),*(void **)(p+24),*(void **)(p+32));
    if(!*(void **)(p+0x90)) *(void **)(p+0x90)=(void *)func_020450F0(1,21,6,10,3,11,1);
    q=*(void **)(p+0x90);
    func_02043B5C(func_02045770(q),0);
    func_0201DD78(15,2,0);
    func_0201C7A4(func_02045770(q),0,5,*(void **)(p+24),*(void **)(p+20));
    func_02045334(q);
    func_02045374(q);
}
