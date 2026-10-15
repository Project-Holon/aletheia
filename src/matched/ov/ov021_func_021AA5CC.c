/*
 * function: FIELD_ENCOUNT_SetupTrainerBattle
 * address:  0x021AA5CC
 * packet:   pkt_ov021_021AA5CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SETUP_Clear  0x020130C4  thumb
 *   TPOKE_DATA_GetRecordField  0x0202A230  thumb
 *   TPOKE_DATA_GetTrainerGroup  0x0202A420  thumb
 *   BTL_SETUP_SetupTrainerMulti  0x02013734  thumb
 *   BTL_SETUP_SetupTrainerDouble  0x02013644  thumb
 *   BTL_SETUP_SetupTrainerTag  0x020136E0  thumb
 *   BTL_SETUP_SetupTrainerSingle  0x02013610  thumb
 *   BTL_SETUP_SetupTrainerTriple  0x02013678  thumb
 *   BTL_SETUP_SetupTrainerRotation  0x020136AC  thumb
 *   FIELD_ENCOUNT_SetFieldSituation  0x021AA304  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Ctx { void *f00; u8 pad04[4]; void *f08; };
struct Info { u32 f00; u32 f04; u8 f08; u8 f09; u16 f0A; u8 f0C; u8 f0D; u8 pad0E[2]; };

extern void BTL_SETUP_Clear(u8 *p);
extern u32 TPOKE_DATA_GetRecordField(void *a, u32 idx);
extern u32 TPOKE_DATA_GetTrainerGroup(u32 key);
extern void FIELD_ENCOUNT_SetFieldSituation(struct Info *out, void *a1, void *a2);
struct Obj020136E0;
struct Obj02013734;
extern void BTL_SETUP_SetupTrainerMulti(struct Obj02013734 *o, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void BTL_SETUP_SetupTrainerTag(struct Obj020136E0 *o, u32 a1, u32 a2, u32 a3, u32 a4, u16 a5);
extern void BTL_SETUP_SetupTrainerDouble(u8 *p, u32 a, u32 b, u32 c, u16 d);
extern void BTL_SETUP_SetupTrainerSingle(u8 *p, u32 a, u32 b, u32 c, u16 d);
extern void BTL_SETUP_SetupTrainerTriple(u8 *p, u32 a, u32 b, u32 c, u16 d);
extern void BTL_SETUP_SetupTrainerRotation(u8 *p, u32 a, u32 b, u32 c, u16 d);

void FIELD_ENCOUNT_SetupTrainerBattle(struct Ctx *ctx, void *a1, u32 mode, u32 flag, void *mon, u32 a5, u16 heap)
{
    struct Info info;
    void *x = ctx->f08;
    u32 r;

    BTL_SETUP_Clear(a1);
    FIELD_ENCOUNT_SetFieldSituation(&info, ctx->f08, ctx->f00);
    r = TPOKE_DATA_GetTrainerGroup(TPOKE_DATA_GetRecordField(mon, 1));
    if (r != 0x11) {
        info.f04 = r;
    }
    switch (mode) {
    case 1:
        if (flag) {
            BTL_SETUP_SetupTrainerMulti(a1, (u32)x, (u32)(&info), flag, (u32)mon, a5, heap);
        } else {
            BTL_SETUP_SetupTrainerDouble(a1, (u32)x, (u32)(&info), (u32)mon, heap);
        }
        return;
    case 0:
        if (a5) {
            BTL_SETUP_SetupTrainerTag(a1, (u32)x, (u32)(&info), (u32)mon, a5, heap);
        } else {
            BTL_SETUP_SetupTrainerSingle(a1, (u32)x, (u32)(&info), (u32)mon, heap);
        }
        return;
    case 2:
        BTL_SETUP_SetupTrainerTriple(a1, (u32)x, (u32)(&info), (u32)mon, heap);
        return;
    case 3:
        BTL_SETUP_SetupTrainerRotation(a1, (u32)x, (u32)(&info), (u32)mon, heap);
        return;
    }
}
