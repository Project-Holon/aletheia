/*
 * function: func_0220B1B0
 * address:  0x0220B1B0
 * packet:   pkt_0220B1B0
 * region:   ov197
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0220B248 0x0220B248 thumb
 *   func_0220B774 0x0220B774 thumb
 *   func_0220B880 0x0220B880 thumb
 */

extern void func_0220B248(void);
extern void func_0220B774(void);
extern void func_0220B880(void);

void func_0220B1B0(int unused, int which)
{
    switch (which)
    {
    case 0:
        func_0220B248();
        break;
    case 1:
        func_0220B774();
        break;
    case 2:
        func_0220B880();
        break;
    }
}
