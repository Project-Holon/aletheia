/*
 * function: OPTION_MENU_ExitTextBox
 * address:  0x021BA254
 * packet:   pkt_ov068_021BA254
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   MI_CpuFill8  0x02082BCC  arm
 */
#include "../include/Obj07683.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Rec3;
struct U16Vec;
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void MI_CpuFill8(void *p, u32 a, u32 b);

void OPTION_MENU_ExitTextBox(u8 *p)
{
    if (((struct Obj07683 *)p)->f8 != 0) {
        PRINTSYS_PrintStreamDelete((struct Rec3 *)(((struct Obj07683 *)p)->f8));
        ((struct Obj07683 *)p)->f8 = 0;
    }
    STRBUF_Delete((struct U16Vec *)(((struct Obj07683 *)p)->f14));
    MI_CpuFill8(p, 0, 0x38);
}
