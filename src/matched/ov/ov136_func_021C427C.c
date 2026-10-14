/*
 * function: MAILSYS_ProcMain
 * address:  0x021C427C
 * packet:   pkt_ov136_021C427C
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MAILSYS_ProcMain 0x021C427C thumb
 *   MAILSYS_RunSequence 0x021C42C8 thumb
 */
typedef unsigned char  u8;
extern int MAILSYS_RunSequence(u8 *p);
int MAILSYS_ProcMain(void *a, void *b, void *c, void *p)
{
    if (MAILSYS_RunSequence(p)) return 1;
    return 0;
}
