/*
 * function: WORLDTRADE_ADAPTER_ClearWindowScreen
 * address:  0x02202644
 * packet:   pkt_02202644
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   func_02041B6C  0x02041B6C  arm
 *
 * switch on kind
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
struct Descriptor;
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
struct Descriptor;
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_PushTile(u32 index);
extern void func_02041B6C(u32 bit);

void WORLDTRADE_ADAPTER_ClearWindowScreen(u32 a, int kind)
{
    BMP_WIN_ClearScreen((struct Descriptor *)a);
    switch (kind) {
    case 0:
        BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)a));
        break;
    case 1:
        func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)a));
        break;
    }
}

