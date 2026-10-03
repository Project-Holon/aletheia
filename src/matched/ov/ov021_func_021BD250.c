/*
 * function: func_021BD250
 * address:  0x021BD250
 * packet:   pkt_ov021_021BD250
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned short u16;

typedef struct {
    u16 h0;
    char pad[6];
    void *f8;
} Obj;

typedef unsigned int   u32;
struct Bmp;
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u32 heap);

void func_021BD250(Obj *p)
{
    p->f8 = func_02043678(2, 2, 0x20, p->h0);
}
