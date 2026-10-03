/*
 * function: func_021FDB08
 * address:  0x021FDB08
 * packet:   pkt_ov094_021FDB08
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02051640  0x02051640  arm
 *   func_02050DB8  0x02050DB8  arm
 *   func_020307B0  0x020307B0  arm
 */
typedef unsigned char  u8;
extern void *func_02051640(char *p);
extern void func_02050DB8(u8 *p);
extern void func_020307B0(void *p);

void func_021FDB08(void *p)
{
    void *q = func_02051640(p);

    func_02050DB8(p);
    func_020307B0(q);
}
