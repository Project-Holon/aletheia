/*
 * function: NNS_SndHeapLoadState
 * address:  0x020748E0
 * packet:   pkt_020737C0
 * status:   EXACT
 * isa:      arm
 * compiler: ../2.0/sp2
 * symbols:
 *   NNS_SndHeapClear  0x02074770  arm
 *   func_0206062C  0x0206062C  arm
 *   func_020605B4  0x020605B4  arm
 *   func_020611D4  0x020611D4  arm
 *   NNSi_SndHeapFlushCommands  0x02074A34  arm
 *   func_02061184  0x02061184  arm
 *   NNSi_SndHeapAllocLevel  0x020749F8  arm
 *
 * Bounded sibling of NNS_SndHeapClear: drains request lists while the key k is
 * below the live count at +0x0C (k == 0 forwards to NNS_SndHeapClear), then
 * func_020611D4(f00, k), NNSi_SndHeapFlushCommands once if any callback ran,
 * func_02061184(f00, f0c) and NNSi_SndHeapAllocLevel(o).
 *
 * Two levers closed the 19-byte floor of docs/notes/pkt_02074894.c.txt:
 *  1. The null cursor of each outer iteration's SECOND func_0206062C is the
 *     node cursor n itself (n = 0 at entry and 0 again whenever the inner walk
 *     ends), not a literal 0.  That is the image's `mov r1, r8` with r8 = n,
 *     and it is what lets one zero serve n, any and the head cursor.
 *  2. Declaration order a, any, n (a in r6, any in r7), per
 *     docs/idioms/declaration-order-decides-which-register-a-local-gets.md.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed   int   s32;

struct Node { u8 pad00[8]; u32 f08; u32 f0c; u32 f10; u32 f14; };
struct Obj  { u32 f00; u8 list[8]; u16 f0c; };

extern void  NNS_SndHeapClear(struct Obj *o);
extern void *func_0206062C(void *list, void *cur);
extern void  func_020605B4(void *list, void *node);
extern void  func_020611D4(u32 owner, s32 key);
extern void  NNSi_SndHeapFlushCommands(void);
extern void  func_02061184(u32 owner, u16 n);
extern void  NNSi_SndHeapAllocLevel(struct Obj *o);

void NNS_SndHeapLoadState(struct Obj *o, s32 k)
{
    void *a;
    u32 any;
    struct Node *n;

    n   = 0;
    any = 0;
    if (k == 0) { NNS_SndHeapClear(o); return; }

    while (k < o->f0c) {
        a = func_0206062C(o->list, 0);
        n = (struct Node *)func_0206062C(a, n);
        while (n != 0) {
            if (n->f0c != 0) {
                ((void (*)(void *, u32, u32, u32))n->f0c)
                    ((u8 *)n + 0x20, n->f08, n->f10, n->f14);
                any = 1;
            }
            n = (struct Node *)func_0206062C(a, n);
        }
        func_020605B4(o->list, a);
    }

    func_020611D4(o->f00, k);
    if (any != 0) NNSi_SndHeapFlushCommands();
    func_02061184(o->f00, o->f0c);
    NNSi_SndHeapAllocLevel(o);
}
