/*
 * function: MB_SEQ_ShowMailDetail
 * address:  0x021C6E64
 * packet:   pkt_ov136_021C6E64
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MB_SEQ_DrawSelectedMail  0x021C5C64  thumb
 *   MB_SEQ_PrintDetailMessage 0x021C6284 thumb
 *   MB_SEQ_ShowMessageWindow 0x021C62BC thumb
 *   MB_SEQ_SetActorVisible 0x021C66B8 thumb
 *   MB_SEQ_SetMessageWait 0x021C71A8 thumb
 *   MB_SEQ_SetButtonsEnabled 0x021C7298 thumb
 */
#include "../include/Obj00127.h"

typedef unsigned char u8;
typedef unsigned int u32;
extern void MB_SEQ_SetActorVisible(u8 *, int, u32);
extern void MB_SEQ_SetButtonsEnabled(void *p, int v);
extern void MB_SEQ_DrawSelectedMail(u8 *);
extern void MB_SEQ_ShowMessageWindow(u8 *);
extern void MB_SEQ_PrintDetailMessage(u8 *);
extern int MB_SEQ_SetMessageWait(char *p, int v, int w);
void MB_SEQ_ShowMailDetail(u8 *p)
{
    MB_SEQ_SetActorVisible(*(u8 * *)&((struct Obj00127 *)p)->f8, 2, 0);
    MB_SEQ_SetButtonsEnabled(*(u8 * *)&((struct Obj00127 *)p)->f8, 1);
    MB_SEQ_DrawSelectedMail(p);
    MB_SEQ_ShowMessageWindow(p);
    MB_SEQ_PrintDetailMessage(p);
    MB_SEQ_SetMessageWait((char *)p, 0, 0xD);
}
