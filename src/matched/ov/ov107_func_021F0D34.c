/*
 * function: func_021F0D34
 * address: 0x021F0D34
 * packet: pkt_ov107_021F0D34
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * 2026-10-05 (wave P16 E9): the draft with a result local (result = 1, result = 6, return result) swapped the aid and result colours (12 B). Returning from each arm (return 6; return 1;) gives the original colours. MI_CpuCopy8 is declared as the three-argument copy (src, dst, size) as in the matched sibling func_021F0754.
 * symbols:
 *   OS_DisableInterrupts 0x02087988 arm
 *   OS_RestoreInterrupts 0x0208799C arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   d_021F6EAC 0x021F6EAC data a4
 *   d_021F6EB4 0x021F6EB4 data a4
 */

#include "../include/G_Zero.h"
#include "../include/G_Masks.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32);
extern void MI_CpuCopy8(const void *, void *, u32);
typedef struct {u8 pad[10];u16 f0A;} Masks;
extern struct Masks d_021F6EAC;
extern struct Zero d_021F6EB4;
typedef struct {u16 f00,f02,f04,f06,f08,f0A,f0C,f0E,f10,f12;} Snapshot;
int func_021F0D34(u16 aid)
{
    u32 state;
    Snapshot snap;
    u16 bit;
    bit = 1 << aid;
    state = OS_DisableInterrupts();
    if (!(d_021F6EAC.f0A & bit)) {
        OS_RestoreInterrupts(state);
        return 0;
    }
    MI_CpuCopy8(((u8 *)&d_021F6EB4), &snap, 20);
    OS_RestoreInterrupts(state);
    if (snap.f04 & bit) return 2;
    if (snap.f06 & bit) return 3;
    if (snap.f08 & bit) return 4;
    if (snap.f0A & bit) return 5;
    if (snap.f0C & bit) return 6;
    return 1;
}
