/*
 * function: func_0218C388
 * address:  0x0218C388
 * packet:   pkt_ov021_0218C388
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020477D4  0x020477D4  arm
 */

typedef struct {
    int h;
    int f4;
    int arr[4];
} S;

void func_020477D4(int h, unsigned short i);

void func_0218C388(S *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (p->arr[i] != 0) {
            func_020477D4(p->h, i);
            p->arr[i] = 0;
        }
    }
}
