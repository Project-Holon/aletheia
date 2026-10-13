/*
 * unit:     no
 * address:  0x0203133C
 * packet:   pkt_02031324
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: PROCSYS_Delete
 *
 * symbols:
 *   PROCSYS_DeleteInternal  0x020314B8  arm
 *
 * A four-instruction tail call to PROCSYS_DeleteInternal
 * (src/matched/PROCSYS_DeleteInternal.c, this same packet), attested by the
 * `matched` class: PROCSYS_DeleteInternal's own EXACT entry pins its address, and
 * this call is the only branch to it found in the ROM.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PROCSYS_Delete.c \
 *       --func PROCSYS_Delete --addr 0x0203133C --cc 1.1p1
 */

struct S020314B8;

extern void PROCSYS_DeleteInternal(struct S020314B8 *p);

void PROCSYS_Delete(struct S020314B8 *p)
{
    PROCSYS_DeleteInternal(p);
}
