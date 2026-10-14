/*
 * function: MB_SEQ_DrawPage
 * address: 0x021C5C00
 * packet: pkt_ov136_021C5C00
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BGWINFRM_HideFrame 0x0202CC70 thumb
 *   BGWINFRM_ShowFrame 0x0202CC58 thumb
 *   MB_SEQ_DrawMailEntry 0x021C6028 thumb ov136
 */
#include "../include/Obj03302.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct WinMgr;
extern void BGWINFRM_HideFrame(struct WinMgr *mgr, u32 idx);
extern void BGWINFRM_ShowFrame(struct WinMgr *mgr, u32 idx);
extern void MB_SEQ_DrawMailEntry(u8 *p, u32 a1, int idx, int sel);
void MB_SEQ_DrawPage(u8 *p)
{
    u16 idx;
    u8 *row;
    u16 offset;
    u16 i;
    idx = 0;
    offset = 10 * ((struct Obj03302 *)p)->f1C;
    row = *(u8 * *)&((struct Obj03302 *)p)->f8+0x2e8+offset;
    offset += 2;
    for (i=0;i<10;i++) {
        if(row[i]==255) BGWINFRM_HideFrame(**(void ** *)&((struct Obj03302 *)p)->f8,idx);
        else {
            MB_SEQ_DrawMailEntry(p,idx,offset,row[i]);
            BGWINFRM_ShowFrame(**(void ** *)&((struct Obj03302 *)p)->f8,idx);
        }
        offset++;
        idx++;
    }
}
