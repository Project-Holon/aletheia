/*
 * function: func_02176CF8
 * address:  0x02176CF8
 * packet:   pkt_ov009_02176CF8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF (capped - see residue)
 *
 * residue (lane T3, 2026-09-30, measured): compiled 236 vs 244 (-8). First diff +0004 image `ldr r3, [pc, #0xe0]` | ours `ldr r6, [pc, #0xdc]` (two literal-pool loads of the queue info merged into one). Pin/flag sweep (9x7) best -O4,p at 188 diffs; -O4,s/-O4 are 90 (worse). Not re-spelled (budget).
 *
 * sdk:      DWCi_InsertReliableQueue (libdwcmatch.TWL.HYB.a dwc_reliable.o)
 *
 * symbols:
 *   DWC_Alloc       0x0205A16C  arm
 *   DWC_Free        0x0205A1B0  arm
 *   MIi_CpuCopy32   0x02082A90  arm
 *   g_021AB178      0x021AB178  data
 *   g_021AB178_head 0x021AB178  data
 *
 * The image carries TWO literal-pool words for the queue info: r3 for the
 * count/head field reads and r6 for the `target` cursor.  mwccarm emits one
 * pool word per (symbol, addend), so two words for one address means the
 * source reached it through two names.  Declaring a second extern
 * (`g_021AB178_head`) at the same address for `target = &...` reproduces both
 * words and closes the whole 188-byte diff in one step; with one name the
 * compiler CSEs them into r6 and the function is 8 bytes short.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov009_func_02176CF8.c  *       --func func_02176CF8 --addr 0x02176CF8 --region ov009 --arm --lang c99 --cc 1.1p1 --diff
 */

typedef struct SendQueue {
    void *f0;
    unsigned char *f4;
    int f8;
    struct SendQueue *fC;
} SendQueue;

typedef struct QueueInfo {
    SendQueue *head;
    int total;
} QueueInfo;

extern void *DWC_Alloc(int kind, int size);
extern void DWC_Free(int kind, void *p, int size);
extern void MIi_CpuCopy32(void *src, void *dst, int size);
extern QueueInfo g_021AB178;
extern SendQueue *g_021AB178_head;

int func_02176CF8(void *connection, unsigned char *buffer, int size)
{
    SendQueue *it;
    SendQueue **target = &g_021AB178_head;
    QueueInfo *q = &g_021AB178;

    if (q->total + size > 0x8000)
        return 0;
    it = q->head;
    if (it != 0) {
        do {
            target = &it->fC;
            it = it->fC;
        } while (it != 0);
    }
    *target = DWC_Alloc(4, sizeof(SendQueue));
    if (*target == 0)
        return 0;
    (*target)->f4 = DWC_Alloc(4, size);
    if ((*target)->f4 == 0) {
        DWC_Free(4, *target, sizeof(SendQueue));
        *target = 0;
        return 0;
    }
    (*target)->f0 = connection;
    (*target)->f8 = size;
    (*target)->fC = 0;
    MIi_CpuCopy32(buffer, (*target)->f4, size);
    g_021AB178.total += size;
    return 1;
}
