/*
 * file:     unit_021DB0E4_p02.c
 * unit:     yes
 * function: func_021DB1D4, func_021DB200, func_021DB224, func_021DB254, func_021DB274, func_021DB298, func_021DB2B8, func_021DB2C8, func_021DB2F8, func_021DB318, func_021DB374, func_021DB404, func_021DB410, func_021DB41C, func_021DB430, func_021DB460, func_021DB474, func_021DB4C4, func_021DB4E8
 * address:  0x021DB1D4
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
 *   func_021D7320 0x021D7320 thumb ov093
 *   func_021DB1A8 0x021DB1A8 thumb ov093
 *   func_021D7324 0x021D7324 thumb ov093
 *   d_021F0C24 0x021F0C24 data a4
 *   func_021C8288 0x021C8288 thumb ov093
 *   func_021D70A8 0x021D70A8 thumb ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5444  0x021D5444  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021DA8A8 0x021DA8A8 thumb ov093
 *   func_021DA96C 0x021DA96C thumb ov093
 *   d_021F0A70 0x021F0A70 data a4
 *   func_021E85F8  0x021E85F8  thumb  ov093
 *   func_021C8290  0x021C8290  thumb  ov093
 *   func_021DB550  0x021DB550  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   d_021F0DD4     0x021F0DD4  data   ov093  a4
 *   d_021F0A58     0x021F0A58  data   ov093  a4
 */
#include "../../matched/include/Obj10063.h"
#include "../../matched/include/Obj21327.h"

struct QS;
struct QQ;
struct QF;
struct S;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

extern int func_021D775C(int);
extern void func_021D7320(struct QS *p, u32 v);
extern int func_021DB1A8(int,int,int,int,unsigned short);
extern void func_021D7324(u8 *p);
extern int func_021C8288(u8 *p);
extern u16 func_021D70A8(struct QQ *p);
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D5444(struct QF *p);
extern int func_021D59B4(u8 *p, int k);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern int func_021DA8A8(int,int,int);
extern void func_021DA96C(void *,int,unsigned int,int);
extern int func_021E85F8(int id);
extern int func_021C8290(u8 *p, int a, int b, void *item);
extern int func_021DB550(int t);
extern int func_021D76BC(int key, u32 val);
void func_021DB1D4(char *a, int b, int c, int *d);
void func_021DB200(char *a, int b, int c, int *d);
void func_021DB224(char *a, int b, int c, int *d);
const unsigned int *func_021DB248(int *n);
void func_021DB254(int a, void *b, int c, int *d);
void func_021DB274(int a, void *b, int c, int *d);
void func_021DB298(int a, void *b, int c, int *d);
void func_021DB2B8(int a, void *b, int c, int *d);
void func_021DB2C8(void *a, void *b, int c);
void func_021DB2F8(int a, void *b, int c);
void func_021DB318(int unused, void *a, int id);
void func_021DB374(void *a, int id, u32 k);
int *func_021DB404(int *p);
int *func_021DB410(int *p);
void func_021DB41C(int a, int b, int c, int *d);
void func_021DB430(int a, void *b, int c);
const unsigned int *func_021DB454(int *p);
void func_021DB460(int a, int b, int c, int *d);
void func_021DB474(int unused, void *a, int id, int *f);
void func_021DB4C4(int a, void *b, int c);
int func_021DB4E8(int a, int b, int c, int d);
extern const unsigned int d_021F0C24[];
extern const unsigned int d_021F0A70[];
extern int d_021F0DD4[];
extern int d_021F0A58[];






/*
 * interface: func_021D7320 stores the full r1 payload unchanged at +12;
 * callback type records the observed pointer, with no arithmetic/narrowing.
 */
void func_021DB1D4(char *a, int b, int c, int *d) { if (c == func_021D775C(3) && *d == 0) { func_021D7320((struct QS *)a,(u32)func_021DB1A8); *d = 1; } }






void func_021DB200(char *a, int b, int c, int *d) { if (c == func_021D775C(2) && *d == 1) { func_021D7324((u8 *)a); *d = 0; } }






void func_021DB224(char *a, int b, int c, int *d) { if (c == func_021D775C(2) && *d == 1) { func_021D7324((u8 *)a); *d = 0; } }






const unsigned int *func_021DB248(int *n) { *n = 5; return d_021F0C24; }







