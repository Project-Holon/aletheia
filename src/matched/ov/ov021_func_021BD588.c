/*
 * function: PLACE_NAME_LETTER_PrintChar
 * address:  0x021BD588
 * packet:   pkt_ov021_021BD588
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   PLACE_NAME_LETTER_GetChar  0x021BD2C8  thumb  ov021
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_SetStringN  0x02045994  arm
 *   PRINTSYS_PrintColor  0x0201C7D0  thumb
 *   BMP_OAM_UploadChars  0x020257D0  thumb
 *   STRBUF_Delete  0x02045808  arm
 */
#include "../include/Obj02719.h"

typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

typedef unsigned char  u8;
extern u16 PLACE_NAME_LETTER_GetChar(u8 *p);
extern u16 STRBUF_GetEosChar(void);
struct Obj;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
struct Strbuf;
extern void STRBUF_SetStringN(struct Strbuf *a, const u16 *b, u32 c);
extern void PRINTSYS_PrintColor(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void BMP_OAM_UploadChars(struct Obj *o);
extern void STRBUF_Delete(struct U16Vec *vec);

void PLACE_NAME_LETTER_PrintChar(u32 *p)
{
    u16 buf[2];
    u32 h;

    buf[0] = PLACE_NAME_LETTER_GetChar((u8 *)p);
    buf[1] = STRBUF_GetEosChar();
    h = (u32)STRBUF_Create(2, ((struct Obj02719 *)p)->f0);
    STRBUF_SetStringN((struct Strbuf *)h, buf, 2);
    PRINTSYS_PrintColor((void *)p[2], 0, 0, (void *)h, (void *)p[1], 0x440);
    BMP_OAM_UploadChars((struct Obj *)p[3]);
    STRBUF_Delete((struct U16Vec *)h);
}
