/*
 * function: FIELD_PLAYER_NOGRID_EndBlockedWalk
 * address:  0x021A5A34
 * packet:   pkt_ov021_021A5A34
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_FreeAcmd  0x0216D4B4  thumb  ov010
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FIELD_PLAYER_CORE_SetStepKind  0x021A3964  thumb  ov021
 */

typedef unsigned int u32;

typedef unsigned short u16;
typedef unsigned char  u8;
u16 FLDMMDL_GetDirDisp(void *p);
void *FLDMMDL_FreeAcmd(char *p);
void FLDMMDL_SetDirDispCheckPause(int a0, int a1);
void FLDMMDL_SetDrawStatus(void *p, u16 v);
void FIELD_PLAYER_CORE_SetStepKind(u8 *p, u32 v);

void FIELD_PLAYER_NOGRID_EndBlockedWalk(u32 *p)
{
    u32 h;
    int v;

    if (p[0] == 3) {
        h = p[7];
        v = FLDMMDL_GetDirDisp((void *)h);
        FLDMMDL_FreeAcmd((char *)h);
        FLDMMDL_SetDirDispCheckPause(h, v);
        FLDMMDL_SetDrawStatus((void *)h, 0);
        FIELD_PLAYER_CORE_SetStepKind((u8 *)p[5], 0);
    }
}
