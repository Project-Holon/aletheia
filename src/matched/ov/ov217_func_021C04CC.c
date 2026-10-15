/*
 * function: RESEARCH_GRAPH_CreateBmps
 * address:  0x021C04CC
 * packet:   pkt_ov217_021C04CC
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021C37A4  0x021C37A4  data  a4
 *   BMP_Create  0x02043678  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25964.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ent {
    u32 a;
    u32 b;
    u32 c;
    u32 pad[8];
};

extern const struct Ent d_021C37A4[];
struct Bmp;
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);

void RESEARCH_GRAPH_CreateBmps(u8 *p)
{
    int i;
    for (i = 0; i < 2; i++)
        *(int *)(p + i * 4 + 0x3B0) = (int)BMP_Create(d_021C37A4[i].a, d_021C37A4[i].b, d_021C37A4[i].c, ((struct Obj25964 *)p)->f4);
}
