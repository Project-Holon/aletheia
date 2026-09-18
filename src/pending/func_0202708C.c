/*
 * function: func_0202708C
 * address:  0x0202708C
 * packet:   pkt_020266E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 *
 * Blocked: data_0209FC04 (a 14-halfword table) is named by one pool word only, 0x020270A8, which is inside this function's own range; the `literal` class discards it and the table is not a table of pointers. Every concrete byte reproduces.
 * status:   MATCH
 * symbols:
 *   data_0209FC04  0x0209FC04  data
 *
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern const u16 data_0209FC04[];

u32 func_0202708C(u32 v)
{
    u32 i;

    for (i = 0; i < 14; i++) {
        if (v == data_0209FC04[i]) {
            return 1;
        }
    }
    return 0;
}
