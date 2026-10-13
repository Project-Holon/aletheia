/*
 * function: func_02062810
 * address:  0x02062810
 * packet:   pkt_02062810
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02062BAC 0x02062BAC arm
 */

typedef unsigned char u8;
struct Tbl;
extern void func_02062BAC(struct Tbl *t);

void func_02062810(void *p)
{
    func_02062BAC((struct Tbl *)((u8 *)p + 8));
}
