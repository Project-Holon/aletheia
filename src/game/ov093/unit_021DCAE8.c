/*
 * file:     unit_021DCAE8.c
 * unit:     yes
 * function: func_021DCAE8, func_021DCB2C, func_021DCB38, func_021DCBD0, func_021DCBDC, func_021DCBE8, func_021DCC04, func_021DCC10, func_021DCC2C, func_021DCC5C, func_021DCC80, func_021DCCEC, func_021DCD20, func_021DCDB8, func_021DCDC4, func_021DCDD0, func_021DCDF8, func_021DCE18, func_021DCE48, func_021DCE90, func_021DCE9C, func_021DCEC4, func_021DCF24, func_021DCF5C, func_021DCF78, func_021DCF9C, func_021DCFA4, func_021DCFB4, func_021DCFD0, func_021DCFF8, func_021DD008, func_021DD044, func_021DD05C, func_021DD068, func_021DD080, func_021DD08C, func_021DD0A4, func_021DD0B0, func_021DD0C8, func_021DD0D4, func_021DD0EC, func_021DD0F8, func_021DD110, func_021DD11C, func_021DD134, func_021DD140, func_021DD158, func_021DD19C, func_021DD1D8, func_021DD234, func_021DD240, func_021DD26C, func_021DD2A4, func_021DD2D0, func_021DD2F8, func_021DD320, func_021DD338, func_021DD368, func_021DD39C, func_021DD480, func_021DD4B0, func_021DD4E0, func_021DD514, func_021DD570, func_021DD57C
 * address:  0x021DCAE8
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
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021E8804  0x021E8804  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D6740  0x021D6740  thumb  ov093
 *   func_020213C0  0x020213C0  thumb
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_021C8288  0x021C8288  thumb  ov093
 *   func_021D85C0  0x021D85C0  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F0AD0     0x021F0AD0  data   ov093  a4
 *   d_021F05E0 0x021F05E0 data a4
 *   func_021D7704 0x021D7704 thumb ov093
 *   d_021F0708 0x021F0708 data a4
 *   func_021B9A40  0x021B9A40  thumb  ov093
 *   func_021B9A5C  0x021B9A5C  thumb  ov093
 *   func_021D7320  0x021D7320  thumb  ov093
 *   func_021D70AC 0x021D70AC thumb ov093
 *   func_021B9A24 0x021B9A24 thumb ov093
 *   d_021F0AE8 0x021F0AE8 data a4
 *   func_021C8010  0x021C8010  thumb  ov093
 *   func_021C815C  0x021C815C  thumb  ov093
 *   func_021B8C5C  0x021B8C5C  thumb  ov093
 *   func_021C8020  0x021C8020  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   d_021F0728     0x021F0728  data   ov093  a4
 *   d_021F0680     0x021F0680  data   ov093  a4
 *   func_021D70A8 0x021D70A8 thumb ov093
 *   func_021D6C24  0x021D6C24  thumb  ov093
 *   d_021F0750     0x021F0750  data   ov093  a4
 *   d_021F0B60     0x021F0B60  data   ov093  a4
 *   func_021D58A8  0x021D58A8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D6F0C  0x021D6F0C  thumb  ov093
 *   d_021F1EA4     0x021F1EA4  data  ov093
 *   func_021D732C  0x021D732C  thumb  ov093
 *   func_021D7360  0x021D7360  thumb  ov093
 *   func_021D70B4  0x021D70B4  thumb  ov093
 *   func_021D7040  0x021D7040  thumb  ov093
 *   func_021D70BC 0x021D70BC thumb ov093
 *   func_021D70DC 0x021D70DC thumb ov093
 *   func_021D7404 0x021D7404 thumb ov093
 *   func_021D7438 0x021D7438 thumb ov093
 *   func_021D7AF0 0x021D7AF0 thumb ov093
 *   func_021C82B8 0x021C82B8 thumb ov093
 *   func_021D805C   0x021D805C  thumb
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_021D70C8 0x021D70C8 thumb ov093
 *   d_021F1AC4 0x021F1AC4 data a4
 *   d_021F1AEC 0x021F1AEC data a4
 *   d_021F1DE4 0x021F1DE4 data a4
 *   d_021F1B14 0x021F1B14 data a4
 *   d_021F1B3C 0x021F1B3C data a4
 *   d_021F1B64 0x021F1B64 data a4
 *   d_021F1B8C 0x021F1B8C data a4
 *   func_021D778C  0x021D778C  thumb  ov093
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D7E10  0x021D7E10  thumb  ov093
 *   d_021F0760     0x021F0760  data   ov093  a4
 *   func_021D67B8 0x021D67B8 thumb ov093
 *   func_021D5778 0x021D5778 thumb ov093
 *   func_021D5584 0x021D5584 thumb ov093
 *   func_021D5448 0x021D5448 thumb ov093
 *   func_021D554C 0x021D554C thumb ov093
 *   func_021D54C0 0x021D54C0 thumb ov093
 *   d_021F1BB4 0x021F1BB4 data a4
 *   func_021DDE30 0x021DDE30 thumb ov093
 *   func_021DDEA4 0x021DDEA4 thumb ov093
 *   d_021F1E6C     0x021F1E6C  data   ov093  a4
 *   d_021F1AA4     0x021F1AA4  data   ov093  a4
 *   d_021F1BDC     0x021F1BDC  data   ov093  a4
 */
