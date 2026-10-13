/*
 * function: BSUBWAY_RECORD_LIST_ShowPage
 * address: 0x021BA438
 * packet: pkt_ov069_021BA438
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two bytes of alignment padding follow.
 * lever: Inline the getter result into the sum; a named result reverses
 * the final adds operands (one concrete byte).
 * symbols:
 *   BSUBWAY_RECORD_LIST_UpdateArrowVisibility 0x021BA384 thumb ov069
 *   BSUBWAY_RECORD_LIST_DrawPageRows 0x021BA480 thumb ov069
 *   func_020260E0 0x020260E0 thumb
 *   BSUBWAY_RECORD_LIST_ShowRecordDetails 0x021B9FF0 thumb ov069
 */
#include "../include/Obj00432.h"
extern void BSUBWAY_RECORD_LIST_UpdateArrowVisibility(char *o, int i, int n);
struct Obj;
struct Rec;
extern void BSUBWAY_RECORD_LIST_DrawPageRows(struct Obj *o);
typedef unsigned char  u8;
struct Sound;
extern u8 func_020260E0(struct Sound *obj);
extern void BSUBWAY_RECORD_LIST_ShowRecordDetails(char *p, struct Rec *tbl, int idx);
void BSUBWAY_RECORD_LIST_ShowPage(char *p, int i)
{
    ((struct Obj00432 *)p)->f160 = i;
    BSUBWAY_RECORD_LIST_UpdateArrowVisibility(p, i, ((struct Obj00432 *)p)->f162);
    BSUBWAY_RECORD_LIST_DrawPageRows((struct Obj *)p);
    BSUBWAY_RECORD_LIST_ShowRecordDetails(p, ((struct Obj00432 *)p)->f8, ((struct Obj00432 *)p)->f160 * 10 + func_020260E0(((struct Obj00432 *)p)->f14C));
}
