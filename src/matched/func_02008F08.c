/*
 * function: func_02008F08
 * address:  0x02008F08
 * packet:   pkt_02008F08
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  020A716C
 * symbols:
 *   g_020A716C      0x020A716C  data
 */

extern char g_020A716C[];
extern void *func_02030734(int a, int b, int c, void *d, int e);
extern void func_02008EAC(void *p);
void *func_02008F08(int a0)
{
    void *p = func_02030734((unsigned short)((a0 & 0x7fff) | 0x8000), 0x38, 0, g_020A716C, 0x87);
    func_02008EAC(p);
    return p;
}
