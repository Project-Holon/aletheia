/*
 * file:     btl_server_p156.c
 * unit:     yes
 * function: func_021D210C, func_021D215C, func_021D21D4, func_021D2234
 * address:  0x021D210C
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
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021EA0F4  0x021EA0F4  thumb  ov093
 *   func_021EA120  0x021EA120  thumb  ov093
 *   func_021CD644  0x021CD644  thumb  ov093
 *   func_021EA280  0x021EA280  thumb  ov093
 *   func_021EA2BC  0x021EA2BC  thumb  ov093
 *   func_021EA384  0x021EA384  thumb  ov093
 *   func_021EA3A0  0x021EA3A0  thumb  ov093
 *   func_021EA678  0x021EA678  thumb  ov093
 *   func_021EA710  0x021EA710  thumb  ov093
 *   func_021B8E70  0x021B8E70  thumb  ov093
 *   func_021F81D0  0x021F81D0  thumb  ov094
 */
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u32 unk00;
    u32 unk04;
    u8 unk08[0x4C];
    void *win;            /* 0x54 */
} Seq_021D210C;

typedef struct {
    u8 unk00[0x54];
    void *win;            /* 0x54 */
    u8 unk58[0x134 - 0x58];
    u32 unk134;
} Seq_021D215C;

typedef struct {
    u32 unk00;
    u32 unk04;
    u8 unk08[0x4C];
    void *win;            /* 0x54 */
} Seq_021D21D4;

typedef struct {
    u32 unk00;
    u32 unk04;
} Seq_021D2234;

extern int func_021B8D8C(void *p, void *a, u32 b);
extern void func_021EA0F4(struct S *s, u32 a, u32 b, u32 c);
extern int func_021EA120(struct S *s);
extern u8 func_021CD644(u8 *p);
extern void func_021EA280(char *ctx, u32 n, int b, const u8 *c, u16 e);
extern int func_021EA2BC(char *ctx);
extern void func_021EA384(char *ctx, int a);
extern int func_021EA3A0(u32 *p);
extern void func_021EA678(char *p, u16 k, int *c);
extern int func_021EA710(u32 *p);
extern u8 func_021B8E70(u8 *p, u32 k);
extern void func_021F81D0(u32 a, u32 b);
int func_021D210C(Seq_021D210C *s, int *state, u32 *a);
int func_021D215C(Seq_021D215C *s, int *state, u32 *a);
int func_021D21D4(Seq_021D21D4 *s, int *state, u32 *a);
int func_021D2234(Seq_021D2234 *s, int *state, u32 *a);


int func_021D210C(Seq_021D210C *s, int *state, u32 *a)
{
    int t;

    switch (*state) {
    case 0:
        t = func_021B8D8C((void *)s->unk00, (void *)s->unk04, (u8)a[0]);
        func_021EA0F4(s->win, (u16)a[2], t, (u8)a[1]);
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA120(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}


int func_021D215C(Seq_021D215C *s, int *state, u32 *a)
{
    u8 buf[8];
    u8 i;
    u16 n;
    u32 p1;
    u16 p2;

    switch (*state) {
    case 0:
        n = a[0];
        p1 = a[1];
        p2 = a[2];
        for (i = 0; i < n; i++) {
            buf[i] = func_021CD644((u8 *)s->unk134);
        }
        func_021EA280(s->win, n, p1, buf, p2);
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA2BC(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}


int func_021D21D4(Seq_021D21D4 *s, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        func_021EA384(s->win, func_021B8D8C((void *)s->unk00, (void *)s->unk04, (u8)a[0]));
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA3A0(s->win)) {
            func_021EA678(s->win, 0x61, (int *)a);
            *state = *state + 1;
        }
        break;
    case 2:
        if (func_021EA710(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}


int func_021D2234(Seq_021D2234 *s, int *state, u32 *a)
{
    int t;

    switch (*state) {
    case 0:
        t = func_021B8D8C((void *)s->unk00, (void *)s->unk04, (u8)a[0]);
        func_021F81D0(a[1], func_021B8E70((u8 *)s->unk00, t));
        *state = *state + 1;
        break;
    case 1:
        return 1;
    }
    return 0;
}
