/*
 * function: FIELD_PLAYER_NOGRID_StartWalkStep
 * address:  0x021A5EDC
 * packet:   pkt_ov021_021A5EDC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
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

extern int FLDMMDL_ACMD_ConvertCodeByDir(int a, int b);
extern void FLDMMDL_SetAcmd(void *p, int a);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void FIELD_PLAYER_CORE_SetStepKind(u8 *p, u32 v);

void FIELD_PLAYER_NOGRID_StartWalkStep(S *a, void *b, int c, int d, u16 e, int f)
{
    int k;
    if (f == 1) {
        k = 0x14;
    } else if (d & 2) {
        k = 0x58;
    } else {
        k = 0xc;
    }
    FLDMMDL_SetAcmd(b, FLDMMDL_ACMD_ConvertCodeByDir(e, k));
    a->f0 = 1;
    FIELD_PLAYER_CORE_SetStepKind(a->f14, 1);
}
