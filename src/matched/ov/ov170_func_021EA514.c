/*
 * function: BOX2_SEQ_MoveGridCursor
 * address:  0x021EA514
 * packet:   pkt_ov170_021EA514
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_GetActorSurfacePos 0x021EC0B0 thumb
 *   BOX2_SEQ_AddActorSurfacePos 0x021EC08C thumb
 *   BOX2_SEQ_SetSlotDim 0x021ED6E4 thumb
 *   BOX2_SEQ_UpdateGridCursor 0x021EA4DC thumb
 *   BOX2_MAIN_CompareSlots 0x021DDE80 thumb
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb
 *   BOX2_SEQ_StateMenuSwap 0x021E1458 thumb
 */

typedef struct {
    unsigned char pad0[0x16];
    unsigned char b16;
    unsigned char pad17;
    unsigned char b18;
    unsigned char pad19[0x2C - 0x19];
    char *work;
} Obj;

extern void BOX2_SEQ_GetActorSurfacePos(char *p, int i, short *a, short *b, unsigned short space);
extern void BOX2_SEQ_AddActorSurfacePos(char *p, int i, int a, int b, unsigned short c);
extern void BOX2_SEQ_SetSlotDim(char **p, int v);
extern int BOX2_SEQ_UpdateGridCursor(Obj *p);
extern int BOX2_MAIN_CompareSlots(unsigned char *p, unsigned a, unsigned b);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_SEQ_StateMenuSwap(char *p);

#define SEL(p) (*(unsigned char *)((p)->work + 0xA17E))

int BOX2_SEQ_MoveGridCursor(Obj *p, unsigned i)
{
    short t[2];
    SEL(p) = i;
    p->b18 = 0;
    BOX2_SEQ_GetActorSurfacePos(p->work, 4, &t[1], &t[0], 0);
    BOX2_SEQ_AddActorSurfacePos(p->work, 10, (short)t[1], (short)(t[0] + 8), (short)0);
    BOX2_SEQ_SetSlotDim((char **)p, 0);
    if (SEL(p) == 0xFF)
        return BOX2_SEQ_UpdateGridCursor(p);
    if (BOX2_MAIN_CompareSlots((unsigned char *)p, p->b16, i) == 0)
        return BOX2_SEQ_UpdateGridCursor(p);
    return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_SEQ_StateMenuSwap, 0x45);
}
