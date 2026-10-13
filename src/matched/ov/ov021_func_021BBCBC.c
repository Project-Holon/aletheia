/*
 * function: FLDEFF_FOOTMARK_Init
 * address:  0x021BBCBC
 * packet:   pkt_ov021_021BBCBC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   FIELD_EFFECT_GetFieldMap  0x021ABE14  thumb  ov021
 *   FIELDMAP_GetEffectBbdAct  0x02188C88  thumb  ov021
 *   FLDEFF_FOOTMARK_InitResource  0x021BBD0C  thumb  ov021
 *   d_021DE30C  0x021DE30C  data
 */

typedef unsigned int u32;

typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
typedef unsigned char  u8;
extern u32 FIELD_EFFECT_GetFieldMap(u8 *p);
extern u32 FIELDMAP_GetEffectBbdAct(u8 *p);
extern void FLDEFF_FOOTMARK_InitResource(u32 *p);
extern const char d_021DE30C[];

typedef struct {
    void *owner;
    void *res;
    char pad[0x34];
    int f3c;
} Obj;

Obj *FLDEFF_FOOTMARK_Init(void *owner, u32 heap)
{
    Obj *o;

    o = func_02030734(heap, 0x40, 1, d_021DE30C, 0x9d);
    o->owner = owner;
    o->res = (void *)FIELDMAP_GetEffectBbdAct((u8 *)FIELD_EFFECT_GetFieldMap(owner));
    FLDEFF_FOOTMARK_InitResource((u32 *)o);
    o->f3c = 0x2000;
    return o;
}
