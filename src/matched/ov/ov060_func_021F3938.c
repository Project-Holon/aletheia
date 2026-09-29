/*
 * function: func_021F3938
 * address:  0x021F3938
 * packet:   pkt_ov060_021F3938
 * region:   ov060
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Leaf filed for ov060 func_021F374C / func_021F36C0 (a file for the same
 * address exists only under ov045, a different overlay at the same address).
 *
 * symbols:
 *   func_02026454  0x02026454  thumb
 *   func_02026474  0x02026474  thumb
 */

extern unsigned int func_02026454(void *p);
extern void *func_02026474(void *p);

void *func_021F3938(void *p)
{
    if (func_02026454(p) == 2) {
        return func_02026474(p);
    }
    return 0;
}
