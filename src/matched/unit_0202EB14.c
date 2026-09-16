/*
 * unit:     yes
 * function: func_0202EB14
 * address:  0x0202EB14
 * packet:   pkt_0202EB14
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202EB0C  0x0202EB0C  thumb
 *   func_02087E60  0x02087E60  arm
 */

typedef unsigned int u32;

struct DeviceInfo {
    u32 bit0:1;
    u32 pad:4;
    u32 bit5:1;
};

extern int func_0202EB0C(void);
extern struct DeviceInfo *func_02087E60(void);

int func_0202EB14(void)
{
    if (func_0202EB0C()) {
        if (func_02087E60()->bit0 && func_02087E60()->bit5) {
            return 1;
        }
        return 0;
    }
    return 0;
}
