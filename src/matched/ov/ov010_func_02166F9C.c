/*
 * function: func_02166F9C
 * address:  0x02166F9C
 * packet:   pkt_ov010_02166F9C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_020120B4  0x020120B4  thumb
 *   ov_id_D9  0x000000D9  data
 *   d_021C3FE0  0x021C3FE0  data  ov217
 *   func_020145CC  0x020145CC  thumb
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Evt;
struct IcaAnime;
extern int func_021BE8D4(void *a, int b, int sel, int d);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_020144DC(int a0, int a1);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern void *func_020145CC(void *a0);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void func_020307B0(void *p);
extern char ov_id_D9[];
extern char d_021C3FE0[];

int func_02166F9C(void *a, int *st, int *p)
{
    int p0 = p[0];
    int p1 = p[1];
    switch (*st) {
    case 0:
        func_02012374(a, (struct Evt **)func_021BE8D4((void *)p0, p1, 0, 0));
        *st = 1;
        break;
    case 1:
        func_02012374(a, (struct Evt **)func_020144DC(p0, p1));
        *st = 2;
        break;
    case 2:
        func_020120B4((struct IcaAnime *)p0, (u32)ov_id_D9, d_021C3FE0, (void *)p[2]);
        *st = 3;
        break;
    case 3:
        func_02012374(a, (struct Evt **)((int)func_020145CC((void *)p0)));
        *st = 4;
        break;
    case 4:
        func_02012374(a, (struct Evt **)func_021BE92C((void *)p0, p1, 0, 0, 1, 0, 0));
        *st = 5;
        break;
    case 5:
        func_020307B0((void *)p[2]);
        return 1;
    }
    return 0;
}
