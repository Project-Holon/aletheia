/*
 * function: func_021BD578
 * address: 0x021BD578
 * packet: pkt_ov110_021BD578
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: independent switch leaf following func_021BD534; all registers
 * are incoming arguments; each arm returns through bx lr.
 */
typedef unsigned char u8;
void func_021BD578(int value,unsigned int which,u8 *p) {
    switch(which) {
    case 0: *(int *)(p+0x3c)=value; break;
    case 1:
    case 3: *(int *)(p+0x3c)=1; break;
    case 2: break;
    default: *(int *)(p+0x3c)=1; break;
    }
}
