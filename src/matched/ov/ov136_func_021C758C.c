/*
 * function: MB_SEQ_ReloadMailList
 * address: 0x021C758C
 * packet: pkt_ov136_021C758C
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * MB_SEQ_ReturnMailItemToBag 0x021C73C8 thumb ov136
 * MB_SEQ_DeleteSelectedMail 0x021C7420 thumb ov136
 * MB_SEQ_FreeMails 0x021C5BE0 thumb ov136
 * MB_SEQ_CollectMails 0x021C5B40 thumb ov136
 * MB_SEQ_SetActorVisible 0x021C66B8 thumb ov136
 * MB_SEQ_DrawPage 0x021C5C00 thumb ov136
 * MB_SEQ_PrintMenuMessage 0x021C630C thumb ov136
 * MB_SEQ_SetMessageWait 0x021C71A8 thumb ov136
 *   BGWINFRM_HideFrame  0x0202CC70  thumb  arm9
 */
#include "../include/Obj00127.h"
#include "../include/Obj23656.h"
#include "../include/Obj23657.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct WinMgr;
extern void MB_SEQ_ReturnMailItemToBag(u8 *p);
extern void MB_SEQ_DeleteSelectedMail(u8 *p);
extern void MB_SEQ_FreeMails(u8 *p);
extern void MB_SEQ_CollectMails(u8 *p);
extern void MB_SEQ_DrawPage(u8 *p);
extern void MB_SEQ_SetActorVisible(u8 *p, int i, u32 v);
extern void BGWINFRM_HideFrame(struct WinMgr *mgr, u32 idx);
extern void MB_SEQ_PrintMenuMessage(u8 *p, unsigned int i);
extern int MB_SEQ_SetMessageWait(char *p, int v, int w);
void MB_SEQ_ReloadMailList(u8 *p)
{
    u16 n;
    MB_SEQ_ReturnMailItemToBag(p); MB_SEQ_DeleteSelectedMail(p); MB_SEQ_FreeMails(p); MB_SEQ_CollectMails(p);
    if(((struct Obj23656 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->f2FC<=10) {
        MB_SEQ_SetActorVisible(((struct Obj00127 *)p)->f8,0,0);
        MB_SEQ_SetActorVisible(((struct Obj00127 *)p)->f8,1,0);
    }
    n=((struct Obj23657 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->f2FE;
    if(((struct Obj00127 *)p)->f1C>n) { ((struct Obj00127 *)p)->f1C=n; p[30]=0; }
    MB_SEQ_DrawPage(p);
    BGWINFRM_HideFrame(**(void ** *)&((struct Obj00127 *)p)->f8,10);
    MB_SEQ_PrintMenuMessage(p,1);
    MB_SEQ_SetMessageWait((char *)p,1,18);
}
