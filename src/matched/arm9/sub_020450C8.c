/*
 * function: BMP_WIN_Exit
 * address:  0x020450C8
 * packet:   pkt_020445F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 *
 * status:   EXACT
 *
 * symbols:
 *   g_02146A50     0x02146A50  data
 *   func_020307B0  0x020307B0  arm
 *
 * The teardown that pairs with BMP_WIN_Init: free the four-byte heap record
 * published at 0x02146A50 and clear the pointer, doing nothing if it was
 * never allocated.  The idempotent shape (test, free, null out) is why the
 * global is read once into a callee-saved register and stored back through
 * the same register rather than re-loaded from the pool.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_WIN_Exit.c \
 *       --func BMP_WIN_Exit --addr 0x020450C8 --cc 1.1p1 --arm
 */

typedef unsigned short u16;

extern u16 *g_02146A50;

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void BMP_WIN_Exit(void)
{
    if (g_02146A50 == 0)
        return;

    func_020307B0(g_02146A50);
    g_02146A50 = 0;
}
