/*
 * function: FLDEFF_ENCOUNT_LoadKind
 * address:  0x021AD7E4
 * packet:   pkt_ov021_021AD7E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_EFFECT_GetArcHandle  0x021ABE24  thumb  ov021
 *   FLDEFF_ENCOUNT_LoadKind0Models  0x021AD8DC  thumb  ov021
 *   FLDEFF_ENCOUNT_LoadModels  0x021AD96C  thumb  ov021
 *   sEncountModelDescs     0x021DE094  data  a2
 */
typedef unsigned short u16;

typedef struct Rec {
    u16 h[7];
} Rec;

extern Rec sEncountModelDescs[];
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 FIELD_EFFECT_GetArcHandle(u8 *p);
struct Desc;
struct P;
extern void FLDEFF_ENCOUNT_LoadKind0Models(struct P *a, struct Desc *d, int c);
extern void FLDEFF_ENCOUNT_LoadModels(struct P *a, struct Desc *d, int c);

#define R(a) ((Rec *)((char *)(a) + 0x88))

void FLDEFF_ENCOUNT_LoadKind(int *a, u32 b)
{
    int t;

    *R(a) = sEncountModelDescs[b];
    t = FIELD_EFFECT_GetArcHandle((u8 *)(*a));
    if (b == 0) {
        FLDEFF_ENCOUNT_LoadKind0Models((struct P *)a, (struct Desc *)R(a), t);
    } else {
        FLDEFF_ENCOUNT_LoadModels((struct P *)a, (struct Desc *)R(a), t);
    }
}
