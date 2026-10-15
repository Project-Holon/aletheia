/*
 * function: STAFF_ROLL_InitWindows
 * address: 0x021B9D34
 * packet: pkt_ov181_021B9D34
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Padding: two zero bytes at 0x021B9DAE, then the next function.
 * symbols:
 *   BMP_WIN_Init 0x02045088 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 */
#include "../include/Obj03327.h"
extern void BMP_WIN_Init(unsigned short);
extern unsigned BMP_WIN_Create(unsigned, unsigned, unsigned, unsigned, unsigned char, unsigned char, unsigned char);
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *);
typedef unsigned char  u8;
struct Cfg;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_PushTile(unsigned);
void STAFF_ROLL_InitWindows(char *p)
{
    unsigned h;
    BMP_WIN_Init(0x8E);
    ((struct Obj03327 *)p)->f2BC = BMP_WIN_Create(1, 0, 0, 0x20, 0x19, 0xF, 1);
    ((struct Obj03327 *)p)->f2C4 = BMP_WIN_Create(5, 0, 0, 0x20, 0x1C, 0xF, 1);
    h = ((struct Obj03327 *)p)->f2BC;
    BMP_WIN_TransferChars((struct Descriptor *)h);
    BMP_WIN_MakeScreen((struct Cfg *)h);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)h));
    h = ((struct Obj03327 *)p)->f2C4;
    BMP_WIN_TransferChars((struct Descriptor *)h);
    BMP_WIN_MakeScreen((struct Cfg *)h);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)h));
}
