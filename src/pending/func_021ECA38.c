/*
 * function: func_021ECA38
 * address:  0x021ECA38
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *
 * Program the two 0x1000 spans of the frame handle and zero its head.
 *
 * Blocked sites: +0022, the THM_CALL to the ARM9 SDK func_0204B5AC.  Every concrete byte
 * matches (including the frame layout the struct forces); the target has no
 * independent witness, so the field stays wildcarded and the entry caps at
 * MATCH.  Same class as func_021DE898.
 */

extern void func_0204B588(int, unsigned short *);
extern void func_0204B5AC(int, int *);
extern void func_0204B570(int, int);
void func_021ECA38(int *p)
{
    struct { unsigned short a[2]; int b[2]; } s;
    s.a[0] = 0;
    s.a[1] = 0;
    func_0204B588(*p, s.a);
    s.b[0] = 0x1000;
    s.b[1] = 0x1000;
    func_0204B5AC(*p, s.b);
    func_0204B570(*p, 0);
}
