/*
 * function: FIELD_PLAYER_NOGRID_StartSlowBlocked
 * address:  0x021A62FC
 * packet:   pkt_ov021_021A62FC
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
 *   FIELD_PLAYER_NOGRID_HasConnectionAhead  0x021A6C6C  thumb
 *   func_020061E4  0x020061E4  thumb
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

extern int FIELD_PLAYER_NOGRID_HasConnectionAhead(u8 *p, u32 k);
extern void func_020061E4(u32 a);

void FIELD_PLAYER_NOGRID_StartSlowBlocked(S *a, void *b, int c, int d, u16 e)
{
    FLDMMDL_SetAcmd(b, FLDMMDL_ACMD_ConvertCodeByDir(e, 0x1c));
    a->f0 = 3;
    FIELD_PLAYER_CORE_SetStepKind(a->f14, 0);
    if (FIELD_PLAYER_NOGRID_HasConnectionAhead((u8 *)a, e) == 0) {
        func_020061E4(0x55a);
    }
}