#include "../../matched/include/Obj07816.h"
#include "../../matched/include/Obj10065.h"
#include "../../matched/include/Obj10066.h"
#include "../../matched/include/Obj13484.h"

struct QI;
struct QK;
struct S;
struct QS;
struct QQ;
struct R4;
struct Node;
struct QR;
struct Unk021D62A8;
struct UtilWork;
struct QG;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u16 h0; u16 pad2; u8 b4; u8 pad5[3]; } Args;

struct Ent { u32 key; u32 (*fn)(u32 *); };

typedef struct Node Node;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int key);
extern int func_021D76BC(int key, u32 val);
extern void func_021C88B4(void *a, int k, int b);
extern void func_021E8804(int a, void *b, int c, int d);
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D6740(struct QK *p);
extern int func_020213C0(u32 a);
extern u16 func_021D5B40(struct QI *p);
extern int func_021C8288(u8 *p);
extern int func_021D85C0(int a, u32 b);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);
extern void func_021D7704(int,int);
extern unsigned char func_021B9A40(unsigned int x);
extern u8 func_021B9A5C(u32 x);
extern void func_021D7320(struct QS *p, u32 v);
extern u8 func_021D70AC(u8 *);
extern int func_021B9A24(unsigned int a, unsigned int b);
extern int func_021C8010(u8 *p, unsigned int v);
extern int func_021C815C(int *p);
extern u8 func_021B8C5C(int kind, u32 flags);
extern u8 func_021C8020(u8 *p, u8 v);
extern int func_021D5B68(void *p);
extern u16 func_021D70A8(struct QQ *p);
extern int func_021D6C24(struct R4 *p);
extern int func_021D58A8(u8 *p, int k);
extern u8 func_021D5440(u8 *p);
extern struct Node *func_021D6F0C(int id, u32 key, int pri, u32 sub_pri, u8 sub, u32 f8, u16 f16);
extern struct Node *func_021D732C(int id, int sub);
extern struct Node *func_021D7360(struct Node *n);
extern u32 func_021D70B4(u8 *p, int i);
extern void func_021D7040(struct Node *n);
extern void func_021D70BC(struct QR *p);
extern void func_021D70DC(u8 *p, int i, u32 v);
extern void func_021D7404(unsigned int,int);
extern int func_021D7438(int,int);
extern int func_021D7AF0(unsigned int);
extern int func_021C82B8(int *,int);
extern u32 func_021D805C(void *p, u32 n);
extern void func_021D70C8(Node *);
extern int func_021D778C(int key, int *out);
extern int func_021D62A8(struct Unk021D62A8 *p);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern int func_021D7E10(struct Unk021D62A8 *p);
extern u16 func_021D67B8(u8 *p);
extern u8 func_021D5778(struct UtilWork *p, u16 id);
extern u8 func_021D5584(struct UtilWork *p, u32 i);
extern u8 func_021D5448(struct QG *p);
extern u8 func_021D554C(u8 *p, u8 i);
extern u16 func_021D54C0(u8 *p, int i);
extern void func_021DDE30(int a, int b, int c, int d, int e);
extern int func_021DDEA4(void *, int, u32);
void func_021DCAE8(int a, void *b, int c, int d);
int *func_021DCB2C(int *p);
void func_021DCB38(int a, void *b, int c);
int *func_021DCBD0(int *p);
int *func_021DCBDC(int *p);
void func_021DCBE8(int a, int b, int c);
void *func_021DCC04(int *p);
void func_021DCC10(int a, int b, int c);
void func_021DCC2C(int a, int b, int c, int *d);
void *func_021DCC50(int *p);
void func_021DCC5C(void *a,void *b,int c,int *d);
void func_021DCC80(void *a, void *b, int c, int *d);
int func_021DCCEC(u8 *a,int b,int c,int d,Args e);
int *func_021DCD14(int *p);
void func_021DCD20(int a, void *b, int c);
int *func_021DCDB8(int *p);
int *func_021DCDC4(int *p);
void func_021DCDD0(int a,unsigned char *b,int c);
void func_021DCDF8(int a,unsigned char *b,int c);
void func_021DCE18(int a,unsigned char *b,int c);
void func_021DCE48(int a, u8 *b, int c);
int *func_021DCE90(int *p);
void func_021DCE9C(int a,int b,unsigned int c);
void *func_021DCEC4(void *a, u32 k);
void func_021DCF24(u8 *p);
void *func_021DCF5C(void *p);
void *func_021DCF78(void *p,unsigned int k);
void func_021DCF9C(void *n);
void func_021DCFA4(void *p);
void func_021DCFB4(void *p);
int func_021DCFD0(int *a,unsigned int b);
int func_021DCFF8(int a, int b);
int func_021DD008(int a);
void func_021DD044(void *a, void *b, int c);
void func_021DD05C(int a, int b, int c);
void func_021DD068(void *a, void *b, int c);
const void *func_021DD074(int *p);
void func_021DD080(int a, int b, int c);
void func_021DD08C(void *a, void *b, int c);
const void *func_021DD098(int *p);
void func_021DD0A4(int a, int b, int c);
void func_021DD0B0(void *a, void *b, int c);
const void *func_021DD0BC(int *p);
void func_021DD0C8(int a, int b, int c);
void func_021DD0D4(void *a, void *b, int c);
const void *func_021DD0E0(int *p);
void func_021DD0EC(int a, int b, int c);
void func_021DD0F8(void *a, void *b, int c);
const void *func_021DD104(int *p);
void func_021DD110(int a, int b, int c);
void func_021DD11C(void *a, void *b, int c);
const void *func_021DD128(int *p);
void func_021DD134(int a, int b, int c);
void func_021DD140(void *a, void *b, int c);
const void *func_021DD14C(int *p);
void func_021DD158(u8 *a, u8 *b, int c, int d);
void func_021DD19C(void *a, u8 *b, int c, int d);
int func_021DD1D8(u8 *a, int b, int c);
int *func_021DD234(int *p);
void func_021DD240(void *a, void *b, int c);
void func_021DD26C(void *a, void *b, int c);
void func_021DD2A4(void *a, void *b, int c);
void func_021DD2D0(int a, void *b, int c);
void func_021DD2F8(int a, void *b, u8 c, int *d);
void func_021DD320(int a, void *b, u8 c, int *d);
u8 func_021DD338(void *a, int b);
u8 func_021DD368(void *a, int b);
int func_021DD39C(int a, void *b, u8 c, int d, int e);
void *func_021DD474(int *p);
void func_021DD480(int a, void *b, int c);
void func_021DD4B0(int a, void *b, int c);
void func_021DD4E0(int a, void *b, int c);
void func_021DD514(int a, u8 *b, int c);
int *func_021DD570(int *p);
int *func_021DD57C(int *p);
extern int d_021F0AD0[];
extern unsigned char d_021F05E0[];
extern unsigned char d_021F0708[];
extern int d_021F0AE8;
extern int d_021F0728[];
extern int d_021F0680[];
extern int d_021F0750[];
extern int d_021F0B60[];
extern struct Ent d_021F1EA4[0xac];
extern const unsigned char d_021F1AC4[];
extern const unsigned char d_021F1AEC[];
extern const unsigned char d_021F1DE4[];
extern const unsigned char d_021F1B14[];
extern const unsigned char d_021F1B3C[];
extern const unsigned char d_021F1B64[];
extern const unsigned char d_021F1B8C[];
/*
 * lever: u8 result local reproduces 021DCEA6/021DCEA8 truncation in r0,
 * then shift-copy to r1; inline narrowing produced an extra register copy.
 */
