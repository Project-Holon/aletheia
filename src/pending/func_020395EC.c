/*
 * function: func_020395EC
 * address:  0x020395EC
 * packet:   pkt_020395EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  str_020A7A78 (string) -- the preceding string "net_handle.c" at
 *           0x020A7A68 ends at 0x020A7A75; the 3-byte gap kills the `string`
 *           class, so 0x020A7A78 has no witness outside 020395EC..02039658.
 *           Every concrete byte of the body reproduces.
 * symbols:
 *   str_020A7A68   0x020A7A68  data
 *   str_020A7A78   0x020A7A78  data
 *   func_02034714  0x02034714  arm
 *   func_0203D788  0x0203D788  arm
 *   func_0203996C  0x0203996C  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern const u8 str_020A7A68[];
extern const u8 str_020A7A78[];
extern void func_02034714(const u8 *file, int line, const u8 *msg);
extern void func_0203D788(void);
extern u32 func_0203996C(u32 a);

int func_020395EC(u32 a)
{
    u32 v;
    int i;

    func_0203D788();
    v = func_0203996C(0xff);
    if (v == a) {
        return 0xff;
    }
    for (i = 0; i < 9; i++) {
        v = func_0203996C(i);
        if (v == a) {
            return i;
        }
    }
    func_02034714(str_020A7A68, 0x6e, str_020A7A78);
    return -1;
}
