/*
 * file:     nns_fnd_frameheap.c
 * unit:     yes
 * function: func_02060FA4, func_02060FEC, func_02061048, func_020610A0, func_020610B4, func_020610E0, func_02061118, func_02061124, func_02061158, func_02061184, func_020611D4
 * address:  0x02060FA4
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * NitroSystem fnd frame heap, NNS_FndFreeByStateToFrmHeap: walk the saved
 * state list at heap+0x2c for the tag (or take the newest when the tag is 0)
 * and restore head/tail allocators and the state link from it.  Written in
 * the library's shape: the frame-heap head sits right after the 0x24-byte
 * NNSiFndHeapHead (GetFrmHeapHeadPtrFromHeapHead as an inline), and the
 * search is the library's `if (tagName) for (; pState; pState = prev) if
 * (match) break;`.  That shape under 1.1p1 is 84 bytes; under ../2.0/sp2 it is
 * 80 bytes, 0 mismatches (the predicated `ldrne/cmpne/bne` loop at
 * 0x020611E4..0x020611F4 is the 2.0 rotation).  Closes the "loop
 * if-conversion wall" of docs/notes/func_020611D4.c.txt and
 * docs/notes/pkt_020611D4.c.txt.
 *
 * symbols:
 *   func_020606D0  0x020606D0  arm
 *   MIi_CpuClear32  0x02082A7C  arm
 */
#include "../../matched/include/Obj04082.h"

struct Obj;
struct Heap;
typedef unsigned int u32;

typedef struct Obj {
    u32 f00[6];
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
} Obj;

typedef unsigned char u8;

struct Heap {
    u32          cur;    /* +0x00 */
    u32          limit;  /* +0x04 */
    struct Node *head;   /* +0x08 */
};

struct Node {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
};

struct H {
    u8          pad_00[0x24];
    struct Heap h24;     /* +0x24 */
};

typedef int BOOL;

typedef struct NNSiFndFrmHeapState {
    u32 tagName;
    void *headAllocator;
    void *tailAllocator;
    struct NNSiFndFrmHeapState *pPrevState;
} NNSiFndFrmHeapState;

typedef struct NNSiFndFrmHeapHead {
    void *headAllocator;
    void *tailAllocator;
    NNSiFndFrmHeapState *pState;
} NNSiFndFrmHeapHead;

typedef struct NNSiFndHeapHead {
    u32 signature;
    void *link[2];      /* NNSFndLink: prev, next */
    u32 childList[3];   /* NNSFndList: head, tail, count/offset */
    void *heapStart;
    void *heapEnd;
    u32 attribute;
} NNSiFndHeapHead;

typedef NNSiFndHeapHead *NNSFndHeapHandle;

extern void func_020606D0(Obj *o, u32 tag, void *p, u32 a, u32 b);
extern void MIi_CpuClear32(u32 data, void *dest, u32 size);
extern void func_02082A7C(int a, int b, int c);
extern void func_0206074C(void *heap);
Obj *func_02060FA4(Obj *o, u32 a1, u32 a2);
u32 func_02060FEC(struct Heap *h, u32 size, u32 align);
unsigned int func_02061048(unsigned int *p, unsigned int a, unsigned int b);
void func_020610A0(void *p0);
void func_020610B4(int *p);
void *func_020610E0(void *mem, u32 size, u32 opt);
void func_02061118(void *heap);
unsigned int func_02061124(char *p, int n, int v);
void func_02061158(void *p, int flags);
int func_02061184(struct H *h, u32 a1);
BOOL func_020611D4(NNSFndHeapHandle heap, u32 tagName);



/*
 * Frame-heap init ('FRMH' tag 0x46524D48): the common heap header through
 * func_020606D0, then the two cursors copied from the block bounds and the
 * state word cleared.  The load/store interleave tell of the 2.0 front end
 * (docs/FRONTEND-PINS.md, pkt_02060480 family): the image writes
 * ldr/mov/str/ldr/mov/str/str at 0x02060FC4..0x02060FDC; 1.1p1 hoists both
 * loads above the stores (17 bytes out, docs/notes/pkt_02060FA4.c.txt).
 * Under ../2.0/sp2 the same C is 68 bytes, 0 mismatches.
 */
