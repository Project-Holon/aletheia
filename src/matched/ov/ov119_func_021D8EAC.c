/*
 * function: func_021D8EAC
 * address: 0x021D8EAC
 * packet: pkt_ov119_021D8EAC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov119/pokemontrade_proc.c and filed here.
 */

/*
 * Hidden leaf (no caller seen): same lookup as func_021D8E90.
 */
int func_021D8EAC(int i, char *p)
{
    if (i >= 0 && i < 2)
        return *(int *)(p + i * 4 + 0x1064);
    return 0;
}
