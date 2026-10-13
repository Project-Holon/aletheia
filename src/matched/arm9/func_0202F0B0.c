/*
 * function: TIME_ICON_Update
 * address:  0x0202F0B0
 * packet:   pkt_0202EF98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_GetBmp   0x02045770  arm
 *   BMP_Clear   0x02043B5C  arm
 *   BMP_Blit   0x020439A0  arm
 *   BMP_WIN_TransferChars   0x02045334  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TIME_ICON_Update.c \
 *       --func TIME_ICON_Update --addr 0x0202F0B0 --cc 1.1p1 --thumb
 */
#include "../include/Obj01310.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
struct Bmp;
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_Blit(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern void BMP_WIN_TransferChars(struct Descriptor *a);

void TIME_ICON_Update(u8 *p)
{
    if (((struct Obj01310 *)p)->f18 == 0)
        return;

    if (((struct Obj01310 *)p)->f13 == 0) {
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj01310 *)p)->f8)), ((struct Obj01310 *)p)->f12);
        BMP_Blit((struct Bmp *)(((struct Obj01310 *)p)->fC), (struct Bmp *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj01310 *)p)->f8)), 0,
                      (u32)((struct Obj01310 *)p)->f15 << 4, 0, 0, 0x10, 0x10, 0);
        BMP_WIN_TransferChars((struct Descriptor *)((struct Obj01310 *)p)->f8);

        ((struct Obj01310 *)p)->f13 = ((struct Obj01310 *)p)->f14;
        ((struct Obj01310 *)p)->f15 = ((struct Obj01310 *)p)->f15 + 1;

        if (((struct Obj01310 *)p)->f15 == 8)
            ((struct Obj01310 *)p)->f15 = 0;
    } else {
        ((struct Obj01310 *)p)->f13 = ((struct Obj01310 *)p)->f13 - 1;
    }
}
