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
 *   NNS_FndInitList  0x02060468  arm
 *   NNS_FndAllocFromFrmHeapEx  0x02061124  arm
 *   NNS_FndAppendListObject  0x020604AC  arm
 *   SND_GetCurrentCommandTag  0x02089D40  arm
 *   func_02089B38  0x02089B38  arm
 *   SND_WaitForCommandProc  0x02089CD4  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Table {
    void *heap;
    char list[0x1c];
};

extern void NNS_FndInitList(int p0, int p1);
extern unsigned int NNS_FndAllocFromFrmHeapEx(char *p, int n, int v);
extern void NNS_FndAppendListObject(void *list, void *node);
extern u32 SND_GetCurrentCommandTag(void);
extern void func_02089B38(u32 a0);
extern void SND_WaitForCommandProc(u32 tag);

int NNSi_SndHeapAllocLevel(struct Table *t);

void NNSi_SndHeapLevelInit(void *node)
{
    NNS_FndInitList((int)node, 0);
}

int NNSi_SndHeapInit(struct Table *t, void *heap)
{
    NNS_FndInitList((int)(&t->list), 0xc);
    t->heap = heap;
    if (NNSi_SndHeapAllocLevel(t)) {
        return 1;
    }
    return 0;
}

int NNSi_SndHeapAllocLevel(struct Table *t)
{
    void *node = (void *)NNS_FndAllocFromFrmHeapEx(t->heap, 0x14, 4);
    if (!node) {
        return 0;
    }
    NNSi_SndHeapLevelInit(node);
    NNS_FndAppendListObject(&t->list, node);
    return 1;
}

void NNSi_SndHeapFlushCommands(void)
{
    void *p = (void *)SND_GetCurrentCommandTag();
    func_02089B38(1);
    SND_WaitForCommandProc((u32)p);
}
