/*
 * function: ZUKAN_INFO_RefreshDisplay
 * address: 0x021BBC38
 * packet: pkt_ov206_021BBC38
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZUKAN_INFO_ShowFormPair 0x021BB4E0 thumb ov206
 *   ZUKAN_INFO_CreateSpeciesActor 0x021BBAB0 thumb ov206
 *   ZUKAN_INFO_SetDrawEnable 0x021BBDA8 thumb ov206
 *   ZUKAN_INFO_DrawMainPage 0x021BAA4C thumb ov206
 */
#include "../include/Obj00031.h"
typedef unsigned short u16;
typedef struct S {
    char pad0[8];
    int f8;
    u16 fc;
    u16 fe;
    char pad10[0xd0];
    int fe0;
    char pad[0x190 - 0xe4];
} S;
extern void ZUKAN_INFO_ShowFormPair(char *p, int mode, int which);
typedef unsigned int   u32;
extern void ZUKAN_INFO_CreateSpeciesActor(struct S *p, u32 a, u32 b, u32 idx);
struct State;
extern void ZUKAN_INFO_SetDrawEnable(struct State *p, int v);
extern void ZUKAN_INFO_DrawMainPage(char *p);
void ZUKAN_INFO_RefreshDisplay(S *p)
{
    ZUKAN_INFO_ShowFormPair((char *)p, 6, p->fe0);
    ZUKAN_INFO_CreateSpeciesActor(p, p->fc, p->fe, ((struct Obj00031 *)p)->f190);
    ZUKAN_INFO_SetDrawEnable((struct State *)p, p->f8);
    ZUKAN_INFO_DrawMainPage((char *)p);
}
