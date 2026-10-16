/*
 * unit:     no
 * address:  0x020304C0
 * packet:   pkt_0202FB34
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: GFL_HEAP_GetBlockName
 *
 * Address of a field 4 bytes into the object that starts 0x1c bytes before
 * the argument: the compiler keeps the two constants as two instructions
 * (`sub #0x1c`, `add #4`) rather than folding them into one, which is what
 * two separate struct-member computations look like against a single
 * folded offset. No relocations.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_HEAP_GetBlockName.c \
 *       --func GFL_HEAP_GetBlockName --addr 0x020304C0 --cc 1.1p1
 */

struct S020304C0 {
    char pad[4];
    int  field4;
};

void *GFL_HEAP_GetBlockName(void *p)
{
    struct S020304C0 *s = (struct S020304C0 *)((char *)p - 0x1c);
    return &s->field4;
}
