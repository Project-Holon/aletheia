/*
 * function: func_0206DBDC
 * address:  0x0206DBDC
 * packet:   pkt_0206DB40
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_0214BAB4   0x0214BAB4  data
 *
 * Spin on the word at +4 of the same global func_0206DB40/60 hold the head
 * pointer in.  The `volatile` is load-bearing: without it mwccarm proves the
 * word cannot change inside the empty loop and collapses the re-read into a
 * single load plus a self-branch (24 bytes against the original's 20, and the
 * load lands at +0 instead of +4).
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206DBDC.c \
 *       --func func_0206DBDC --addr 0x0206DBDC --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Node {
    void *head;
    volatile u32 f4;
};

extern struct Node g_0214BAB4;

void func_0206DBDC(void)
{
    while (g_0214BAB4.f4 != 0)
        ;
}
