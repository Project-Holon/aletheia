/*
 * function: MB_SEQ_DeleteWindows
 * address: 0x021C5F44
 * packet: pkt_ov136_021C5F44
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MB_SEQ_DeleteWindows 0x021C5F44 thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   BMP_WIN_Exit 0x020450C8 arm
 */
#include "../include/Obj08203.h"
#include "../include/Obj23546.h"
#include "../include/Obj23547.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Descriptor;
struct PrintSys;
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
struct S02031140;
extern void TCBL_Destroy(struct S02031140 *p);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 GF_FONT_Delete(void *ptr);
extern void BMP_WIN_Exit(void);

void MB_SEQ_DeleteWindows(u8 *p)
{
    u32 i;
    PRINTSYS_QUE_Delete(((struct Obj23546 *)(*(u8 * *)&((struct Obj08203 *)p)->f8))->f1C4);
    TCBL_Destroy((struct S02031140 *)(((struct Obj23547 *)(*(u8 * *)&((struct Obj08203 *)p)->f8))->f1CC));
    for (i = 0; i < 0x20; i++) {
        BMP_WIN_Delete(*(void **)(*(u8 * *)&((struct Obj08203 *)p)->f8 + i * 4 + 0x44));
    }
    GF_FONT_Delete((void *)(((struct Obj08203 *)p)->f18));
    BMP_WIN_Exit();
}
