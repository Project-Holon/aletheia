/*
 * function: FIELD_BUILDMODEL_RegisterObject
 * address:  0x0218BA04
 * packet:   pkt_ov021_0218BA04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_BUILDMODEL_GetModelIndex  0x0218BBD0  thumb  ov021
 *   FIELD_BUILDMODEL_AddEntry  0x0218C4A0  thumb  ov021
 */

/*
 * The const on s is load-bearing: it settles the store order and keeps the
 * move of d into r3 next to the call.
 */
typedef struct {
    int x;
    int y;
    int z;
    unsigned short w;
    unsigned char hi;
    unsigned char lo;
} Src;

typedef struct {
    int k;
    int x;
    int y;
    int z;
    unsigned short w;
} Args;

int FIELD_BUILDMODEL_GetModelIndex(void *p, unsigned int i);
void FIELD_BUILDMODEL_AddEntry(void *p, int a, Args *args, int d);

static inline void Args_SetPos(Args *v, int x, int y, int z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}

void FIELD_BUILDMODEL_RegisterObject(void *p, int a, const Src *s, int d)
{
    Args args;
    args.k = FIELD_BUILDMODEL_GetModelIndex(p, (unsigned short)(s->lo + (s->hi << 8)));
    Args_SetPos(&args, s->x, s->y, -s->z);
    args.w = s->w;
    FIELD_BUILDMODEL_AddEntry(p, a, &args, d);
}
