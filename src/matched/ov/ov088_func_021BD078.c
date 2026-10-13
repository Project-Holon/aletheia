/*
 * function: STARTMENU_SaveEraseCreateWindow
 * address:  0x021BD078
 * packet:   pkt_ov088_021BD078
 * region:   ov088
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: the extent runs two bytes long (trailing padding pair).
 *
 * symbols:
 *   BMP_WIN_Init  0x02045088  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   func_02049B40  0x02049B40  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void BMP_WIN_Init(u16 heapId);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

void STARTMENU_SaveEraseCreateWindow(int *p)
{
    int h = 0x81;
    int w = 0x1e;
    BMP_WIN_Init(0x81);
    p[7] = BMP_WIN_Create(0, 1, 0x13, w, 4, 0xf, 1);
    func_0201F5BC(0, 1, 0xe, 0, h);
    func_02049B40(0x17, 5, 0, w << 4, 0x20, h);
}
