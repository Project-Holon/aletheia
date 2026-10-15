/*
 * function: MB_SEQ_PushMailTool
 * address:  0x021C7504
 * packet:   pkt_ov136_021C7504
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FILE_UTIL_GetItemSlot  0x0202138C  thumb
 *   PROCSYS_Push  0x02031348  arm
 *   MAILTOOL_CreateWriteArgs  0x021C3CC0  thumb
 *   d_021C7D5C 0x021C7D5C data a4
 */
#include "../include/Obj06532.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bf7 {
    u8 v : 7;
    u8 w : 1;
};
extern const u8 d_021C7D5C[];
extern u8 FILE_UTIL_GetItemSlot(u16 v);
extern void *MAILTOOL_CreateWriteArgs(void *a, unsigned b, unsigned c, unsigned d, unsigned heap);
extern void PROCSYS_Push(void *, u32, const void *, void *);
int MB_SEQ_PushMailTool(u8 *p)
{
    ((struct Obj06532 *)p)->f10 = (void *)MAILTOOL_CreateWriteArgs(**(void ** *)&((struct Obj06532 *)p)->f4, 2, ((struct Bf7 *)(p + 0x21))->v, FILE_UTIL_GetItemSlot(((struct Obj06532 *)p)->f22), 0x65);
    PROCSYS_Push(((struct Obj06532 *)p)->f30, (u32)-1, d_021C7D5C, ((struct Obj06532 *)p)->f10);
    return 0;
}
