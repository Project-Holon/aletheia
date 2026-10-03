/*
 * function: func_0201F81C
 * address:  0x0201F81C
 * packet:   pkt_0201F81C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02030734        0x02030734  arm
 *   sBmpMenuWorkFile     0x020A7374  data
 *
 * bmp_menuwork.c: allocate a menu item list of n cleared 8-byte entries plus
 * a terminator entry { 0xFFFFFFFF, heap } (line 0x29, __FILE__ anchor
 * 0x020A7374 "bmp_menuwork.c").  The previous reading
 * (docs/notes/pkt_0201F81C.c.txt) stored the index into both fields; the
 * loop stores ZERO (the `adds r1, r6, #0` before the loop is the zero
 * rematerialised off the index register and never updated), and with that
 * the index lands in r6 and the frame gets its own `sub sp, #4`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201F81C.c \
 *       --func func_0201F81C --addr 0x0201F81C --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    const void *str;    /* +0x00 */
    u32         param;  /* +0x04 */
} BmpMenuWork;

extern char sBmpMenuWorkFile[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

BmpMenuWork *func_0201F81C(u32 n, u32 heap)
{
    BmpMenuWork *p;
    u32 i;

    p = func_02030734((u16)heap, (n + 1) * sizeof(BmpMenuWork), 1, sBmpMenuWorkFile, 0x29);
    if (p != 0) {
        for (i = 0; i < n; i++) {
            p[i].str = 0;
            p[i].param = 0;
        }
        p[i].str = (const void *)0xFFFFFFFF;
        p[i].param = heap;
    }
    return p;
}
