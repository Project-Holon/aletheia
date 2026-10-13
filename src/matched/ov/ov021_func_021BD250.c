/*
 * function: PLACE_NAME_LETTER_CreateBmp
 * address:  0x021BD250
 * packet:   pkt_ov021_021BD250
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_Create  0x02043678  arm  arm9
 */

typedef unsigned short u16;

typedef struct {
    u16 h0;
    char pad[6];
    void *f8;
} Obj;

typedef unsigned int   u32;
struct Bmp;
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);

void PLACE_NAME_LETTER_CreateBmp(Obj *p)
{
    p->f8 = BMP_Create(2, 2, 0x20, p->h0);
}
