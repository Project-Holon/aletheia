/*
 * function: MSL_CONSOLE_IO_WriteConsole
 * address:  0x0209D7D4
 * packet:   pkt_0209D7D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 * symbols:
 *   MSL_CONSOLE_IO_WriteString  0x0209D778  arm
 *   MSL_CONSOLE_IO_WriteChar  0x0209D774  arm
 *
 * MSL console write hook (the __write_console shape: handle, buffer,
 * size_t *count, returns 0): terminate the buffer's last byte, emit the
 * buffer, then emit the saved byte.  Both callees are bare `bx lr` stubs
 * in this release build.
 *
 * Closed 2026-09-24 (wave 21, lane G) from DIFF 43
 * (docs/notes/MSL_CONSOLE_IO_WriteConsole.c.txt).  The lever is the ARITY of
 * MSL_CONSOLE_IO_WriteString: it takes ONE argument.  The image's `mov r1, #0` is not a
 * second argument but the register the compiler picked for the terminator
 * store, free once `mov r0, r1` has consumed buffer; every earlier spelling
 * passed `(buffer, 0)`, which made the zero an argument CSE'd with the
 * store and forced it into r2 with a `mov r1, r2` copy (72 bytes).  With
 * the one-argument prototype the body is 68 bytes, 0 out.
 *
 * EXACT*: the listing extent runs to 0x0209D820 because the 8-byte
 * `mov r0, #0; bx lr` leaf at 0x0209D818 saves no lr and carries no label
 * (worth seeding into layout/function_starts.txt).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/MSL_CONSOLE_IO_WriteConsole.c \
 *       --func MSL_CONSOLE_IO_WriteConsole --addr 0x0209D7D4 --arm --cc 1.1p1
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern void MSL_CONSOLE_IO_WriteString(void *str);
extern void MSL_CONSOLE_IO_WriteChar(void *p);

int MSL_CONSOLE_IO_WriteConsole(int handle, u8 *buffer, u32 *count)
{
    if (*count > 1) {
        u8 *end = buffer + *count;
        u8 c = end[-1];
        end[-1] = 0;
        MSL_CONSOLE_IO_WriteString(buffer);
        MSL_CONSOLE_IO_WriteChar(&c);
    } else {
        MSL_CONSOLE_IO_WriteChar(buffer);
    }
    return 0;
}
