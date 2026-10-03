/*
 * function: func_021C2274
 * address: 0x021C2274
 * packet: pkt_ov099_021C2274
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_021C2370 0x021C2370 thumb ov099
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045334 0x02045334 arm
 */
typedef short s16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct WordSet;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern void func_021C2370(char *, int);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C7A4(void *, s16, s16, void *, void *);
extern void func_02045334(struct Descriptor *d);
void func_021C2274(char *p, void *window, int id)
{
    func_02043B5C(func_02045770(window), 0);
    func_0201DD78(15, 2, 0);
    func_021C2370(p, id - 1);
    func_02045CAC(*(void **)(p + 0xe0), 33, *(void **)(p + 0xf0));
    func_0201F250(*(void **)(p + 0x8b0), *(void **)(p + 0xf8), *(void **)(p + 0xf0));
    func_0201C7A4(func_02045770(window), 2, 8, *(void **)(p + 0xf8), *(void **)(p + 0xe8));
    func_02045334(window);
}
