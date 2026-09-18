/*
 * function: func_020097C4
 * address:  0x020097C4
 * packet:   pkt_020097C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  020A7198 - string class refuses (its left neighbour is a table,
 *           not a string: the bytes before the NUL run are 0x00 0x04 0x00
 *           0x00 0x00 0x04 of the byte table at 0x020A7174, not printable
 *           ASCII), and the pool word in this function is the address's only
 *           witness anywhere in the image.  Same class of dead end as
 *           src/pending/func_02008F08.c (0x020A716C, "mail.c").
 * symbols:
 *   g_020A7198      0x020A7198  data
 */

extern char g_020A7198[];
extern void *func_02030734(int a, int b, int c, void *d, int e);
extern void func_02009800(void *p);

void *func_020097C4(int a0)
{
    void *p = func_02030734((unsigned short)a0, 0x7c4, 1, g_020A7198, 0x39);
    func_02009800(p);
    return p;
}
