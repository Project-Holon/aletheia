/*
 * function: UNION_CHARA_ActionTalk
 * address:  0x0217B6B4
 * packet:   pkt_ov019_0217B6B4
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   UNION_CHARA_GetMmdl 0x0217AFB0  thumb  ov019
 *   UNION_CHARA_MakeObjId 0x0217AED4  thumb  ov019
 *   FLDMMDL_CheckPossibleAcmd 0x0216D3CC  thumb  ov010
 *   FIELDMAP_GetFieldPlayer 0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl 0x021A3074  thumb  ov021
 *   FLDMMDL_GetDirDisp 0x0216D5F8  thumb  ov010
 *   FLDMMDL_SetAcmd 0x0216D410  thumb  ov010
 *   FLDMMDL_EndAcmd 0x0216D480  thumb  ov010
 *   FLDMMDL_SetStatusBit 0x0216D548  thumb  ov010
 *   FLDMMDL_ClearStatusBit 0x0216D550  thumb  ov010
 */

typedef unsigned short u16;

struct S {
    char pad[0x58];
    u16 f58;
};

typedef unsigned int   u32;
typedef unsigned char  u8;
extern void *UNION_CHARA_GetMmdl(void **a, u8 *b, u8 *c);
extern u16 UNION_CHARA_MakeObjId(u8 *a, u8 *b);
extern int FLDMMDL_CheckPossibleAcmd(int);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern u16 FLDMMDL_GetDirDisp(void *p);
extern void FLDMMDL_SetAcmd(int, int);
extern int FLDMMDL_EndAcmd(char *p);
extern u32 *FLDMMDL_SetStatusBit(u32 *p, u32 v);
extern u32 *FLDMMDL_ClearStatusBit(u32 *p, u32 v);

int UNION_CHARA_ActionTalk(char *base, int *p, int r2, unsigned char *state)
{
    struct S *q = (struct S *)(base + 0x2830);
    int h;
    int k;

    h = (int)UNION_CHARA_GetMmdl((void **)base, (u8 *)(*p), (u8 *)p);
    switch (*state) {
    case 0:
        if (FLDMMDL_CheckPossibleAcmd(h) == 1) {
            switch (FLDMMDL_GetDirDisp(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer((void *)r2)))) {
            case 0:
                k = 1;
                break;
            case 1:
                k = 0;
                break;
            case 2:
                k = 3;
                break;
            case 3:
            default:
                k = 2;
                break;
            }
            FLDMMDL_SetAcmd(h, k);
            *state = *state + 1;
        }
        break;
    case 1:
        if (FLDMMDL_EndAcmd((char *)h) == 1) {
            FLDMMDL_SetStatusBit((u32 *)h, 8);
            *state = *state + 1;
        }
        break;
    case 2:
        if (q->f58 != UNION_CHARA_MakeObjId((u8 *)(*p), (u8 *)p)) {
            FLDMMDL_ClearStatusBit((u32 *)h, 8);
            return 1;
        }
        break;
    }
    return 0;
}
