/*
 * function: func_021C3198
 * address:  0x021C3198
 * packet:   pkt_ov021_021C3198
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * VBlank task: applies the saved display setup, ends itself, flags completion.
 *
 * symbols:
 *   d_021DA700     0x021DA700  data  ov021
 */

typedef unsigned int u32;

typedef struct { u32 v[4]; } T;

struct Node;
extern void func_02040588(u32 which, u32 enable);
extern void func_0203FC28(T *p);
extern void func_02030EAC(struct Node *n);
extern const T d_021DA700;

void func_021C3198(void *p, u32 *done)
{
    T t;

    func_02040588(0, 1);
    t = d_021DA700;
    func_0203FC28(&t);
    func_02030EAC(p);
    if (done != 0)
        *done = 1;
}
