/*
 * function: func_021C5E58
 * address: 0x021C5E58
 * packet: pkt_ov136_021C5E58
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: DIFF
 * note: 2026-10-02 body matches; residue: orig keeps loop copy r6=i at loop top and reloads table pool word per use (not hoisted); loop2 starts from that copy (j=0x1f). tried j=i copy, second extern name g_7A20b
 * symbols:
 *   func_021C5E58 0x021C5E58 thumb
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
extern void func_02045088(u32);
extern u32 func_0201D7EC(int, int, int, int, u32);
extern u32 func_0203101C(u32, u32, u32, u32);
extern u32 func_0201C440(u32);
extern u32 func_020450F0(u32 bg, u32 x, u32 y, u32 w, u32 h, u32 pal, u32 base);
extern u32 func_02045770(u32 win);
extern void func_02043B5C(u32, u32);
extern void func_02045334(u32 v);
extern void func_02045374(u32 v);
extern u32 func_02045730(u32 v);
extern void func_020409B4(u32 v);

void func_021C5E58(u8 *p)
{
    u32 i;
    u32 j;
    struct Slot *sl;
    u32 t;
    func_02045088(0x66);
    *(u32 *)(p + 0x18) = func_0201D7EC(0x17, 0, 0, 0, 0x66);
    *(u32 *)(*(u8 **)(p + 8) + 0x1CC) = func_0203101C(0x66, 0x66, 0x20, 0x20);
    *(u32 *)(*(u8 **)(p + 8) + 0x1C4) = func_0201C440(0x66);
    for (i = 0; i < 0x20; i++) {
        *(u32 *)(*(u8 **)(p + 8) + i * 4 + 0x44) = func_020450F0((u8)g_7A20[i].w0, g_7A20b[i].b4, g_7A20b[i].b5, g_7A20b[i].b6, g_7A20b[i].b7, (u8)g_7A20b[i].h8, 1);
        sl = (struct Slot *)(*(u8 **)(p + 8) + 0xC4);
        sl[i].w = *(u32 *)(*(u8 **)(p + 8) + i * 4 + 0x44);
        j = i;
        sl[i].id = j;
    }
    for (; j < 0x16; j++) {
        func_02043B5C(func_02045770(*(u32 *)(*(u8 **)(p + 8) + j * 4 + 0x44)), 4);
        func_02045334(*(u32 *)(*(u8 **)(p + 8) + j * 4 + 0x44));
    }
    t = *(u32 *)(*(u8 **)(p + 8) + 0x44);
    func_02045334(t);
    func_02045374(t);
    func_020409B4(func_02045730(t));
    t = *(u32 *)(*(u8 **)(p + 8) + 0x48);
    func_02045334(t);
    func_02045374(t);
    func_020409B4(func_02045730(t));
}
