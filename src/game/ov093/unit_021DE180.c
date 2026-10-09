/*
 * file:     unit_021DE180.c
 * unit:     yes
 * function: func_021DE180, func_021DE21C, func_021DE228, func_021DE24C, func_021DE270, func_021DE2A0, func_021DE300, func_021DE31C, func_021DE34C, func_021DE358
 * address:  0x021DE180
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
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021DCFF8  0x021DCFF8  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D5D68 0x021D5D68 thumb ov093
 *   func_021DD044 0x021DD044 thumb ov093
 *   d_021F1A84 0x021F1A84 data a4
 *   func_021D7E10 0x021D7E10 thumb ov093
 *   func_021DD19C  0x021DD19C  thumb  ov093
 *   d_021F1564 0x021F1564 data a4
 *   d_021F1E3C     0x021F1E3C  data   ov093  a4
 */
#include "../../matched/include/Obj10068.h"
#include "../../matched/include/Obj21385.h"
#include "../../matched/include/Obj21387.h"

struct QQ;
struct S;
struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char    s8;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5B68(void *p);
extern int func_021DCFF8(int a, int b);
extern void *func_021C88A4(char *p, int a, int b);
extern int func_021D7B74(u8 *p, u32 k);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern u16 func_021D70A8(struct QQ *p);
extern void func_021C88C8(void *a, void *b);
extern int func_021D5D68(s8 *p);
extern void func_021DD044(void *, void *, int);
extern int func_021D7E10(struct Unk021D62A8 *);
void func_021DD19C(void *a, u8 *b, int c, int d);
void func_021DE180(int a, void *b, int c, int *d);
int *func_021DE21C(int *p);
void func_021DE228(int a, void *b, int c, int a3);
void func_021DE24C(int a, void *b, int c, int d);
void func_021DE270(int a, void *b, int c);
void func_021DE2A0(void *a, void *b, int c, u8 *a3);
void func_021DE300(void *a, void *b, int c, u8 *d);
void *func_021DE310(int *p);
void func_021DE31C(int a, void *b, int c);
void func_021DE34C(int a, int b, int c, u8 *a3);
void func_021DE358(int a, int b, int c, u8 *d);
void *func_021DE368(int *p);
extern u8 d_021F1A84[];
extern u8 d_021F1564[];
extern int d_021F1E3C[];


void func_021DE180(int a, void *b, int c, int *d)
{
    u8 *m;
    void *mon;
    u8 k;
    u8 j;

    if (c == func_021D775C(2) && *d != 0) {
        k = *d - 1;
        mon = func_021C7CF4(b, k);
        if (func_021D5B68(mon) == 0) {
            j = func_021DCFF8(a, 2);
            m = (u8 *)func_021C88A4(b, 7, c);
            m[6] = k;
            ((struct Obj10068 *)m)->f4 = func_021D7B74(mon, j);
            func_021C8838(m + 0xc, 2, 0x407);
            func_021C8860((struct S *)(m + 0xc), m[6]);
            func_021C8860((struct S *)(m + 0xc), c);
            func_021C8860((struct S *)(m + 0xc), func_021D70A8((void *)a));
            func_021C88C8(b, m);
        }
    }
}


int *func_021DE21C(int *p)
{
    *p = 6;
    return d_021F1E3C;
}


/*
 * interface: func_021C7CF4 leaves r0 live for the following call; r1 carries c.
 */
void func_021DE228(int a, void *b, int c, int a3) { if (func_021D5D68(func_021C7CF4(b,c))) func_021DD044((void *)a,b,c); }




/*
 * extent: two-byte alignment padding at 021DE26E.
 * interface: original restores r3 from r7 before calling 021DE228.
 */
void func_021DE24C(int a, void *b, int c, int d) { if (func_021D775C(12) != 6) func_021DE228(a,b,c,d); }




/*
 * extent: two-byte alignment padding at 021DE29E.
 * interface: func_021C7CF4 leaves r0 live for the following call; r1 carries c.
 */
void func_021DE270(int a, void *b, int c) { if(c == func_021D775C(2)) { if(func_021D5D68(func_021C7CF4(b,c))) func_021DD044((void *)a,b,c); } }




void func_021DE2A0(void *a, void *b, int c, u8 *a3)
{
    u8 *m;
    u8 *n;

    if (c == func_021D775C(2)) {
        m = (u8 *)func_021C88A4(b, 0x12, c);
        m[4] = c;
        func_021C88C8(b, m);
        n = (u8 *)func_021C88A4(b, 4, c);
        func_021C8838(n + 4, 2, 0x3f2);
        func_021C8860((struct S *)(n + 4), c);
        func_021C8860((struct S *)(n + 4), func_021D70A8(a));
        func_021C88C8(b, n);
    }
}



void func_021DE300(void *a, void *b, int c, u8 *d) { if (((struct Obj21385 *)d)->f18) func_021DE2A0(a,b,c,d); }



/*
 * interface: r3 is untouched before bl; forward its incoming fourth argument.
 * lever: fourth argument keeps r3 live; three arguments give ldr/cmp r3.
 */
void *func_021DE310(int *p) { *p=4; return d_021F1A84; }



/*
 * extent: two-byte alignment padding at 021DE34A.
 * interface: func_021C7CF4 leaves r0 live for the following call; r1 carries c.
 */
void func_021DE31C(int a, void *b, int c) { if(c == func_021D775C(2)) { if(func_021D7E10(func_021C7CF4(b,c))) func_021DD044((void *)a,b,c); } }




void func_021DE34C(int a, int b, int c, u8 *a3)
{
    func_021DD19C((void *)a, (u8 *)b, c, 0x26);
}



void func_021DE358(int a, int b, int c, u8 *d) { if (((struct Obj21387 *)d)->f18) func_021DE34C(a,b,c,d); }



void *func_021DE368(int *p) { *p=1; return d_021F1564; }
