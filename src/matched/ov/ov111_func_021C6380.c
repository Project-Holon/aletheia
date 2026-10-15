/*
 * function: VIEWER_TEXT_PrintColorAt
 * address:  0x021C6380
 * packet:   pkt_ov111_021C6380
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_PrintColor  0x0201C7D0  thumb
 *   d_021C8768     0x021C8768  data  a2
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;

struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_PrintColor(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern const u16 d_021C8768[];

typedef struct {
    u8 pad0[0x31FC];
    void *f31FC;
} Work;

void VIEWER_TEXT_PrintColorAt(void *a, Work *p, int x, int y, void *s, int idx)
{
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(a), x, y, s, p->f31FC, d_021C8768[idx]);
}
