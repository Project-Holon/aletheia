/*
 * function: FLDEFF_HIDE_Start
 * address:  0x021D046C
 * packet:   pkt_ov021_021D046C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sHideFuncs     0x021DB93C  data  ov021  a4
 *   FIELD_EFFECT_GetFieldMapData  0x021ABE18  thumb  ov021
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Arg021D046C {
    u32 h1;
    u32 h2;
    u32 b;
    u32 c;
} Arg021D046C;

extern int FIELD_EFFECT_GetResource(u32 a, u32 b);
extern u32 FIELD_EFFECT_GetFieldMapData(u8 *p);
extern void FIELD_EFFECT_AddObject(void *a, void *b, u32 c, u32 d, void *e, u32 f);
extern char sHideFuncs[];

void FLDEFF_HIDE_Start(void *a, u32 b, u32 c)
{
    Arg021D046C arg;

    arg.h1 = FIELD_EFFECT_GetResource((u32)a, 0xf);
    arg.h2 = FIELD_EFFECT_GetFieldMapData(a);
    arg.b = b;
    arg.c = c;
    FIELD_EFFECT_AddObject(a, sHideFuncs, 0, 0, &arg, 0);
}
