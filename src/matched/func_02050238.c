/*
 * function: func_02050238
 * address:  0x02050238
 * packet:   pkt_020500B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Appends one {u16, u32} record (8 bytes, id in the low half) to the array
 * the caller's object keeps at +12, at the slot func_02033CA8 hands back for
 * the pool at +20; the return is the slot narrowed to u16.
 *
 * The four bytes that cost three attempts are the first store's register
 * pairing: the pointer form `*(u16 *)(*(u32 *)((char *)p + 12) + idx * 8)`
 * compiles the same two instructions as the original but allocates them the
 * other way round (`ldr r1,[r6,#12]; lsl r2,r0,#3; strh r5,[r1,r2]` against
 * the original's r2/r1), a whole-function DIFF at +001C.  Written as an
 * array subscript on an 8-byte struct element,
 * `((struct S8 *)*(u32 *)((char *)p + 12))[idx].h`, it comes out EXACT.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050238.c \
 *       --func func_02050238 --addr 0x02050238 --cc 1.1p1 --arm
 *   EXACT, 64 bytes, 1 relocation site, resolved [label].
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct S8 {
    u16 h;
    u16 pad;
    u32 w;
};

extern int func_02033CA8(u32 a, int b);

int func_02050238(void *p, u16 b, int c)
{
    int idx = func_02033CA8(*(u32 *)((char *)p + 20), 1);

    ((struct S8 *)*(u32 *)((char *)p + 12))[idx].h = b;
    ((struct S8 *)*(u32 *)((char *)p + 12))[idx].w = c;
    return (u16)idx;
}
