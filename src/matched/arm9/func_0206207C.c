/*
 * function: func_0206207C
 * address:  0x0206207C
 * packet:   pkt_02061EB8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_02061D0C  0x02061D0C  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Node;
struct Range;
extern u32 func_02061D0C(struct Node **head1, struct Node **head2, struct Range *range);

typedef struct Node0206207C {
    u32 f00;
    u32 f04;
    struct Node0206207C *f08;
    struct Node0206207C *f0c;
} Node0206207C;

int func_0206207C(void *headp, void *freep, int a2, int a3)
{
    u32 buf[2];
    Node0206207C *x;

    buf[0] = a2;
    buf[1] = a2 + a3;
    func_02061D0C(headp, freep, (struct Range *)buf);
    x = *(Node0206207C **)freep;
    if (x != 0) {
        *(Node0206207C **)freep = x->f0c;
    }
    if (x == 0) {
        return 0;
    }
    x->f00 = buf[0];
    x->f04 = buf[1] - buf[0];
    x->f08 = 0;
    x->f0c = 0;
    if (*(Node0206207C **)headp != 0) {
        (*(Node0206207C **)headp)->f08 = x;
    }
    x->f0c = *(Node0206207C **)headp;
    x->f08 = 0;
    *(Node0206207C **)headp = x;
    return 1;
}
