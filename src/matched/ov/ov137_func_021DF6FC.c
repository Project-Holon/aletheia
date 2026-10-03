/*
 * function: func_021DF6FC
 * address: 0x021DF6FC
 * packet: pkt_ov137_021DF6FC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_0202EE30 0x0202EE30 thumb
 *   func_0203D7BC 0x0203D7BC arm
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_0203A5E4 0x0203A5E4 arm
 *   func_021DEB10 0x021DEB10 thumb ov137
 *   func_02184174 0x02184174 thumb ov022
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Entry;
struct Link;
extern struct Entry *func_020399A8(void);
extern u32 func_02039CB4(struct Link *p, u32 lo, u32 hi);
extern u8 *func_0202EE30(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
extern void func_0203D7BC(int);
extern void func_0203D7B0(int);
extern void func_0203A5E4(unsigned);
extern void *func_021DEB10(void *);
extern void func_02184174(u8 *p);
int func_021DF6FC(u8 *p)
{
    void *ctx;
    ctx = func_020399A8();
    if (*(int *)(p + 24) == 0) {
        if (func_02039CB4(ctx, 206, 40)) {
            *(void **)(p + 3496) = func_0202EE30(*(void **)(p + 3480), *(void **)(p + 3312), 15, 16, 114);
            func_0203D7BC(0);
            func_0203A5E4(10240);
            func_02184174(func_021DEB10(p));
            *(int *)p = 49;
        }
    } else {
        *(int *)(p + 12) += 1;
        if (*(int *)(p + 12) >= 180) {
            *(int *)(p + 12) = 0;
            if ((*(int **)(p + 220))[15] == 0) func_0203D7B0(0);
            *(int *)p = 49;
        }
    }
    return 0;
}
