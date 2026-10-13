/*
 * function: EFFECT_ENCOUNT_RestoreSpot
 * address:  0x021AAB74
 * packet:   pkt_ov021_021AAB74
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012A38  0x02012A38  thumb
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb
 *   EFFECT_ENCOUNT_CreateEffectObj  0x021AAFC0  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 */

typedef struct Ent {
    unsigned short id;
    short x;
    short y;
    short z;
    unsigned long w;
    unsigned char b;
    unsigned char flags : 4;
    unsigned char f4 : 2;
    unsigned char f6 : 2;
} Ent;

typedef struct Self {
    void *ctx;
    char pad04[4];
    void *obj;
} Self;

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct BigObj;
extern u32 func_02012A38(const struct BigObj *p);
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern void EFFECT_ENCOUNT_CreateEffectObj(Self *self, int a, Ent *e);
extern void MI_CpuFill8(void *p, int v, unsigned long n);

void EFFECT_ENCOUNT_RestoreSpot(Self *self, int a)
{
    Ent *e = (Ent *)(func_02012A38(self->obj) + 0x10);
    unsigned short id;

    if (e->flags == 0 || e->f4 == 0)
        return;
    e->f4 = 0;
    id = FIELDMAP_GetZoneId(self->ctx);
    if (id != e->id || e->f6 != 0)
        MI_CpuFill8(e, 0, 0x10);
    else
        EFFECT_ENCOUNT_CreateEffectObj(self, a, e);
}