extern int d_021F0760[];
extern u8 d_021F1BB4[];
extern int d_021F1E6C[];
extern int d_021F1AA4[];
extern int d_021F1BDC[];






void func_021DCAE8(int a, void *b, int c, int d)
{
    if (c == func_021D775C(2) && func_021D76BC(0x51, 1) != 0) {
        func_021C88B4(b, 2, c);
        func_021E8804(a, b, c, d);
        func_021C88B4(b, 3, c);
    }
}






int *func_021DCB2C(int *p)
{
    *p = 3;
    return d_021F0AD0;
}






void func_021DCB38(int a, void *b, int c)
{
    u8 *m;
    void *mon;
    u32 n;

    if (c == func_021D775C(2)) {
        mon = func_021C7CF4(b, c);
        n = func_021D6740(mon);
        if (n != 0 && func_020213C0(n) != 0 && func_021D5B40(mon) == 0
            && (func_021C8288(b) == 1 || func_021D85C0((int)b, 0x32) != 0)) {
            m = (u8 *)func_021C88A4(b, 0x20, c);
            ((struct Obj07816 *)m)->f0 |= 0x20 << 18;
            ((struct Obj07816 *)m)->f4 = n;
            m[6] = c;
            m[7] = 1;
            func_021C8838(m + 0xc, 2, 0x1db);
            func_021C8860((struct S *)(m + 0xc), c);
            func_021C8860((struct S *)(m + 0xc), n);
            func_021C88C8(b, m);
        }
    }
}





