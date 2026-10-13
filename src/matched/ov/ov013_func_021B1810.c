/*
 * function: VCT_AUDIO_InsertReadyPacket
 * address:  0x021B1810
 * packet:   pkt_ov013_021B1810
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gVctReadyHead  0x021B4BAC  data  ov013  a4
 *   gVctReadyCount  0x021B4BB8  data  ov013  a4
 *   gVctReadyTail  0x021B4BC4  data  ov013  a4
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 */

typedef unsigned int u32;

typedef struct Node {
    u32 f0;
    struct Node *next;
    struct Node *prev;
    u32 fC;
    u32 f10;
    u32 f14;
    u32 key;
} Node;

extern Node *gVctReadyHead[3];
extern int gVctReadyCount[3];
extern Node *gVctReadyTail[3];

extern int func_02087988(void);
extern void func_0208799C(int);

int VCT_AUDIO_InsertReadyPacket(Node *n, u32 idx)
{
    int irq;
    Node *cur;

    if (n == 0)
        return -1;
    if (idx >= 3)
        return -1;

    irq = func_02087988();
    if (gVctReadyHead[idx] == 0) {
        gVctReadyHead[idx] = n;
        n->next = 0;
        gVctReadyHead[idx]->prev = 0;
        gVctReadyTail[idx] = gVctReadyHead[idx];
    } else {
        for (cur = gVctReadyTail[idx]; cur != 0; cur = cur->next) {
            if (cur->key < n->key) {
                n->next = cur;
                n->prev = cur->prev;
                cur->prev = n;
                if (n->prev != 0)
                    n->prev->next = n;
                if (cur == gVctReadyTail[idx])
                    gVctReadyTail[idx] = n;
                goto done;
            }
        }
        n->next = 0;
        n->prev = gVctReadyHead[idx];
        gVctReadyHead[idx]->next = n;
        gVctReadyHead[idx] = n;
    }
done:
    gVctReadyCount[idx]++;
    func_0208799C(irq);
    return gVctReadyCount[idx];
}
