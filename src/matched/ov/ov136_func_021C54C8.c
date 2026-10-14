/*
 * function: MB_SEQ_ProcMain
 * address:  0x021C54C8
 * packet:   pkt_ov136_021C54C8
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MB_SEQ_ProcMain 0x021C54C8 thumb
 *   MB_SEQ_Update 0x021C68A0 thumb
 */
typedef unsigned char  u8;
extern int MB_SEQ_Update(u8 *p, int *st);
int MB_SEQ_ProcMain(void *a, void *b, void *c, void *p)
{
    if (MB_SEQ_Update(p, b) == 0) return 1;
    return 0;
}
