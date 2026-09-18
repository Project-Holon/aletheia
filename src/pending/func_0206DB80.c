/*
 * function: func_0206DB80
 * address:  0x0206DB80
 * packet:   pkt_0206DB80
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  DIFF, 88 compiled against 92: mwccarm keeps the address of 0x0214BAB4 in r4 across the func_02082AA8 call and reuses it for the trailing store; the original re-materialises it from its pool word (`ldr r0,[pc]` twice more).  This is the address-reload residue documented in docs/notes/pkt_0206A12C.c.txt; the two pool words and all three call sites do resolve
 *
 * symbols:
 *   g_0214BAB4       0x0214BAB4  data
 *   func_0206DBDC    0x0206DBDC  arm
 *   func_02082AA8    0x02082AA8  arm
 *
 * Drains the block described by the global at 0x0214BAB4: word 1 is handed to
 * func_0206DBDC, then word 0's object has its word count cleared, its payload
 * (object + 4) filled with 0x04000400 over count*4 bytes, and its count
 * zeroed.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0206DB80.c \
 *       --func func_0206DB80 --addr 0x0206DB80 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern u32  g_0214BAB4[];
extern void func_0206DBDC(void);
extern void func_02082AA8(void *dst, u32 c, u32 n);

void func_0206DB80(void)
{
    if (g_0214BAB4[1] != 0)
        func_0206DBDC();
    if (g_0214BAB4[0] != 0 && *(u32 *)g_0214BAB4[0] != 0) {
        func_02082AA8((void *)(g_0214BAB4[0] + 4), 0x04000400,
                      *(u32 *)g_0214BAB4[0] * 4);
        *(u32 *)g_0214BAB4[0] = 0;
    }
}
