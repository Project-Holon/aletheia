/*
 * function: func_021D97D0
 * address:  0x021D97D0
 * packet:   pkt_021D97D0
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D965C  0x021D965C  thumb
 *   func_021D97B8  0x021D97B8  thumb
 *
 * Start-op for the ov175 object's +0x1c stream: func_021D965C, then spin
 *     on func_021D97B8 until it reports ready.  Mirrors func_021D63C8.
 */

typedef unsigned long u32;

extern void func_021D965C(char *obj);
extern u32 func_021D97B8(char *obj);

void func_021D97D0(char *obj)
{
    func_021D965C(obj);
    while (func_021D97B8(obj) == 0)
        ;
}

