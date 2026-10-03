/*
 * function: func_021DCC48
 * address: 0x021DCC48
 * packet: pkt_ov134_021DCC48
 * region: ov134
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: body ends at 021DCC9C; callback table and zero data follow.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Big;
struct Blk37;
extern void *func_02012EBC(struct Big *p);
extern u8 *func_02012944(void *p);
extern void *func_0200CA1C(void *);
extern u32 func_0200873C(void *);
extern u32 func_0201AA18(void *p);
extern u32 func_0200CA38(struct Blk37 *p);
void func_021DCC48(u8 *p, void *unused, u8 *out)
{
    void *a;
    void *b;
    a = func_02012EBC(*(void **)(p + 0x14));
    func_02012944(*(void **)(p + 0x14));
    b = func_0200CA1C(*(void **)(p + 0x14));
    *(u32 *)(out + 0) = *(u32 *)(p + 4);
    *(u32 *)(out + 8) = *(u32 *)(p + 0x14);
    *(u32 *)(out + 4) = func_0200873C(a);
    out[12] = 1;
    out[13] = 1;
    out[14] = func_0201AA18(*(void **)(p + 4));
    out[15] = 0;
    out[16] = 0;
    out[17] = 0;
    out[18] = 0;
    *(u16 *)(out + 20) = 0;
    *(u32 *)(out + 24) = func_0200CA38(b);
    *(u32 *)(out + 32) = 0;
    *(u32 *)(out + 36) = 0;
}
