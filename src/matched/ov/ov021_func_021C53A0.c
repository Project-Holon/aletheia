/*
 * function: SHORTCUT_MENU_InitList
 * address:  0x021C53A0
 * packet:   pkt_ov021_021C53A0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   SHORTCUT_MENU_CreateList  0x021C58CC  thumb  ov021
 */
#include "../include/Obj00874.h"

typedef unsigned short u16;
typedef unsigned char u8;

extern void MI_CpuFill8(void *p, int v, int n);
typedef unsigned int   u32;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *d);
struct Cfg;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern unsigned char BMP_WIN_GetBgLayer(struct Descriptor *d);
extern void func_020409B4(unsigned int index);
extern void SHORTCUT_MENU_CreateList(char *p, u16 a, u16 b, u32 heap);

void SHORTCUT_MENU_InitList(int *a, const u16 *b, u32 c, u32 d, u32 e, u32 f, int *g, u16 h)
{
    int i = 0;
    int r;

    MI_CpuFill8(a, 0, 0x4c);
    a[3] = e;
    a[8] = f;
    ((struct Obj00874 *)a)->f34 = h;
    a[0xe] = c;
    a[0xf] = d;
    for (i = 0; i < 3; i++) {
        a[0xa + i] = g[i];
    }
    r = BMP_WIN_Create(1, 1, 0xc, 0x1e, 0xc, 0xb, 1);
    a[2] = r;
    BMP_WIN_TransferChars((struct Descriptor *)r);
    BMP_WIN_MakeScreen((struct Cfg *)r);
    func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)r));
    a[4] = a[2];
    ((struct Obj00874 *)a)->f14 = 0;
    SHORTCUT_MENU_CreateList((char *)a, b[0], b[1], h);
}
