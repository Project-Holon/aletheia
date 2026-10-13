/*
 * function: BTLV_CORE_Delete
 * address:  0x021E9034
 * packet:   pkt_ov093_021E9034
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MSG_Exit  0x021EECD8  thumb  ov093
 *   func_021E907C  0x021E907C  thumb  ov093
 *   BTLV_SCU_Delete  0x021EB234  thumb  ov093
 *   TCBL_Destroy  0x02031140  arm
 *   STRBUF_Delete  0x02045808  arm
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   func_020307B0  0x020307B0  arm
 */
#include "../include/Obj05223.h"
extern void BTL_MSG_Exit(void);
extern void func_021E907C(void *p);
extern void BTLV_SCU_Delete(void *p);
struct S02031140;
struct U16Vec;
extern void TCBL_Destroy(struct S02031140 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern unsigned int GF_FONT_Delete(void *ptr);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void BTLV_CORE_Delete(char *p)
{
    BTL_MSG_Exit();
    func_021E907C(((struct Obj05223 *)p)->f180);
    BTLV_SCU_Delete(((struct Obj05223 *)p)->f17C);
    TCBL_Destroy(((struct Obj05223 *)p)->f178);
    STRBUF_Delete(((struct Obj05223 *)p)->fAC);
    GF_FONT_Delete(((struct Obj05223 *)p)->fB0);
    GF_FONT_Delete(((struct Obj05223 *)p)->fB4);
    func_020307B0(p);
}
