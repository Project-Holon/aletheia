/*
 * function: func_021AF174
 * address:  0x021AF174
 * packet:   pkt_ov021_021AF174
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct S { u32 f0; u32 f4; u32 f8; } S;

extern int func_02158F58(int a0);
extern void *func_02029620(void *a, u16 b, u16 c);
extern void func_0215897C(void *vm, void *task);

int func_021AF174(S *s, u32 *st)
{
    u32 x = s->f8;

    func_02158F58(x);
    switch (*st) {
    case 0:
        func_0215897C((void *)x, func_02029620((void *)s->f0, 0, 0));
        (*st)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}
