/*
 * function: WIPE_SUB_RequestLineMaskHBlank
 * address:  0x02022F0C
 * packet:   pkt_02022F0C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  02022F60 label
 *
 * symbols:
 *   WIPE_RequestSetHBlankSlot  0x02022518  thumb
 *   WIPE_SUB_LineMaskHBlank  0x02022F60  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern void WIPE_RequestSetHBlankSlot(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
struct S;
extern void WIPE_SUB_LineMaskHBlank(struct S *p);

void WIPE_SUB_RequestLineMaskHBlank(u32 a0, u8 *a1, u32 a2)
{
    WIPE_RequestSetHBlankSlot(a0, (u32)a1, (u32)WIPE_SUB_LineMaskHBlank, a1[0x309], a2);
}
