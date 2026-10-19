/*
 * function: WIFI_BSUBWAY_GRAPHIC_DeleteWindow
 * address: 0x021D7C58
 * packet: pkt_ov116_021D7C58
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   WORDSET_Delete 0x0201ED04 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   BMP_MENU_DeleteYesNo 0x0201FEF4 thumb
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   WIFI_BSUBWAY_GRAPHIC_DeleteBgAnim 0x021D7FC4 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon 0x021D81B4 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_Delete 0x021D82AC thumb ov116
 */
#include "../include/Obj01721.h"
typedef unsigned char u8;
struct Descriptor;
struct Rec;
struct Rec3;
struct S02031140;
struct U16Vec;
struct WordSet;
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void TCBL_Destroy(struct S02031140 *p);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern unsigned int WORDSET_Delete(struct WordSet *p);
typedef unsigned int   u32;
extern u32 GF_FONT_Delete(void *ptr);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void WIFI_BSUBWAY_GRAPHIC_DeleteBgAnim(u8 *p);
extern void WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon(u8 *p);
extern void BMP_MENU_DeleteYesNo(u8 *o);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void WIFI_BSUBWAY_GRAPHIC_Delete(void *);
extern void GF_FONT_SetDefaultTextColor(void);
extern void MI_CpuFill8(void *,int,int);
void WIFI_BSUBWAY_GRAPHIC_DeleteWindow(u8 *p) {
    if(((struct Obj01721 *)p)->f0!=0) {
        if(((struct Obj01721 *)p)->f9A4) PRINTSYS_PrintStreamDelete(((struct Obj01721 *)p)->f9A4);
        TCBL_Destroy(((struct Obj01721 *)p)->f9A8);
        MSGDATA_Delete(((struct Obj01721 *)p)->f990);
        WORDSET_Delete(((struct Obj01721 *)p)->f994);
        GF_FONT_Delete(((struct Obj01721 *)p)->f998);
        STRBUF_Delete(((struct Obj01721 *)p)->f99C);
        STRBUF_Delete(((struct Obj01721 *)p)->f9A0);
        WIFI_BSUBWAY_GRAPHIC_DeleteBgAnim(p);
        WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon(p);
        if(((struct Obj01721 *)p)->f980) {
            BMP_MENU_DeleteYesNo(((struct Obj01721 *)p)->f980);
            ((struct Obj01721 *)p)->f980=0;
        }
        BMP_WIN_Delete(((struct Obj01721 *)p)->f97C);
        WIFI_BSUBWAY_GRAPHIC_Delete(((struct Obj01721 *)p)->f8);
        GF_FONT_SetDefaultTextColor();
        MI_CpuFill8(p,0,0x9ac);
    }
}
