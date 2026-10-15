/*
 * unit:     no
 * function: MSL_CONSOLE_IO_RunInitHandlers
 * address:  0x0209D820
 * packet:   pkt_0209D784
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Runs a callback table at 0x020A64F8 until a null slot.  The image word at
 * 0x020A64F8 is 0 (the table is populated at runtime) and it is near string
 * data, so neither `data_table` nor any external witness exists; this file
 * still reaches EXACT because mwccarm emits the constant as a bare ABS32
 * literal that the object marks with NO relocation, so the pool word is
 * compared verbatim and no attestation is needed.
 */

typedef void (*Handler)(void);

void MSL_CONSOLE_IO_RunInitHandlers(void)
{
    Handler *p = (Handler *)0x020A64F8;
    while (p != 0 && *p != 0)
    {
        (*p)();
        p++;
    }
}