/*
 * function: func_02159340
 * address: 0x02159340
 * packet: pkt_ov010_02159340
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero alignment padding follows the 46-byte function.
 * lever: inline byte reader binds the load before incrementing the cursor;
 * a postincrement expression schedules the cursor store before the load.
 * symbols:
 *   func_0215932C 0x0215932C thumb ov010
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_0215932C(unsigned int, unsigned int);
static inline int ReadByte(u8 *p)
{
    int v = **(u8 **)(p + 20);
    (*(u8 **)(p + 20))++;
    return v;
}
int func_02159340(u8 *p)
{
    u8 a, b;
    a = (*(u32 **)(p + 28))[ReadByte(p)];
    b = (*(u32 **)(p + 28))[ReadByte(p)];
    p[14] = func_0215932C(a, b);
    return 0;
}
