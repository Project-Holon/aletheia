/*
 * function: func_0205D010
 * address:  0x0205D010
 * packet:   pkt_0205D010
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  ABS32 func_0205CF24 at +0x08: no branch anywhere outside this range reaches 0x0205CF24
 */

extern void func_0205CF24(void);
void func_0205D010(void)
{
    func_0205CF24();
}
