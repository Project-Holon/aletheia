/*
 * file:     unit_021E281C.c
 * unit:     yes
 * function: func_021E281C, func_021E2898, func_021E2908
 * address:  0x021E281C
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
 *   func_021D6940  0x021D6940  thumb  ov093
 *   func_021E8860  0x021E8860  thumb  ov093
 *   d_021F26AC     0x021F26AC  data   ov093  a4
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   _s32_div_f     0x0209C0A4  arm
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   d_021F2CA8     0x021F2CA8  data   ov093  a2
 *   d_021F2CAA     0x021F2CAA  data   ov093  a2
 *   d_021F249C     0x021F249C  data   ov093  a4
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   d_021F2444     0x021F2444  data   ov093  a4
 */
struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D6940(const u8 *p, int i, u32 j, u16 *out);
extern void func_021E8860(int n);
extern int func_021D59B4(u8 *p, int k);
extern int func_021D76BC(int key, u32 v);
extern int func_021D62A8(struct Unk021D62A8 *p);
extern void func_021D7704(int a, int b);
void func_021E281C(int a, void *b, int c);
int *func_021E288C(int *p);
void func_021E2898(int a, void *b, int c);
int *func_021E28FC(int *p);
void func_021E2908(int a, void *b, int c);
int *func_021E293C(int *p);
extern int d_021F26AC[];
extern u16 d_021F2CA8[];
extern u16 d_021F2CAA[];
extern int d_021F249C[];
extern int d_021F2444[];


void func_021E281C(int a, void *b, int c)
{
    void *v;
    u8 t;
    u8 j;
    u16 buf[4];

    if (c == func_021D775C(3)) {
        v = func_021C7CF4(b, c);
        t = func_021D775C(4);
        j = 0;
        while (func_021D6940(v, 0, j++, buf) != 0) {
            if (((u8 *)buf)[5] == t && buf[1] != 0) {
                func_021E8860(2);
                return;
            }
        }
    }
}


int *func_021E288C(int *p)
{
    *p = 1;
    return d_021F26AC;
}


void func_021E2898(int a, void *b, int c)
{
    void *m;
    int x;
    int y;
    u32 r;
    u32 i;

    if (c == func_021D775C(3)) {
        m = func_021C7CF4(b, c);
        x = func_021D59B4(m, 0xD);
        y = func_021D59B4(m, 0xE);
        r = x * 0x30 / y;
        if (r == 0)
            r = 1;
        for (i = 0; i < 5; i++) {
            if (r <= d_021F2CA8[i * 2])
                break;
        }
        func_021D76BC(0x30, d_021F2CAA[i * 2]);
    }
}


int *func_021E28FC(int *p)
{
    *p = 1;
    return d_021F249C;
}


void func_021E2908(int a, void *b, int c)
{
    int k;

    if (c == func_021D775C(3)) {
        k = func_021D62A8(func_021C7CF4(b, c));
        if (k == 5 || k == 1 || k == 4)
            func_021D7704(0x31, 2 << 12);
    }
}


int *func_021E293C(int *p)
{
    *p = 1;
    return d_021F2444;
}
