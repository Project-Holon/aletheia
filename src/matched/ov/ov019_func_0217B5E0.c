/*
 * function: UNION_CHARA_ActionAppear
 * address:  0x0217B5E0
 * packet:   pkt_ov019_0217B5E0
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   UNION_CHARA_GetMmdl  0x0217AFB0  thumb  ov019
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FLDMMDL_GetGridNowPos  0x0216D828  thumb  ov010
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FLDMMDL_SetStatusBitVanish  0x0216DAC8  thumb  ov010
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   FLDMMDL_EndAcmd  0x0216D480  thumb  ov010
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 */

typedef short s16;

typedef unsigned short u16;
typedef unsigned char  u8;
extern void *UNION_CHARA_GetMmdl(void **a, u8 *b, u8 *c);
extern int FLDMMDL_CheckPossibleAcmd(int);
extern void FLDMMDL_GetGridNowPos(int, s16 *);
extern void FLDMMDL_SetAcmd(void *a0, u16 a1);
extern void FLDMMDL_SetStatusBitVanish(unsigned int *p, unsigned int v);
extern int FLDMMDL_CheckEndAcmd(int);
extern int FLDMMDL_EndAcmd(char *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);

int UNION_CHARA_ActionAppear(char *base, int *p, int r2, unsigned char *state)
{
    s16 a[8];
    int h = (int)UNION_CHARA_GetMmdl((void **)base, (u8 *)(*p), (u8 *)p);
    switch (*state) {
    case 0:
        if (FLDMMDL_CheckPossibleAcmd(h) == 1) {
            FLDMMDL_GetGridNowPos((int)FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer((void *)r2)), a);
            FLDMMDL_GetGridNowPos(h, a + 4);
            if (a[4] != a[0] || a[6] != a[2]) {
                FLDMMDL_SetAcmd((void *)h, 0x44);
                FLDMMDL_SetStatusBitVanish((unsigned int *)h, 0);
                *state = *state + 1;
            }
        }
        break;
    case 1:
        if (FLDMMDL_CheckEndAcmd(h) == 1) { FLDMMDL_EndAcmd((char *)h); return 1; }
        break;
    }
    return 0;
}
