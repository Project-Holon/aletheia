/*
 * function: FIELD_EVENT_CHECK_InitInput
 * address:  0x0218A4E0
 * packet:   pkt_ov021_0218A4E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Fills the 0x40 byte field input record for one frame: pad trigger and held
 * keys, the held d-pad direction, the player object's position, facing and
 * movement state, and the request bitfield at 0x3C (talk on A, menu on X,
 * registered item on Y, no-input, step, surf and push flags).
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012844  0x02012844  thumb
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb
 *   FIELD_PLAYER_UpdateStepPhase  0x021A2FE4  thumb
 *   FIELD_PLAYER_GetStepKind  0x021A3080  thumb
 *   FIELD_PLAYER_GetStepPhase  0x021A308C  thumb
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_GetPosPtr  0x0216D888  thumb  ov010
 *   func_02012B38  0x02012B38  thumb
 *   FIELD_STATUS_GetProcAction  0x02014478  thumb
 *   FIELD_PLAYER_GetNowAttribute  0x021A30C8  thumb
 *   FIELD_PLAYER_GetGridMoveState  0x021A3584  thumb
 *   KEY_GetTrg  0x020362DC  arm  arm9
 *   KEY_GetCont  0x0203630C  arm  arm9
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct FieldInput {
    u16 f0;
    u16 pad02;
    void *sys;
    void *f8;
    void *fC;
    u16 f10;
    u16 pad12;
    u8 *pos;
    void *f18;
    u32 f1C;
    u32 f20;
    u16 f24;
    u16 f26;
    u32 trg;
    u32 cont;
    u16 dir;
    u16 pad32;
    u32 f34;
    u32 f38;
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 b5 : 1;
    u32 b6 : 1;
    u32 b7 : 1;
    u32 b8 : 1;
    u32 b9 : 1;
    u32 b10 : 1;
};

extern void MI_CpuFill8(void *p, int v, u32 n);
extern u16 FIELDMAP_GetHeapId(u8 *p);
struct BigObj;
struct Ctx;
struct Sub02014444Obj;
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012844(const struct BigObj *p);
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern u32 KEY_GetTrg(void);
extern unsigned int KEY_GetCont(void);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void FIELD_PLAYER_UpdateStepPhase(u32 *p);
extern u32 FIELD_PLAYER_GetStepKind(u8 *p);
extern u32 FIELD_PLAYER_GetStepPhase(u8 *p);
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
extern u16 FLDMMDL_GetDirDisp(void *p);
extern void *FLDMMDL_GetPosPtr(void *p);
extern void *func_02012B38(const struct BigObj *p);
extern u16 FIELD_STATUS_GetProcAction(struct Sub02014444Obj *o);
extern u32 FIELD_PLAYER_GetNowAttribute(void **ctx);
extern int FIELD_PLAYER_GetGridMoveState(void *v);

void FIELD_EVENT_CHECK_InitInput(struct FieldInput *p, void *sys, struct Obj00020 *pos)
{
    void *obj;

    MI_CpuFill8(p, 0, 0x40);
    p->f0 = FIELDMAP_GetHeapId((u8 *)pos);
    p->sys = sys;
    p->f8 = func_020120F4(sys);
    p->fC = (void *)func_02012844(p->f8);
    p->f10 = FIELDMAP_GetZoneId((u8 *)pos);
    p->trg = KEY_GetTrg();
    p->cont = KEY_GetCont();
    p->dir = 9;
    if (p->cont & 0x40)
        p->dir = 0;
    else if (p->cont & 0x80)
        p->dir = 1;
    else if (p->cont & 0x20)
        p->dir = 2;
    else if (p->cont & 0x10)
        p->dir = 3;
    p->pos = (u8 *)pos;
    p->f18 = FIELDMAP_GetFieldPlayer(pos);
    FIELD_PLAYER_UpdateStepPhase(p->f18);
    p->f20 = FIELD_PLAYER_GetStepKind(p->f18);
    p->f1C = FIELD_PLAYER_GetStepPhase(p->f18);
    obj = FIELD_PLAYER_GetMmdl(p->f18);
    p->f24 = FLDMMDL_GetDirDisp(obj);
    p->f34 = (u32)FLDMMDL_GetPosPtr(obj);
    p->f26 = FIELD_STATUS_GetProcAction(func_02012B38(p->f8));
    p->f38 = FIELD_PLAYER_GetNowAttribute(p->f18);

    if (p->f1C == 3 || p->f1C == 0) {
        u8 n;

        p->b10 = 1;
        p->b0 = (p->trg & 1) ? 1 : 0;
        p->b1 = (p->trg & 0x400) ? 1 : 0;
        p->b6 = (p->trg & 0x800) ? 1 : 0;
        n = 0;
        n += p->b0;
        n += p->b1;
        n += p->b6;
        if (n == 0)
            p->b7 = 1;
    }
    p->b2 = 0;
    p->b9 = 0;
    if (p->f20 == 1)
        p->b2 = (p->f1C == 3) ? 1 : 0;
    if (FIELD_PLAYER_GetGridMoveState(p->f18))
        p->b9 = 1;
    p->b3 = (p->f1C == 3) ? 1 : 0;
    p->b4 = 0;
    if (p->f1C != 3 && p->f20 == 2)
        p->b4 = 1;
    if ((p->f24 == 0 && (p->cont & 0x40)) || (p->f24 == 1 && (p->cont & 0x80))
        || (p->f24 == 2 && (p->cont & 0x20)) || (p->f24 == 3 && (p->cont & 0x10)))
        p->b5 = 1;
    else
        p->b5 = 0;
}
