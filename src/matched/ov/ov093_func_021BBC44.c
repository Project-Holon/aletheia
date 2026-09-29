/*
 * function: func_021BBC44
 * address:  0x021BBC44
 * packet:   pkt_ov093_021BBC44
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C84E8  0x021C84E8  thumb  ov093
 *   func_021BBCC4  0x021BBCC4  thumb  ov093
 *   func_021D6EE8  0x021D6EE8  thumb  ov093
 *   func_021BB920  0x021BB920  thumb  ov093
 *   func_021D74E4  0x021D74E4  thumb  ov093
 *   func_021BBCD4  0x021BBCD4  thumb  ov093
 *   func_021BC610  0x021BC610  thumb  ov093
 *   func_021BBFA8  0x021BBFA8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_021C84E8(u8 *p);
extern void func_021BBCC4(u8 *p);
extern void func_021D6EE8(void);
extern void func_021BB920(int);
extern void func_021D74E4(void);
extern void func_021BBCD4(u8 *p);
extern u8 func_021BC610(u8 *p, int a, u8 *q, int n);
extern u8 func_021BBFA8(u8 *p, u8 k);

int func_021BBC44(u8 *p, int a)
{
    int *q;
    u32 i;

    *(int *)(p + 0x14) = 0;
    q = *(int **)(p + 0xc);
    q[0] = 0;
    q[1] = 0;
    if (p[0x77c] == 0) {
        func_021C84E8(p);
        func_021BBCC4(p + 0x3e0);
        for (i = 0; i < 4; i++)
            p[i + 0x1fe8] = 0;
        func_021D6EE8();
        func_021BB920(*(int *)p);
        func_021D74E4();
        func_021BBCD4(p);
        p[0x782] = func_021BC610(p, a, p + 0x7e0, 6);
        p[0x77c] = 1;
    }
    p[0x783] = func_021BBFA8(p, p[0x783]);
    return *(int *)(p + 0x14);
}
