/*
 * function: OEKAKI_BlitBrush
 * address:  0x02185BBC
 * packet:   pkt_ov023_02185BBC
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   BMP_CreateFromBuffer  0x020436FC  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Blit  0x020439A0  arm
 *   BMP_Delete  0x020437AC  arm
 *
 * Clearing dx/dy before the w/h subtraction is what moves a1 into r0 at
 * entry (t in r1, the bound in r2); clearing it last keeps a1 in r1.
 */

typedef unsigned short u16;
typedef unsigned int   u32;
struct Bmp;
struct Obj020437AC;
extern struct Bmp *BMP_CreateFromBuffer(void *pixels, u32 width, u32 height, u32 depth, u16 heap);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *a);
extern void BMP_Blit(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern void BMP_Delete(struct Obj020437AC *p);

void OEKAKI_BlitBrush(int a0, int a1, int x, int y, int w, int h, int dx, int dy,
                   int mx, int my)
{
    int s;
    int t;

    if (dx < 0) {
        t = -dx;
        if (t > mx)
            t = mx;
        x += t;
        dx = 0;
        w -= t;
    }
    if (dy < 0) {
        t = -dy;
        if (t > my)
            t = my;
        y += t;
        dy = 0;
        h -= t;
    }
    s = (int)BMP_CreateFromBuffer((void *)a1, 8, 8, 0x20, 0x28);
    BMP_Blit((struct Bmp *)s, (struct Bmp *)((int)BMP_WIN_GetBmp((struct Descriptor *)a0)), x, y, dx, dy, w, h, 0);
    BMP_Delete((struct Obj020437AC *)s);
}
