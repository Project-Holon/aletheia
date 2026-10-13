/*
 * function: INTRUDE_FIELD_InitMmdlCopyAnime
 * address:  0x0217C758
 * packet:   pkt_ov018_0217C758
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Initialises a 0x18-byte record (cleared by the fill below) and, when the
 * last argument is set, places its field object. The pool carries
 * 0x02183AF0 twice (stores, then call arguments), so two extern names:
 * see docs/idioms/a-duplicated-pool-word-is-a-second-extern-name-for-the-same-address.md.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012964  0x02012964  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_GetPosY  0x0216D8AC  thumb  ov010
 *   FLDMMDL_InitPosRecord  0x0216E618  thumb  ov010
 *   FLDMMDL_AddMmdl  0x0216CE60  thumb  ov010
 *   INTRUDE_FIELD_ChangePlayerLook  0x0217BCDC  thumb  ov018
 *   FLDMMDL_SetStatusBitVanish  0x0216DAC8  thumb  ov010
 *   d_02183AF0     0x02183AF0  data  a4
 *   g_02183AF0     0x02183AF0  data  a4
 */

#include "../include/G_Tmpl.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

typedef struct {
    void *f0;
    void *f4;
    s16 f8;
    s16 fA;
    u16 fC;
    u8 fE;
    u8 fF;
    u8 f10;
    u8 f11;
    u8 f12;
    u8 f13;
    void *f14;
} Rec;

typedef struct {
    u16 f0;
    u16 f2;
    u8 pad04[8];
    u16 fC;
} Tmpl;

extern struct Tmpl d_02183AF0;
extern struct Tmpl g_02183AF0;

extern void func_02082BCC(void *, int, int);
struct BigObj;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012964(const struct BigObj *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern u16 FIELDMAP_GetZoneId(unsigned char *);
extern u16 FLDMMDL_GetObjCode(void *);
extern int FLDMMDL_GetGridNowX(void *);
extern int FLDMMDL_GetGridNowZ(void *);
extern u32 FLDMMDL_GetPosY(void *p);
extern void FLDMMDL_InitPosRecord(Tmpl *, u16, u16, int);
extern void *FLDMMDL_AddMmdl(int, Tmpl *, int);
extern void INTRUDE_FIELD_ChangePlayerLook(u8 *p, void *a1, int id, u8 kind, u8 flag);
extern void FLDMMDL_SetStatusBitVanish(unsigned int *, unsigned int);

void INTRUDE_FIELD_InitMmdlCopyAnime(Rec *r, void *a1, void *a2, void *a3, u16 id, u8 kind,
                   u8 flag, u16 idx, int place)
{
    int sys;
    void *obj;
    int zone;
    int x;
    int y;

    func_02082BCC(r, 0, 0x18);
    r->f0 = a1;
    r->f4 = a2;
    r->fC = id;
    r->fE = kind;
    r->fF = flag;
    r->fA = 15;
    r->f8 = r->fA;
    r->f13 = idx;
    if (place != 0) {
        sys = func_02012964(func_020120F4(a1));
        obj = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(a2));
        zone = FIELDMAP_GetZoneId(a2);
        d_02183AF0.f2 = FLDMMDL_GetObjCode(obj);
        d_02183AF0.fC = idx;
        x = FLDMMDL_GetGridNowX(obj);
        y = FLDMMDL_GetGridNowZ(obj);
        FLDMMDL_InitPosRecord(((Tmpl *)&g_02183AF0), x, y, FLDMMDL_GetPosY(obj));
        r->f14 = FLDMMDL_AddMmdl(sys, ((Tmpl *)&g_02183AF0), zone);
        INTRUDE_FIELD_ChangePlayerLook(a3, r->f0, r->fC, r->fE, r->fF);
        FLDMMDL_SetStatusBitVanish(obj, 1);
        FLDMMDL_SetStatusBitVanish(r->f14, 0);
    }
}
