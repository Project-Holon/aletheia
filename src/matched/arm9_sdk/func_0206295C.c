/*
 * function: func_0206295C
 * address:  0x0206295C
 * packet:   pkt_0206295C
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

void func_0206295C(void *animBank)
{
    func_02062BAC((struct Tbl *)((u8 *)animBank + 8));
}
