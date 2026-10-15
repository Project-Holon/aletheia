/*
 * function: MSL_CONSOLE_IO_CloseConsole
 * address:  0x0209D818
 * packet:   pkt_0209D818
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * MSL console close hook: the FILE tables at 0x020A876C and 0x020A87B8
 * hold MSL_CONSOLE_IO_ReadConsole, MSL_CONSOLE_IO_WriteConsole and this function in a row.  The
 * unit file is src/game/arm9/unit_0209D724.c.
 */

int MSL_CONSOLE_IO_CloseConsole(int handle)
{
    return 0;
}
