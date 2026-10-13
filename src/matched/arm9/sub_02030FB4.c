/*
 * unit:     no
 * address:  0x02030FB4
 * packet:   pkt_02030BBC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: TCBL_GetTaskWork
 *
 * Returns a stored pointer at +0x10, or the address of an embedded object
 * at +0x18 when that pointer is null: the "owned or embedded" accessor
 * shape. No relocations.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TCBL_GetTaskWork.c \
 *       --func TCBL_GetTaskWork --addr 0x02030FB4 --cc 1.1p1
 */

struct S02030FB4 {
    char  pad[0x10];
    void *field10;
    char  pad2[4];
    char  embedded[1];
};

void *TCBL_GetTaskWork(struct S02030FB4 *p)
{
    void *v = p->field10;
    if (v == 0) {
        v = &p->embedded;
    }
    return v;
}
