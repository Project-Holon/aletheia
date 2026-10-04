/*
 * function: func_021F000C
 * address:  0x021F000C
 * packet:   pkt_ov035_021F000C
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F000C 0x021F000C thumb
 *   func_02040588 0x02040588 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_020409B4 0x020409B4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_020120F4 0x020120F4 thumb
 *   func_02012944 0x02012944 thumb
 *   func_02008550 0x02008550 thumb
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   func_02049238 0x02049238 arm
 *   d_021F05B0    0x021F05B0 data a4
 *   d_021F05BC    0x021F05BC data ov035 a4
 *   d_021F05C8    0x021F05C8 data ov035 a4
 *   d_021F05E8    0x021F05E8 data ov035 a4
 *   d_021F0608    0x021F0608 data ov035 a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02040588(u8 which, u32 enable);
extern void func_0203FCA0(u32 bgId, const void *tmpl, u32 type);
extern void func_020414EC(u32 i);
extern void func_020409B4(u32 layer);
extern void *func_020490F4(unsigned int id, unsigned int heap);
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012944(void *p);
struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_02049B68(void *h, u32 a, u32 b, u32 c, u32 d, u32 e);
extern u32 func_02049740(void *h, u32 id, u32 layer, u32 ofs, u32 size, u32 heap);
extern void func_02049990(void *h, u32 id, u32 layer, u32 ofs, u32 chrOfs, u32 a5, u32 a6,
    u32 heap);
extern void func_02049238(void *h);

extern const u32 d_021F05B0[];
extern const u32 d_021F05BC[];
extern const u8 d_021F05C8[];
extern const u8 d_021F05E8[];
extern const u8 d_021F0608[];

void func_021F000C(char *p, u32 heap)
{
    int i;
    void *h;
    u32 r;

    for (i = 4; i <= 7; i++)
        func_02040588(i, 0);
    func_0203FCA0(6, d_021F0608, 0);
    func_020414EC(6);
    func_020409B4(6);
    func_02040588(6, 1);
    func_0203FCA0(5, d_021F05C8, 0);
    func_020414EC(5);
    func_020409B4(5);
    func_02040588(5, 1);
    func_0203FCA0(4, d_021F05E8, 0);
    func_020414EC(4);
    func_020409B4(4);
    func_02040588(4, 1);
    h = func_020490F4(0x1E, heap);
    i = func_02008550((const struct Sub0200852CObj *)func_02012944(func_020120F4(*(void **)(p + 4))));
    func_02049B68(h, d_021F05BC[i], 4, 0, 1, heap);
    r = func_02049740(h, d_021F05B0[i], 6, 0, 0, heap);
    *(u32 *)(p + 0x10) = r;
    func_02049990(h, 3, 6, 0, (u16)r, 0, 0, heap);
    func_02049238(h);
}
