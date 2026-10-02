/*
 * function: func_021BD1B0
 * address: 0x021BD1B0
 * packet: pkt_ov093_021BD1B0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BCA08 0x021BCA08 thumb ov093
 *   func_021BCC50 0x021BCC50 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 a, b, c; u8 d0, flag; u16 pad; } E;
extern E *func_021BCA08(void *, u8);
extern void func_021BCC50(void *, E *);
int func_021BD1B0(void *p, u8 x)
{
    E *e = func_021BCA08(p, x);
    if (e && e->flag == 0) {
        func_021BCC50(p, e);
        return 1;
    }
    return 0;
}
