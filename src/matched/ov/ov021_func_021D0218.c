/*
 * function: FLDEFF_BTRAIN_Start
 * address:  0x021D0218
 * packet:   pkt_ov021_021D0218
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sBtrainFuncs     0x021DB8DC  data  ov021  a4
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 *   FLDEFF_BTRAIN_LoadResources  0x021D0174  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Arg021D0218 {
    u32 h;
    u32 v;
} Arg021D0218;

struct B;
extern int FIELD_EFFECT_GetResource(u32 a, u32 b);
extern void FLDEFF_BTRAIN_LoadResources(struct B *p, int i);
extern void FIELD_EFFECT_AddObject(void *a, void *b, u32 c, u32 d, void *e, u32 f);
extern char sBtrainFuncs[];

void FLDEFF_BTRAIN_Start(void *a, u32 v, u32 c)
{
    Arg021D0218 arg;

    arg.h = FIELD_EFFECT_GetResource((u32)a, 0xe);
    arg.v = v;
    FLDEFF_BTRAIN_LoadResources((struct B *)arg.h, v);
    FIELD_EFFECT_AddObject(a, sBtrainFuncs, c, 0, &arg, 0);
}
