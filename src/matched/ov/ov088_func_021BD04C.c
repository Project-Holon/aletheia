/*
 * function: STARTMENU_SaveEraseFreeResources
 * address:  0x021BD04C
 * packet:   pkt_ov088_021BD04C
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   APP_KEYCURSOR_Delete  0x02028604  thumb
 *   TCBL_Destroy  0x02031140  arm
 *   STRBUF_Delete  0x02045808  arm
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 *   func_020461D4  0x020461D4  arm
 */
#include "../include/Obj04351.h"

extern int APP_KEYCURSOR_Delete(int a0);
struct Rec;
struct S02031140;
struct U16Vec;
extern void TCBL_Destroy(struct S02031140 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
typedef unsigned int   u32;
extern u32 GF_FONT_Delete(void *ptr);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void func_020461D4(unsigned char);

void STARTMENU_SaveEraseFreeResources(unsigned char *p)
{
    APP_KEYCURSOR_Delete((int)(((struct Obj04351 *)p)->f24));
    TCBL_Destroy(((struct Obj04351 *)p)->f18);
    STRBUF_Delete(((struct Obj04351 *)p)->f10);
    GF_FONT_Delete(((struct Obj04351 *)p)->f4);
    MSGDATA_Delete(((struct Obj04351 *)p)->f8);
    func_020461D4(p[0x0C]);
}
