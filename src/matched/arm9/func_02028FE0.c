/*
 * function: func_02028FE0
 * address:  0x02028FE0
 * packet:   pkt_02028FD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned int u32;

struct T {
    u32 pad00[7];
    u32 f1c;
};

extern void func_02029344(void *obj, u32 value);
extern void func_02029364(struct T *p);
extern void func_02029374(struct T *p);
extern void func_020293D8(struct T *p);
extern void func_0202945C(struct T *p);

void func_02028FE0(struct T *p)
{
    switch (p->f1c) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        func_020293D8(p);
        func_02029374(p);
        func_02029344(p, 7);
        break;
    case 5:
        func_02029344(p, 8);
        break;
    case 6:
        func_02029344(p, 0xd);
        break;
    case 7:
        func_0202945C(p);
        func_02029344(p, 1);
        func_02029364(p);
        break;
    }
}
