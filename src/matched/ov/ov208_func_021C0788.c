/*
 * function: ov208_func_021C0788
 * address:  0x021C0788
 * packet:   pkt_ov208_021C0788
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   data_021C8570  0x021C8570  data
 *   data_021C85A4  0x021C85A4  data
 *   func_02049B90  0x02049B90  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_02045B38  0x02045B38  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;
typedef int            s32;

struct WinCfg {
    u8 bg;
    u8 x;
    u8 y;
    u8 w;
    u8 h;
    u8 pal;
    u8 base;
};

struct WinCfg2 {
    struct WinCfg e[2];
};

struct WinCfg4 {
    struct WinCfg e[4];
};

extern const struct WinCfg2 data_021C8570;
extern const struct WinCfg4 data_021C85A4;

extern void func_02049B90(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *func_02045770(struct Descriptor *win);
extern void func_02043B5C(u32 a, u32 b);
extern void func_02045334(struct Descriptor *win);
extern u32  func_02045B38(u32 resident, u32 arc, u32 file, u32 heap);

#define W(o) (*(u32 *)(p + (o)))

void ov208_func_021C0788(u16 *heap, u8 *p, int key)
{
    struct WinCfg2 a;
    struct WinCfg4 b;
    u8 i;

    a = data_021C8570;
    b = data_021C85A4;
    func_02049B90(0x17, 5, 4, 0, 0x100, 0x20, *heap);
    func_02049B90(0x17, 5, 0, 0, 0, 0x20, *heap);
    for (i = 0; i < 2; i++) {
        *(u32 *)(p + i * 4 + 0x44) = func_020450F0(a.e[i].bg, a.e[i].x, a.e[i].y, a.e[i].w, a.e[i].h, a.e[i].pal, a.e[i].base);
        func_02043B5C((u32)func_02045770((struct Descriptor *)*(u32 *)(p + i * 4 + 0x44)), 0);
        func_02045334((struct Descriptor *)*(u32 *)(p + i * 4 + 0x44));
    }
    for (i = 0; i < 4; i++) {
        *(u32 *)(p + i * 4 + 0x14) = func_020450F0(b.e[i].bg, b.e[i].x, b.e[i].y, b.e[i].w, b.e[i].h, b.e[i].pal, b.e[i].base);
        func_02043B5C((u32)func_02045770((struct Descriptor *)*(u32 *)(p + i * 4 + 0x14)), 0);
        func_02045334((struct Descriptor *)*(u32 *)(p + i * 4 + 0x14));
    }
    W(0xc) = func_02045B38(0, 2, 0xea, *heap);
    W(0x10) = func_02045B38(0, 2, 0x59, *heap);
}