int *func_021DCBD0(int *p)
{
    *p = 1;
    return d_021F0728;
}





int *func_021DCBDC(int *p)
{
    *p = 1;
    return d_021F0680;
}





void func_021DCBE8(int a, int b, int c) { if (c == func_021D775C(2)) func_021D7704(53,8192); }






void *func_021DCC04(int *p) { *p = 1; return d_021F05E0; }







/*
 * extent: trailing two-byte zero alignment at 021DCC2A.
 */
void func_021DCC10(int a, int b, int c) { if (c == func_021D775C(2)) func_021D7704(0x35, 2048); }







void func_021DCC2C(int a, int b, int c, int *d) { if (c == func_021D775C(2)) *d = func_021D76BC(32,-func_021D775C(32)); }







void *func_021DCC50(int *p) { *p = 1; return d_021F0708; }







void func_021DCC5C(void *a,void *b,int c,int *d) { if(c==func_021D775C(2)) func_021DCC80(a,b,c,d); }







void func_021DCC80(void *a, void *b, int c, int *d)
{
    u8 *m;
    u32 x;

    if (*d == 0) {
        x = func_021B9A5C(func_021B9A40(c));
        func_021C88B4(b, 2, c);
        m = (u8 *)func_021C88A4(b, 4, c);
        func_021C8838(m + 4, 1, 0xb0);
        func_021C8860((struct S *)(m + 4), x);
        func_021C88C8(b, m);
        func_021C88B4(b, 3, c);
        func_021D7320(a, (u32)((void *)func_021DCCEC));
        *d = 1;
    }
}






/*
 * extent: callback followed by store-and-return leaf at 021DCD14.
 * stack: the by-value record begins in the fifth argument slot; the body
 * reads its halfword at +0 and byte at +4 using a common stack base.
 */
int func_021DCCEC(u8 *a,int b,int c,int d,Args e)
{
    if(c==5) {
        if(!func_021B9A24(func_021D70AC(a),e.b4)) {
            if(func_020213C0(e.h0)) return 1;
        }
    }
    return 0;
}






int *func_021DCD14(int *p) { *p=3; return &d_021F0AE8; }







void func_021DCD20(int a, void *b, int c)
{
    u8 *m;
    void *p;
    int k;
    int n;

    if (c == func_021D775C(2)) {
        n = func_021C8010(b, c);
        k = func_021C8020(b, func_021B8C5C(func_021C815C(b), n));
        p = func_021C7CF4(b, k);
        if (func_021D5B68(func_021C7CF4(b, c)) == 0 && func_021D5B68(p) == 0) {
            m = (u8 *)func_021C88A4(b, 0x33, c);
            ((struct Obj10065 *)m)->f0 |= 2 << 22;
            m[4] = k;
            func_021C8838(m + 8, 2, 0x284);
            func_021C8860((struct S *)(m + 8), c);
            func_021C8860((struct S *)(m + 8), m[4]);
            func_021C88C8(b, m);
        }
    }
}




