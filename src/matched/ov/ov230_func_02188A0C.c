/*
 * function: func_02188A0C
 * address: 0x02188A0C
 * packet: pkt_ov230_02188A0C
 * status: EXACT
 * region: ov230
 * isa: arm
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * extent: lead60B; larger loader follower02188A48..02188B48, then encoded payload through02188CB0.
 */
int func_02188A0C(unsigned word)
{
    unsigned char opcode=word>>24;
    if ((opcode&14)==10) {
        if ((opcode&240)==240) return 1;
        if (opcode&1) return 2;
        else return 3;
    }
    return 0;
}
