/*
 * file:     event_poke_status_p23.c
 * unit:     yes
 * function: func_0215AC1C, func_0215AC3C, func_0215AC68, func_0215ACA8, func_0215ACC8, func_0215AD38
 * address:  0x0215AC1C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02159AE8   0x02159AE8  thumb  ov010
 *   func_0215A5E4   0x0215A5E4  thumb  ov010
 *   func_020127A4   0x020127A4  thumb
 *   func_02008550   0x02008550  thumb
 *   func_02159B10 0x02159B10 thumb ov010
 *   func_02012F08 0x02012F08 thumb
 *   func_0200C234 0x0200C234 thumb
 *   func_0200C248  0x0200C248  thumb
 *   func_0203F4E4  0x0203F4E4  arm
 *   func_02012F5C  0x02012F5C  thumb
 *   func_02008A7C  0x02008A7C  thumb
 *   func_0200C258  0x0200C258  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_020071EC  0x020071EC  thumb
 *   func_020071E4  0x020071E4  thumb
 *   func_0200723C  0x0200723C  thumb
 *   func_0215A5D0  0x0215A5D0  thumb  ov010
 */
struct Sub0200852CObj;
struct Blk34;
struct Sub020089A8Obj;
struct RtcDate;
struct Big;
struct Sub020071E4Ctrl;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    int a;
    int b;
    int c;
    int d;
} V4;

extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0215A5E4(void *a0);
extern int func_020127A4(void *);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern unsigned int func_02159B10(void *,void *);
extern void *func_02012F08(int *p);
extern u32 func_0200C234(struct Blk34 *p, u32 bit);
extern void func_0200C248(struct Blk34 *p, u32 bit);
extern void func_0203F4E4(struct RtcDate *date);
extern void *func_02012F5C(void **h);
extern void func_02008A7C(struct Sub020089A8Obj *obj, u32 i, u32 a, u32 b, u32 c);
extern u32 func_0200C258(struct Blk34 *p);
extern void *func_02012EBC(struct Big *p);
extern unsigned char func_020071EC(const struct Sub020071E4Ctrl *ctrl);
extern u8 func_020071E4(const struct Sub020071E4Ctrl *ctrl);
extern void func_0200723C(int, unsigned *, unsigned *);
extern u16 func_0215A5D0(void *p);
int func_0215AC1C(void *a0, void *a1);
int func_0215AC3C(int a,int b);
int func_0215AC68(int a, int b);
int func_0215ACA8(int a0, int a1);
int func_0215ACC8(int a, int b);
int func_0215AD38(int a0, int a1);


/*
 * The arm9 chain result is biased by the record's own 0x20 before the
 * halfword store.
 */
int func_0215AC1C(void *a0, void *a1)
{
    u16 *p = func_02159AE8(a0, a1);

    *p = (u16)func_02008550((const struct Sub0200852CObj *)(func_020127A4(func_0215A5E4(a1)) + 0x20));

    return 0;
}

/*
 * interfaces: Lookup results used despite legacy void forwarders; observed inputs retained.
 */
int func_0215AC3C(int a,int b)
{
    u16 *out = func_02159AE8((void *)a,(void *)b);
    int k = func_02159B10((void *)a,(void *)b);
    *out = func_0200C234(func_02012F08(func_0215A5E4((void *)b)),k);
    return 0;
}


int func_0215AC68(int a, int b)
{
    V4 v;
    int r4 = func_02159B10((void *)a, (void *)b);
    void *r5 = func_0215A5E4((void *)b);

    func_0200C248(func_02012F08(r5), r4);
    func_0203F4E4((struct RtcDate *)(&v));
    func_02008A7C(func_02012F5C(r5), r4, v.a, v.b, v.c);
    return 0;
}


int func_0215ACA8(int a0, int a1)
{
    u16 *t4;
    int t5;
    void *p;
    void *v0;

t5 = a1 + 0;
    t4 = func_02159AE8((void *)a0, (void *)a1);
loc_0215ACB0:
a0 = t5 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215ACB8:
    p = func_02012F08((int *)v0);
loc_0215ACBC:
    a0 = func_0200C258(p);
loc_0215ACC0:
*t4 = a0;
a0 = 0;
    return a0;}


int func_0215ACC8(int a, int b)
{
    int r4;
    unsigned short *r7;
    unsigned short *m;
    unsigned short *r5;
    unsigned s2;
    unsigned s1;

    r4 = (int)func_02012EBC(func_0215A5E4((void *)b));
    r7 = func_02159AE8((void *)a, (void *)b);
    m = func_02159AE8((void *)a, (void *)b);
    r5 = func_02159AE8((void *)a, (void *)b);
    s2 = 0;
    s1 = 0;
    *r7 = func_020071EC((const struct Sub020071E4Ctrl *)r4);
    *m = func_020071E4((const struct Sub020071E4Ctrl *)r4);
    func_0200723C(r4, &s1, &s2);
    if (s1 * 3 < s2) {
        *r5 = 0;
    } else {
        *r5 = 1;
    }
    return 0;
}


int func_0215AD38(int a0, int a1)
{
    int t5;
    u16 *q;

t5 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215AD40:
a0 = t5 + 0;
    a0 = func_0215A5D0((void *)a0);
loc_0215AD48:
*q = a0;
a0 = 0;
    return a0;}
