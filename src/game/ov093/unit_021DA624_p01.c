/*
 * file:     unit_021DA624_p01.c
 * unit:     yes
 * function: func_021DA624, func_021DA6EC, func_021DA748, func_021DA780
 * address:  0x021DA624
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
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7D54 0x021C7D54 thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D5B40 0x021D5B40 thumb ov093
 *   func_021D78AC 0x021D78AC thumb ov093
 *   func_021C88B4 0x021C88B4 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   d_021F09B0 0x021F09B0 data a4
 *   d_021F0B00 0x021F0B00 data a4
 *   func_021D76BC   0x021D76BC  thumb ov093
 *   func_021D5B48 0x021D5B48 thumb ov093
 */
struct QI;
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int);
extern u8 func_021C7D54(u8 *p, u8 *k, u8 *out);
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D5B40(struct QI *p);
extern u32 func_021D78AC(u32);
extern void func_021C88B4(void *, int, int);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *, int, int);
extern void func_021C8860(struct S *p, u32 val);
extern void func_021C88C8(void *, void *);
extern int func_021D76BC(int key, u32 val);
extern int func_021D5B48(u8 *p);
void func_021DA624(int a, void *b, int c);
int *func_021DA6D4(int *p);
int *func_021DA6E0(int *p);
void func_021DA6EC(int a, int b, int c);
void func_021DA748(int a, int *b, int c, int *d);
void func_021DA780(int a, int b, int c, int *d);
extern int d_021F09B0, d_021F0B00;

void func_021DA624(int a, void *b, int c)
{
    u16 values[4];
    u8 buf[4];
    u8 n;
    u8 count;
    u8 i;
    u8 choice;
    u8 *p;
    void *q;
    if (c != func_021D775C(2)) return;
    n = func_021C7D54(b, (u8 *)c, buf);
    count = 0;
    for (i = 0; i < n; i++) {
        q = func_021C7CF4(b, buf[i]);
        values[count] = func_021D5B40(q);
        if (values[count] != 0) count++;
    }
    if (count == 0) return;
    choice = func_021D78AC(count);
    func_021C88B4(b, 2, c);
    p = func_021C88A4(b, 4, c);
    func_021C8838(p + 4, 2, 0x1b7);
    func_021C8860((struct S *)(p + 4), c);
    func_021C8860((struct S *)(p + 4), values[choice]);
    func_021C88C8(b, p);
    func_021C88B4(b, 3, c);
}

int *func_021DA6D4(int *p) { *p = 2; return &d_021F09B0; }

int *func_021DA6E0(int *p) { *p = 3; return &d_021F0B00; }


void func_021DA6EC(int a, int b, int c)
{
    u8 *p;
    int m = 4;

    if (c != func_021D775C(4))
        return;
    if (func_021D76BC(0x41, 1) == 0)
        return;
    func_021C88B4((void *)b, 2, c);
    p = func_021C88A4((char *)b, m, c);
    func_021C8838(p + 4, 2, 0xd2);
    func_021C8860((struct S *)(p + 4), c);
    func_021C88C8((void *)b, p);
    func_021C88B4((void *)b, 3, c);
}


/*
 * extent: trailing two-byte alignment padding.
 */
void func_021DA748(int a, int *b, int c, int *d)
{
    int k = 4;
    if (c == func_021D775C(k)) {
        if (func_021D5B48(func_021C7CF4(b, c)) != 0) {
            *d = func_021D76BC(0x3a, k);
            return;
        }
        *d = 0;
    }
}


void func_021DA780(int a, int b, int c, int *d)
{
    u8 *p;

    if (c != func_021D775C(2))
        return;
    if (*d == 0)
        return;
    func_021C88B4((void *)b, 2, c);
    p = func_021C88A4((char *)b, 4, c);
    func_021C8838(p + 4, 2, 0x202);
    func_021C8860((struct S *)(p + 4), c);
    func_021C88C8((void *)b, p);
    func_021C88B4((void *)b, 3, c);
    *d = 0;
}
