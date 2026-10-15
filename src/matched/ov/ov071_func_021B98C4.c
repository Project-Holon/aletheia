/*
 * function: MONOLITH_TOOL_LIST_HideMessage
 * address:  0x021B98C4
 * packet:   pkt_ov071_021B98C4
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   func_02034714  0x02034714  arm
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   d_021BABFC     0x021BABFC  data  a4
 */
#include "../include/Obj00044.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern char d_021BABFC[];
struct CharBuf;
struct Descriptor;
struct Rec3;
struct U16Vec;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void GF_FONT_SetTextColor(u32 a, u32 b, u32 c);

void MONOLITH_TOOL_LIST_HideMessage(char *a)
{
    void *r6;

    r6 = BMP_WIN_GetBmp(((struct Obj00044 *)a)->f280);
    if (((struct Obj00044 *)a)->f294 == 0)
        func_02034714(d_021BABFC, 0, d_021BABFC);
    PRINTSYS_PrintStreamDelete(((struct Obj00044 *)a)->f294);
    ((struct Obj00044 *)a)->f294 = 0;
    STRBUF_Delete(((struct Obj00044 *)a)->f290);
    ((struct Obj00044 *)a)->f290 = 0;
    BMP_MENUWORK_DrawWindowBorder(((struct Obj00044 *)a)->f280, 0);
    BMP_Clear(r6, 0xff);
    BMP_WIN_TransferChars(((struct Obj00044 *)a)->f280);
    GF_FONT_SetTextColor(0xf, 2, 0);
}
