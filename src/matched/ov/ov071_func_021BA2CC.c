/*
 * function: MONOLITH_TOOL_MainInfoScreen
 * address:  0x021BA2CC
 * packet:   pkt_ov071_021BA2CC
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   MONOLITH_TOOL_DrawActiveEntry  0x021BA528  thumb  ov071
 *   MONOLITH_TOOL_DrawSelectedEntry  0x021BA5D4  thumb  ov071
 */
#include "../include/Obj06192.h"
#include "../include/Obj09900.h"
#include "../include/Obj13188.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *a);
struct PrintSys;
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void MONOLITH_TOOL_DrawActiveEntry(u32 **a, u8 *b, u8 *c);
extern void MONOLITH_TOOL_DrawSelectedEntry(void *a, void *b, void *c);

int MONOLITH_TOOL_MainInfoScreen(int a, int *b, u8 *o, u8 *c)
{
    int i;
    u8 f[3];
    u32 t;
    u8 *e;

    if (o[0x2d] == 1) {
        return 1;
    }
    for (i = 0; i < 3; i++) {
        t = (*(u32 **)(o + 4))[2];
        e = c + i * 8;
        if (e[0x10] != 0) {
            if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)t, (void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj06192 *)e)->fC))) == 0) {
                BMP_WIN_TransferChars((struct Descriptor *)((struct Obj06192 *)e)->fC);
                e[0x10] = 0;
            }
        }
        f[i] = e[0x10] == 0;
    }
    if (*b == 0) {
        if ((*(u8 **)(o + 8))[3] == 1 && f[1] == 1) {
            MONOLITH_TOOL_DrawActiveEntry((u32 **)o, ((struct Obj09900 *)o)->f4, c);
            (*(u8 **)(o + 8))[3] = 0;
        }
        if ((*(u8 **)(o + 8))[1] != ((struct Obj13188 *)c)->f24 && f[2] == 1) {
            MONOLITH_TOOL_DrawSelectedEntry(o, ((struct Obj09900 *)o)->f4, c);
            ((struct Obj13188 *)c)->f24 = (*(u8 **)(o + 8))[1];
        }
        return 0;
    }
    return 0;
}
