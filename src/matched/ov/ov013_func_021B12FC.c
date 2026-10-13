/*
 * function: VCT_AUDIO_ResetPendingList
 * address:  0x021B12FC
 * packet:   pkt_ov013_021B12FC
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   g_021B4B98     0x021B4B98  data  a4
 *   g_021B4BA0     0x021B4BA0  data  a4
 */

extern int OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(int s);

extern struct {
    void *head;
    void *tail;
} g_021B4B98;
extern int g_021B4BA0[3];

void VCT_AUDIO_ResetPendingList(void)
{
    int s;
    int i;

    s = OS_DisableInterrupts();
    g_021B4B98.tail = 0;
    g_021B4B98.head = 0;
    for (i = 0; i < 3; i++) {
        g_021B4BA0[i] = 0;
    }
    OS_RestoreInterrupts(s);
}
