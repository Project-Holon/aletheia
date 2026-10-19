/*
 * function: SHINKA_DEMO_DeleteWindows
 * address: 0x022052E8
 * packet: pkt_ov195_022052E8
 * region: ov195
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_KEYCURSOR_Delete 0x02028604 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   BG_SYS_FreeTileRun 0x0203FB44 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 */
#include "../include/Obj02240.h"
extern int APP_KEYCURSOR_Delete(int);
struct Descriptor;
struct Rec3;
struct S02031140;
struct U16Vec;
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void TCBL_Destroy(struct S02031140 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
struct Rec;
extern unsigned int MSGDATA_Delete(struct Rec *rec);
typedef unsigned int   u32;
extern void BG_SYS_FreeTileRun(u32 layer, u32 offset, u32 size);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
void SHINKA_DEMO_DeleteWindows(int task, int *p)
{
    APP_KEYCURSOR_Delete(((struct Obj02240 *)p)->f84);
    if (((struct Obj02240 *)p)->f64) PRINTSYS_PrintStreamDelete((struct Rec3 *)(((struct Obj02240 *)p)->f64));
    TCBL_Destroy((struct S02031140 *)(((struct Obj02240 *)p)->f68));
    if (((struct Obj02240 *)p)->f80) STRBUF_Delete((struct U16Vec *)(((struct Obj02240 *)p)->f80));
    MSGDATA_Delete(((struct Obj02240 *)p)->f78);
    MSGDATA_Delete(((struct Obj02240 *)p)->f7C);
    BG_SYS_FreeTileRun(1, (unsigned short)(((struct Obj02240 *)p)->f74), (unsigned short)(((struct Obj02240 *)p)->f74 >> 16));
    BMP_WIN_Delete((struct Descriptor *)(((struct Obj02240 *)p)->f6C));
    BMP_WIN_Delete((struct Descriptor *)(((struct Obj02240 *)p)->f70));
}
