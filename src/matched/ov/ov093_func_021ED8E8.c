/*
 * function: BTLV_SCU_TaskMsgWinFadeOut
 * address:  0x021ED8E8
 * packet:   pkt_ov093_021ED8E8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_SCU_StartMsgWinFadeOut  0x021ED798  thumb  ov093
 *   BTLV_SCU_UpdateMsgWinFade  0x021ED814  thumb  ov093
 *   TCBL_DeleteTask  0x02031194  arm
 */

typedef unsigned char u8;

struct Sub {
    u8 pad[0x14];
};

struct Q {
    char *f00;
    int f04;
    u8 *f08;
};

struct S;
extern void BTLV_SCU_StartMsgWinFadeOut(struct S *s);
extern int BTLV_SCU_UpdateMsgWinFade(struct S *s);
struct TcblNode;
extern void TCBL_DeleteTask(struct TcblNode *n);

void BTLV_SCU_TaskMsgWinFadeOut(int a,struct Q *q)
{
    switch (q->f04) {
    case 0:
        BTLV_SCU_StartMsgWinFadeOut((struct S *)(q->f00 + 0x154));
        q->f04++;
        break;
    case 1:
        if (BTLV_SCU_UpdateMsgWinFade((struct S *)(q->f00 + 0x154)) != 0) {
            (*q->f08)--;
            TCBL_DeleteTask((struct TcblNode *)a);
        }
        break;
    }
}
