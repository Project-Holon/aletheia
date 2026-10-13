/*
 * function: FLDMMDL_MOVECODE_StartMirrorTurn
 * address:  0x0219B390
 * packet:   pkt_ov021_0219B390
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_CheckStatusBit  0x0216D55C  thumb  ov010
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FLDMMDL_SetStatusBit  0x0216D548  thumb  ov010
 *   gMmdlMirrorDirCycles     0x021D4FCC  data    a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;

extern u16 FLDMMDL_GetDirDisp(void *p);
extern int FLDMMDL_CheckStatusBit(int a, int b);
extern void FLDMMDL_SetDirDispCheckPause(int a0, int a1);
extern u32 *FLDMMDL_SetStatusBit(u32 *p, u32 v);
extern u32 gMmdlMirrorDirCycles[][4];

void FLDMMDL_MOVECODE_StartMirrorTurn(int a, s8 *b)
{
    int i;
    u32 v;
    u32 n;

    v = FLDMMDL_GetDirDisp((void *)a);
    for (i = 0; i < 4 && v != gMmdlMirrorDirCycles[b[1]][i]; i++) {
    }
    i++;
    b[0] = v;
    i %= 4;
    n = gMmdlMirrorDirCycles[b[1]][i];
    if (FLDMMDL_CheckStatusBit(a, 8) != 0) {
        b[2] = 1;
    } else {
        b[2] = 0;
    }
    FLDMMDL_SetDirDispCheckPause(a, (u16)n);
    FLDMMDL_SetStatusBit((u32 *)a, 8);
}
