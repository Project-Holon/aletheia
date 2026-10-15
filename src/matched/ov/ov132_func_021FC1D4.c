/*
 * function: func_021FC1D4
 * address: 0x021FC1D4
 * packet: pkt_ov132_021FC1D4
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   STA_ACTING_GetCharSystem 0x021F9DD4 thumb ov132
 *   func_021F6E78 0x021F6E78 thumb ov112
 *   func_021F6F14 0x021F6F14 thumb ov112
 *   func_021F6F1C 0x021F6F1C thumb ov112
 *   STA_ACTING_SetCharSlot 0x021F9DE8 thumb ov132
 *   STA_ACTING_MarkDirty 0x021F95E8 thumb ov132
 */
#include "../include/Obj10562.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern void *STA_ACTING_GetCharSystem(void *);
extern u8 *func_021F6E78(u8 *p, int v);
extern void func_021F6F14(void *a, char *p, u16 b, u8 c);
extern void func_021F6F1C(void *a, char *p, u32 b, u32 c);
extern void STA_ACTING_SetCharSlot(void *,void *,u8);
extern void STA_ACTING_MarkDirty(char *p);
int func_021FC1D4(int a,char **p)
{
    char *q;
    u32 x,y;
    void *r,*s;
    q=p[0];
    x=VM_GetU32((struct Cursor *)p[1]);
    y=VM_GetU32((struct Cursor *)p[1]);
    r=STA_ACTING_GetCharSystem(((struct Obj10562 *)q)->f34);
    s=func_021F6E78(r,1);
    func_021F6F14(r,s,0x3ff,0x10);
    func_021F6F1C(r,s,y,0);
    STA_ACTING_SetCharSlot(((struct Obj10562 *)q)->f34,s,x);
    STA_ACTING_MarkDirty(((struct Obj10562 *)q)->f34);
    return 0;
}
