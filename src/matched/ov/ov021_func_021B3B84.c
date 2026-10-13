/*
 * function: SCRCMD_PROC_FLD_FreeShopResources
 * address:  0x021B3B84
 * packet:   pkt_ov021_021B3B84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_PROC_FLD_FreeShopResources 0x021B3B84 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 */
#include "../include/Obj03599.h"

struct Rec;
struct S02031140;
struct U16Vec;
struct WordSet;
extern void TCBL_Destroy(struct S02031140 *p);
typedef unsigned int   u32;
extern u32 func_0201ED04(struct WordSet *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 MSGDATA_Delete(struct Rec *rec);

void SCRCMD_PROC_FLD_FreeShopResources(char *p)
{
    TCBL_Destroy(((struct Obj03599 *)p)->f1B4);
    func_0201ED04(((struct Obj03599 *)p)->f190);
    STRBUF_Delete(((struct Obj03599 *)p)->f19C);
    STRBUF_Delete(((struct Obj03599 *)p)->f198);
    STRBUF_Delete(((struct Obj03599 *)p)->f1A0);
    STRBUF_Delete(((struct Obj03599 *)p)->f194);
    MSGDATA_Delete(((struct Obj03599 *)p)->f188);
    MSGDATA_Delete(((struct Obj03599 *)p)->f18C);
}
