/*
 * function: func_021B9674
 * address: 0x021B9674
 * packet: pkt_ov218_021B9674
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_021B6144 0x021B6144 thumb ov067
 *   func_021B9AD0 0x021B9AD0 thumb ov218
 *   func_021BA94C 0x021BA94C thumb ov218
 */
struct S;
extern void func_0204E720(unsigned int, int, int, int);
extern int func_0204E804(void);
extern int func_021B6144(struct S *);
extern void func_021B9AD0(char *);
extern void func_021BA94C(char *);
int func_021B9674(void *ctx, int *state, void *unused, char *p)
{
    int result = 0;
    switch (*state) {
    case 0:
        func_0204E720(3, 16, 0, 1);
        ++*state;
        break;
    case 1:
        if (func_0204E804() == 0)
            ++*state;
        break;
    case 2:
        if (func_021B6144(*(struct S **)(p + 0x24)) != 0)
            result = 1;
        break;
    }
    func_021B9AD0(*(char **)(p + 0x28));
    func_021BA94C(*(char **)(p + 4));
    return result != 0;
}
