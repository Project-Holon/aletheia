/*
 * function: BOX2_SEQ_SetActorAnim
 * address:  0x021EA878
 * packet:   pkt_ov170_021EA878
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CURSOR_MOVE_SetSkipBit 0x0202614C thumb
 *   CURSOR_MOVE_ClearSkipBit 0x02026124 thumb
 *   BOX2_SEQ_DrawFrameList 0x021EB988 thumb
 *   d_021EF8FC 0x021EF8FC data a1
 *   d_021EF8F4 0x021EF8F4 data a1
 */

typedef struct {
    unsigned char pad0[0x16];
    unsigned char b16;
    unsigned char pad17[0x2C - 0x17];
    char *work;
} Obj;

typedef unsigned int   u32;
struct Sound;
extern void CURSOR_MOVE_SetSkipBit(struct Sound *obj, u32 idx);
extern void CURSOR_MOVE_ClearSkipBit(struct Sound *obj, u32 idx);
extern void BOX2_SEQ_DrawFrameList(Obj *p, const void *e, unsigned n);
extern const unsigned char d_021EF8FC[];
extern const unsigned char d_021EF8F4[];

#define OBJ(p) (*(void **)((p)->work + 0x70))

void BOX2_SEQ_SetActorAnim(Obj *p, int v)
{
    if (v != 0) {
        if (p->b16 < 0x1E)
            CURSOR_MOVE_SetSkipBit(OBJ(p), 0x24);
        else
            CURSOR_MOVE_SetSkipBit(OBJ(p), 9);
        BOX2_SEQ_DrawFrameList(p, d_021EF8FC, 3);
    } else {
        if (p->b16 < 0x1E)
            CURSOR_MOVE_ClearSkipBit(OBJ(p), 0x24);
        else
            CURSOR_MOVE_ClearSkipBit(OBJ(p), 9);
        BOX2_SEQ_DrawFrameList(p, d_021EF8F4, 2);
    }
}
