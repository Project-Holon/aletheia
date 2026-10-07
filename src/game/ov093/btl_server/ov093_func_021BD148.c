/*
 * function: func_021BD148
 * address: 0x021BD148
 * packet: pkt_ov093_021BD148
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero bytes at 0x021BD16E are alignment padding.
 * symbols:
 *   func_021BCA08 0x021BCA08 thumb ov093
 *   func_021BCB98 0x021BCB98 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 a, b, c; u8 d0, flag; u16 pad; } E;
extern E *func_021BCA08(void *, u8);
extern int func_021BCB98(void *, E *, int);
int func_021BD148(void *p, u8 x)
{
    E *e = func_021BCA08(p, x);
    if (e && e->flag == 0) {
        if (func_021BCB98(p, e, 0) >= 0) return 1;
    }
    return 0;
}
