/*
 * function: BTLV_SCU_TaskMonSendOut
 * address:  0x021ED460
 * packet:   pkt_ov093_021ED460
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 *   BTLV_SCU_ShowMonSlot  0x021EDA04  thumb  ov093
 *   TCBL_DeleteTask  0x02031194  arm  arm9
 */
typedef unsigned char u8;
typedef unsigned short u16;
struct Q { u8 *a; u16 state; u8 *cnt; };
extern int func_021F7EB4(void);
struct E;
extern void BTLV_SCU_ShowMonSlot(struct E *e);
struct TcblNode;
extern void TCBL_DeleteTask(struct TcblNode *n);
void BTLV_SCU_TaskMonSendOut(void *task, struct Q *q)
{
    switch (q->state) {
    case 0:
        if (func_021F7EB4() == 0) {
            BTLV_SCU_ShowMonSlot((struct E *)q->a);
            q->state = q->state + 1;
        }
        break;
    case 1:
        (*q->cnt)--;
        TCBL_DeleteTask(task);
        break;
    }
}
