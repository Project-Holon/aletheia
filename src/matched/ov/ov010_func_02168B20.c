/*
 * function: func_02168B20
 * address:  0x02168B20
 * packet:   pkt_ov010_02168B20
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * lever: 02026454 reads the live 02012138 result in r0 in cases 0 and 1.
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CCC  0x02188CCC  thumb ov021
 *   func_02012138  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026400  0x02026400  thumb
 *   func_02012158  0x02012158  thumb
 *   func_020121CC  0x020121CC  thumb
 *   func_021A0F7C  0x021A0F7C  thumb ov021
 *   func_02168B18  0x02168B18  thumb ov010
 */

struct Ctx;
extern void *func_0201210C(const struct Ctx *);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Comm;
struct IcaAnime;
extern u32 func_02188CCC(u8 *p);
extern unsigned int func_02012138(const struct Ctx *);
extern u32 func_02026454(void *obj);
extern void func_02026400(struct Comm *p);
extern void func_02012158(char *p, unsigned int v);
extern u32 func_020121CC(struct IcaAnime *p);
extern int func_021A0F7C(u32 a, u32 b, u32 c, u32 d);
extern void func_02168B18(int *);

typedef enum { ST_0, ST_1, ST_2, ST_3, ST_4, ST_5 } State;

int func_02168B20(int a, int *b, int *c)
{
    int s = c[2];
    int x = func_02188CCC((u8 *)((int)func_0201210C((const struct Ctx *)s)));
    int y = func_02012138((const struct Ctx *)s);
    State t = (State)*b;
    switch (t) {
    case 0:
        if (func_02026454((void *)y) != 0)
            func_02026400((struct Comm *)y);
        (*b)++;
        break;
    case 1:
        if (func_02026454((void *)y) != 0)
            break;
        func_02012158((char *)s, 0);
        (*b)++;
        break;
    case 2:
        if (c[1] != 0) {
            func_02012158((char *)s, 1);
            func_020121CC((struct IcaAnime *)s);
        }
        (*b)++;
        break;
    case 3:
        func_021A0F7C(x, 8, (u32)func_02168B18, (u32)c);
        (*b)++;
        break;
    case 4:
        if (c[0] != 0)
            *b = t + 1;
        break;
    case 5:
        return 1;
    }
    return 0;
}
