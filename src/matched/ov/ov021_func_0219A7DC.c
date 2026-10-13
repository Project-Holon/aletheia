/*
 * function: FLDMMDL_MOVECODE_SwingStepRotateDir
 * address:  0x0219A7DC
 * packet:   pkt_ov021_0219A7DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gMmdlSwingDirsLeft     0x021D504C  data  a4
 *   gMmdlSwingDirsRight     0x021D5060  data  a4
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FLDMMDL_GetDirHeader  0x0216D5D4  thumb  ov010
 *   FLDMMDL_MOVE_GetDirTableValue  0x021642A4  thumb  ov010
 */

typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int v[5]; } Arr;
extern const Arr gMmdlSwingDirsLeft;
extern const Arr gMmdlSwingDirsRight;
extern u16 FLDMMDL_GetDirDisp(void *p);
extern void FLDMMDL_SetDirDispCheckPause(int a0, int a1);
extern int FLDMMDL_GetDirHeader(void *p);
extern u16 FLDMMDL_MOVE_GetDirTableValue(int i);

int FLDMMDL_MOVECODE_SwingStepRotateDir(u32 a, s8 *b)
{
    Arr ta = gMmdlSwingDirsLeft;
    Arr tb = gMmdlSwingDirsRight;
    int *t;
    int i;
    int cur;
    t = ta.v;
    if (b[0] != 2)
        t = tb.v;
    cur = FLDMMDL_GetDirDisp((void *)a);
    i = 0;
    if (t[0] != 9) {
        do {
            if (cur == t[i])
                break;
            i++;
        } while (t[i] != 9);
    }
    i++;
    if (t[i] == 9)
        i = 0;
    FLDMMDL_SetDirDispCheckPause((u32)a, (u16)t[i]);
    if (FLDMMDL_GetDirDisp((void *)a) == FLDMMDL_GetDirHeader((void *)a))
        b[0] = FLDMMDL_MOVE_GetDirTableValue(b[0]);
    b[2] = 0;
    return 1;
}
