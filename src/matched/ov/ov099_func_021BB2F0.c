/*
 * function: func_021BB2F0
 * address:  0x021BB2F0
 * packet:   pkt_ov099_021BB2F0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02009864  0x02009864  thumb
 *   func_02040AF0  0x02040AF0  arm
 *   func_020414AC  0x020414AC  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_021BB528  0x021BB528  thumb  ov099
 *   func_02041B6C  0x02041B6C  arm
 *   func_02045334  0x02045334  arm
 *   func_02043598  0x02043598  arm
 */

typedef unsigned char u8;

typedef unsigned int   u32;
struct CharBuf;
struct Descriptor;
struct Sub020097BCObj;
extern u32 func_02009864(const struct Sub020097BCObj *obj, u32 i, u32 field);
extern void func_02040AF0(int a, void *b, void *c, int d);
extern void func_020414AC(int a);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_021BB528(char *p, int v);
extern void func_02041B6C(u32 bit);
extern void func_02045334(struct Descriptor *d);
extern void func_02043598(u32 mask, u32 enable);

void func_021BB2F0(char *p, int v)
{
    char *q;

    func_02009864(*(void **)(p + 4), *(u8 *)(p + 0x8ED) - 1, 9);
    q = *(char **)(p + 0x8C0);
    func_02040AF0(6, q + 0xC, *(void **)(q + 8), 0);
    func_020414AC(7);
    func_02043B5C(func_02045770(*(void **)(p + 0x95C)), 0);
    func_02043B5C(func_02045770(*(void **)(p + 0x958)), 0);
    func_021BB528(p, v);
    func_02041B6C(7);
    func_02045334(*(void **)(p + 0x95C));
    func_02045334(*(void **)(p + 0x958));
    func_02043598(2, 0);
    func_02043598(8, 1);
}
