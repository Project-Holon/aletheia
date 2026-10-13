/*
 * function: FIELD_TASK_UpdateSpinEaseOut
 * address:  0x021C7500
 * packet:   pkt_ov021_021C7500
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _ffltu         0x0209BE04  arm
 *   FIELD_TASK_GetSpinAcmdEaseOut  0x021C73B4  thumb  ov021
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 w0;
    u32 w4;
    u16 h8;
    u16 ha;
    u8  bc;
    u8  pad;
    u16 he;
} Ctl;

extern u16 FIELD_TASK_GetSpinAcmdEaseOut(float a, float b, float c);
extern void FLDMMDL_SetAcmd(void *a0, u16 a1);
extern void FLDMMDL_SetDirDispCheckPause(int a0, int a1);

int FIELD_TASK_UpdateSpinEaseOut(Ctl *o)
{
    u32 s;

    s = o->w4;
    FLDMMDL_SetAcmd((void *)s, FIELD_TASK_GetSpinAcmdEaseOut((float)(u32)o->h8, (float)(u32)o->ha, (float)(u32)o->bc));
    o->h8 = o->h8 + 1;
    if (o->ha < o->h8) {
        FLDMMDL_SetDirDispCheckPause(s, o->he);
        return 1;
    }
    return 0;
}
