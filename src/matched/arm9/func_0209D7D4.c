/*
 * function: func_0209D7D4
 * address:  0x0209D7D4
 * packet:   pkt_0209D7D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 * symbols:
 *   func_0209D778  0x0209D778  arm
 *   func_0209D774  0x0209D774  arm
 *
 * MSL console write hook (the __write_console shape: handle, buffer,
 * size_t *count, returns 0): terminate the buffer's last byte, emit the
 * buffer, then emit the saved byte.  Both callees are bare `bx lr` stubs
 * in this release build.
 *
 * Closed 2026-09-24 (wave 21, lane G) from DIFF 43
 * (docs/notes/func_0209D7D4.c.txt).  The lever is the ARITY of
 * func_0209D778: it takes ONE argument.  The image's `mov r1, #0` is not a
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
 *   python3 tools/match.py one --src src/matched/func_0209D7D4.c \
 *       --func func_0209D7D4 --addr 0x0209D7D4 --arm --cc 1.1p1
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern void func_0209D778(u8 *str);
extern void func_0209D774(u8 *p);

int func_0209D7D4(int handle, u8 *buffer, u32 *count)
{
    if (*count > 1) {
        u8 *end = buffer + *count;
        u8 c = end[-1];
        end[-1] = 0;
        func_0209D778(buffer);
        func_0209D774(&c);
    } else {
        func_0209D774(buffer);
    }
    return 0;
}
