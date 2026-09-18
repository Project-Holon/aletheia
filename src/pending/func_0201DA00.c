/*
 * function: func_0201DA00
 * address:  0x0201DA00
 * packet:   pkt_0201DA00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  0209E73C
 * symbols:
 *   g_0209E73C      0x0209E73C  data
 */

extern int g_0209E73C[];
void func_0201DA00(char *font, int c, int heap)
{
    void (*fn)(char *, unsigned char, unsigned char, int);
    *(int *)font = c;
    fn = (void (*)(char *, unsigned char, unsigned char, int))g_0209E73C[c];
    fn(font, *(unsigned char *)(font + 0x7e), *(unsigned char *)(font + 0x7f), heap);
}
