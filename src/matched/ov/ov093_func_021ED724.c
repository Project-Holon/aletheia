/*
 * function: BTLV_SCU_TaskMonGraphicSwap
 * address:  0x021ED724
 * packet:   pkt_ov093_021ED724
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_EFFECT_StartHitTask  0x021F7D80  thumb  ov094
 *   BTLV_EFFECT_ResetPokeSprite  0x021F7E38  thumb  ov094
 *   BTLV_EFFECT_IsBusy  0x021F7EB4  thumb  ov094
 *   TCBL_DeleteTask  0x02031194  arm
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

struct S { char *w; u32 k; void *v; u32 c; u8 pad10; u8 f; u8 pad12[2]; u8 *cnt; };

extern void BTLV_EFFECT_StartHitTask(void *a, int b);
extern void BTLV_EFFECT_ResetPokeSprite(void *a, int b);
extern int BTLV_EFFECT_IsBusy(void);
struct TcblNode;
extern void TCBL_DeleteTask(struct TcblNode *n);

void BTLV_SCU_TaskMonGraphicSwap(u32 x, struct S *t)
{
    switch (t->c) {
    case 0:
        if (t->f == 0)
            BTLV_EFFECT_StartHitTask(t->v, t->k);
        else
            BTLV_EFFECT_ResetPokeSprite(t->v, t->k);
        t->c++;
        break;
    case 1:
        if (BTLV_EFFECT_IsBusy() == 0) {
            (*t->cnt)--;
            TCBL_DeleteTask((struct TcblNode *)x);
        }
        break;
    }
}
