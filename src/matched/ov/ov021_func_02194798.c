/*
 * function: TALKMSGWIN_Delete
 * address:  0x02194798
 * packet:   pkt_ov021_02194798
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TALKMSGWIN_ReleaseEntry  0x02194B3C  thumb  ov021
 *   d_020A814C     0x020A814C  data  a4
 *   d_020A8144     0x020A8144  data  a4
 *   TCBL_Destroy  0x02031140  arm
 *   func_020307B0  0x020307B0  arm
 */
#include "../include/Obj09485.h"

extern void (*d_020A814C)(void *p);
extern void (*d_020A8144)(void *p);

typedef unsigned char  u8;
struct S02031140;
extern void TALKMSGWIN_ReleaseEntry(u8 *p, u8 *e);
extern void TCBL_Destroy(struct S02031140 *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void TALKMSGWIN_Delete(unsigned char *a)
{
    int i;

    for (i = 0; i < 0x20; i++)
        TALKMSGWIN_ReleaseEntry(a, a + 0x18 + i * 0x64);
    d_020A814C(((struct Obj09485 *)a)->fCCC);
    d_020A8144(((struct Obj09485 *)a)->fCC8);
    TCBL_Destroy(((struct Obj09485 *)a)->fC98);
    func_020307B0(a);
}
