/*
 * file:     unit_021D8B50.c
 * unit:     yes
 * function: func_021D8B50, func_021D8B84, func_021D8BB4, func_021D8C00, func_021D8C0C, func_021D8C30, func_021D8C3C, func_021D8C4C, func_021D8C58, func_021D8C68, func_021D8C74, func_021D8C84, func_021D8C90, func_021D8CA0, func_021D8CAC, func_021D8CF4, func_021D8D34
 * address:  0x021D8B50
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
 *   d_021F07C0 0x021F07C0 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7AD4 0x021D7AD4 thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   d_021F07B8 0x021F07B8 data a4
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D76BC   0x021D76BC  thumb ov093
 *   d_021F0698     0x021F0698  data   ov093  a4
 *   func_021D7B60  0x021D7B60  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_0201C1E8  0x0201C1E8  thumb
 *   d_021F07D8     0x021F07D8  data   ov093  a4
 *   d_021F06B0     0x021F06B0  data   ov093  a4
 *   d_021F0610     0x021F0610  data   ov093  a4
 *   d_021F0648     0x021F0648  data   ov093  a4
 *   d_021F0640     0x021F0640  data   ov093  a4
 *   d_021F0638     0x021F0638  data   ov093  a4
 */
struct UtilWork;
struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int);
extern int func_021D7AD4(int);
extern void func_021D7704(int,int);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
int func_021D76BC(int key, u32 val);
extern u32 func_021D7B60(void *p, u32 n);
extern int func_021D59B4(u8 *p, int k);
extern int func_021D62A8(struct Unk021D62A8 *p);
extern int func_0201C1E8(int a);
void func_021D8B50(int a, int b, int c);
void *func_021D8B78(int *p);
void func_021D8B84(int a, int b, int c);
void *func_021D8BA8(int *p);
void func_021D8BB4(int u, int a, int k);
int *func_021D8C00(int *p);
void func_021D8C0C(void *a, void *b, int c);
int *func_021D8C30(int *p);
void func_021D8C3C(int a, int b, int c);
int *func_021D8C4C(int *p);
void func_021D8C58(int a, int b, int c);
int *func_021D8C68(int *p);
void func_021D8C74(int a, int b, int c);
int *func_021D8C84(int *p);
void func_021D8C90(int a, int b, int c);
int *func_021D8CA0(int *p);
void func_021D8CAC(int a, int b, int c);
void func_021D8CF4(int u, int a, int b);
int *func_021D8D34(int *p);
extern unsigned char d_021F07C0[];
extern unsigned int d_021F07B8;
extern int d_021F0698[];
extern int d_021F07D8[];
extern int d_021F06B0[];
extern int d_021F0610[];
extern int d_021F0648[];
extern int d_021F0640[];
extern int d_021F0638[];




void func_021D8B50(int a, int b, int c)
{
    if(c==func_021D775C(4) && func_021D7AD4(func_021D775C(0x38))==2) func_021D7704(0x35,0xC00);
}




void *func_021D8B78(int *p)
{
    *p = 1;
    return d_021F07C0;
}



void func_021D8B84(int a, int b, int c)
{
    if (c == func_021D775C(3) && func_021D775C(0x45)) func_021D7704(0x35, 3 << 11);
}



void *func_021D8BA8(int *p) { *p = 1; return &d_021F07B8; }




void func_021D8BB4(int u, int a, int k)
{
    u32 *r;

    if (k == func_021D775C(2)) {
        if (func_021D5BDC(func_021C7CF4((int *)a, k), 0) != 0) {
            r = func_021C88A4((void *)a, 14, k);
            r[0] |= 2 << 22;
            r[1] = 5;
            ((u8 *)r)[0xf] = 1;
            ((u8 *)r)[0x10] = k;
            ((u8 *)r)[0xc] = 1;
            func_021C88C8((void *)a, r);
        }
    }
}



int *func_021D8C00(int *p)
{
    *p = 1;
    return d_021F0698;
}



void func_021D8C0C(void *a, void *b, int c)
{
    if (c == func_021D775C(2)) {
        if (func_021D775C(0x44) != 0)
            func_021D76BC(0x35, 2 << 12);
    }
}


int *func_021D8C30(int *p)
{
    *p = 1;
    return d_021F07D8;
}


void func_021D8C3C(int a, int b, int c)
{
    func_021D8CAC(b, c, 9);
}


int *func_021D8C4C(int *p)
{
    *p = 1;
    return d_021F06B0;
}


void func_021D8C58(int a, int b, int c)
{
    func_021D8CAC(b, c, 10);
}


int *func_021D8C68(int *p)
{
    *p = 1;
    return d_021F0610;
}


void func_021D8C74(int a, int b, int c)
{
    func_021D8CAC(b, c, 11);
}


int *func_021D8C84(int *p)
{
    *p = 1;
    return d_021F0648;
}


void func_021D8C90(int a, int b, int c)
{
    func_021D8CAC(b, c, 6);
}


int *func_021D8CA0(int *p)
{
    *p = 1;
    return d_021F0640;
}


void func_021D8CAC(int a, int b, int c)
{
    void *p;
    u32 lim;

    if (b == func_021D775C(3)) {
        p = func_021C7CF4((int *)a, b);
        lim = func_021D7B60(p, 3);
        if (func_021D59B4(p, 13) <= lim) {
            if (c == func_021D775C(22))
                func_021D7704(0x35, 3 << 11);
        }
    }
}



void func_021D8CF4(int u, int a, int b)
{
    if (b == func_021D775C(3)) {
        if (func_021D62A8(func_021C7CF4((int *)a, b)) != 0) {
            if (func_0201C1E8((u16)func_021D775C(0x12)) == 1)
                func_021D7704(0x35, 3 << 11);
        }
    }
}


int *func_021D8D34(int *p)
{
    *p = 1;
    return d_021F0638;
}
