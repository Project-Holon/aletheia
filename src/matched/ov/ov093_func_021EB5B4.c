/*
 * function: func_021EB5B4
 * address:  0x021EB5B4
 * packet:   pkt_ov093_021EB5B4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8ED8  0x021B8ED8  thumb  ov093
 *   func_021B98AC  0x021B98AC  thumb  ov093
 *   func_021D5864  0x021D5864  thumb  ov093
 *   func_021F7EE8  0x021F7EE8  thumb  ov094
 *   func_021EDA04  0x021EDA04  thumb  ov093
 *   func_021EB584  0x021EB584  thumb  ov093
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 func_021B8ED8(u8 *, u32);
extern int func_021B98AC(char *const *, u8);
extern int func_021D5864(int);
extern void func_021F7EE8(int, u32);
extern void func_021EDA04(u8 *);
extern void func_021EB584(int);
extern int func_021F7EB4(void);
int func_021EB5B4(u8 *p, int *state, u8 *src, u8 n)
{
    switch (*state) {
    case 0: {
        u32 c;
        u32 i;
        u8 k;
        for (i = 0; i < n; i++) {
            c = src[i];
            k = func_021B8ED8(*(u8 **)(p + 0x134), c);
            func_021F7EE8(func_021D5864(func_021B98AC(*(char *const **)(p + 0x138), k)), c);
            func_021EDA04(p + 0x48 + k * 12);
        }
        *state = *state + 1;
        break;
    }
    case 1:
        if (p[0x150] != 0)
            return 1;
        func_021EB584(-3);
        *state = *state + 1;
        break;
    case 2:
        if (func_021F7EB4() == 0)
            return 1;
        break;
    }
    return 0;
}
