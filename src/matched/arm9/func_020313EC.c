/*
 * function: PROCSYS_MainInternal
 * address:  0x020313EC
 * packet:   pkt_020313EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   PROCSYS_PushQueued  0x020313A0  arm
 *   PROCSYS_StepProc  0x020315F0  arm
 *   PROCSYS_FreeProc  0x02031590  arm
 *   PROCSYS_NewProc  0x02031538  arm
 *
 * procsys.c: advance the process chain one frame.  A pending call at +0xC
 * is pushed first (PROCSYS_PushQueued); then the current process at +8 runs one
 * step (PROCSYS_StepProc) and, when it finishes, is freed and replaced either
 * by a freshly built process from the parked parameters at +0x14..+0x1C
 * (+0x10 set) or by its parent.
 *
 * The earlier 12-byte residue (docs/notes/pkt_020313EC.c.txt) was the
 * `prev = p->node->prev;` load written once above the test: written as
 * the first statement of BOTH arms, the compiler hoists the common load
 * below the compare, which is the image's order (ldr f10, cmp, ldr node,
 * ldr prev, beq).
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Node Node;
struct Node {
    u32 pad[6];
    Node *prev;
    Node *next;
};

typedef struct {
    u16 heap;
    u16 pad02;
    u32 f04;
    Node *node;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
} Obj;

extern int PROCSYS_PushQueued(int a0);
extern u32   PROCSYS_StepProc(Node *n);
extern void PROCSYS_FreeProc(void *ptr);
struct Obj02031538;
extern struct Obj02031538 *PROCSYS_NewProc(u32 a0, u32 a1, u32 a2, u32 heap);

u32 PROCSYS_MainInternal(Obj *p)
{
    u32 r;
    Node *prev;

    if (p->node == 0) {
        return 0;
    }
    if (p->f0c != 0) {
        PROCSYS_PushQueued((int)p);
    }
    r = PROCSYS_StepProc(p->node);
    if (r == 1) {
        if (p->f10 != 0) {
            prev = p->node->prev;
            PROCSYS_FreeProc(p->node);
            p->node = (Node *)PROCSYS_NewProc(p->f14, p->f18, p->f1c, p->heap);
            if (prev != 0) {
                prev->next = p->node;
            }
            p->node->prev = prev;
            p->f10 = 0;
            p->f14 = 0xFFFFFFFF;
            p->f18 = 0;
            p->f1c = 0;
        } else {
            prev = p->node->prev;
            PROCSYS_FreeProc(p->node);
            p->node = prev;
            if (prev != 0) {
                prev->next = 0;
            }
        }
    }
    if (p->node == 0) {
        return 0;
    }
    return (r == 1) ? 2 : 1;
}
