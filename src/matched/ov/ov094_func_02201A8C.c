/*
 * function: BTLV_CLACT_Create
 * address:  0x02201A8C
 * packet:   pkt_ov094_02201A8C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlvClactFileName  0x0220AE88  data  a4
 *   CLACT_CreateUnit  0x0204B100  arm  arm9
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Res {
    void *owner;
    void *h;
    char pad[0x80 - 8];
    u16 heap;
} Res;
typedef unsigned char  u8;
struct Bank;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern const char gBtlvClactFileName[];

Res *BTLV_CLACT_Create(void *owner, u16 heap)
{
    Res *r = func_02030734(heap, 0x84, 1, gBtlvClactFileName, 0x4f);
    r->owner = owner;
    r->heap = heap;
    r->h = CLACT_CreateUnit(7, 0, heap);
    return r;
}
