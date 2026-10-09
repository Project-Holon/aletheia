/*
 * file:     unit_02176B68.c
 * unit:     yes
 * function: func_02176B68, func_02176B80, func_02176BE4
 * address:  0x02176B68
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_CleanupReliableQueue (libdwcmatch.TWL.HYB.a dwc_reliable.o)
 *
 * symbols:
 *   DWC_Free    0x0205A1B0  arm
 *   g_021AB178  0x021AB178  data
 */

typedef struct SendQueue {
    struct SendQueue *f0;
    void *f4;
    int f8;
    struct SendQueue *fC;
} SendQueue;

typedef struct QueueInfo {
    SendQueue *head;
    int size;
} QueueInfo;

extern void DWC_Free(int kind, void *p, int size);
extern QueueInfo g_021AB178;

/*
 * Clears both words of the queue state object.
 */
/*
 * Clears the first two words of the state object.
 */
void func_02176B68(void)
{
    g_021AB178.head = 0;
    g_021AB178.size = 0;
}

void func_02176B80(char *p)
{
    SendQueue *it;

    while ((it = g_021AB178.head) != 0) {
        g_021AB178.head = it->fC;
        DWC_Free(4, it->f4, it->f8);
        DWC_Free(4, it, 0);
    }
    g_021AB178.head = 0;
    g_021AB178.size = 0;
}

/*
 * Set while the queue size is under 0x6000.
 */
/*
 * Set while the word at +4 of the state object is under 0x6000.
 */
int func_02176BE4(void)
{
    return g_021AB178.size < 0x6000;
}