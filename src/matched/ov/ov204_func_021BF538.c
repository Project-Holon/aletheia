/*
 * function: func_021BF538
 * address: 0x021BF538
 * packet: pkt_ov204_021BF538
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * lever: A switch with -1 before -2 preserves the outlined return order.
 * symbols:

 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

int func_021BF538(u8 *p,int *out)
{
    int v=*(int *)(p+44);
    switch(v){case -1:return 0;case -2:return 2;}
    if(out!=0)*out=v;
    return 1;
}
