/*
 * unit:     no
 * address:  0x020309B8
 * packet:   pkt_020307E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: GFL_HEAP_AuditFree
 *
 * The free-side audit, the counterpart of GFL_HEAP_AuditAlloc: same three opening
 * calls, then the actual release of the block and a dump of the heap it
 * came from.
 *
 *   void GFL_HEAP_AuditFree(void *p)
 *
 * The difference from GFL_HEAP_AuditAlloc is that the block's heap id is needed
 * twice here, so it is bound to a local and costs r4, while in
 * GFL_HEAP_AuditAlloc it flows straight from GFL_HEAP_GetBlockHeapId into GFL_HEAP_GetAllocCountById and
 * costs nothing. sub_02060F90 is handed the header address (p - 0x1c), the
 * same address GFL_HEAP_AllocMemory got back from the expanded-heap allocator, and
 * GFL_HEAP_GetTotalFreeSize then dumps the heap the id names.
 *
 * The 0x13-byte scratch buffer is declared first, which is what puts it at
 * sp + 0; the stack frame is rounded to 0x14.
 *
 * symbols:
 *   GFL_HEAP_GetAllocCountById    0x0203046C  arm
 *   GFL_HEAP_GetTotalFreeSize    0x02030344  arm
 *   GFL_HEAP_GetBlockHeapId    0x020304B8  arm
 *   GFL_HEAP_GetBlockName    0x020304C0  arm
 *   GFL_HEAP_ReadAllocSiteName    0x020308B8  arm
 *   sub_02060F90    0x02060F90  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_HEAP_AuditFree.c \
 *       --func GFL_HEAP_AuditFree --addr 0x020309B8 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 GFL_HEAP_GetBlockHeapId(void *p);
extern void *GFL_HEAP_GetBlockName(void *p);
extern u16 GFL_HEAP_GetAllocCountById(u32 heapId);
extern int GFL_HEAP_ReadAllocSiteName(u8 *buf, const char *name);
extern int sub_02060F90(char *p);
extern void *GFL_HEAP_GetTotalFreeSize(u32 heapId);

void GFL_HEAP_AuditFree(void *p)
{
    u8 buf[0x13];
    void *rec;
    u32 heapId;

    rec = GFL_HEAP_GetBlockName(p);
    heapId = GFL_HEAP_GetBlockHeapId(p);
    GFL_HEAP_GetAllocCountById(heapId);
    GFL_HEAP_ReadAllocSiteName(buf, (const char *)rec);
    sub_02060F90((char *)p - 0x1c);
    GFL_HEAP_GetTotalFreeSize(heapId);
}
