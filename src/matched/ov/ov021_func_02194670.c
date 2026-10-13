/*
 * function: TALKMSGWIN_Create
 * address:  0x02194670
 * packet:   pkt_ov021_02194670
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   TCBL_Create  0x0203101C  arm
 *   TALKMSGWIN_InitEntry  0x02194A58  thumb  ov021
 *   TALKMSGWIN_LoadFrameGraphics  0x021954CC  thumb  ov021
 *   sTalkMsgWinFileName     0x021DDAC4  data  a4
 *   d_020A8140     0x020A8140  data  a4
 *   d_020A8148     0x020A8148  data  a4
 */
#include "../include/Obj07451.h"

typedef unsigned short u16;
typedef struct { unsigned w[6]; } T24;

extern int sTalkMsgWinFileName;
extern void *(*d_020A8140)(int, int, int);
extern void *(*d_020A8148)(int, int, int);

extern void *func_02030734(unsigned int heap, unsigned int size, int clear, const char *site, u16 tag);
typedef unsigned int   u32;
struct Tcbl;
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern int TALKMSGWIN_InitEntry(u32 a);
typedef unsigned char  u8;
extern u32 TALKMSGWIN_LoadFrameGraphics(u32 p, u8 *e);

void *TALKMSGWIN_Create(u16 *a)
{
    unsigned char *r6;
    int i;

    r6 = (unsigned char *)func_02030734(*a, 0xcd0, 1, (const char *)&sTalkMsgWinFileName, 0xec);
    *(T24 *)r6 = *(T24 *)a;
    ((struct Obj07451 *)r6)->fC98 = TCBL_Create(*a, *a, 0x20, 0x20);
    for (i = 0; i < 0x20; i++)
        TALKMSGWIN_InitEntry((u32)(r6 + 0x18 + i * 0x64));
    ((struct Obj07451 *)r6)->fCC8 = d_020A8140(0x20, 0, 0);
    ((struct Obj07451 *)r6)->fCCC = d_020A8148(0x20, 0, 0);
    ((struct Obj07451 *)r6)->fC9C = TALKMSGWIN_LoadFrameGraphics((u32)r6, r6) >> 5;
    return r6;
}
