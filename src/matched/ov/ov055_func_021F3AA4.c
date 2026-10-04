/*
 * function: func_021F3AA4
 * address:  0x021F3AA4
 * packet:   pkt_ov055_021F3AA4
 * region:   ov055
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02189A38  0x02189A38  thumb  ov021
 *   func_02189A2C  0x02189A2C  thumb  ov021
 *   func_021F3F30  0x021F3F30  thumb  ov055
 *   func_021F3D90  0x021F3D90  thumb  ov055
 *   func_021F3CF4  0x021F3CF4  thumb  ov055
 *   func_021F4474  0x021F4474  thumb  ov055
 */

extern int func_02189A38(int);
typedef signed short   s16;
extern int func_02189A2C(int *a);
extern void func_021F3F30(char *, char *, int);
extern void func_021F3D90(char *);
extern void func_021F3CF4(char *, int, int);
extern void func_021F4474(s16 *a, s16 *b, int *c);

void func_021F3AA4(int a, int b, char *c)
{
    int i;

    func_021F3F30(c + 0x308, c, func_02189A38(b));
    if (func_02189A2C((int *)b)) {
        for (i = 0; i < 0x20; i++)
            func_021F3D90(c + 8 + i * 0x18);
    }
    for (i = 0; i < 0x20; i++)
        func_021F3CF4(c + 8 + i * 0x18, *(int *)(c + 4), *(int *)c);
    func_021F4474((s16 *)(c + 0x348), (s16 *)(c + 0x308), (int *)b);
}
