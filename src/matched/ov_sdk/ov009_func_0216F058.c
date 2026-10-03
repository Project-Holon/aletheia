/*
 * function: func_0216F058
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
 *   func_0216BA08  0x0216BA08  arm  ov009
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_02176358  0x02176358  arm  ov009
 *   func_0216F014  0x0216F014  arm  ov009
 */

typedef struct {
    int pid;
    unsigned int bitmap;
    int id;
} Poll;

extern int func_0216BA08(void);
extern int func_02175F3C(void);
extern void *func_02176358(void);
extern void func_0216F014(unsigned int bitmap);

void func_0216F058(const Poll *p)
{
    int pid = p->pid;
    unsigned int bitmap = p->bitmap;
    int id = p->id;
    int *node;

    if (func_0216BA08() != 0) {
        return;
    }
    if (id != *(int *)(func_02175F3C() + 0x7c8)) {
        return;
    }
    node = func_02176358();
    if (node == 0) {
        return;
    }
    if (*node != pid) {
        return;
    }
    func_0216F014(bitmap);
}
