/*
 * file:     unit_021E65B0_p02.c
 * unit:     yes
 * function: func_021E67F4, func_021E6800, func_021E6840
 * address:  0x021E67F4
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
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021E6908 0x021E6908 thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021D5778 0x021D5778 thumb ov093
 *   func_021D5584 0x021D5584 thumb ov093
 *   func_021D7040 0x021D7040 thumb ov093
 *   d_021F2B58     0x021F2B58  data   ov093  a4

 */
struct S;
struct Node;
struct UtilWork;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern int func_021E6908(u16);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5B68(void *);
extern u8 func_021D5778(struct UtilWork *p, u16 id);
extern u8 func_021D5584(struct UtilWork *p, u32 i);
extern void func_021D7040(struct Node *n);
void func_021E6800(int u, void *a, u32 b, u32 *q);
void func_021E6840(void *x, void *a, int c);


extern int d_021F2B58[];
int *func_021E67F4(int *p);

int *func_021E67F4(int *p)
{
    *p = 3;
    return d_021F2B58;
}

void func_021E6800(int u, void *a, u32 b, u32 *q)
{
    u8 *e;

    if (b == func_021D775C(3)) {
        e = func_021C88A4(a, 4, b);
        func_021C8838(e + 4, 2, 0x278);
        func_021C8860((struct S *)(e + 4), b);
        func_021C88C8(a, e);
        q[6] = 1;
    }
}

/*
 * lever: Callback kind 10 is reused as the multiplier, then decreased by 11;
 * this retains the live constant and reproduces the spill frame and muls.
 */
void func_021E6840(void *x, void *a, int c)
{
    u8 k;
    void *m;
    u16 id;
    int i;
    u8 *p;
    int multiplier;
    if (c == func_021D775C(4)) {
        if (func_021E6908((u16)func_021D775C(18)) == 0) {
            if (func_021D5B68(func_021C7CF4(a, c)) != 0) {
                k = func_021D775C(3);
                m = func_021C7CF4(a, k);
                id = func_021D775C(20);
                i = func_021D5778(m, id);
                if (i != 4) {
                    multiplier = 10;
                    p = func_021C88A4(a, multiplier, c);
                    p[5] = k;
                    p[6] = i;
                    multiplier -= 11;
                    p[4] = func_021D5584(m, (u8)i) * multiplier;
                    p[7] |= 2;
                    func_021C8838(p + 8, 2, 0x27b);
                    func_021C8860((struct S *)(p + 8), k);
                    func_021C8860((struct S *)(p + 8), id);
                    func_021C88C8(a, p);
                }
                func_021D7040(x);
            }
        }
    }
}
