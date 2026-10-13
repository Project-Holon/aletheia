/*
 * function: BTL_REC_AppendPacket
 * address:  0x021EE608
 * packet:   pkt_ov093_021EE608
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 */
#include "../include/Obj07866.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void MI_CpuCopy8(const void *, void *, u32);

void BTL_REC_AppendPacket(u8 *p, const u8 *src, int n)
{
    u32 pos;
    u32 end;

    if (p[2] == 0) {
        pos = ((struct Obj07866 *)p)->f0;
        n = n - 1;
        end = pos + n;
        if (end <= 0xC00) {
            MI_CpuCopy8(src + 1, p + 8 + pos, n);
            ((struct Obj07866 *)p)->f0 = end;
        } else {
            p[2] = 1;
        }
    }
}
