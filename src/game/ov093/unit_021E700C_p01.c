/*
 * file:     unit_021E700C_p01.c
 * unit:     yes
 * function: func_021E7080, func_021E70E4
 * address:  0x021E7080
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   d_021F2404     0x021F2404  data  ov093  a1
 *   d_021F2654     0x021F2654  data  ov093  a4
 *   func_021C83A0  0x021C83A0  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern int func_021D76BC(int key, u32 val);
extern u32 func_021C83A0(u8 *p, int i);
extern u8 func_021D5440(u8 *p);
void func_021E7080(int x, int a, int c);
int *func_021E70D8(int *p);
void func_021E70E4(int x, int a, int c);
extern const u8 d_021F2404[7];
extern int d_021F2654[];


/*
 * note:     the bonus is a compound add onto the fetched value
 *           (`t = get(0x30); t += sum * 0x14; set(0x30, t);`): it copies sum
 *           into r1 and multiplies by 0x14 held in r0 like the image; every
 *           single-expression spelling (`t + sum * 0x14`, an inline helper,
 *           a narrow or enum multiplier local) multiplies in the constant's
 *           register and is 4 bytes short.  func_021E70D8 is the unlabelled
 *           12-byte store-and-return leaf after the pool (twin of
 *           ov093_func_021E7164.c's func_021E71D8).
 */
void func_021E7080(int x, int a, int c)
{
    void *m;
    int sum;
    u32 i;
    int v;
    int t;

    if (c == func_021D775C(3)) {
        m = func_021C7CF4((int *)a, c);
        sum = 0;
        for (i = 0; i < 7; i++) {
            v = func_021D59B4(m, d_021F2404[i]) - 6;
            if (v > 0) {
                sum += v;
            }
        }
        if (sum != 0) {
            t = func_021D775C(0x30);
            t += sum * 0x14;
            func_021D76BC(0x30, t);
        }
    }
}


int *func_021E70D8(int *p)
{
    *p = 1;
    return d_021F2654;
}


void func_021E70E4(int x, int a, int c)
{
    void *m;
    int p;
    int q;
    int r;
    int v;

    if (c == func_021D775C(3)) {
        func_021C7CF4((int *)a, c);
        m = func_021C7CF4((int *)a, (u8)func_021D775C(4));
        p = func_021C83A0((u8 *)a, c);
        q = func_021C83A0((u8 *)a, func_021D5440(m));
        r = p / q;
        if (r >= 5) {
            v = 0x78;
        } else if (r == 4) {
            v = 0x64;
        } else if (r == 3) {
            v = 0x50;
        } else {
            v = 0x3c;
            if (r != 2) {
                v = 0x28;
            }
        }
        func_021D76BC(0x30, v);
    }
}
