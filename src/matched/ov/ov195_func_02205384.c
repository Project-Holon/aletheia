/*
 * function: SHINKA_DEMO_PrintText
 * address:  0x02205384
 * packet:   pkt_02205384
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SHINKA_DEMO_ClearText 0x0220549C thumb ov195
 *   SHINKA_DEMO_BuildString 0x02205620 thumb ov195
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStreamCallBack 0x0201CD10 thumb
 */
#include "../include/Obj01429.h"

typedef unsigned short u16;
typedef unsigned int u32;

extern void SHINKA_DEMO_ClearText(char *, int);
extern u32 SHINKA_DEMO_BuildString(u32, u32, u32, u32, u32, u32, u32);
extern signed char MSG_SPEED_GetWait(void);
typedef signed short   s16;
typedef signed int     s32;
struct Rec;
extern struct Rec *PRINTSYS_PrintStreamCallBack(u32 a0, s16 a1, s16 a2, u32 a3, u32 a4, s32 a5, u32 a6, u32 a7, u32 a8, u16 a9, u32 a10);

void SHINKA_DEMO_PrintText(char *a, u32 b, u32 c, u32 d, u32 k0, u32 v0, u32 k1, u32 v1)
{
    SHINKA_DEMO_ClearText(a, 0xf);
    *(u32 *)&((struct Obj01429 *)a)->f80 = SHINKA_DEMO_BuildString(((struct Obj01429 *)a)->f2, b, c, k0, v0, k1, v1);
    *(u32 *)&((struct Obj01429 *)a)->f64 = (u32)PRINTSYS_PrintStreamCallBack(*(u32 *)&((struct Obj01429 *)a)->f6C, 0, 0, *(u32 *)&((struct Obj01429 *)a)->f80, ((struct Obj01429 *)a)->f8,
                                       MSG_SPEED_GetWait(), ((struct Obj01429 *)a)->f68, 2, ((struct Obj01429 *)a)->f2, 0xf, d);
}
