/*
 * function: func_021F399C
 * address:  0x021F399C
 * packet:   pkt_ov060_021F399C
 * region:   ov060
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    int a;
    int b;
    int c;
} V;

extern void func_021BE4B4(char *p, int i, int j, int v);
extern void func_021BE6CC(void *p, int i, int j, u16 k, int flag);
extern V *func_021BE480(void *p, int i, int j);

void func_021F399C(u8 *o, void *p, V *v)
{
    int i;

    func_021BE4B4(p, 0, 0x14, 0);
    for (i = 0; i < 3; i++) {
        func_021BE6CC(p, 0, 0x14, (u16)i, 0);
    }
    *func_021BE480(p, 0, 0x14) = *v;
    o[1] = 1;
}
