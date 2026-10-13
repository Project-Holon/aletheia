/*
 * function: MONOLITH_TOOL_LIST_DrawEntryNames
 * address:  0x021B9A40
 * packet:   pkt_ov071_021B9A40
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STRBUF_Create  0x020457B0  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   PRINTSYS_PrintColor  0x0201C7D0  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   d_021BAAF8     0x021BAAF8  data  a2
 */
#include "../include/Obj03664.h"
#include "../include/Obj09897.h"
#include "../include/Obj20756.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed short s16;

extern u16 d_021BAAF8[];
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void PRINTSYS_PrintColor(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void STRBUF_Delete(struct U16Vec *vec);

int MONOLITH_TOOL_LIST_DrawEntryNames(char *a, char *b)
{
    int j;
    int i;
    char *r6;
    void *buf;

    j = 0;
    buf = STRBUF_Create(0x20, 0x61);
    i = ((struct Obj03664 *)a)->f27D;
    if (i < ((struct Obj03664 *)a)->f27C) {
        do {
            if (i >= 1 && i < ((struct Obj03664 *)a)->f27C - 1) {
                r6 = a + i * 4;
                MSGDATA_ReadString((struct MsgBank *)(((struct Obj03664 *)a)->f20), ((struct Obj09897 *)r6)->fEC, buf);
                PRINTSYS_PrintColor(((struct Obj09897 *)r6)->f24, 0, 0, buf, ((struct Obj20756 *)b)->fC,
                              d_021BAAF8[((struct Obj09897 *)r6)->f1B4]);
            }
            j++;
            if (j >= 3)
                break;
            i++;
        } while (i < ((struct Obj03664 *)a)->f27C);
    }
    STRBUF_Delete(buf);
    ((struct Obj03664 *)a)->f27D = i;
    return ((struct Obj03664 *)a)->f27D >= ((struct Obj03664 *)a)->f27C;
}
