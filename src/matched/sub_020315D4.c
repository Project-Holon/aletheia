/*
 * unit:     no
 * address:  0x020315D4
 * packet:   pkt_02031324
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_020315D4
 *
 * symbols:
 *   ENV_SetResourceSet  0x020307B0  arm
 *
 * Unregisters a stored resource-set pointer at +0x14 with
 * ENV_SetResourceSet and clears the field.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020315D4.c \
 *       --func sub_020315D4 --addr 0x020315D4 --cc 1.1p1
 */

struct S020315D4 {
    char  pad[0x14];
    void *field14;
};

extern void ENV_SetResourceSet(void *p);

void sub_020315D4(struct S020315D4 *p)
{
    ENV_SetResourceSet(p->field14);
    p->field14 = 0;
}
