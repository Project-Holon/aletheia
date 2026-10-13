/*
 * function: FIELD_EFFECT_LoadResources
 * address:  0x021ABE30
 * packet:   pkt_ov021_021ABE30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_EFFECT_FindResourceSlot  0x021ABF2C  thumb
 *   FIELD_EFFECT_GetResourceDef  0x021ABF48  thumb
 */

typedef unsigned short u16;

typedef struct {
    int f0;
    int f4;
} E;

typedef struct T T;

typedef struct {
    int id;
    int (*f4)(T *t, u16 h);
    void (*f8)(T *t, int v);
} D;

struct T {
    int f0;
    u16 h4;
    u16 pad6;
    int pad8[2];
    E *f10;
};

extern E *FIELD_EFFECT_FindResourceSlot(T *t, int id);
extern D *FIELD_EFFECT_GetResourceDef(int id);

void FIELD_EFFECT_LoadResources(T *t, int *arr, int n)
{
    E *e;
    D *d;
    for (; n != 0; n--) {
        e = FIELD_EFFECT_FindResourceSlot(t, 0x18);
        d = FIELD_EFFECT_GetResourceDef(*arr);
        e->f0 = *arr;
        e->f4 = d->f4(t, t->h4);
        arr++;
    }
}
