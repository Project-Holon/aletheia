/*
 * function: func_02013980
 * address:  0x02013980
 * packet:   pkt_0201394C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   sZonedataFile  0x020A729C  data
 *
 * zonedata.c.  A lazy 0xc00-byte zeroed allocation hung off the object at
 * +0x94: the allocator gets the caller's heap (its own r0 is overwritten by
 * the pointer arithmetic, so the heap is carried in r1 at entry), the class
 * id 3 << 10 and the file name/line pair.  The `str r0, [sp]` is the fifth
 * argument, i.e. the source line 0x39a.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02013980.c \
 *       --func func_02013980 --addr 0x02013980 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct ZoneData {
    u8  pad00[0x94];
    u8 *f94;            /* +0x94 */
};

typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u8 sZonedataFile;

void func_02013980(struct ZoneData *o, u32 heap)
{
    if (o->f94 == 0) {
        o->f94 = func_02030734(heap, 3 << 10, 0, (const char *)&sZonedataFile, 0x39a);
    }
}
