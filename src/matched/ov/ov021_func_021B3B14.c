/*
 * function: SCRCMD_PROC_FLD_AllocShopResources
 * address:  0x021B3B14
 * packet:   pkt_ov021_021B3B14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_PROC_FLD_AllocShopResources 0x021B3B14 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   TCBL_Create 0x0203101C arm
 *   func_02045EC0 0x02045EC0 arm
 */
#include "../include/Obj00037.h"

typedef unsigned short u16;

typedef unsigned int   u32;
struct MsgBank;
struct Tcbl;
struct U16Vec;
struct WordSet;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);

int SCRCMD_PROC_FLD_AllocShopResources(char *p, int a)
{
    ((struct Obj00037 *)p)->f188 = func_02045B38(0, 3, 423, ((struct Obj00037 *)p)->f4);
    ((struct Obj00037 *)p)->f18C = func_02045B38(0, 2, 53, ((struct Obj00037 *)p)->f4);
    ((struct Obj00037 *)p)->f190 = func_0201EC64(((struct Obj00037 *)p)->f4);
    ((struct Obj00037 *)p)->f198 = STRBUF_Create(200, ((struct Obj00037 *)p)->f4);
    ((struct Obj00037 *)p)->f1B4 = TCBL_Create(((struct Obj00037 *)p)->f4, ((struct Obj00037 *)p)->f4, 32, 32);
    ((struct Obj00037 *)p)->f19C = func_02045EC0(((struct Obj00037 *)p)->f188, 29);
    return a;
}
