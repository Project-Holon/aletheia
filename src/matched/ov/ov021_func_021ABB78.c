/*
 * function: func_021ABB78
 * address:  0x021ABB78
 * packet:   pkt_ov021_021ABB78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021AB760  0x021AB760  thumb
 *   func_021ABABC  0x021ABABC  thumb
 *   func_0218F05C  0x0218F05C  thumb
 */

typedef struct {
    int pad[7];
    int f1c;
} S;

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_021AB760(u8 *p);
extern void func_0218F05C(unsigned char *a);
typedef unsigned short u16;
extern void func_021ABABC(int a0, const u16 *p, void *q);

void func_021ABB78(int a, S *s, int c)
{
    int h = func_021AB760((u8 *)a);
    func_021ABABC(a, (const u16 *)s, (void *)c);
    if (s->f1c != 0) {
        func_0218F05C((unsigned char *)h);
    }
}
