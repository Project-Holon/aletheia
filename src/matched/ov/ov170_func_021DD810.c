/*
 * function: BOX2_MAIN_ResetShayminFormInBox
 * address: 0x021DD810
 * packet: pkt_ov170_021DD810
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the repeated third-argument truncations require a u16 extern parameter.
 * symbols:
 *   BOX2_MAIN_GetPartyValueAt 0x021DD25C thumb ov170
 *   BOX2_MAIN_GetMonAt 0x021DD2D0 thumb ov170
 *   BOX2_MAIN_ChangeFormAndRegister 0x021DD6E8 thumb ov170
 *   BOX2_MAIN_RecalcPartyParam 0x021DD8A8 thumb ov170
 *   BOX2_SEQ_ShowSlotIcon 0x021EC48C thumb ov170
 *   BOX2_MAIN_RefreshCurrentBoxMonInfo 0x021DEFEC thumb ov170
 */
#include "../include/Obj00000.h"
extern unsigned BOX2_MAIN_GetPartyValueAt(void ***,unsigned short,unsigned short,unsigned,unsigned);
extern int BOX2_MAIN_GetMonAt(void ***p, int a, unsigned b);
extern void BOX2_MAIN_ChangeFormAndRegister(void **,void *,unsigned);
typedef unsigned int   u32;
extern void BOX2_MAIN_RecalcPartyParam(void **pp, u32 idx);
extern void BOX2_SEQ_ShowSlotIcon(unsigned char *p, int box, int pos, int win);
extern void BOX2_MAIN_RefreshCurrentBoxMonInfo(char *p, int b);
void BOX2_MAIN_ResetShayminFormInBox(unsigned char *p,unsigned a,unsigned b,unsigned box)
{
    if(a<30 && b<30) return;
    if(a>=30 && b>=30) return;
    if(a>=30) a=b;
    if(BOX2_MAIN_GetPartyValueAt((void ***)p,a,box,5,0)!=492) return;
    if(BOX2_MAIN_GetPartyValueAt((void ***)p,a,box,0x6f,0)==0) return;
    BOX2_MAIN_ChangeFormAndRegister((void **)p,(void *)BOX2_MAIN_GetMonAt((void ***)p,box,a),0);
    BOX2_MAIN_RecalcPartyParam((void **)p,a);
    if(box==p[0x14])
        BOX2_SEQ_ShowSlotIcon(p,box,a,*(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C+a+0x3dd2));
    if(p[0x16]==a) BOX2_MAIN_RefreshCurrentBoxMonInfo((char *)p,a);
}
