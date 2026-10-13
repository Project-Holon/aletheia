/*
 * unit:     no
 * function: ARC_UTIL_LoadMemberWithSize
 * address:  0x0204A298
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
 *   func_020834C0  0x020834C0  arm
 *   func_020307B0  0x020307B0  arm
 *   arc_util_file   0x020A7F30  data
 *
 * The out-parameter twin of ARC_UTIL_LoadMember directly above it: the handle
 * ARC_TOOL_GetMemberSize returns is written through the fifth (stack) argument and
 * the same three arc_util.c line numbers appear, shifted by 43.
 */
#include "../include/Obj16075.h"

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 ARC_TOOL_GetMemberSize(u32 a, u32 b);
extern void *      func_02030734(u32 a0, u32 a1, int a2, const char *file, u16 line);
extern void ARC_TOOL_ReadMember(void *dst, u32 archive_id, u32 member);
extern int         func_020834C0(int a0, int a1);
extern u32 func_020307B0(void *p);
extern const char  arc_util_file[];

int ARC_UTIL_LoadMemberWithSize(int a0, int a1, int a2, int a3, u32 *out)
{
    int r;
    int t;

    *out = ARC_TOOL_GetMemberSize(a0, a1);
    if (a2 != 0) {
        r = (int)func_02030734((u16)((a3 & 0x7fff) | 0x8000), *out, 0, arc_util_file, 1642);
    } else {
        r = (int)func_02030734(a3, *out, 0, arc_util_file, 1646);
    }
    ARC_TOOL_ReadMember((void *)r, a0, a1);
    if (a2 != 0) {
        *out = ((struct Obj16075 *)r)->f0 >> 8;
        t = (int)func_02030734(a3, *out, 0, arc_util_file, 1656);
        func_020834C0(r, t);
        func_020307B0((void *)r);
        r = t;
    }
    return r;
}
