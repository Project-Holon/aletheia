/*
 * function: func_021F3764
 * address:  0x021F3764
 * packet:   pkt_021F3764
 * region:   ov044
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  first call target 0x02188D2C has no func_ label anywhere in the
 *           image (unlabelled leaf in ov009/ov021/ov096/ov230); the second,
 *           func_021BE580, resolves. Byte-correct otherwise.
 *
 * symbols:
 *   func_021F3764 0x021F3764 thumb
 *   func_02188D2C 0x02188D2C thumb
 *   func_021BE580 0x021BE580 thumb ov021
 */

extern void func_02188D2C(void);
extern void func_021BE580(void);

void func_021F3764(void)
{
    func_02188D2C();
    func_021BE580();
}
