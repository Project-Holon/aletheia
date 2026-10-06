/*
 * file:     unit_0206DB80_p02.c
 * unit:     yes
 * function: func_0206DBDC, func_0206DBF4
 * address:  0x0206DBDC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_0214BAB4   0x0214BAB4  data
 */
typedef unsigned int u32;

struct Node {
    void *head;
    volatile u32 f4;
};

void func_0206DBDC(void);
void func_0206DBF4(void *arg);
extern struct Node g_0214BAB4;


/*
 * Spin on the word at +4 of the same global func_0206DB40/60 hold the head
 * pointer in.  The `volatile` is load-bearing: without it mwccarm proves the
 * word cannot change inside the empty loop and collapses the re-read into a
 * single load plus a self-branch (24 bytes against the original's 20, and the
 * load lands at +0 instead of +4).
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206DBDC.c \
 *       --func func_0206DBDC --addr 0x0206DBDC --cc 1.1p1 --arm
 */
void func_0206DBDC(void)
{
    while (g_0214BAB4.f4 != 0)
        ;
}


/*
 * NitroSystem G3D gecom.c: the GX-command DMA completion callback that
 * NNS_G3dGeSendDL (func_0206DC00) passes to the async DMA start; it clears
 * the in-flight word it is handed (&g_0214BAB4.busy).  A 12-byte leaf with
 * no lr save, so disasm.py folds it into func_0206DBDC's listing extent;
 * filed as the witness that clears func_0206DC00's ABS32 site once
 * 0x0206DBF4 is seeded in layout/function_starts.txt.
 */
void func_0206DBF4(void *arg)
{
    *(volatile u32 *)arg = 0;
}
