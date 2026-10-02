/*
 * function: func_021D88D0
 * address: 0x021D88D0
 * packet: pkt_ov093_021D88D0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D84F0 0x021D84F0 thumb ov093
 *   d_021F05A0 0x021F05A0 data a4
 */
extern unsigned int func_021D84F0(unsigned int,unsigned int);
extern unsigned char d_021F05A0[];

void *func_021D88D0(unsigned int *p)
{
    *p=func_021D84F0(7,1); return d_021F05A0;
}
