/*
 * function: BTLV_EFFECT_DeleteTask
 * address:  0x021F89BC
 * packet:   pkt_ov094_021F9AB8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlvEff     0x0220AF20  data   ov094
 *   GFL_HEAP_Free   0x020307B0  arm
 *   TCB_DeleteTask   0x02030EAC  arm
 *   TCBL_GetOwnedWork   0x02030EE8  arm
 *   BTLV_EFFECT_FindTaskIndex  0x021F899C  thumb  ov094
 */
typedef struct {
    char pad[8];
    void *handle[32];      /* 0x008 */
    void (*cb[32])(void *); /* 0x088 */
    int arg[32];           /* 0x108 */
} Work;

extern Work *gBtlvEff;

typedef unsigned int u32;

extern int BTLV_EFFECT_FindTaskIndex(void *h);
struct Node;
struct S02030EE8;
extern u32 TCBL_GetOwnedWork(struct S02030EE8 *p);
extern void TCB_DeleteTask(struct Node *n);
extern u32 GFL_HEAP_Free(void *p);

void BTLV_EFFECT_DeleteTask(void *h)
{
    int i = BTLV_EFFECT_FindTaskIndex(h);
    void *w;

    if (h == 0)
        return;
    w = (void *)TCBL_GetOwnedWork(h);
    if (gBtlvEff->cb[i] != 0)
        gBtlvEff->cb[i](h);
    if (w != 0)
        GFL_HEAP_Free(w);
    TCB_DeleteTask(h);
    gBtlvEff->handle[i] = 0;
    gBtlvEff->cb[i] = 0;
}
