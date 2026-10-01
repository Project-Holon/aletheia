/*
 * function: func_021E11D0
 * address: 0x021E11D0
 * packet: pkt_ov183_021E11D0
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Extent remainder: zero alignment halfword at 021E1242.
 */
typedef unsigned short u16;
void func_021E11D0(char *p,int state)
{
    *(int *)(p+0x244)=*(int *)(p+0x240);
    *(int *)(p+0x240)=state;
    *(int *)(p+0x248)=0;
    *(int *)(p+0x24c)=0;
    *(int *)(p+0x250)=0;
    *(int *)(p+0x254)=0;
    if (state) {
        *(int *)(p+0x248)=*(u16 *)(p+(state-1)*4+0x21c);
        *(int *)(p+0x24c)=*(u16 *)(p+(state-1)*4+0x21e);
    }
    if (*(int *)(p+0x244)) {
        *(int *)(p+0x250)=*(u16 *)(p+(*(int *)(p+0x244)-1)*4+0x21c);
        *(int *)(p+0x254)=*(u16 *)(p+(*(int *)(p+0x244)-1)*4+0x21e);
    }
}
