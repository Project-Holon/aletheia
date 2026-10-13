/*
 * function: FLDMMDL_MOVE_InitWallWalk
 * address:  0x0219C0D4
 * packet:   pkt_ov021_0219C0D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   FLDMMDL_InitMoveProcWork  0x0216D684  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *FLDMMDL_InitMoveProcWork(int a0, int a1, u32 a2, u32 a3);

void FLDMMDL_MOVE_InitWallWalk(u32 a, u32 b, u32 c, u32 a3)
{
    u32 *p = FLDMMDL_InitMoveProcWork(a, 12, c, a3);
    p[1] = b;
    p[2] = c;
}
