/*
 * function: BEACON_VIEW_DrawEntryText
 * address:  0x021F2144
 * packet:   pkt_ov032_021F2144
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BEACON_VIEW_DrawEntryText 0x021F2144 thumb
 *   BEACON_VIEW_StartWindowCTask 0x021F21B0 thumb
 *   BMP_Clear 0x02043B5C arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   BMP_OAM_UploadChars 0x020257D0 thumb
 */
#include "../include/Obj07635.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef signed short   s16;
struct CharBuf;
struct Obj;
extern void BEACON_VIEW_StartWindowCTask(char *p, char *q, int *r);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void PRINTSYS_PrintColor(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void BMP_OAM_UploadChars(struct Obj *o);

void BEACON_VIEW_DrawEntryText(char *p, char *q, void *text, u16 col, u32 a4)
{
    u32 *t;

    t = (u32 *)(q + 0x18);
    BMP_Clear((struct CharBuf *)t[1], 0);
    if (((struct Obj07635 *)p)->f7A != 0) {
        PRINTSYS_PrintColor((void *)t[1], 0, 0, text, (void *)(((struct Obj07635 *)p)->fB0), col);
        BMP_OAM_UploadChars((struct Obj *)t[0]);
        return;
    }
    PRINTSYS_PrintQueColor((void *)(((struct Obj07635 *)p)->fB4), t[1], 0, 0, (u32)text, ((struct Obj07635 *)p)->fB0, col);
    BEACON_VIEW_StartWindowCTask(p, q, (int *)a4);
}