/*
 * Allocate 76 bytes, keep the handle, then configure it.
 */
int *func_021DCDB8(int *p)
{
    *p = 1;
    return d_021F0750;
}




int *func_021DCDC4(int *p)
{
    *p = 3;
    return d_021F0B60;
}




void func_021DCDD0(int a,unsigned char *b,int c) { if(c==func_021D775C(4) && func_021D775C(70)==0) func_021DCE48(a,b,c); }




void func_021DCDF8(int a,unsigned char *b,int c) { if(c==func_021D775C(2)) func_021DCE48(a,b,c); }




void func_021DCE18(int a,unsigned char *b,int c) { int k; k=func_021D775C(16); if(k!=func_021D70A8((void *)a) && c==func_021D775C(2)) func_021DCE48(a,b,c); }





void func_021DCE48(int a, u8 *b, int c)
{
    u8 *p;
    if (func_021D6C24(func_021C7CF4((int *)b, c))) {
        p = func_021C88A4((char *)b, 0x34, c);
        p[4] = c;
        func_021C8838(p + 8, 2, 478);
        func_021C8860((struct S *)(p + 8), c);
        func_021C88C8(b, p);
    }
}



int *func_021DCE90(int *p)
{
    *p = 1;
    return d_021F0760;
}



void func_021DCE9C(int a,int b,unsigned int c) { unsigned char k; k=func_021D775C(3); if(func_021B9A24(c,k)) func_021D7704(53,4506); }






void *func_021DCEC4(void *a, u32 k)
{
    u32 i;
    u16 t;
    u8 sub;
    u32 f8;
    u32 loc;

    for (i = 0; i < 0xac; i++) {
        if (k == d_021F1EA4[i].key) {
            t = func_021D58A8(a, 0xc);
            sub = func_021D5440(a);
            f8 = d_021F1EA4[i].fn(&loc);
            return func_021D6F0C(5, k, 6, t, sub, f8, loc);
        }
    }
    return 0;
}





void func_021DCF24(u8 *p)
{
    Node *n = func_021D732C(5, func_021D5440(p));
    while (n != 0) {
        Node *next = func_021D7360(n);
        if (func_021D70B4((u8 *)n, 6) == 0)
            func_021D7040(n);
        n = next;
    }
}





/*
 * interface: 021D5B40's u16 field result is kept as a full register value
 * until the explicit halfword truncation at 021DCF68/021DCF6C; the caller
 * therefore uses a wide result and a u16 021DCEC4 argument, as the listing shows.
 */
void *func_021DCF5C(void *p) { int k; k=func_021D5B40(p); if(k) return func_021DCEC4(p,(unsigned short)k); return 0; }





void *func_021DCF78(void *p,unsigned int k) { void *q; if(k) { q=func_021DCEC4(p,k); if(q) { func_021D70BC(q); func_021D70DC(q,6,1); return q; } } return 0; }






/*
 * tail-call thunk to func_021D7040
 */
void func_021DCF9C(void *n)
{
    func_021D7040(n);
}





void func_021DCFA4(void *p) { func_021D7404(func_021D5440(p),5); }





void func_021DCFB4(void *p) { if(!func_021D7438(func_021D5440(p),5)) func_021DCF5C(p); }





/*
 * interface: 021C82B8 forwards r1=2 unchanged to 021B911C; r0 is consumed
 * after the call at 021DCFEA, requiring a result despite its legacy void extern.
 */
int func_021DCFD0(int *a,unsigned int b) { if(func_021D7AF0(b)) return 1; if(func_021C82B8(a,2)) return 1; return 0; }






/* 021DCFF8  pass-through: second callee takes the first one's result */
/*
 * Leaf with no calls and no pool; 6 instructions, 16 bytes: push {r4, lr}; adds r4, r1, #0; bl func_021D70A8; adds r1, r4, #0; bl func_021D805C; pop {r4, pc}.
 */
int func_021DCFF8(int a, int b)
{
    return func_021D805C((void *)func_021D70A8((void *)a), b);
}





int func_021DD008(int a) { int n; float f; n=func_021DCFF8(a,2)+100; if(n>0) f=0.5f+(float)(n<<12); else f=(float)(n<<12)-0.5f; return (int)f/100; }





