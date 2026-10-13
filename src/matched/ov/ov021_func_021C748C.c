/*
 * function: FIELD_TASK_UpdateSpinEaseIn
 * address:  0x021C748C
 * packet:   pkt_ov021_021C748C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   _ffltu         0x0209BE04  arm
 *   FIELD_TASK_GetSpinAcmdEaseIn  0x021C734C  thumb  ov021
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
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

extern u16 FIELD_TASK_GetSpinAcmdEaseIn(float a, float b, float c);
extern void FLDMMDL_SetAcmd(u32 a, int b);

int FIELD_TASK_UpdateSpinEaseIn(Ctl *o)
{
    u32 s;
    int k;

    s = o->w4;
    FLDMMDL_SetAcmd(s, FIELD_TASK_GetSpinAcmdEaseIn((float)(u32)o->h8, (float)(u32)o->ha, (float)(u32)o->bc));
    o->h8 = o->h8 + 1;
    if (o->ha < o->h8) {
        switch (o->he) {
        default:
        case 0: k = 0; break;
        case 1: k = 1; break;
        case 2: k = 2; break;
        case 3: k = 3; break;
        }
        FLDMMDL_SetAcmd(s, k);
        return 1;
    }
    return 0;
}
