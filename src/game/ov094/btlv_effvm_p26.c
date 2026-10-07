/*
 * file:     btlv_effvm_p26.c
 * unit:     yes
 * function: func_021F899C, func_021F89BC
 * address:  0x021F899C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_0220AF20  0x0220AF20  data  ov094
 *   sub_020307B0   0x020307B0  arm
 *   sub_02030EAC   0x02030EAC  arm
 *   sub_02030EE8   0x02030EE8  arm
 */
struct Node;
struct S02030EE8;
typedef struct {
    char pad[8];
    void *handle[32];      /* 0x008 */
    void (*cb[32])(void *); /* 0x088 */
    int arg[32];           /* 0x108 */
} Work;

typedef unsigned int u32;

extern u32 sub_02030EE8(struct S02030EE8 *p);
extern void sub_02030EAC(struct Node *n);
extern u32 sub_020307B0(void *p);
int func_021F899C(void *h);
void func_021F89BC(void *h);
extern Work *d_0220AF20;


int func_021F899C(void *h)
{
    int i;

    for (i = 0; i < 32; i++) {
        if (d_0220AF20->handle[i] == h)
            break;
    }
    return i;
}


void func_021F89BC(void *h)
{
    int i = func_021F899C(h);
    void *w;

    if (h == 0)
        return;
    w = (void *)sub_02030EE8(h);
    if (d_0220AF20->cb[i] != 0)
        d_0220AF20->cb[i](h);
    if (w != 0)
        sub_020307B0(w);
    sub_02030EAC(h);
    d_0220AF20->handle[i] = 0;
    d_0220AF20->cb[i] = 0;
}
