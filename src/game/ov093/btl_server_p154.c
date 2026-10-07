/*
 * file:     btl_server_p154.c
 * unit:     yes
 * function: func_021D1FB4, func_021D2000
 * address:  0x021D1FB4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021CD9E0  0x021CD9E0  thumb  ov093
 *   func_021EA6F4  0x021EA6F4  thumb  ov093
 *   func_021EA710  0x021EA710  thumb  ov093
 *   func_021B98AC  0x021B98AC  thumb  ov093
 *   func_021D80A8  0x021D80A8  thumb  ov093
 *   func_0201BD28  0x0201BD28  thumb
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u8 unk00[0x54];
    void *win;            /* 0x54 */
} Seq;

extern u32 func_021CD9E0(u8 *p);
extern void func_021EA6F4(void *p, u8 b, u16 c);
extern int func_021EA710(u32 *p);
extern u8 *func_021B98AC(char *const *q, u8 b);
extern int func_021D80A8(void *p);
extern u32 func_0201BD28(u32 v, u32 n);
int func_021D1FB4(Seq *s, int *state, u32 *a);
u32 func_021D2000(u32 *p, u32 k, u8 b);


int func_021D1FB4(Seq *s, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        if (func_021CD9E0((u8 *)s)) {
            return 1;
        }
        func_021EA6F4(s->win, a[0], a[1]);
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA710(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}


/*
 * Unlabelled leaf (filed for the blocker of func_021D2030, lane S15).
 */
u32 func_021D2000(u32 *p, u32 k, u8 b)
{
    u8 *r;

    if (k != 0xAE) {
        return func_0201BD28(k, 0x1B);
    }
    r = func_021B98AC((char *const *)p[1], b);
    if (r) {
        return func_021D80A8(r);
    }
    return func_0201BD28(k, 0x1B);
}
