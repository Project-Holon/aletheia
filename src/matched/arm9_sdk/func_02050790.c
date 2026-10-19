/*
 * function: BILLBOARD_ACT_Draw
 * address:  0x02050790
 * packet:   pkt_02050790
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_LSTlPopFront (libdwcutil.TWL.HYB.a list.o)
 *
 * symbols:
 *   DWCi_LSTlErase 0x0204F7DC arm
 */

typedef struct tagLISTCB {
    void *head;
    void *tail;
} LISTCB;

extern void DWCi_LSTlErase(void *ob);

void BILLBOARD_ACT_Draw(LISTCB *list, int b, int c)
{
    DWCi_LSTlErase(list->tail);
}
