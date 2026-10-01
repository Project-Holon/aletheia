/*
 * function: func_021F90E0
 * address: 0x021F90E0
 * packet: pkt_ov132_021F90E0
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FAC74 0x021FAC74 thumb ov132
 *   d_021FDBD0 0x021FDBD0 data a1
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Bytes { u8 a, b, c, d; };
extern const struct Bytes d_021FDBD0;
extern void *func_021FAC74(void *, void *, int);
void func_021F90E0(u8 *p)
{
    u8 i;
    u32 *table;
    struct Bytes order;
    table = *(u32 **)(p + 0xb4);
    order = d_021FDBD0;
    func_021FAC74(*(void **)(p + 0xb0), (u8 *)table + table[0], 1);
    for (i = 0; i < 4; i++) {
        if (table[0] != table[((u8 *)&order)[i]]) {
            func_021FAC74(*(void **)(p + 0xb0), *(u8 **)(p + 0xb4) + table[((u8 *)&order)[i]], 1);
        }
    }
}
