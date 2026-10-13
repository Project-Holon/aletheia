/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * function: NNSi_SndHeapLevelInit, NNSi_SndHeapInit, NNSi_SndHeapAllocLevel, NNSi_SndHeapFlushCommands
 * address:  0x020749B4
 * packet:   pkt_020749C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02060468  0x02060468  arm
 *   func_02061124  0x02061124  arm
 *   func_020604AC  0x020604AC  arm
 *   func_02089D40  0x02089D40  arm
 *   func_02089B38  0x02089B38  arm
 *   func_02089CD4  0x02089CD4  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Table {
    void *heap;
    char list[0x1c];
};

extern void func_02060468(int p0, int p1);
extern unsigned int func_02061124(char *p, int n, int v);
extern void func_020604AC(void *list, void *node);
extern u32 func_02089D40(void);
extern void func_02089B38(u32 a0);
extern void func_02089CD4(u32 tag);

int NNSi_SndHeapAllocLevel(struct Table *t);

void NNSi_SndHeapLevelInit(void *node)
{
    func_02060468((int)node, 0);
}

int NNSi_SndHeapInit(struct Table *t, void *heap)
{
    func_02060468((int)(&t->list), 0xc);
    t->heap = heap;
    if (NNSi_SndHeapAllocLevel(t)) {
        return 1;
    }
    return 0;
}

int NNSi_SndHeapAllocLevel(struct Table *t)
{
    void *node = (void *)func_02061124(t->heap, 0x14, 4);
    if (!node) {
        return 0;
    }
    NNSi_SndHeapLevelInit(node);
    func_020604AC(&t->list, node);
    return 1;
}

void NNSi_SndHeapFlushCommands(void)
{
    void *p = (void *)func_02089D40();
    func_02089B38(1);
    func_02089CD4((u32)p);
}
