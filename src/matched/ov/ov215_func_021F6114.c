/*
 * function: EGG_DEMO_MENU_Delete
 * address: 0x021F6114
 * packet: pkt_ov215_021F6114
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   TCBL_Destroy 0x02031140 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   BG_SYS_FreeTileRun 0x0203FB44 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 */
#include "../include/Obj02926.h"
typedef unsigned short u16;
typedef unsigned int   u32;
struct Descriptor;
struct Rec;
struct Rec3;
struct S02031140;
struct U16Vec;
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void TCBL_Destroy(struct S02031140 *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void BG_SYS_FreeTileRun(u32 layer, u32 offset, u32 size);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
void EGG_DEMO_MENU_Delete(void *unused,char *p)
{
    if(((struct Obj02926 *)p)->f50) PRINTSYS_PrintStreamDelete(((struct Obj02926 *)p)->f50);
    if(((struct Obj02926 *)p)->f68) STRBUF_Delete(((struct Obj02926 *)p)->f68);
    TCBL_Destroy(((struct Obj02926 *)p)->f54);
    MSGDATA_Delete(((struct Obj02926 *)p)->f64);
    BG_SYS_FreeTileRun(1,(u16)((struct Obj02926 *)p)->f60,(u16)(((struct Obj02926 *)p)->f60>>16));
    BMP_WIN_Delete(((struct Obj02926 *)p)->f58);
    BMP_WIN_Delete(((struct Obj02926 *)p)->f5C);
}
