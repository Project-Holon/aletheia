/*
 * function: func_021BB2B0
 * address:  0x021BB2B0
 * packet:   pkt_ov099_021BB2B0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02009864  0x02009864  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   func_021BB528  0x021BB528  thumb  ov099
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 */
#include "../include/Obj06353.h"

typedef unsigned char u8;

typedef unsigned int   u32;
struct CharBuf;
struct Descriptor;
struct Sub020097BCObj;
extern u32 func_02009864(const struct Sub020097BCObj *obj, u32 i, u32 field);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void func_021BB528(char *p, int v);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);

void func_021BB2B0(char *p, int v)
{
    func_02009864(((struct Obj06353 *)p)->f4, ((struct Obj06353 *)p)->f8ED - 1, 9);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj06353 *)p)->f958), 0);
    func_021BB528(p, v);
    BG_SYS_SetSubPlaneVisible(2, 0);
    BG_SYS_SetSubPlaneVisible(8, 1);
}
