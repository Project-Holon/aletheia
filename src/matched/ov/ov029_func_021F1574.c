/*
 * function: func_021F1574
 * address:  0x021F1574
 * packet:   pkt_ov029_021F1574
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     the two tables are `const`: non-const, the copy of p lands after the first
 *           stack-argument store (4 bytes out). The loop needs i = 0 hoisted first, the
 *           base hoisted and q = p + i*4 with q[0x6e].
 * symbols:
 *   func_0204ABF0  0x0204ABF0  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049F78  0x02049F78  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0203D88C  0x0203D88C  arm
 *   func_0203D34C  0x0203D34C  arm
 *   d_021F31C8     0x021F31C8  data  a4
 *   d_021F33CC     0x021F33CC  data  a4
 */

extern int func_0204ABF0(int, int, int, int, int);
extern int func_0204A6C8(int, int, int, int, int);
extern int func_0204AF28(int, int, int, int);
extern int func_02049F78(int, int, void *, int);
extern void func_020307B0(void *p);
typedef unsigned int   u32;
extern void func_0203D88C(u32 a, u32 b);
extern void func_0203D34C(u32 a, u32 b);
extern const int d_021F31C8[];
extern const int d_021F33CC[];

void func_021F1574(char *p, int idx)
{
    int i;
    int r;
    char *loc;
    int *base;
    int *q;

    i = 0;
    *(int *)(p + 0x28) = func_0204ABF0(*(int *)(p + 0x24), d_021F31C8[idx], 1, 0, 0x70);
    *(int *)(p + 0x2c) = func_0204A6C8(*(int *)(p + 0x24), 0x16, 0, 1, 0x70);
    *(int *)(p + 0x30) = func_0204AF28(*(int *)(p + 0x24), 0x15, 0x14, *(unsigned short *)(p + 0xc));
    r = func_02049F78(*(int *)(p + 0x24), 0x18, &loc, *(unsigned short *)(p + 0xc));
    base = *(int **)(loc + 0xc);
    for (; i < 17; i++) {
        q = (int *)(p + i * 4);
        q[0x6e] = base[d_021F33CC[i]];
    }
    func_020307B0((void *)r);
    func_0203D88C(0xda, 0xe);
    func_0203D34C(0, *(unsigned short *)(p + 0xc));
}