void func_021DD044(void *a, void *b, int c)
{
    func_021D70C8(a);
    func_021C88B4(b, 0, c);
}






void func_021DD05C(int a, int b, int c)
{
    func_021DD158((u8 *)a, (u8 *)b, c, 1);
}





void func_021DD068(void *a, void *b, int c)
{
    func_021DD19C(a, b, c, 1);
}





const void *func_021DD074(int *p)
{
    *p = 5;
    return d_021F1AC4;
}






void func_021DD080(int a, int b, int c)
{
    func_021DD158((u8 *)a, (u8 *)b, c, 2);
}





void func_021DD08C(void *a, void *b, int c)
{
    func_021DD19C(a, b, c, 2);
}





const void *func_021DD098(int *p)
{
    *p = 5;
    return d_021F1AEC;
}






void func_021DD0A4(int a, int b, int c)
{
    func_021DD158((u8 *)a, (u8 *)b, c, 4);
}





void func_021DD0B0(void *a, void *b, int c)
{
    func_021DD19C(a, b, c, 4);
}





const void *func_021DD0BC(int *p)
{
    *p = 5;
    return d_021F1DE4;
}






void func_021DD0C8(int a, int b, int c)
{
    func_021DD158((u8 *)a, (u8 *)b, c, 3);
}





void func_021DD0D4(void *a, void *b, int c)
{
    func_021DD19C(a, b, c, 3);
}





const void *func_021DD0E0(int *p)
{
    *p = 5;
    return d_021F1B14;
}






void func_021DD0EC(int a, int b, int c)
{
    func_021DD158((u8 *)a, (u8 *)b, c, 6);
}





void func_021DD0F8(void *a, void *b, int c)
{
    func_021DD19C(a, b, c, 6);
}





const void *func_021DD104(int *p)
{
    *p = 5;
    return d_021F1B3C;
}






void func_021DD110(int a, int b, int c)
{
    func_021DD158((u8 *)a, (u8 *)b, c, 5);
}





void func_021DD11C(void *a, void *b, int c)
{
    func_021DD19C(a, b, c, 5);
}





const void *func_021DD128(int *p)
{
    *p = 5;
    return d_021F1B64;
}






void func_021DD134(int a, int b, int c)
{
    func_021DD158((u8 *)a, (u8 *)b, c, 0x25);
}





void func_021DD140(void *a, void *b, int c)
{
    func_021DD19C(a, b, c, 37);
}





const void *func_021DD14C(int *p)
{
    *p = 5;
    return d_021F1B8C;
}






void func_021DD158(u8 *a, u8 *b, int c, int d)
{
    int loc;
    if (c == func_021D775C(2)) {
        if (func_021D778C(0x2e, &loc) == 0 || loc == 3 || loc == 0) {
            if (func_021DD1D8(b, c, d) != 0)
                func_021DD044(a, b, c);
        }
    }
}





void func_021DD19C(void *a, u8 *b, int c, int d)
{
    u8 *p;
    if (c == func_021D775C(2) && func_021DD1D8(b, c, d)) {
        p = func_021C88A4((char *)b, 11, c);
        ((struct Obj10066 *)p)->f4 = d;
        p[0x14] = 1;
        p[8] = c;
        func_021C88C8(b, p);
    }
}




int func_021DD1D8(u8 *a, int b, int c)
{
    u8 *m = func_021C7CF4((int *)a, b);
    switch (c) {
    case 0x25:
        if (func_021D62A8((struct Unk021D62A8 *)m) == 0 && func_021D62C4((struct Unk021D62A8 *)m, 6) == 0)
            break;
        return 1;
    case 0x24:
        if (func_021D62A8((struct Unk021D62A8 *)m) != 0)
            return 1;
        return 0;
    case 0x26:
        if (func_021D7E10((struct Unk021D62A8 *)m) != 0)
            return 1;
        return 0;
    default:
        return func_021D62C4((struct Unk021D62A8 *)m, c);
    }
    return 0;
}


int *func_021DD234(int *p)
{
    *p = 7;
    return d_021F1E6C;
}


void func_021DD240(void *a, void *b, int c)
{
    if (c == func_021D775C(2)) {
        if (func_021DD338(b, c) != 4)
            func_021DD044(a, b, c);
    }
}




void func_021DD26C(void *a, void *b, int c)
{
    int v;
    if (c == func_021D775C(2)) {
        v = func_021D775C(0x2e);
        if (v != 2 && v != 0) return;
        if (func_021DD368(b, c) != 4)
            func_021DD044(a, b, c);
    }
}