void func_021DB254(int a, void *b, int c, int *d)
{
    func_021DB374(b, c, func_021C8288(b));
    *d = 1;
}







void func_021DB274(int a, void *b, int c, int *d)
{
    if (c == func_021D775C(2)) func_021DB254(a, b, c, d);
}







void func_021DB298(int a, void *b, int c, int *d)
{
    if (*d != 0) func_021DB374(b, c, func_021C8288(b));
}







void func_021DB2B8(int a, void *b, int c, int *d)
{
    if (*d != 0) func_021DB318(a, b, c);
}






void func_021DB2C8(void *a, void *b, int c)
{
    int v;
    if (c == func_021D775C(2)) {
        v = func_021D775C(16);
        if (v != func_021D70A8(a)) func_021DB318((int)a, b, c);
    }
}






void func_021DB2F8(int a, void *b, int c)
{
    if (c == func_021D775C(2)) func_021DB318(a, b, c);
}




void func_021DB318(int unused, void *a, int id)
{
    u8 *r;
    void *m;

    m = func_021C7CF4(a, id);
    if (func_021D5444(m) == 0x15f && func_021D59B4(m, 0x13) != 0) {
        r = (u8 *)func_021C88A4(a, 0x39, id);
        r[4] = id;
        r[5] = 0;
        func_021C8838(r + 8, 2, 0xde);
        func_021C8860((struct S *)(r + 8), id);
        func_021C88C8(a, r);
    }
}



void func_021DB374(void *a, int id, u32 k)
{
    u8 *r;
    void *m;
    u32 v;
    u32 s;

    m = func_021C7CF4(a, id);
    if (func_021D5444(m) == 0x15f) {
        v = (u8)func_021D59B4(m, 0x13);
        switch (k) {
        case 0:
            s = 0;
            break;
        case 1:
            s = 1;
            break;
        case 2:
            s = 2;
            break;
        case 3:
            s = 3;
            break;
        default:
            s = 0;
            break;
        }
        if (s != v) {
            r = (u8 *)func_021C88A4(a, 0x39, id);
            ((struct Obj10063 *)r)->f0 |= 0x800000;
            r[4] = id;
            r[5] = s;
            func_021C8838(r + 8, 2, 0xde);
            func_021C8860((struct S *)(r + 8), id);
            func_021C88C8(a, r);
        }
    }
}


int *func_021DB404(int *p)
{
    *p = 9;
    return d_021F0DD4;
}


int *func_021DB410(int *p)
{
    *p = 3;
    return d_021F0A58;
}


void func_021DB41C(int a, int b, int c, int *d)
{
    *d = func_021DB4E8(b, c, (int)d, 10);
}




void func_021DB430(int a, void *b, int c)
{
    if (func_021DA8A8((int)b, c, 10) != 0) func_021DA96C(b, c, 3, 1);
}




const unsigned int *func_021DB454(int *p)
{
    *p = 3;
    return d_021F0A70;
}




void func_021DB460(int a, int b, int c, int *d)
{
    *d = func_021DB4E8(b, c, (int)d, 12);
}




void func_021DB474(int unused, void *a, int id, int *f)
{
    u8 *r;

    if (*f != 0) {
        if (func_021E85F8(id) != 0) {
            r = (u8 *)func_021C88A4(a, 4, id);
            ((struct Obj21327 *)r)->f0 |= 0x800000;
            func_021C8838(r + 4, 2, 0x1c0);
            func_021C8860((struct S *)(r + 4), id);
            func_021C88C8(a, r);
        }
        *f = 0;
    }
}




void func_021DB4C4(int a, void *b, int c)
{
    if (func_021DA8A8((int)b, c, 12) != 0) func_021DA96C(b, c, 3, 1);
}




int func_021DB4E8(int a, int b, int c, int d)
{
    u8 k;
    u16 t;
    u8 n;

    k = func_021D775C(3);
    if (k != b && d == func_021D775C(0x16)) {
        t = func_021D775C(0x12);
        if (func_021C8290((u8 *)a, k, b, (void *)t) == 0 && func_021DB550(t) == 0) {
            n = func_021D775C(4);
            if (func_021D76BC(4, b) != 0 && n != b)
                return 1;
        }
    }
    return 0;
}
