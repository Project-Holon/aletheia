/*
 * function: FLDEFF_IWAKUDAKI_Start
 * address:  0x021ADD7C
 * packet:   pkt_ov021_021ADD7C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   func_021ABE8C  0x021ABE8C  thumb  ov021
 *   FIELD_EFFECT_LoadResources  0x021ABE30  thumb  ov021
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 *   sIwakudakiFuncs     0x021D9290  data  a4
 */

typedef unsigned char u8;
typedef int s32;

typedef struct Vec3 { s32 x, y, z; } Vec3;
typedef struct Arg { unsigned a; Vec3 v; } Arg;

extern u8 sIwakudakiFuncs[];

struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *a, struct VecFx32 *v);
struct T;
extern int func_021ABE8C(struct T *a, int b);
extern void FIELD_EFFECT_LoadResources(int a, int *b, int c);
typedef unsigned int   u32;
extern int FIELD_EFFECT_GetResource(u32 a, u32 b);
extern void FIELD_EFFECT_AddObject(int a, u8 *b, int c, int d, Arg *e, int f);

void FLDEFF_IWAKUDAKI_Start(int a, int b)
{
    Vec3 v;
    Arg s;
    int n;

    FLDMMDL_GetPos((const struct Actor *)a, (struct VecFx32 *)&v);
    v.y += 0x1000;
    v.z += 0xc000;
    if (func_021ABE8C((struct T *)b, 10) == 0) {
        n = 10;
        FIELD_EFFECT_LoadResources(b, &n, 1);
    }
    s.a = FIELD_EFFECT_GetResource(b, 10);
    s.v = v;
    FIELD_EFFECT_AddObject(b, sIwakudakiFuncs, 0, 0, &s, 0);
}
