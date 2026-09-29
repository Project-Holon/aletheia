/*
 * unit:     yes
 * function: func_021EE23C, func_021EE25C, func_021EE264
 * address:  0x021EE23C
 * packet:   pkt_ov093_021EE23C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_0204E720  0x0204E720  arm
 *   func_021EB318  0x021EB318  thumb  ov093
 *   func_021EE3E8  0x021EE3E8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Q {
    int f00;
    int f04;
};

struct T {
    u16 v[7];
};

struct O {
    u8 pad00[0xe0];
    int (*fe0)(void *, void *);
    int (*fe4)(void *, void *);
    void *fe8;
    int fec;
};

extern void func_02043B5C(int a, int b);
extern void func_02045334(int a);
extern void func_0204E720(int a, int b, int c, int d);
extern int func_021EB318(void);
extern int func_021EE3E8(void *a, void *b);

void func_021EE23C(struct Q *q)
{
    func_02043B5C(q->f04, 12);
    func_02045334(q->f00);
    func_0204E720(1, 16, 0, -3);
}

int func_021EE25C(void)
{
    return func_021EB318();
}

void func_021EE264(char *o, int a, struct T *src)
{
    *(int *)(o + 0x16c) = a;
    *(struct T *)(o + 0x170) = *src;
    ((struct O *)o)->fe0 = 0;
    ((struct O *)o)->fe4 = func_021EE3E8;
    ((struct O *)o)->fe8 = o;
    ((struct O *)o)->fec = 0;
}