void func_021DD2A4(void *a, void *b, int c)
{
    if (c == func_021D775C(2)) {
        if (func_021DD368(b, c) != 4)
            func_021DD044(a, b, c);
    }
}




void func_021DD2D0(int a, void *b, int c)
{
    if (c == func_021D775C(2) && func_021DD338(b, c) != 4)
        func_021D76BC(0x51, 1);
}




/*
 * extent: trailing two-byte alignment padding.
 * prototype: third DD39C input widened to full register width; no truncation at call.
 */
void func_021DD2F8(int a, void *b, u8 c, int *d)
{
    if (c == func_021D775C(2)) func_021DD39C(a, b, c, (int)d, 0);
}




/*
 * extent: trailing two-byte alignment padding.
 */
void func_021DD320(int a, void *b, u8 c, int *d)
{
    if (d[6] != 0) func_021DD39C(a, b, c, (int)d, 1);
}



/*
 * extent: trailing two-byte alignment padding.
 * prototype: C7CF4 result used and r1 supplied; 5584 index is the u8 return of 5778.
 */
u8 func_021DD338(void *a, int b)
{
    void *m;
    u8 slot;
    m = func_021C7CF4(a, b);
    slot = func_021D5778(m, func_021D67B8(m));
    if (slot != 4 && func_021D5584(m, slot) == 0) return slot;
    return 4;
}



u8 func_021DD368(void *a, int b)
{
    void *m;
    u32 n, i;
    m = func_021C7CF4(a, b);
    n = func_021D5448(m);
    for (i = 0; i < n; i++) {
        if (func_021D5584(m, (u8)i) == 0) return (u8)i;
    }
    return 4;
}



int func_021DD39C(int a, void *b, u8 c, int d, int e)
{
    void *m;
    u32 i;
    u32 n;
    u8 slot;
    u8 *r;
    m = func_021C7CF4(b, c);
    slot = func_021DD338(b, c);
    if (slot == 4) {
        slot = func_021DD368(b, c);
        if (slot == 4 && e) {
            n = func_021D5448(m);
            for (i = 0; i < n; i++) {
                if (func_021D554C(m, i)) {
                    slot = i;
                    break;
                }
            }
        }
    }
    if (slot != 4) {
        r = (u8 *)func_021C88A4(b, 9, c);
        r[4] = 10;
        r[5] = c;
        r[6] = slot;
        r[7] = (r[7] & ~1) | 1;
        func_021C8838(r + 8, 2, 0x38f);
        func_021C8860((struct S *)(r + 8), c);
        func_021C8860((struct S *)(r + 8), func_021D70A8((void *)a));
        func_021C8860((struct S *)(r + 8), func_021D54C0(m, slot));
        func_021C88C8(b, r);
        return 1;
    }
    return 0;
}



void *func_021DD474(int *p) { *p = 5; return d_021F1BB4; }



void func_021DD480(int a, void *b, int c)
{
    if (func_021D62C4(func_021C7CF4(b, c), 15) == 0)
        func_021DDE30(a, (int)b, c, 2, 1);
}



void func_021DD4B0(int a, void *b, int c)
{
    if (func_021D62C4(func_021C7CF4(b, c), 15) == 0)
        func_021DDE30(a, (int)b, c, 2, 0);
}



void func_021DD4E0(int a, void *b, int c)
{
    if (func_021D62C4(func_021C7CF4(b, c), 15) == 0 && func_021DDEA4(b, c, 2) != 0)
        func_021DD044((void *)a, b, c);
}




void func_021DD514(int a, u8 *b, int c)
{
    u8 *p;
    if (c == func_021D775C(2)) {
        p = func_021C88A4((char *)b, 5, c);
        p[6] = c;
        ((struct Obj13484 *)p)->f4 = func_021DCFF8(a, 2);
        func_021C8838(p + 8, 2, 908);
        func_021C8860((struct S *)(p + 8), c);
        func_021C8860((struct S *)(p + 8), func_021D70A8((void *)a));
        func_021C88C8(b, p);
    }
}


int *func_021DD570(int *p)
{
    *p = 4;
    return d_021F1AA4;
}


int *func_021DD57C(int *p)
{
    *p = 5;
    return d_021F1BDC;
}
