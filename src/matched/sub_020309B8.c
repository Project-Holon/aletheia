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
 * function: sub_020309B8
 *
 * The free-side audit, the counterpart of sub_02030984: same three opening
 * calls, then the actual release of the block and a dump of the heap it
 * came from.
 *
 *   void sub_020309B8(void *p)
 *
 * The difference from sub_02030984 is that the block's heap id is needed
 * twice here, so it is bound to a local and costs r4, while in
 * sub_02030984 it flows straight from sub_020304B8 into sub_0203046C and
 * costs nothing. sub_02060F90 is handed the header address (p - 0x1c), the
 * same address sub_02030098 got back from the expanded-heap allocator, and
 * sub_02030344 then dumps the heap the id names.
 *
 * The 0x13-byte scratch buffer is declared first, which is what puts it at
 * sp + 0; the stack frame is rounded to 0x14.
 *
 * symbols:
 *   sub_0203046C    0x0203046C  arm
 *   sub_02030344    0x02030344  arm
 *   sub_020304B8    0x020304B8  arm
 *   sub_020304C0    0x020304C0  arm
 *   sub_020308B8    0x020308B8  arm
 *   sub_02060F90    0x02060F90  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020309B8.c \
 *       --func sub_020309B8 --addr 0x020309B8 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 sub_020304B8(void *p);
extern void *sub_020304C0(void *p);
extern u16 sub_0203046C(u32 heapId);
extern int sub_020308B8(u8 *buf, const char *name);
extern u32 sub_02060F90(void *block);
extern void *sub_02030344(u32 heapId);

void sub_020309B8(void *p)
{
    u8 buf[0x13];
    void *rec;
    u32 heapId;

    rec = sub_020304C0(p);
    heapId = sub_020304B8(p);
    sub_0203046C(heapId);
    sub_020308B8(buf, (const char *)rec);
    sub_02060F90((char *)p - 0x1c);
    sub_02030344(heapId);
}
