/*
 * unit:     no
 * function: ARC_UTIL_LoadMember
 * address:  0x0204A1BC
 * packet:   pkt_0204A1BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   ARC_TOOL_GetMemberSize  0x020490A8  arm
 *   func_02030734  0x02030734  arm
 *   ARC_TOOL_ReadMember  0x02048F4C  arm
 *   MI_UncompressLZ8  0x020834C0  arm
 *   func_020307B0  0x020307B0  arm
 *   arc_util_file   0x020A7F30  data
 *
 * arc_util.c's "open a member and read it" entry.  The three __LINE__
 * constants 1599, 1603 and 1611 are the only three the pool carries, and
 * each is the fifth argument of a func_02030734 call whose fourth
 * argument is the file-name word at 0x020A7F30 ("arc_util.c").
 */
#include "../include/Obj16074.h"

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 ARC_TOOL_GetMemberSize(u32 a, u32 b);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 tag);
extern void ARC_TOOL_ReadMember(void *dst, u32 archive_id, u32 member);
extern int         MI_UncompressLZ8(int a0, int a1);
extern u32 func_020307B0(void *p);
extern const char  arc_util_file[];

int ARC_UTIL_LoadMember(int a0, int a1, int a2, int a3)
{
    int t;
    int r;
    int t2;

    if (a2 != 0) {
        t = ARC_TOOL_GetMemberSize(a0, a1);
        r = (int)func_02030734((u16)((a3 & 0x7fff) | 0x8000), t, 0, arc_util_file, 1599);
    } else {
        t = ARC_TOOL_GetMemberSize(a0, a1);
        r = (int)func_02030734(a3, t, 0, arc_util_file, 1603);
    }
    ARC_TOOL_ReadMember((void *)r, a0, a1);
    if (a2 != 0) {
        t2 = (int)func_02030734(a3, ((struct Obj16074 *)r)->f0 >> 8, 0, arc_util_file, 1611);
        MI_UncompressLZ8(r, t2);
        func_020307B0((void *)r);
        r = t2;
    }
    return r;
}
