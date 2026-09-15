/*
 * function: func_0204C788
 * address:  0x0204C788
 * packet:   pkt_0204BD64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_020307B0   0x020307B0  arm
 *
 * Release the 0x10-byte entry array func_0204C718 allocates at +0x04 and NULL
 * the pointer.  The pointer has to survive the free call, so the object is
 * kept in r4 and the store is written after it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204C788.c \
 *       --func func_0204C788 --addr 0x0204C788 --cc 1.1p1 --arm
 */

typedef unsigned char u8;

struct Pool {
    u8    pad_00[4];
    void *ents;   /* 0x04 */
};

extern void sub_020307B0(void *p);

void func_0204C788(struct Pool *p)
{
    sub_020307B0(p->ents);
    p->ents = 0;
}
