/*
 * function: func_021A7484
 * address:  0x021A7484
 * packet:   pkt_ov021_021A7484
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A752C  0x021A752C  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned int u32;

typedef struct {
    u32 w[3];
} E;

typedef struct {
    E *arr;
    u32 n;
    void *p8;
} S;

extern void func_021A752C(E *e);
extern void func_020307B0(void *p);

void func_021A7484(S *s)
{
    u32 i;
    if (s->p8 != 0) {
        for (i = 0; i < s->n; i++) {
            func_021A752C(&s->arr[i]);
        }
        func_020307B0(s->arr);
        s->arr = 0;
        func_020307B0(s->p8);
        s->p8 = 0;
    }
}
