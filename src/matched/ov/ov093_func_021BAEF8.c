/*
 * function: func_021BAEF8
 * address: 0x021BAEF8
 * packet: pkt_ov093_021BAEF8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Case 4 falls through into case 5; the two entry points prevent the
 * field-address setup from moving above the state increment.
 * symbols:
 *   func_021BB724 0x021BB724 thumb ov093
 *   func_021BB798 0x021BB798 thumb ov093
 *   func_021BB040 0x021BB040 thumb ov093
 *   func_021BB0A0 0x021BB0A0 thumb ov093
 *   func_021BB768 0x021BB768 thumb ov093
 *   func_021BB7D0 0x021BB7D0 thumb ov093
 *   func_021BA618 0x021BA618 thumb ov093
 *   func_021BABEC 0x021BABEC thumb ov093
 *   func_021BB280 0x021BB280 thumb ov093
 *   func_021BB6A8 0x021BB6A8 thumb ov093
 *   func_021BB628 0x021BB628 thumb ov093
 *   func_021BBD80 0x021BBD80 thumb ov093
 *   func_021BBD8C 0x021BBD8C thumb ov093
 *   func_021C84D8 0x021C84D8 thumb ov093
 *   func_021B916C 0x021B916C thumb ov093
 *   func_021BABF4 0x021BABF4 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021BB724(u8 *p, int a, int b, int c);
extern int func_021BB798(u8 *);
extern int func_021BB040(u8 *);
extern u32 func_021BB0A0(u8 *);
extern void func_021BB768(u8 *p, int a, u32 i, int b, int c);
extern void func_021BB7D0(const u8 *p);
extern int func_021BA618(u8 *);
extern void func_021BABEC(void *, void *);
extern int func_021BB280(u8 *p);
extern void func_021BB6A8(u8 *);
extern int func_021BB628(u8 *, int, int);
extern void func_021BBD80(u8 *);
extern int func_021BBD8C(u8 *, void *);
extern int func_021C84D8(u8 *p);
extern void func_021B916C(u8 *p, u32 x);
extern void func_021BABF4(void *);

int func_021BAEF8(u8 *p, int *s)
{
    switch (*s) {
    case 0:
        func_021BB724(p, 5, (int)(p + 0xcb4), p[0xcba]);
        (*s)++;
        break;
    case 1:
        if (func_021BB798(p)) {
            if (func_021BB040(p)) {
                p[0xec] = func_021BB0A0(p);
                func_021BB768(p, 4, 0, (int)(p + 0xec), 1);
            }
            (*s)++;
        }
        break;
    case 2:
        if (func_021BB798(p)) {
            func_021BB7D0(p);
            if (func_021BA618(*(u8 **)(p + 0xc))) {
                func_021BABEC(p, (void *)func_021BB280);
                break;
            }
            func_021BB6A8(p);
            if (func_021BB628(p, 2, 0))
                (*s)++;
            else
                *s += 2;
        }
        break;
    case 3:
        if (func_021BB798(p)) {
            func_021BB7D0(p);
            (*s)++;
        }
        break;
    case 4:
        func_021BB7D0(p);
        func_021BBD80(*(u8 **)(p + 0x44));
        (*s)++;
    case 5:
        *(int *)(p + 0x48) = func_021BBD8C(*(u8 **)(p + 0x44), p + 0xb4);
        {
            int *q = *(int **)(p + 0xcb0);
            func_021BB724(p, 8, (int)(q + 2), *q);
        }
        (*s)++;
        break;
    case 6:
        if (func_021BB798(p)) {
            func_021BB7D0(p);
            switch (*(int *)(p + 0x48)) {
            case 2:
                *s = 0;
                break;
            case 3:
                *s = 5;
                break;
            case 4:
                func_021B916C((u8 *)(*(int *)(p + 0xc)), func_021C84D8((u8 *)(*(int *)(p + 0x44))));
                func_021BABEC(p, (void *)func_021BB280);
                break;
            case 5:
                return 1;
            default:
                func_021BABF4(p);
                break;
            }
        }
        break;
    }
    return 0;
}
