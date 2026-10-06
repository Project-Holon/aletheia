/*
 * function: func_021DF298
 * address:  0x021DF298
 * packet:   pkt_021DF298
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
 *   func_021DFCE8  0x021DFCE8  arm
 *
 * Open the 0x021DFCE8 slot; when it hands back a handle, queue it under category
 * 0x0a and post an 8-byte message.
 */

typedef unsigned int   u32;
extern int func_021DFCE8(u32 *a0);
extern int func_021DF644(int, int);
extern void func_02059F54(int, int);

int func_021DF298(u32 *a0)
{
    int r = func_021DFCE8(a0);

    if (r)
        func_02059F54(8, func_021DF644(0xa, r));
    return r;
}

