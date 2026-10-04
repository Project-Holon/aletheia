/*
 * function: func_021D5CCC
 * address: 0x021D5CCC
 * packet: pkt_ov115_021D5CCC
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes at 0x021D5D3A follow the return.
 * symbols:
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
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
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201C7D0(void *,s16,s16,void *,void *,u16);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32);
void func_021D5CCC(u8 *p, u32 n) {
    void *w;
    if (*(void **)(p+0x34)==0) *(void **)(p+0x34)=(void *)func_020450F0(1,4,7,24,2,11,1);
    w=*(void **)(p+0x34);
    func_02043B5C(func_02045770(w),0);
    func_02045CAC(*(void **)(p+0x1c),n,*(void **)(p+0x28));
    func_0201C7D0(func_02045770(w),0,0,*(void **)(p+0x28),*(void **)(p+0x24),0x3cc0);
    func_02045334(w);
    func_02045374(w);
    func_02041B6C(1);
}
