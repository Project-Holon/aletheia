/*
 * file:     dwc_reliable.c
 * unit:     yes
 * function: func_02176B68, func_02176B80, func_02176BE4, func_02176C00, func_02176C14, func_02176CF8
 * address:  0x02176B68
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * sdk:      DWCi_CleanupReliableQueue (libdwcmatch.TWL.HYB.a dwc_reliable.o)
 * Tail call passing the address of func_02195CC0 as the first argument.
 *
 * symbols:
 *   DWC_Free    0x0205A1B0  arm
 *   g_021AB178  0x021AB178  data
 *   func_02195CC0  0x02195CC0  arm  ov009
 *   DWC_Alloc       0x0205A16C  arm
 *   MIi_CpuCopy32   0x02082A90  arm
 *   g_021AB178_head 0x021AB178  data
 */
typedef struct SendQueue {
    void *connection;
    unsigned char *data;
    int size;
    struct SendQueue *next;
} SendQueue;

typedef struct QueueInfo {
    SendQueue *head;
    int total;
} QueueInfo;

extern void DWC_Free(int kind, void *p, int size);
extern void func_02195CC0(void);
extern void *DWC_Alloc(int kind, int size);
extern void MIi_CpuCopy32(void *src, void *dst, int size);
void func_02176B68(void);
void func_02176B80(char *p);
int func_02176BE4(void);
int func_02176C00(void);
int func_02176C14(int (*func)(void *, unsigned char *, int, int));
int func_02176CF8(void *connection, unsigned char *buffer, int size);
extern QueueInfo g_021AB178;
extern SendQueue *g_021AB178_head;


/*
 * Clears both words of the queue state object.
 */
/*
 * Clears the first two words of the state object.
 */
void func_02176B68(void)
{
    g_021AB178.head = 0;
    g_021AB178.total = 0;
}


void func_02176B80(char *p)
{
    SendQueue *it;

    while ((it = g_021AB178.head) != 0) {
        g_021AB178.head = it->next;
        DWC_Free(4, it->data, it->size);
        DWC_Free(4, it, 0);
    }
    g_021AB178.head = 0;
    g_021AB178.total = 0;
}


/*
 * Set while the queue size is under 0x6000.
 */
/*
 * Set while the word at +4 of the state object is under 0x6000.
 */
int func_02176BE4(void)
{
    return g_021AB178.total < 0x6000;
}


int func_02176C00(void)
{
    return func_02176C14((int (*)(void *, unsigned char *, int,  int))func_02195CC0);
}



/*
 * sdk:      DWCi_ProcessReliableQueueEx (libdwcmatch.TWL.HYB.a dwc_reliable.o)
 */
int func_02176C14(int (*func)(void *, unsigned char *, int, int))
{
    SendQueue *it;
    int retrycount;
    int res;

    for (it = g_021AB178.head; it != 0; it = it->next) {
        retrycount = 0;
        do {
            res = func(it->connection, it->data, it->size, 1);
            if (res == 0) {
                g_021AB178.total -= it->size;
                DWC_Free(4, it->data, it->size);
                it->data = 0;
                it->size = 0;
                it->connection = 0;
                break;
            }
            retrycount++;
        } while (retrycount < 3);
        if (retrycount == 3)
            break;
    }
    for (it = g_021AB178.head; it != 0; it = g_021AB178.head) {
        if (it->data != 0)
            break;
        g_021AB178.head = it->next;
        DWC_Free(4, it, 0);
    }
    return it == 0;
}



/*
 * residue (lane T3, 2026-09-30, measured): compiled 236 vs 244 (-8). First diff +0004 image `ldr r3, [pc, #0xe0]` | ours `ldr r6, [pc, #0xdc]` (two literal-pool loads of the queue info merged into one). Pin/flag sweep (9x7) best -O4,p at 188 diffs; -O4,s/-O4 are 90 (worse). Not re-spelled (budget).
 *
 * sdk:      DWCi_InsertReliableQueue (libdwcmatch.TWL.HYB.a dwc_reliable.o)
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
            target = &it->next;
            it = it->next;
        } while (it != 0);
    }
    *target = DWC_Alloc(4, sizeof(SendQueue));
    if (*target == 0)
        return 0;
    (*target)->data = DWC_Alloc(4, size);
    if ((*target)->data == 0) {
        DWC_Free(4, *target, sizeof(SendQueue));
        *target = 0;
        return 0;
    }
    (*target)->connection = connection;
    (*target)->size = size;
    (*target)->next = 0;
    MIi_CpuCopy32(buffer, (*target)->data, size);
    g_021AB178.total += size;
    return 1;
}
