/*
 * function: func_021F94D8
 * address:  0x021F94D8
 * packet:   pkt_ov094_021F94D8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tears down the owner's work: func_021F97E4, free, then func_02011264.
 *
 * symbols:
 *   func_02011324 0x02011324 thumb
 *   func_021F97E4 0x021F97E4 thumb ov094
 *   func_020307B0 0x020307B0 arm
 *   func_02011264 0x02011264 thumb
 */
extern void *func_02011324(void *);
extern void func_021F97E4(void *);
extern void func_020307B0(void *);
extern void func_02011264(void *);

void func_021F94D8(void *a)
{
    void *s = func_02011324(a);
    func_021F97E4(a);
    func_020307B0(s);
    func_02011264(a);
}
