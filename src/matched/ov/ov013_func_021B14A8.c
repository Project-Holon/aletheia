/*
 * function: VCT_AUDIO_FindPending
 * address:  0x021B14A8
 * packet:   pkt_ov013_021B14A8
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
 *   gVctPendingList  0x021B4B98  data  a4
 */

typedef unsigned int u32;
typedef struct Node { u32 f0; struct Node *prev; struct Node *next; u32 f0c; unsigned char f10; unsigned char type; } Node;
extern u32 func_02087988(void);
extern void func_0208799C(u32 h);
extern Node *gVctPendingList[2];

Node *VCT_AUDIO_FindPending(u32 type)
{
    Node *p = gVctPendingList[0];
    u32 h = func_02087988();

    for (; p; p = p->next) {
        if (p->type == type) {
            func_0208799C(h);
            return p;
        }
    }
    func_0208799C(h);
    return 0;
}
