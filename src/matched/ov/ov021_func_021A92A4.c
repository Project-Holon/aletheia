/*
 * function: FIELD_MENU_LoadScreen
 * address:  0x021A92A4
 * packet:   pkt_ov021_021A92A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 *
 * symbols:
 *   func_020275E4  0x020275E4  thumb
 *   func_02027624  0x02027624  thumb
 *   func_02027628  0x02027628  thumb
 *   func_0202762C  0x0202762C  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049658  0x02049658  arm
 *   ARC_UTIL_LoadPaletteDataFromHandle  0x02049EF4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   BG_SYS_DrawTileEx  0x020410D0  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Scr {
    u8 pad00[0xC];
    u16 data[0x300];
};

extern u32 func_020275E4(void);
extern u32 func_02027624(void);
extern u32 func_02027628(void);
extern u32 func_0202762C(void);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049B68(void *o, u32 a, u32 b, u32 c, u32 d, u32 e);
extern void func_02049658(void *o, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void *ARC_UTIL_LoadPaletteDataFromHandle(void *o, u32 a, u32 b, void **out, u32 e);
extern void ARC_TOOL_DeleteHandle(void *o);
extern void BG_SYS_DrawTileEx(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_02041B6C(u8 a);
extern u32 func_020307B0(void *p);

void FIELD_MENU_LoadScreen(u32 a, u32 b)
{
    struct Scr *ptr;
    void *h;
    int i;
    u16 *d;
    void *o;

    o = func_020490F4(func_020275E4(), a);
    func_02049B68(o, func_02027624(), 4, 0x60, 0x20, a);
    func_02049658(o, func_02027628(), b, 0x80, 0, 0, a);
    h = ARC_UTIL_LoadPaletteDataFromHandle(o, func_0202762C(), 0, (void **)&ptr, a);
    ARC_TOOL_DeleteHandle(o);
    d = ptr->data;
    for (i = 0; i < 0x300; i++) {
        d[i] = (d[i] + 0x80) | 0x3000;
    }
    BG_SYS_DrawTileEx((u8)b, 0, 0x15, 0x20, (u32)3, (u32)ptr->data, (u32)0, (u32)0x15, (u32)0x20, (u32)0x18);
    func_02041B6C(b);
    func_020307B0(h);
}
