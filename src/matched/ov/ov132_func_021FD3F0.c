/*
 * function: func_021FD3F0
 * address: 0x021FD3F0
 * packet: pkt_ov132_021FD3F0
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * layout: 021FC862..021FC93E initializes four 48-byte records at +0x60.
 */
struct Record { int f0; int flag; char pad8[0x14]; char *data; char pad20[0x10]; };
struct Context { char pad0[0x60]; struct Record rec[4]; };
void *func_021FD3F0(long i,struct Context *p)
{
    p->rec[i].flag=0;
    return p->rec[i].data;
}
