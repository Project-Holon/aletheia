/*
 * function: func_021B6E74
 * address: 0x021B6E74
 * packet: pkt_ov133_021B6E74
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MUSICAL_MCSS_CreateRenderObj 0x021F5164 thumb ov112
 *   MUSICAL_MCSS_SetRenderFieldA 0x021F5438 thumb ov112
 *   MUSICAL_MCSS_SetRenderFieldB 0x021F5444 thumb ov112
 *   MUSICAL_MCSS_SetupRenderObj 0x021F5204 thumb ov112
 *   MUSICAL_MCSS_TickAnim 0x021F51E8 thumb ov112
 *   MUSICAL_MCSS_DrawRenderObj 0x021F51F4 thumb ov112
 *   MUSICAL_MCSS_GetRenderFlags 0x021F545C thumb ov112
 *   MUSICAL_MCSS_GetRenderPos 0x021F5350 thumb ov112
 */
#include "../include/Obj02852.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *MUSICAL_MCSS_CreateRenderObj(u32 heap);
extern void MUSICAL_MCSS_SetRenderFieldA(void **p, int b);
extern void MUSICAL_MCSS_SetRenderFieldB(u8 *, int);
extern u8 *MUSICAL_MCSS_SetupRenderObj(u8 *, void *, int);
extern void MUSICAL_MCSS_TickAnim(u8 *);
extern void MUSICAL_MCSS_DrawRenderObj(void **p);
extern u8 *MUSICAL_MCSS_GetRenderFlags(u8 *p);
extern void MUSICAL_MCSS_GetRenderPos(int *p, int *q);
void func_021B6E74(u8 *p)
{
    int v[3];
    int *q;
    *(u8 * *)&((struct Obj02852 *)p)->f187C = MUSICAL_MCSS_CreateRenderObj(((struct Obj02852 *)p)->f0);
    MUSICAL_MCSS_SetRenderFieldA((void **)(*(u8 * *)&((struct Obj02852 *)p)->f187C), 0x50000);
    MUSICAL_MCSS_SetRenderFieldB(*(u8 * *)&((struct Obj02852 *)p)->f187C, 0x3fe0);
    *(u8 * *)&((struct Obj02852 *)p)->f1880 = MUSICAL_MCSS_SetupRenderObj(*(u8 * *)&((struct Obj02852 *)p)->f187C, (*(void ***)(p + 4))[1], 0);
    MUSICAL_MCSS_TickAnim(*(u8 * *)&((struct Obj02852 *)p)->f187C);
    MUSICAL_MCSS_DrawRenderObj((void **)(*(u8 * *)&((struct Obj02852 *)p)->f187C));
    q = (int *)MUSICAL_MCSS_GetRenderFlags(*(u8 * *)&((struct Obj02852 *)p)->f1880);
    v[0] = (0x80000 - q[0]) / 16;
    v[1] = (0xc0000 - (0x70000 - q[1])) / 16;
    v[2] = 0x28000;
    MUSICAL_MCSS_GetRenderPos((int *)(*(u8 * *)&((struct Obj02852 *)p)->f1880), v);
}
