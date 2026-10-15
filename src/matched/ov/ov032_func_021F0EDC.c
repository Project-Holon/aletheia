/*
 * function: BEACON_VIEW_ResetEntry
 * address:  0x021F0EDC
 * packet:   pkt_ov032_021F0EDC
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BEACON_VIEW_ResetEntry  0x021F0EDC  thumb
 *   BEACON_VIEW_SetEntryVisible  0x021F0EA4  thumb  ov032
 *   BEACON_VIEW_SetEntryStatusVisible  0x021F0ED0  thumb  ov032
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_OAM_UploadChars  0x020257D0  thumb
 *   STRBUF_Clear  0x0204581C  arm
 *   TCBL_DeleteTask  0x02031194  arm
 */
#include "../include/Obj00225.h"

typedef unsigned char u8;

extern void BEACON_VIEW_SetEntryVisible(char *p, unsigned a);
extern void BEACON_VIEW_SetEntryStatusVisible(char *p, int a);
struct CharBuf;
struct Obj;
struct TcblNode;
struct U16Vec;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_OAM_UploadChars(struct Obj *o);
extern void STRBUF_Clear(struct U16Vec *vec);
extern void TCBL_DeleteTask(struct TcblNode *n);

void BEACON_VIEW_ResetEntry(char *p)
{
    int z = 0;

    BEACON_VIEW_SetEntryVisible(p, 0);
    BEACON_VIEW_SetEntryStatusVisible(p, 0);
    BMP_Clear((struct CharBuf *)(((struct Obj00225 *)p)->f1C), 0);
    BMP_OAM_UploadChars((struct Obj *)(*(int *)&((struct Obj00225 *)p)->f18));
    STRBUF_Clear((struct U16Vec *)(*(int *)&((struct Obj00225 *)p)->f24));
    STRBUF_Clear((struct U16Vec *)(*(int *)&((struct Obj00225 *)p)->f20));
    ((struct Obj00225 *)p)->f1 = 0xff;
    ((struct Obj00225 *)p)->f2 = z;
    ((struct Obj00225 *)p)->f3 = z;
    if (((struct Obj00225 *)p)->f2C != 0) {
        TCBL_DeleteTask((struct TcblNode *)(((struct Obj00225 *)p)->f2C));
        ((struct Obj00225 *)p)->f2C = z;
    }
    if (*(int *)&((struct Obj00225 *)p)->f30 != 0) {
        TCBL_DeleteTask((struct TcblNode *)(*(int *)&((struct Obj00225 *)p)->f30));
        *(int *)&((struct Obj00225 *)p)->f30 = 0;
    }
}
