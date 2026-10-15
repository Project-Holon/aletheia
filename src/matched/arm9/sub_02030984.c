/*
 * unit:     no
 * address:  0x02030984
 * packet:   pkt_020307E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: GFL_HEAP_AuditAlloc
 *
 * The watched-allocation audit, reached only from GFL_HEAP_NotifyAlloc when the
 * global watch id g_020A7820 names this allocation's heap.
 *
 *   void GFL_HEAP_AuditAlloc(void *p)
 *
 * Only r0 is read; GFL_HEAP_NotifyAlloc also sets r1 to the size, a leftover
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 *
 * Three things happen, and two of them discard their results, which is
 * what a stripped diagnostic looks like: the calls survive for their side
 * effects (sub_0203046C records an error code in the heap table at +0xe)
 * and for the bounds checking they perform, while the value each computes
 * is dropped.
 *
 *  - sub_020304C0(p) is the provenance record stamped by GFL_HEAP_StampAllocSite,
 *    i.e. header+4. It is live across two calls and so costs r4.
 *  - sub_020304B8(p) is a plain `ldrh [p, #-0x1c]`: the heap id stored in
 *    the first halfword of the block header. It feeds sub_0203046C, the
 *    id-to-arena mapper, whose result is dropped.
 *  - GFL_HEAP_ReadAllocSiteName copies the provenance name into a 0x13-byte stack
 *    buffer and validates it (all bytes printable 0x20..0x7e, and a '.'
 *    present unless the name fills all 0x12 bytes); its verdict is also
 *    dropped. The buffer is declared before the pointer locals, which is
 *    what puts it at sp+0.
 *
 * symbols:
 *   sub_0203046C    0x0203046C  arm
 *   sub_020304B8    0x020304B8  arm
 *   sub_020304C0    0x020304C0  arm
 *   GFL_HEAP_ReadAllocSiteName    0x020308B8  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_HEAP_AuditAlloc.c \
 *       --func GFL_HEAP_AuditAlloc --addr 0x02030984 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 sub_020304B8(void *p);
extern void *sub_020304C0(void *p);
extern u16 sub_0203046C(u32 heapId);
extern int GFL_HEAP_ReadAllocSiteName(u8 *buf, const char *name);

void GFL_HEAP_AuditAlloc(void *p, u32 size)
{
    u8 buf[0x13];
    void *rec;

    rec = sub_020304C0(p);
    sub_0203046C(sub_020304B8(p));
    GFL_HEAP_ReadAllocSiteName(buf, (const char *)rec);
}
