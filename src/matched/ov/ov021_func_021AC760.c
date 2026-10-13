/*
 * function: FLDEFF_GRASS_Start
 * address:  0x021AC760
 * packet:   pkt_ov021_021AC760
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The v.z -= 0x2000 adjust is written in both arms of the if; the
 * compiler tail-merges the arms and keeps the 2 of 0x2000 in r6
 * (docs/idioms/a-constant-shifted-in-a-merged-tail-is-a-statement-repeated-in-each-arm.md).
 *
 * symbols:
 *   gFldeffGrassObjFuncs  0x021D90EC  data
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 *   FLDMMDL_MOVE_GetMapHeight  0x02163E58  thumb  ov010
 *   FLDMMDL_MOVE_GridToVectorPos  0x02164280  thumb  ov010
 *   FLDMMDL_CheckStatusBit  0x0216D55C  thumb  ov010
 *   FLDMMDL_GetObjId  0x0216D588  thumb  ov010
 *   FLDMMDL_GetZoneId  0x0216D590  thumb  ov010
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_GetPosY  0x0216D8AC  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct V3 { int x, y, z; } V3;
typedef struct Arg {
    u32 f0;
    u32 f4;
    int f8;
    int fc;
    u16 h10;
    u16 h12;
    V3 pos;
    int f20;
} Arg;

extern int FIELD_EFFECT_GetResource(u32 a, u32 b);
extern u16 FLDMMDL_GetObjId(void *p);
extern u16 FLDMMDL_GetZoneId(void *p);
extern int FLDMMDL_GetGridNowX(void *p);
extern int FLDMMDL_GetGridNowZ(void *p);
extern void FLDMMDL_MOVE_GridToVectorPos(int x, int y, int *p);
extern u32 FLDMMDL_GetPosY(void *p);
extern int FLDMMDL_CheckStatusBit(int a0, int a1);
extern void FLDMMDL_MOVE_GetMapHeight(u32 a, V3 *v, int *out);
extern void FIELD_EFFECT_AddObject(u32 a, u8 *b, u32 c, u32 d, Arg *e, u32 f);
extern u8 gFldeffGrassObjFuncs[];

void FLDEFF_GRASS_Start(u32 a, u32 b, u32 c, int d)
{
    V3 v;
    Arg s;
    int tmp;

    if (d >= 8)
        return;
    s.f0 = FIELD_EFFECT_GetResource(a, 2);
    s.f4 = b;
    s.f20 = d;
    s.h10 = FLDMMDL_GetObjId((void *)b);
    s.h12 = FLDMMDL_GetZoneId((void *)b);
    s.f8 = FLDMMDL_GetGridNowX((void *)b);
    s.fc = FLDMMDL_GetGridNowZ((void *)b);
    FLDMMDL_MOVE_GridToVectorPos((s16)s.f8, (s16)s.fc, (int *)(&v));
    v.y = FLDMMDL_GetPosY((void *)b);
    if (FLDMMDL_CheckStatusBit(b, 0x2000) != 0) {
        v.y += 7 * 0x1000;
        v.z -= 0x2000;
    } else {
        FLDMMDL_MOVE_GetMapHeight(b, &v, &tmp);
        v.y = tmp + 9 * 0x1000;
        v.z -= 0x2000;
    }
    s.pos = v;
    FIELD_EFFECT_AddObject(a, gFldeffGrassObjFuncs, 0, c, &s, 0);
}
