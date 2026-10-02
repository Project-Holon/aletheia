/*
 * function: func_021BA028
 * address: 0x021BA028
 * packet: pkt_ov072_021BA028
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: trailing two-byte alignment padding.
 * symbols:
 *   func_021B6448 0x021B6448 thumb ov067
 */
extern int func_021B6448(unsigned char *);
int func_021BA028(char *p) {
    int n;
    n = func_021B6448(*(unsigned char **)(p + 12));
    if (n == -1) n = *(int *)(p + 24);
    return n;
}
