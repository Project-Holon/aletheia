/*
 * function: FLDMMDL_MOVECODE_SpinStepTurn
 * address:  0x0219A604
 * packet:   pkt_ov021_0219A604
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_MOVECODE_GetDirTowardPlayerInSet  0x0219B200  thumb  ov021
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb  ov021
 *   FLDMMDL_SetLocalAcmd  0x0216D438  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int FLDMMDL_MOVECODE_GetDirTowardPlayerInSet(int a, int id, int end);
extern u16 FLDMMDL_GetDirDisp(void *p);
extern int FLDMMDL_ACMD_ConvertCodeByDir(int a, int b);
extern void FLDMMDL_SetLocalAcmd(char *a0, int a1);

int FLDMMDL_MOVECODE_SpinStepTurn(u32 a, u8 *s)
{
    u32 v = FLDMMDL_MOVECODE_GetDirTowardPlayerInSet(a, 0x26, 9);
    if (v == 9) {
        v = FLDMMDL_GetDirDisp((void *)a);
    }
    FLDMMDL_SetLocalAcmd((char *)a, (u16)((u32)FLDMMDL_ACMD_ConvertCodeByDir((u16)v, (u16)0)));
    s[2] = 1;
    return 1;
}
