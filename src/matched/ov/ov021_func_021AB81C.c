/*
 * function: func_021AB81C
 * address:  0x021AB81C
 * packet:   pkt_ov021_021AB81C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021AB868  0x021AB868  thumb
 *   func_02049238  0x02049238  arm
 *   func_020307B0  0x020307B0  arm
 */

typedef struct {
    int pad[2];
    int f8[2];
} S;

extern void func_021AB868(S *s);
extern void func_02049238(int a);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void func_021AB81C(S *s)
{
    int i;
    func_021AB868(s);
    for (i = 0; i < 2; i++) {
        func_02049238(s->f8[i]);
    }
    func_020307B0(s);
}
