/*
 * function: FLDMMDL_MOVE_InitFaceDir
 * address:  0x0219BF60
 * packet:   pkt_ov021_0219BF60
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   FLDMMDL_InitMoveProcWork  0x0216D684  thumb  ov010
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *FLDMMDL_InitMoveProcWork(int a0, int a1, u32 a2, u32 a3);
extern u32 FLDMMDL_SetDirDispCheckPause(u32, u32);

u32 FLDMMDL_MOVE_InitFaceDir(u32 a, u32 b, u32 c, u32 a3)
{
    u8 *p = FLDMMDL_InitMoveProcWork(a, 4, c, a3);
    p[1] = 9;
    p[2] = c;
    return FLDMMDL_SetDirDispCheckPause(a, 0);
}
