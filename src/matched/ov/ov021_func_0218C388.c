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

typedef unsigned int   u32;
struct Owner;
int func_020477D4(struct Owner *owner, u32 index);

void func_0218C388(S *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (p->arr[i] != 0) {
            func_020477D4((struct Owner *)p->h, (unsigned short)i);
            p->arr[i] = 0;
        }
    }
}
