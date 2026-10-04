/*
 * function: func_021BAB5C
 * address:  0x021BAB5C
 * packet:   pkt_ov093_021BAB5C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045808  0x02045808  arm
 *   func_020307B0  0x020307B0  arm
 *   func_021BBB48  0x021BBB48  thumb  ov093
 *   func_021EEAE0  0x021EEAE0  thumb  ov093
 */

typedef unsigned char  u8;
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
extern void func_020307B0(void *p);
extern void func_021BBB48(u8 *p);
extern void func_021EEAE0(void *p);

void func_021BAB5C(int a)
{
    int i;
    char *p = (char *)a;
    func_02045808((struct U16Vec *)(*(int *)(p + 0xac)));
    func_021BBB48((u8 *)(*(int *)(p + 0x44)));
    for (i = 0; i < 4; i++) {
        unsigned char *e = (unsigned char *)p + i * 0xc;
        if (e[0x1f] != 0xff && *(int *)(e + 0x14) != 0 && e[0x1e] == 0)
            func_021EEAE0((void *)(*(int *)(e + 0x14)));
    }
    func_020307B0((void *)a);
}
