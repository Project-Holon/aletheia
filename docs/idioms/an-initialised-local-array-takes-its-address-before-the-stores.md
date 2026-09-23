# An initialised local array takes its address before the stores

summary: `u8 buf[6] = {0, 0, 0, 0, 0, 0};` materialises `add rN, sp, #0` first and stores through rN; six separate `buf[k] = 0;` assignments store off sp and sink the address to its first use.

Found in: src/matched/func_0203DAC4.c (0x0203DAC4)

The image zeroes a six-byte MAC buffer as

    add r8, sp, #0
    mov r4, #0
    ldr r6, [pc, #...]
    strb r4, [r8]
    ...
    strb r4, [r8, #5]

and then passes r8 to a compare call.  Six plain assignments to `u8 buf[8]`
(or `u8 buf[6]`, a struct, a `u8 *p = buf` alias, an inline clear helper)
all compile to `strb r4, [sp, #k]` with `add r8, sp, #0` sunk below the
stores: 24 bytes out at the right size, and 2000 permuter compiles do not
move it.  A declaration with an initialiser, `u8 buf[6] = {0, 0, 0, 0, 0, 0};`
(here in the block scope that also holds the second search loop), is lowered
through the array's address, so the address is computed first and the stores
go through it.  A `memset` or a `= {0}` on an eight-byte array instead merges
the stores into a word and a halfword.
