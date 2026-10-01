/*
 * function: func_021B9B78
 * address: 0x021B9B78
 * packet: pkt_ov218_021B9B78
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012FFC 0x02012FFC thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 * Caller stores the live r0 return of legacy void forwarder 0201CCE4.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
struct CharBuf;
struct Cfg;
struct MsgBank;
struct WordSet;
extern signed char func_02012FFC(void);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *, u8);
extern void func_0201DD78(u32, u32, u32);
extern void func_02045CAC(struct MsgBank *, u32, void *);
extern void func_0201F250(struct WordSet *, void *, void *);
extern u32 func_0201CCE4(u32, u32, u32, u32, u32, u32, u32, u32, u16, u16);
extern void func_0201F73C(void *, int, int, int);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *);
extern u8 func_02045730(struct Descriptor *);
extern void func_02041B6C(u32);
void func_021B9B78(char *p, u32 id)
{
    int value = func_02012FFC();
    struct Descriptor *obj = *(struct Descriptor **)(p + 0x24);
    func_02043B5C(func_02045770(obj), 15);
    func_0201DD78(1, 2, 15);
    func_02045CAC(*(struct MsgBank **)(p + 8), id, *(void **)(p + 0x18));
    func_0201F250(*(struct WordSet **)(p + 0x14), *(void **)(p + 0x1c), *(void **)(p + 0x18));
    *(u32 *)(p + 0x20) = func_0201CCE4((u32)obj, 4, 0, *(u32 *)(p + 0x1c), *(u32 *)(p + 0xc), value, *(u32 *)(p + 4), 65535, *(u16 *)p, 15);
    func_0201F73C(*(void **)(p + 0x24), 2, 1, 15);
    func_02045334(obj);
    func_02045374((struct Cfg *)obj);
    func_02041B6C(func_02045730(obj));
}
