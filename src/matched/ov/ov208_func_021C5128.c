/*
 * function: ZUKAN_DETAIL_FORM_CreateModelItem
 * address:  0x021C5128
 * packet:   pkt_ov208_021C5128
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZUKAN_DETAIL_FORM_AddModel  0x021C5000  thumb
 *   func_02030734  0x02030734  arm
 *   MCSS_GetAnimCtrl  0x02015EE8  thumb
 *   NNS_G2dSetCellAnimationParam  0x02063000  arm
 *   ZUKAN_DETAIL_FORM_OnAnimStopRequest  0x021C5248  thumb
 *   ZUKAN_DETAIL_FORM_GetModelOffsets  0x021C7F6C  thumb
 *   data_021C8E64  0x021C8E64  data
 */

typedef unsigned int u32;

typedef struct {
    float x;
    float y;
    float z;
} VecF;

struct Ov208Mdl {
    u32 obj;
    void *turn;
    VecF pos[5];
};

extern u32  ZUKAN_DETAIL_FORM_AddModel(void *sys, u32 species, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6,
                                u32 a7);
typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *MCSS_GetAnimCtrl(void *p);
extern void NNS_G2dSetCellAnimationParam(int p0, int p1, int p2, int p3);
extern void ZUKAN_DETAIL_FORM_OnAnimStopRequest(void *work);
extern void ZUKAN_DETAIL_FORM_GetModelOffsets(VecF *pos, u32 species, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6,
                                u32 a7);
extern const char data_021C8E64[];

void ZUKAN_DETAIL_FORM_CreateModelItem(struct Ov208Mdl *m, u32 heap, void *sys, u32 species, u32 a4, u32 a5,
                         u32 a6, u32 a7, u32 a8, u32 a9)
{
    m->obj = ZUKAN_DETAIL_FORM_AddModel(sys, species, a4, a5, a6, a7, a8, a9);
    m->turn = func_02030734(heap, 0x10, 1, data_021C8E64, 0xab1);
    NNS_G2dSetCellAnimationParam((int)MCSS_GetAnimCtrl((void *)m->obj), 1, (int)m->turn, (int)ZUKAN_DETAIL_FORM_OnAnimStopRequest);
    ZUKAN_DETAIL_FORM_GetModelOffsets(m->pos, species, a4, a5, a6, a7, a8, a9);
}
