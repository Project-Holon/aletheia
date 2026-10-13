/*
 * function: func_021A82A8
 * address:  0x021A82A8
 * packet:   pkt_ov021_021A82A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A8268  0x021A8268  thumb
 *   FIELD_BUILDMODEL_PlayNodeSlot  0x0218C88C  thumb
 *   FIELD_BUILDMODEL_GetNodeCurrentKindTableEntry  0x0218C990  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 */

typedef unsigned short u16;

typedef struct {
    int pad[10];
    int f28;
} S;

extern int func_021A8268(unsigned int a);
extern void FIELD_BUILDMODEL_PlayNodeSlot(unsigned char *p, int v, int c);
extern int FIELD_BUILDMODEL_GetNodeCurrentKindTableEntry(unsigned char *p, int v);
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);

void func_021A82A8(S *s)
{
    u16 v;
    if (func_021A8268((unsigned int)s)) {
        FIELD_BUILDMODEL_PlayNodeSlot((unsigned char *)s->f28, 1, 0);
        if (FIELD_BUILDMODEL_GetNodeCurrentKindTableEntry((unsigned char *)s->f28, (int)(&v))) {
            GFL_USE_PlaySeDefaultVolume(v);
        }
    }
}
