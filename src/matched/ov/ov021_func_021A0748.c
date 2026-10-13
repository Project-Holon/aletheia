/*
 * function: FIELD_LIGHT_LoadTable
 * address:  0x021A0748
 * packet:   pkt_ov021_021A0748
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ARC_TOOL_GetMemberSize  0x020490A8  arm
 *   _u32_div_f  0x0209C2B0  arm
 *   ARC_TOOL_ReadMember  0x02048F4C  arm
 *   VEC_Fx16Normalize  0x0207CDB8  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12699.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern u32 ARC_TOOL_GetMemberSize(u32 b, u32 c);
extern void ARC_TOOL_ReadMember(void *a, u32 b, u32 c);
extern void VEC_Fx16Normalize(void *a, void *b);

void FIELD_LIGHT_LoadTable(u8 *a, u32 b, u32 c)
{
    u32 i;
    s32 j;
    u8 *q;

    ((struct Obj12699 *)a)->fC = ARC_TOOL_GetMemberSize(b, c) / 0x34;
    ARC_TOOL_ReadMember(a + 0x10, b, c);
    for (i = 0; i < ((struct Obj12699 *)a)->fC; i++) {
        q = a + 0x20 + i * 0x34;
        for (j = 0; j < 4; j++) {
            VEC_Fx16Normalize(q + j * 6, q + j * 6);
        }
    }
}
