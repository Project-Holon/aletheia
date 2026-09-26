/*
 * function: func_02185D64
 * address:  0x02185D64
 * packet:   pkt_02185D64
 * region:   ov219
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Unblocked: 0x0203F734 is an unlabelled ARM leaf (it saves no lr, so
 *           disasm.py gives it no func_ label); matched at 0x0203F734 and
 *           now attests both calls here on the `matched` class.
 * symbols:
 *   func_0203F734  0x0203F734  arm
 *   func_0207C7B4  0x0207C7B4  arm
 */

extern int func_0203F734(int x);
extern int func_0207C7B4(int x);

int func_02185D64(int *p, int *q)
{
    int dx = p[0] - q[0];
    int dy;

    if (dx < 0)
        dx = -dx;
    dy = p[1] - q[1];
    if (dy < 0)
        dy = -dy;
    if (dx > func_0203F734(180))
        dx = 0xFFFF - dx;
    if (dy > func_0203F734(180))
        dy = 0xFFFF - dy;
    return func_0207C7B4((dx * dx + dy * dy) << 12) >> 12;
}
