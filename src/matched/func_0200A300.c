/*
 * function: func_0200A300
 * address:  0x0200A300
 * packet:   pkt_0200A2B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  0200A358 - not matched yet, and this file's own call at 0x0200A32C is the only branch to it in the image; matching 0x0200A358 (pkt_0200A358) converts this site to the `matched` class.  All 56 bytes right, 3 of 4 sites resolved (incl. the 020A71A4 string).
 * symbols:
 *   g_020A71A4      0x020A71A4  data
 */

typedef unsigned int u32;

extern char g_020A71A4[];
extern void *func_02030734(void *heap, int b, int c, void *d, int e);
extern void  func_02082BCC(void *p, int c, u32 n);
extern void  func_0200A358(void *p, void *a0, void *a1, void *a2);

void *func_0200A300(void *a0, void *a1, void *a2)
{
    void *p = func_02030734(a2, 0xc, 0, g_020A71A4, 0x260);

    func_02082BCC(p, 0, 0xc);
    func_0200A358(p, a0, a1, a2);
    return p;
}
