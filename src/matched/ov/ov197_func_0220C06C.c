/*
 * function: func_0220C06C
 * address: 0x0220C06C
 * packet: pkt_ov197_0220C06C
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
void func_0220C06C(char *p)
{
    unsigned i;
    for(i=0;i<9;i++) *(int *)(p+0x544+i*4)=-1;
    for(i=0;i<9;i++) *(int *)(p+0x568+i*4)=-1;
    for(i=0;i<3;i++) *(int *)(p+0x58c+i*4)=-1;
}
