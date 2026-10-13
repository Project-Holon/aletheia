/*
 * function: func_021F4F10
 * address: 0x021F4F10
 * packet: pkt_ov194_021F4F10
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_GetEosChar 0x02045A98 arm
 */
extern unsigned short STRBUF_GetEosChar(void);
int func_021F4F10(const unsigned short *a, const unsigned short *b)
{
    unsigned short sentinel = STRBUF_GetEosChar();
    int i;
    for (i = 0; i < 3; i++, a++, b++) {
        if (*a == 0x3000 && *b == sentinel) return 1;
        if (*a != *b) return 0;
        if (*b == sentinel) return 0;
    }
    return 1;
}
