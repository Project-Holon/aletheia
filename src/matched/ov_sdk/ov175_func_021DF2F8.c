/*
 * function: func_021DF2F8
 * address:  0x021DF2F8
 * packet:   pkt_021DF2F8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02059F54  0x02059F54  arm
 *   func_021DF644  0x021DF644  arm
 *   func_021DFD00  0x021DFD00  arm
 *
 * Open the 0x021DFD00 slot; when it hands back a handle, queue it under
 * category 0x0a and post an 8-byte message.
 */

typedef unsigned int   u32;
extern int func_021DFD00(u32 *a0);
extern int func_021DF644(int, int);
extern void func_02059F54(int, int);

int func_021DF2F8(u32 *a0)
{
    int r = func_021DFD00(a0);

    if (r)
        func_02059F54(8, func_021DF644(0xa, r));
    return r;
}

