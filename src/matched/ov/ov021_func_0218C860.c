/*
 * function: FIELD_BUILDMODEL_DeleteNode
 * address:  0x0218C860
 * packet:   pkt_ov021_0218C860
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_BUILDMODEL_RemoveNode  0x0218BA48  thumb  ov021
 *   FIELD_BUILDMODEL_FreeAnimSet  0x0218C0D8  thumb  ov021
 *   FIELD_BUILDMODEL_SwapEntryModelId  0x0218C54C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 */

void FIELD_BUILDMODEL_RemoveNode(void *s, void *v);
void FIELD_BUILDMODEL_FreeAnimSet(void **s);
void FIELD_BUILDMODEL_SwapEntryModelId(void *p, int save);
typedef unsigned int   u32;
u32 func_020307B0(void *p);

typedef struct {
    void *owner;
    int f4;
    void *f8;
    unsigned char fC[1];
} S;

void FIELD_BUILDMODEL_DeleteNode(S *p)
{
    if (p != 0) {
        FIELD_BUILDMODEL_RemoveNode(p->owner, p);
        FIELD_BUILDMODEL_FreeAnimSet((void **)p->fC);
        if (p->f8 != 0)
            FIELD_BUILDMODEL_SwapEntryModelId(p->f8, 1);
        func_020307B0(p);
    }
}
