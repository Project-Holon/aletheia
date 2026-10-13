/*
 * function: FIELD_BUILDMODEL_CreateModels
 * address:  0x0218BD28
 * packet:   pkt_ov021_0218BD28
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   FIELD_BUILDMODEL_LoadModel  0x0218BEE8  thumb  ov021
 *   gBuildModelFileName     0x021DD9CC  data  a4
 */

typedef struct {
    unsigned short heap;
    unsigned char pad[0x1AA];
    unsigned short n;
    unsigned char pad2[0x1A];
    unsigned int count;
    unsigned char *ents;
} S;

extern unsigned char gBuildModelFileName[];
void *func_02030734(unsigned int heap, unsigned int size, int clear, const char *site, unsigned short tag);
void FIELD_BUILDMODEL_LoadModel(S *p, unsigned char *e, int i, int arg);

void FIELD_BUILDMODEL_CreateModels(S *p, int arg)
{
    unsigned short n = p->n;
    unsigned char i;
    if (n != 0) {
        p->count = n;
        p->ents = func_02030734(p->heap, n * 0x18, 1, (const char *)gBuildModelFileName, 0x45F);
        for (i = 0; i < p->count; i++)
            FIELD_BUILDMODEL_LoadModel(p, p->ents + i * 0x18, i, arg);
    }
}
