/*
 * function: FIELD_PLAYER_NOGRID_StartRailStand
 * address:  0x021A63F0
 * packet:   pkt_ov021_021A63F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb
 *   FLDMMDL_SetAcmd  0x0216D410  thumb
 *   FIELD_PLAYER_CORE_SetStepKind  0x021A3964  thumb
 */

typedef unsigned short u16;

typedef struct {
    int f0;
    int pad[4];
    unsigned char *f14;
} S;

extern u16 FLDMMDL_GetDirDisp(void *p);
extern int FLDMMDL_ACMD_ConvertCodeByDir(int a, int b);
extern void FLDMMDL_SetAcmd(void *p, int a);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void FIELD_PLAYER_CORE_SetStepKind(u8 *p, u32 v);

void FIELD_PLAYER_NOGRID_StartRailStand(S *a, void *b, int c, int d, u16 e)
{
    if (e == 9) {
        e = FLDMMDL_GetDirDisp(b);
    }
    FLDMMDL_SetAcmd(b, FLDMMDL_ACMD_ConvertCodeByDir(e, 0));
    a->f0 = 0;
    FIELD_PLAYER_CORE_SetStepKind(a->f14, 0);
}
