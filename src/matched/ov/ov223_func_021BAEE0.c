/*
 * function: PSEL_DeleteWin
 * address: 0x021BAEE0
 * packet: pkt_ov223_021BAEE0
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Trailing AF2E halfword is zero alignment padding.
 * symbols:
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   TCBL_Destroy 0x02031140 arm
 *   MSGDATA_Delete 0x02045C04 arm
 */
#include "../include/Obj02266.h"
typedef unsigned char u8;
struct Rec3;
struct U16Vec;
struct Descriptor;
struct S02031140;
struct Rec;
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *);
extern void STRBUF_Delete(struct U16Vec *);
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void TCBL_Destroy(struct S02031140 *);
extern u32 MSGDATA_Delete(struct Rec *rec);
void PSEL_DeleteWin(char *p)
{
    u8 i;
    if (*(struct Rec3 * *)&((struct Obj02266 *)p)->f250)
        PRINTSYS_PrintStreamDelete(*(struct Rec3 * *)&((struct Obj02266 *)p)->f250);
    if (*(struct U16Vec * *)&((struct Obj02266 *)p)->f258)
        STRBUF_Delete(*(struct U16Vec * *)&((struct Obj02266 *)p)->f258);
    for (i = 0; i < 3; i++)
        BMP_WIN_Delete(*(struct Descriptor **)(p + 0x238 + i * 4));
    TCBL_Destroy(*(struct S02031140 * *)&((struct Obj02266 *)p)->f254);
    MSGDATA_Delete(*(struct Rec * *)&((struct Obj02266 *)p)->f234);
}
