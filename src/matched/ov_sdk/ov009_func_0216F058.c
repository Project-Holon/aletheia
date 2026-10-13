/*
 * function: DWCi_ProcessMatchPollingPacket
 * address:  0x0216F058
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWCi_ProcessMatchPollingPacket: on a client, closes the aids a server poll no longer lists.
 *
 * symbols:
 *   DWC_IsServerMyself  0x0216BA08  arm  ov009
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   DWCi_NodeInfoList_GetServerNodeInfo  0x02176358  arm  ov009
 *   DWCi_CheckDeadAIDBitmap  0x0216F014  arm  ov009
 */

typedef struct {
    int pid;
    unsigned int bitmap;
    int id;
} Poll;

extern int DWC_IsServerMyself(void);
extern int func_02175F3C(void);
extern void *DWCi_NodeInfoList_GetServerNodeInfo(void);
extern void DWCi_CheckDeadAIDBitmap(unsigned int bitmap);

void DWCi_ProcessMatchPollingPacket(const Poll *p)
{
    int pid = p->pid;
    unsigned int bitmap = p->bitmap;
    int id = p->id;
    int *node;

    if (DWC_IsServerMyself() != 0) {
        return;
    }
    if (id != *(int *)(func_02175F3C() + 0x7c8)) {
        return;
    }
    node = DWCi_NodeInfoList_GetServerNodeInfo();
    if (node == 0) {
        return;
    }
    if (*node != pid) {
        return;
    }
    DWCi_CheckDeadAIDBitmap(bitmap);
}
