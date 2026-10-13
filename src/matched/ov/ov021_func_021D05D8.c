/*
 * function: FLDEFF_BUBBLE_Start
 * address:  0x021D05D8
 * packet:   pkt_ov021_021D05D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DB968     0x021DB968  data  ov021  a4
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Arg021D05D8 {
    u32 h;
    void *a;
} Arg021D05D8;

typedef struct Vec021D05D8 {
    int x, y, z;
} Vec021D05D8;

extern int FIELD_EFFECT_GetResource(u32 a, u32 b);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *, struct VecFx32 *);
extern void FIELD_EFFECT_AddObject(void *a, void *b, void *c, u32 d, void *e, u32 f);
extern char d_021DB968[];

void FLDEFF_BUBBLE_Start(void *a, void *b)
{
    Arg021D05D8 arg;
    Vec021D05D8 v;

    arg.h = FIELD_EFFECT_GetResource((u32)b, 0x10);
    arg.a = a;
    FLDMMDL_GetPos(a, (struct VecFx32 *)&v);
    FIELD_EFFECT_AddObject(b, d_021DB968, &v, 0, &arg, 0);
}
