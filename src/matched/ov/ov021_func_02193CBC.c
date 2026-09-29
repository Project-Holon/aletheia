/*
 * function: func_02193CBC
 * address:  0x02193CBC
 * packet:   pkt_ov021_02193CBC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02193F6C  0x02193F6C  thumb  ov021
 *   func_02082BCC  0x02082BCC  arm
 *   func_02193FE8  0x02193FE8  thumb  ov021
 *   func_02194078  0x02194078  thumb  ov021
 */

extern void func_02193F6C(void *p);
extern void func_02082BCC(void *p, int v, int n);
extern void func_02193FE8(void *p);
extern void func_02194078(void *p);

void func_02193CBC(unsigned char *p)
{
    int i;
    unsigned char *q = *(unsigned char **)(p + 4);

    p[0] = 0;
    p[1] = 0;
    *(int *)(p + 8) = 0;
    if (q != 0) {
        for (i = 0; i < 10; i++)
            func_02193F6C(*(unsigned char **)(p + 4) + i * 0x50);
    }
    if (*(void **)(p + 0x14) != 0)
        func_02082BCC(*(void **)(p + 0x14), 0, 0x600);
    func_02193FE8(p + 0x18);
    func_02194078(p + 0x11c);
}
