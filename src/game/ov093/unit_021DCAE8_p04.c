/*
 * file:     unit_021DCAE8_p04.c
 * unit:     yes
 * function: func_021DCE9C, func_021DCEC4, func_021DCF24, func_021DCF5C, func_021DCF78, func_021DCF9C, func_021DCFA4, func_021DCFB4, func_021DCFD0, func_021DCFF8, func_021DD008, func_021DD044, func_021DD05C, func_021DD068
 * address:  0x021DCE9C
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
 *   func_021B9A24 0x021B9A24 thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   func_021D58A8  0x021D58A8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D6F0C  0x021D6F0C  thumb  ov093
 *   d_021F1EA4     0x021F1EA4  data  ov093
 *   func_021D732C  0x021D732C  thumb  ov093
 *   func_021D7360  0x021D7360  thumb  ov093
 *   func_021D70B4  0x021D70B4  thumb  ov093
 *   func_021D7040  0x021D7040  thumb  ov093
 *   func_021D5B40 0x021D5B40 thumb ov093
 *   func_021D70BC 0x021D70BC thumb ov093
 *   func_021D70DC 0x021D70DC thumb ov093
 *   func_021D7404 0x021D7404 thumb ov093
 *   func_021D7438 0x021D7438 thumb ov093
 *   func_021D7AF0 0x021D7AF0 thumb ov093
 *   func_021C82B8 0x021C82B8 thumb ov093
 *   func_021D70A8   0x021D70A8  thumb
 *   func_021D805C   0x021D805C  thumb
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_021D70C8 0x021D70C8 thumb ov093
 *   func_021C88B4 0x021C88B4 thumb ov093
 *   func_021DD158  0x021DD158  thumb  ov093
 *   func_021DD19C 0x021DD19C thumb ov093
 *   d_021F1AC4 0x021F1AC4 data a4
 */
struct Node;
struct QI;
struct QR;
struct QQ;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Ent { u32 key; u32 (*fn)(u32 *); };

typedef struct Node Node;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int);
extern int func_021B9A24(unsigned int a, unsigned int b);
extern void func_021D7704(int,int);
extern int func_021D58A8(u8 *p, int k);
extern u8 func_021D5440(u8 *p);
extern struct Node *func_021D6F0C(int id, u32 key, int pri, u32 sub_pri, u8 sub, u32 f8, u16 f16);
extern struct Node *func_021D732C(int id, int sub);
extern struct Node *func_021D7360(struct Node *n);
extern u32 func_021D70B4(u8 *p, int i);
extern void func_021D7040(struct Node *n);
extern u16 func_021D5B40(struct QI *p);
extern void func_021D70BC(struct QR *p);
extern void func_021D70DC(u8 *p, int i, u32 v);
extern void func_021D7404(unsigned int,int);
extern int func_021D7438(int,int);
extern int func_021D7AF0(unsigned int);
extern int func_021C82B8(int *,int);
extern u16 func_021D70A8(struct QQ *p);
extern u32 func_021D805C(void *p, u32 n);
extern void func_021D70C8(Node *);
extern void func_021C88B4(void *, int, int);
void func_021DD158(u8 *a, u8 *b, int c, int d);
extern void func_021DD19C(void *, unsigned char *, int, int);
void func_021DCE9C(int a,int b,unsigned int c);
void *func_021DCEC4(void *a, u32 k);
void func_021DCF24(u8 *p);
void *func_021DCF5C(void *p);
void *func_021DCF78(void *p,unsigned int k);
void func_021DCF9C(void *n);
void func_021DCFA4(void *p);
void func_021DCFB4(void *p);
int func_021DCFD0(int *a,unsigned int b);
/* 021DCFF8 pass-through: second callee takes the first one's result */ int func_021DCFF8(int a, int b);
int func_021DD008(int a);
void func_021DD044(void *a, void *b, int c);
void func_021DD05C(int a, int b, int c);
void func_021DD068(void *a, void *b, int c);
const void *func_021DD074(int *p);
extern struct Ent d_021F1EA4[0xac];
extern const unsigned char d_021F1AC4[];

/*
 * lever: u8 result local reproduces 021DCEA6/021DCEA8 truncation in r0,
 * then shift-copy to r1; inline narrowing produced an extra register copy.
 */
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
