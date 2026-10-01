/*
 * function: func_0221039C
 * address: 0x0221039C
 * packet: pkt_ov198_0221039C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:

 */
typedef unsigned char u8;
struct Flag {u8 low:7;u8 bit:1;};
int func_0221039C(char *p)
{
    if (((struct Flag *)(p+0x1e9b))->bit==0) return *(int *)(p+0x217c);
    return 0x1d;
}
