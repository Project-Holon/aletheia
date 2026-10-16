/*
 * function: ZUKAN_INFO_ShowFormPair
 * address: 0x021BB4E0
 * packet: pkt_ov206_021BB4E0
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKE_PERSONAL_GetParam 0x0201AE1C thumb
 *   ZUKAN_INFO_LayoutFormPair 0x021BB534 thumb ov206
 *   ZUKAN_INFO_LayoutFormPairEx 0x021BB79C thumb ov206
 *   ZUKAN_INFO_DisableOtherRows 0x021BB980 thumb ov206
 */
#include "../include/Obj25405.h"
typedef unsigned int   u32;
struct Personal;
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);
extern void ZUKAN_INFO_LayoutFormPair(char *,int,int,int);
extern void ZUKAN_INFO_LayoutFormPairEx(char *,int,int,int,int);
struct State;
extern void ZUKAN_INFO_DisableOtherRows(struct State *p);
void ZUKAN_INFO_ShowFormPair(char *p,int mode,int which)
{
    int mon=((struct Obj25405 *)p)->f26C;
    unsigned char first=POKE_PERSONAL_GetParam((const struct Personal *)mon,6);
    unsigned char second=POKE_PERSONAL_GetParam((const struct Personal *)mon,7);
    if(first==second) second=17;
    if(mode==6) ZUKAN_INFO_LayoutFormPair(p,first,second,which);
    else ZUKAN_INFO_LayoutFormPairEx(p,first,second,mode,which);
    ZUKAN_INFO_DisableOtherRows((struct State *)p);
}
