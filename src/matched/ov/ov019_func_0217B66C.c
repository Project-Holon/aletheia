/*
 * function: UNION_CHARA_ActionDisappear
 * address:  0x0217B66C
 * packet:   pkt_ov019_0217B66C
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   UNION_CHARA_GetMmdl  0x0217AFB0  thumb  ov019
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   FLDMMDL_EndAcmd  0x0216D480  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned char  u8;
extern void *UNION_CHARA_GetMmdl(void **a, u8 *b, u8 *c);
extern int FLDMMDL_CheckPossibleAcmd(int);
extern void FLDMMDL_SetAcmd(void *a0, u16 a1);
extern int FLDMMDL_CheckEndAcmd(int);
extern int FLDMMDL_EndAcmd(char *p);

int UNION_CHARA_ActionDisappear(char *base, int *p, int r2, unsigned char *state)
{
    int h = (int)UNION_CHARA_GetMmdl((void **)base, (u8 *)(*p), (u8 *)p);
    switch (*state) {
    case 0:
        if (FLDMMDL_CheckPossibleAcmd(h) == 1) { FLDMMDL_SetAcmd((void *)h, 0x43); *state = *state + 1; }
        break;
    case 1:
        if (FLDMMDL_CheckEndAcmd(h) == 1) { FLDMMDL_EndAcmd((char *)h); return 1; }
        break;
    }
    return 0;
}
