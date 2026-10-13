/*
 * function: FIELD_GIMMICK_BRIDGE_Update
 * address:  0x021F3740
 * packet:   pkt_ov047_021F3740
 * region:   ov047
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FIELD_GIMMICK_BRIDGE_IsOnSwayTile  0x021F381C  thumb  ov047
 *   FLDMMDL_SetDrawOffsetOutside  0x0216D8E0  thumb  ov010
 *   func_02005728  0x02005728  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   func_0203F684  0x0203F684  arm
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   _ll_mul        0x0209C054  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   gBridgeSwayAmplitudes     0x021F3840  data  ov047  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef long long s64;

typedef struct Rec12 { s32 a; s32 b; s32 c; } Rec12;
typedef struct Obj {
    s32 f00;
    u8 *f04;
    Rec12 r;
} Obj;

extern u8 gBridgeSwayAmplitudes[];

struct Big;
struct Ctx;
extern void *FIELDMAP_GetGameSystem(void *p);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
extern int FIELD_GIMMICK_BRIDGE_IsOnSwayTile(int *p);
extern void FLDMMDL_SetDrawOffsetOutside(u8 *p, Rec12 *src);
typedef unsigned int   u32;
extern u32 func_02005728(u32 range);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern short func_0203F684(unsigned short x);
extern int _fflt(int a);
extern int _fadd(int a, int b);
extern int _fsub(int a, int b);
extern int _ffix(int a);

void FIELD_GIMMICK_BRIDGE_Update(int a)
{
    s16 *p;
    Obj *o;
    int r;
    int v;
    s32 x;

    p = (s16 *)GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem((void *)a))), 0x1f);
    o = (Obj *)FIELDMAP_GetCommonWork((char *)a, 1);
    if (FIELD_GIMMICK_BRIDGE_IsOnSwayTile((int *)o) == 0) {
        o->r.b = 0;
        p[0] = 0;
        FLDMMDL_SetDrawOffsetOutside(o->f04, &o->r);
        return;
    }
    if (p[0] == 0) {
        p[1] = gBridgeSwayAmplitudes[func_02005728(4)];
    }
    v = p[1];
    if (v > 0) {
        r = _fadd(0x3f000000, _fflt(v << 12));
    } else {
        r = _fsub(_fflt(v << 12), 0x3f000000);
    }
    r = _ffix(r);
    x = func_0203F684((u16)p[0]);
    o->r.b = (s32)(((s64)x * r + 0x800) >> 12);
    FLDMMDL_SetDrawOffsetOutside(o->f04, &o->r);
    p[0] = (p[0] + 8) % 360;
}
