/*
 * function: FLDMMDL_MOVECODE_SpinStepRotateDir
 * address:  0x0219A6CC
 * packet:   pkt_ov021_0219A6CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   gMmdlSpinDirsLeft     0x021D5024  data  a4
 *   gMmdlSpinDirsRight     0x021D5038  data  a4
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 */

typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int v[5]; } Arr;
extern const Arr gMmdlSpinDirsLeft;
extern const Arr gMmdlSpinDirsRight;
extern u16 FLDMMDL_GetDirDisp(void *p);
extern void FLDMMDL_SetDirDispCheckPause(int a0, int a1);

int FLDMMDL_MOVECODE_SpinStepRotateDir(u32 a, s8 *b)
{
    Arr ta = gMmdlSpinDirsLeft;
    Arr tb = gMmdlSpinDirsRight;
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
    b[2] = 0;
    return 1;
}
