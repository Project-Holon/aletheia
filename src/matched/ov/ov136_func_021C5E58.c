/*
 * function: func_021C5E58
 * address: 0x021C5E58
 * packet: pkt_ov136_021C5E58
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lang: c99
 * lever: 021C5EE2 branches to 021C5E9A, after the r6=r4 copy at
 *   021C5E98. The first loop stores zero ids, and a new second loop starts
 *   at zero. Literal zero plus separate loops reproduces that shared r6.
 *   The old j=i inside the loop incorrectly started loop two at 31.
 * symbols:
 *   func_021C5E58 0x021C5E58 thumb ov136
 *   func_02045088 0x02045088 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0203101C 0x0203101C arm
 *   func_0201C440 0x0201C440 thumb
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   g_7A20 0x021C7A20 data
 *   g_7A20b 0x021C7A20 data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ent {
    u32 w0;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    u16 h8;
    u16 pad;
};
struct Slot {
    u32 w;
    u8 id;
    u8 pad[3];
};
extern const struct Ent g_7A20[];
extern const struct Ent g_7A20b[];
extern void func_02045088(u16);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct GfFont;
struct Tcbl;
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct Tcbl *func_0203101C(u32 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_0201C440(void *);
extern u32 func_020450F0(u32 bg, u32 x, u32 y, u32 w, u8 h, u8 pal, u8 base);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 v);
typedef enum { SLOT_ZERO = 0 } SlotIndex;

void func_021C5E58(u8 *p)
{
    u32 i;
    u32 j;
    struct Slot *sl;
    void *t;
    func_02045088(0x66);
    *(void **)(p + 0x18) = func_0201D7EC(0x17, 0, 0, 0, 0x66);
    *(void **)(*(u8 **)(p + 8) + 0x1CC) = func_0203101C(0x66, 0x66, 0x20, 0x20);
    *(u32 *)(*(u8 **)(p + 8) + 0x1C4) = func_0201C440((void *)0x66);
    for (i = 0; i < 0x20; i++) {
        *(u32 *)(*(u8 **)(p + 8) + i * 4 + 0x44) = func_020450F0((u8)g_7A20[i].w0, g_7A20[i].b4, g_7A20[i].b5, g_7A20[i].b6, g_7A20[i].b7, (u8)g_7A20[i].h8, 1);
        sl = (struct Slot *)(*(u8 **)(p + 8) + 0xC4);
        sl[i].w = *(u32 *)(*(u8 **)(p + 8) + i * 4 + 0x44);
        sl[i].id = 0;
    }
    for (j = 0; j < 0x16; j++) {
        func_02043B5C(func_02045770(*(void **)(*(u8 **)(p + 8) + j * 4 + 0x44)), 4);
        func_02045334(*(void **)(*(u8 **)(p + 8) + j * 4 + 0x44));
    }
    t = *(void **)(*(u8 **)(p + 8) + 0x44);
    func_02045334(t);
    func_02045374(t);
    func_020409B4(func_02045730(t));
    t = *(void **)(*(u8 **)(p + 8) + 0x48);
    func_02045334(t);
    func_02045374(t);
    func_020409B4(func_02045730(t));
}
