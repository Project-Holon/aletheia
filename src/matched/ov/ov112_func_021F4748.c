/*
 * function: MUSICAL_MCSS_DeleteWindows
 * address: 0x021F4748
 * packet: pkt_ov112_021F4748
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   TCBL_Destroy 0x02031140 arm
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 *   TIME_ICON_Delete  0x0202F038  thumb  arm9
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb  arm9
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb  arm9
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb  arm9
 */
#include "../include/Obj01924.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct PrintSys;
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void TIME_ICON_Delete(u8 *);
struct Descriptor;
struct Rec;
struct Rec3;
struct S02031140;
struct U16Vec;
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 GF_FONT_Delete(void *ptr);
extern void TCBL_Destroy(struct S02031140 *p);
void MUSICAL_MCSS_DeleteWindows(u8 *p)
{
    PRINTSYS_QUE_Clear((struct PrintSys *)(((struct Obj01924 *)p)->f38));
    PRINTSYS_QUE_Delete((struct PrintSys *)(((struct Obj01924 *)p)->f38));
    if (*(u8 * *)&((struct Obj01924 *)p)->f34) {
        TIME_ICON_Delete(*(u8 * *)&((struct Obj01924 *)p)->f34);
        *(u32 *)&((struct Obj01924 *)p)->f34=0;
    }
    if (((struct Obj01924 *)p)->f24) PRINTSYS_PrintStreamDelete(((struct Obj01924 *)p)->f24);
    if (((struct Obj01924 *)p)->f2C) STRBUF_Delete(((struct Obj01924 *)p)->f2C);
    MSGDATA_Delete(((struct Obj01924 *)p)->f28);
    BMP_WIN_Delete(((struct Obj01924 *)p)->f1C);
    GF_FONT_Delete(((struct Obj01924 *)p)->f20);
    TCBL_Destroy(((struct Obj01924 *)p)->f18);
}