Obj *func_02060FA4(Obj *o, u32 a1, u32 a2)
{
    func_020606D0(o, 0x46524D48, (char *)o + 0x30, a1, a2);
    o->f24 = o->f18;
    o->f28 = o->f1c;
    o->f2c = 0;
    return o;
}





u32 func_02060FEC(struct Heap *h, u32 size, u32 align)
{
    u32 amask = align - 1;
    u32 p = (amask + h->cur) & ~amask;
    u32 e = size + p;
    u32 sz;

    if (e > h->limit) {
        return 0;
    }

    sz = e - h->cur;
    if ((u8)((u32 *)h)[-1] & 1) {
        MIi_CpuClear32(0, (void *)h->cur, sz);
    }

    h->cur = e;
    return p;
}




unsigned int func_02061048(unsigned int *p, unsigned int a, unsigned int b)
{
    unsigned int v = (p[1] - a) & ~(b - 1);
    unsigned int r2;
    unsigned char c;
    if (v < p[0])
        return 0;
    r2 = p[1] - v;
    c = (unsigned char)p[-1];
    if (c & 1)
        func_02082A7C(0, (int)v, (int)r2);
    p[1] = v;
    return v;
}





void func_020610A0(void *p0){ ((struct Obj04082 *)p0)->f24 = (int)((struct Obj04082 *)p0)->f18; ((struct Obj04082 *)p0)->f2C = (int)0; }




void func_020610B4(int *p)
{
    int *q = (int *)p[0xb];
    if (q != 0) {
        do {
            q[2] = p[7];
            q = (int *)q[3];
        } while (q != 0);
    }
    p[0xa] = p[7];
}





/*
 * Frame-heap create guard (twin of 0x02060C5C): word-align both ends of the
 * block, refuse anything under 0x30 bytes, else hand (start, end, opt) to
 * func_02060FA4.  Two levers closed the old 2-register residue of
 * docs/notes/pkt_020610E0.c.txt: the third parameter is passed straight
 * through in r2 (which is why `end - start` lands in r3), and the end sum is
 * spelled size + mem (`add r1, r1, r0`).
 */
void *func_020610E0(void *mem, u32 size, u32 opt)
{
    u32 end = (size + (u32)mem) & ~3u;
    u32 start = ((u32)mem + 3) & ~3u;
    if (start > end || end - start < 0x30)
        return 0;
    return func_02060FA4((void *)start, end, opt);
}




void func_02061118(void *heap){ func_0206074C(heap); }




unsigned int func_02061124(char *p, int n, int v)
{
    if (n == 0)
        n = 1;
    n = (n + 3) & ~3;
    p += 0x24;
    if (v >= 0)
        return func_02060FEC((struct Heap *)p, (unsigned int)n, (unsigned int)v);
    else
        return func_02061048((unsigned int *)p, (unsigned int)n, (unsigned int)-v);
}




void func_02061158(void *p, int flags)
{
    if (flags & 1)
        func_020610A0(p);
    if (flags & 2)
        func_020610B4(p);
}





int func_02061184(struct H *h, u32 a1)
{
    struct Node *p;
    u32 saved = h->h24.cur;

    p = (struct Node *)func_02060FEC(&h->h24, 0x10, 4);
    if (p == 0) {
        return 0;
    }

    p->unk_00 = a1;
    p->unk_04 = saved;
    p->unk_08 = h->h24.limit;
    p->unk_0c = (u32)h->h24.head;
    h->h24.head = p;
    return 1;
}


static inline NNSiFndFrmHeapHead *GetFrmHeapHeadPtrFromHeapHead(NNSiFndHeapHead *pHHead)
{
    return (NNSiFndFrmHeapHead *)((u32)pHHead + sizeof(NNSiFndHeapHead));
}


BOOL func_020611D4(NNSFndHeapHandle heap, u32 tagName)
{
    NNSiFndFrmHeapHead *pFrmHeapHd = GetFrmHeapHeadPtrFromHeapHead(heap);
    NNSiFndFrmHeapState *pState = pFrmHeapHd->pState;

    if (tagName != 0) {
        for (; pState; pState = pState->pPrevState) {
            if (pState->tagName == tagName)
                break;
        }
    }

    if (pState == 0) {
        return 0;
    }

    pFrmHeapHd->headAllocator = pState->headAllocator;
    pFrmHeapHd->tailAllocator = pState->tailAllocator;
    pFrmHeapHd->pState = pState->pPrevState;

    return 1;
}
