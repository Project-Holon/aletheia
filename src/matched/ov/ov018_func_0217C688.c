/*
 * function: INTRUDE_FIELD_StepPlayerSpin
 * address:  0x0217C688
 * packet:   pkt_ov018_0217C688
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Per-frame step of the 0x18-byte record INTRUDE_FIELD_InitMmdlCopyAnime initialises.
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FIELDMAP_IsReady  0x02188BE8  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   INTRUDE_FIELD_ChangePlayerLook  0x0217BCDC  thumb  ov018
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   INTRUDE_FIELD_gSpinAcmds     0x021836A0  data  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

typedef struct {
    void *f0;
    unsigned char *f4;
    s16 f8;
    s16 fA;
    u16 fC;
    u8 fE;
    u8 fF;
    u8 f10;
    u8 f11;
    u8 f12;
    u8 f13;
    int f14;
} Rec;

extern const u8 INTRUDE_FIELD_gSpinAcmds[4];

struct Ctx;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int FIELDMAP_IsReady(void *);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern int FLDMMDL_CheckPossibleAcmd(int a0);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void INTRUDE_FIELD_ChangePlayerLook(u8 *p, void *a1, int id, u8 kind, u8 flag);
extern void FLDMMDL_SetAcmd(void *a0, u16 a1);

int INTRUDE_FIELD_StepPlayerSpin(Rec *r, void *a1)
{
    void *obj;
    s16 v;

    switch (r->f10) {
    case 0:
        r->fA = 15;
        r->f8 = r->fA;
        GFL_USE_PlaySeDefaultVolume(0x738);
        r->f10++;
        break;
    case 1:
        if (FIELDMAP_IsReady(r->f4) == 1) {
            obj = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer((struct Obj00020 *)r->f4));
            if (FLDMMDL_CheckPossibleAcmd((int)obj) == 1) {
                if (r->fA >= 15 && r->f12 != 0 && INTRUDE_FIELD_gSpinAcmds[r->f11] == 1) {
                    r->f10++;
                    break;
                }
                r->f11 = (r->f11 + 1) & 3;
                v = r->fA;
                r->f8 = v;
                if (r->f12 == 0) {
                    r->fA--;
                    if (r->fA <= 1) {
                        GAMESYSTEM_GetGameData(r->f0);
                        INTRUDE_FIELD_ChangePlayerLook(a1, r->f0, r->fC, r->fE, r->fF);
                        r->f12++;
                    }
                } else if (v < 15) {
                    r->fA++;
                }
                FLDMMDL_SetAcmd(obj, INTRUDE_FIELD_gSpinAcmds[r->f11]);
            }
        }
        break;
    default:
        return 1;
    }
    return 0;
}
