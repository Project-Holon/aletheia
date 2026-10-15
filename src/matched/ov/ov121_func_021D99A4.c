/*
 * function: MYSTERY_UTIL_CreateWindow
 * address: 0x021D99A4
 * packet: pkt_ov121_021D99A4
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: u16 c/d in the function and drawing callee preserve spill and reload order;
 *        heap also stays u16 in both allocation callees to reload each call.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   d_021DFBA0 0x021DFBA0 data a1
 */
#include "../include/Obj01929.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const char d_021DFBA0[];
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *, int, u32);
extern void *STRBUF_Create(u32, u16);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_PushTile(u32);
void *MYSTERY_UTIL_CreateWindow(u32 a, u32 b, u16 c, u16 d, u8 e, u8 f, u8 g, u32 h, u16 heap)
{
    u8 *p;
    void *q;
    p = func_02030734(heap, 0x28, 0, d_021DFBA0, 0x55);
    MI_CpuFill8(p, 0, 0x28);
    ((struct Obj01929 *)p)->f8 = h;
    ((struct Obj01929 *)p)->f14 = b;
    ((struct Obj01929 *)p)->f16 = 0x440;
    ((struct Obj01929 *)p)->f24 = a;
    ((struct Obj01929 *)p)->f10 = STRBUF_Create(0x200, heap);
    q = (void *)BMP_WIN_Create((u8)b, (u16)c, (u16)d, (u8)e, f, g, 1);
    ((struct Obj01929 *)p)->fC = q;
    ((struct Obj01929 *)p)->f0 = q;
    p[4] = 0;
    BMP_Clear(BMP_WIN_GetBmp(q), ((struct Obj01929 *)p)->f16 & 31);
    if (((struct Obj01929 *)p)->f24 == 0) {
        BMP_WIN_TransferChars(((struct Obj01929 *)p)->fC);
        BMP_WIN_MakeScreen(((struct Obj01929 *)p)->fC);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(((struct Obj01929 *)p)->fC));
    }
    return p;
}
