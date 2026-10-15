/*
 * function: gpiOperationsAreBlocking
 * address:  0x0218E2DC
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Walks the +0x5c4 list; true as soon as a node has a non-zero +8 word and
 * a first word other than 3.
 *
 * symbols:
 *

 */

int gpiOperationsAreBlocking(char *p)
{
    char *q = *(char **)(*(char **)p + 0x5c4);

    while (q != 0) {
        if (*(int *)(q + 8) != 0 && *(int *)q != 3) return 1;
        q = *(char **)(q + 0x20);
    }
    return 0;
}


