/*
 * function: func_0218C4EC
 * address:  0x0218C4EC
 * packet:   pkt_ov021_0218C4EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0218C518  0x0218C518  thumb  ov021
 */

typedef struct {
    void *key;
    int a;
    int b;
    int c;
} Ent;

void func_0218C518(void *p, Ent *e);

void func_0218C4EC(unsigned char *p, void *key)
{
    Ent *e = (Ent *)(p + 0x1F8);
    int i;
    for (i = 0; i < 0x120; i++) {
        if (e[i].key == key)
            func_0218C518(p, &e[i]);
    }
}
