/*
 * function: func_02184A14
 * address:  0x02184A14
 * packet:   pkt_ov020_02184A14
 * region:   ov020
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02012374  0x02012374  thumb
 *   func_02161824  0x02161824  thumb  ov010
 *   func_02184360  0x02184360  thumb  ov020
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_021BC550  0x021BC550  thumb  ov021
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_021C6E48  0x021C6E48  thumb  ov021
 */

typedef unsigned char  u8;
typedef short s16;

typedef unsigned int   u32;
struct Evt;
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void *func_02161824(void *a, void *b);
extern void *func_02184360(u8 *p, int value);
extern u32 func_02188D20(u8 *p);
extern u32 func_02188D38(u8 *p);
extern void func_021BC550(void *p, int v);
extern int func_021BE8D4(void *a, int b, int sel, int d);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern int func_021C6E48(int a);

int func_02184A14(int ctx, int *state, u8 *p)
{
    int x = *(int *)(p + 0);
    int z = *(int *)(p + 8);
    int t = func_02188D38((u8 *)z);

    switch (*state) {
    case 0:
        func_02012374((struct Evt *)ctx, (struct Evt **)func_021BE8D4((void *)x, z, 1, 0));
        (*state)++;
        break;
    case 1:
        if (func_021C6E48(t)) {
            func_02012374((struct Evt *)ctx, func_02161824((void *)x, (void *)z));
            (*state)++;
        }
        break;
    case 2:
        func_02012374((struct Evt *)ctx, func_02184360(p, 0));
        (*state)++;
        break;
    case 3:
        func_02012374((struct Evt *)ctx, (struct Evt **)func_021BE92C((void *)x, z, 1, 0, 1, 0, 0));
        (*state)++;
        break;
    case 4:
        func_021BC550((void *)func_02188D20((u8 *)z), *(s16 *)(p + 0x14));
        return 1;
    }
    return 0;
}
