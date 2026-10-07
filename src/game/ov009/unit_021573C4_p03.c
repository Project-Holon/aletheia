/*
 * file:     unit_021573C4_p03.c
 * unit:     yes
 * function: func_021579BC, func_021579E8
 * address:  0x021579BC
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082EA4  0x02082EA4  arm
 *   func_02166444  0x02166444  arm  ov009
 *   g_021A1CC0  0x021A1CC0  data
 *   g_021A826C  0x021A826C  data
 */
extern void func_02082EA4(void *src, void *dst, unsigned long size);
extern long func_02166444(unsigned char *dst, unsigned char *header, long headerLen, unsigned char *body, long bodyLen);
int func_021579BC(unsigned short *a, unsigned short *b);
void func_021579E8(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len);
extern char g_021A1CC0[];
extern unsigned char g_021A826C;

/*
 * Compares three halfwords through advancing cursors; 1 at the first
 * mismatch, 0 when all three agree.
 */
int func_021579BC(unsigned short *a, unsigned short *b)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (*a++ != *b++) return 1;
    }
    return 0;
}


/*
 * sdk:      send_packet (libcps.TWL.HYB.a(network.o))
 */
void func_021579E8(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len)
{
    func_02082EA4(g_021A1CC0, hdr + 6, 6);
    g_021A826C = func_02166444(hdr, hdr + 6, hdr_len - 6, body, body_len) < 0;
}
