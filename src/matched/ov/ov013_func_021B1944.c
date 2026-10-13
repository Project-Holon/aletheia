/*
 * function: VCT_AUDIO_PopReadyPacket
 * address:  0x021B1944
 * packet:   pkt_ov013_021B1944
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   VCT_POOL_FreeFrame  0x021B2FE4  arm  ov013
 *   gVctReadyHead  0x021B4BAC  data  a4
 *   gVctReadyCount  0x021B4BB8  data  a4
 *   gVctReadyTail  0x021B4BC4  data  a4
 */

typedef unsigned int u32;
typedef struct Node { u32 f0; struct Node *prev; struct Node *next; u32 f0c; unsigned char f10; unsigned char type; } Node;
extern u32 func_02087988(void);
extern void func_0208799C(u32 h);
extern void VCT_POOL_FreeFrame(Node *n);
extern Node *gVctReadyHead[];
extern u32 gVctReadyCount[];
extern Node *gVctReadyTail[];

Node *VCT_AUDIO_PopReadyPacket(u32 t)
{
    Node *n;
    u32 h = func_02087988();

    n = gVctReadyHead[t];
    if (n) {
        Node *next = n->next;

        gVctReadyHead[t] = next;
        gVctReadyCount[t]--;
        if (next)
            next->prev = 0;
        else
            gVctReadyTail[t] = 0;
    }
    func_0208799C(h);
    return (Node *)gVctReadyCount[t];
}
