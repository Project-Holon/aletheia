/*
 * file:     btl_server_p153.c
 * unit:     yes
 * function: func_021D1E6C, func_021D1EB4, func_021D1F10, func_021D1F58
 * address:  0x021D1E6C
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
 *   func_021EA678  0x021EA678  thumb  ov093
 *   func_021EA710  0x021EA710  thumb  ov093
 *   func_021EA720  0x021EA720  thumb  ov093
 *   func_020061E4  0x020061E4  thumb
 *   func_021EA694  0x021EA694  thumb  ov093
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u8 unk00[0x54];
    void *win;            /* 0x54 */
} Seq;

extern u32 func_021CD9E0(u8 *p);
extern void func_021EA678(char *p, u16 k, int *c);
extern int func_021EA710(u32 *p);
extern int func_021EA720(u32 *p);
extern void func_020061E4(unsigned int arg);
extern void func_021EA694(char *p, u16 k, int *c);
int func_021D1E6C(Seq *s, int *state, u32 *a);
int func_021D1EB4(Seq *s, int *state, u32 *a);
int func_021D1F10(Seq *s, int *state, u32 *a);
int func_021D1F58(Seq *s, int *state, u32 *a);


int func_021D1E6C(Seq *s, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        if (func_021CD9E0((u8 *)s)) {
            return 1;
        }
        func_021EA678(s->win, a[0], (int *)(a + 1));
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


int func_021D1EB4(Seq *s, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        if (func_021CD9E0((u8 *)s)) {
            return 1;
        }
        func_021EA678(s->win, a[0], (int *)(a + 2));
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA720(s->win)) {
            func_020061E4(a[1]);
        }
        if (func_021EA710(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}


int func_021D1F10(Seq *s, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        if (func_021CD9E0((u8 *)s)) {
            return 1;
        }
        func_021EA694(s->win, a[0], (int *)(a + 1));
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


int func_021D1F58(Seq *s, int *state, u32 *a)
{
    switch (*state) {
    case 0:
        if (func_021CD9E0((u8 *)s)) {
            return 1;
        }
        func_021EA694(s->win, a[0], (int *)(a + 2));
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA720(s->win)) {
            func_020061E4(a[1]);
        }
        if (func_021EA710(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}
