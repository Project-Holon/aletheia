/*
 * function: func_021F2F44
 * address:  0x021F2F44
 * packet:   pkt_ov032_021F2F44
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * note:     func_0204B258 takes two arguments (twin ov029_func_021F1DE8): the
 *           0x12C result still in r1 at that call is its second argument.
 * symbols:
 *   func_021F2F44 0x021F2F44 thumb
 *   d_021F35E0 0x021F35E0 data ov032 a4
 *   func_0204B100 0x0204B100 arm
 *   func_0204B034 0x0204B034 arm
 *   func_0204B258 0x0204B258 arm
 *   func_02025538 0x02025538 thumb
 *   func_021F3264 0x021F3264 thumb ov032
 *   func_021F32F8 0x021F32F8 thumb ov032
 *   func_02043598 0x02043598 arm
 */

typedef struct { int w[4]; } T16;

extern T16 d_021F35E0;
extern int func_0204B100(int, int, unsigned);
extern int func_0204B034(T16 *, int, unsigned);
extern void func_0204B258(int, int);
extern int func_02025538(unsigned, int);
extern void func_021F3264(char *);
extern void func_021F32F8(char *, unsigned char);
extern void func_02043598(unsigned, unsigned);

void func_021F2F44(char *p)
{
    T16 t;
    int i;

    *(int *)(p + 0x128) = func_0204B100(0x40, 0, *(unsigned short *)(p + 0x94));
    t = d_021F35E0;
    *(int *)(p + 0x12c) = func_0204B034(&t, 1, *(unsigned short *)(p + 0x98));
    func_0204B258(*(int *)(p + 0x128), *(int *)(p + 0x12c));
    *(int *)(p + 0x124) = func_02025538(*(unsigned short *)(p + 0x98), *(int *)(p + 0x128));
    func_021F3264(p);
    for (i = 0; i < 5; i++) {
        func_021F32F8(p, i);
    }
    func_02043598(0x10, 1);
}
