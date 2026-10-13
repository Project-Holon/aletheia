/*
 * function: BMP_MENULIST_ShiftChars4bpp
 * address:  0x02020A58
 * packet:   pkt_02020A58
 * region:   arm9
 * unit:     no
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_GetPixels  0x020437D4  arm
 *   BMP_GetWidth  0x020437DC  arm
 *   BMP_GetHeight  0x020437E4  arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Bmp;
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern u16 BMP_GetWidth(const struct Bmp *bmp);
extern u16 BMP_GetHeight(const struct Bmp *bmp);

void BMP_MENULIST_ShiftChars4bpp(void *bmp, u32 dir, u32 start, u32 color, u16 size)
{
    u32  wt;
    u32  fill;
    s32  len;
    s32  y;
    s32  src;
    s32  dst;
    u32  t;
    s32  x;
    u8  *buf;

    buf = BMP_GetPixels(bmp);
    fill = (color << 24) | (color << 16) | (color << 8) | color;
    wt = (u32)BMP_GetWidth(bmp) >> 3;
    len = size;
    if (len == 0)
        len = (wt * ((u32)BMP_GetHeight(bmp) >> 3)) << 5;

    switch (dir) {
    case 0:
        for (y = 0; y < len; y += 0x20) {
            t = start;
            for (x = 0; x < 8; x++) {
                dst = y + x * 4;
                src = y + (((t & 7) | (wt * (t & ~7u))) << 2);
                *(u32 *)(buf + dst) =
                    (src < len) ? *(u32 *)(buf + src) : fill;
                t++;
            }
        }
        break;
    case 1:
        buf = buf + (len - 4);
        for (y = 0; y < len; y += 0x20) {
            t = start;
            for (x = 0; x < 8; x++) {
                u32 *q;
                u32  v;
                dst = y + x * 4;
                src = y + (((t & 7) | (wt * (t & ~7u))) << 2);
                if (src < len) {
                    v = *(u32 *)(buf - src);
                    q = (u32 *)(buf - dst);
                } else {
                    q = (u32 *)(buf - dst);
                    v = fill;
                }
                t++;
                *q = v;
            }
        }
        break;
    case 2:
    case 3:
        break;
    }
}

