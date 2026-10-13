/*
 * function: FLDMMDL_MOVECODE_MoveFixedDir
 * address:  0x0219A54C
 * packet:   pkt_ov021_0219A54C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetMoveProcWork  0x0216D69C  thumb  ov010
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 */

typedef unsigned int u32;
typedef struct { u32 v; int n; } St;
extern void *FLDMMDL_GetMoveProcWork(void *p);
extern void FLDMMDL_SetDirDispCheckPause(int a0, int a1);

void FLDMMDL_MOVECODE_MoveFixedDir(u32 a)
{
    St *p = FLDMMDL_GetMoveProcWork((void *)a);
    switch (p->n) {
    case 0:
        FLDMMDL_SetDirDispCheckPause(a, (unsigned short)p->v);
        p->n = p->n + 1;
        break;
    case 1:
        break;
    }
}
