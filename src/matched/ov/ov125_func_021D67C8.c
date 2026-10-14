/*
 * function: GDS_RAP_RequestUploadEntry
 * address: 0x021D67C8
 * packet: pkt_ov125_021D67C8
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GDS_RAP_IsIdle 0x021D730C thumb ov125
 */
#include "../include/Obj14003.h"
typedef struct { int words[32]; } Block128;
typedef struct { int words[108]; } Block432;
extern int GDS_RAP_IsIdle(char *);
int GDS_RAP_RequestUploadEntry(char *p, const Block128 *a, const Block432 *b)
{
    if (!GDS_RAP_IsIdle(p)) return 0;
    *(Block128 *)(p + 0x174) = *a;
    *(Block432 *)(p + 0x1f4) = *b;
    p[0x401] = 0x3c;
    ((struct Obj14003 *)p)->f3D8 = 0x5208;
    return 1;
}
