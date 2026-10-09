/*
 * file:     btl_server_p09.c
 * unit:     yes
 * function: func_021BCEFC, func_021BCF34, func_021BCF70, func_021BCFAC, func_021BD080, func_021BD0C0
 * address:  0x021BCEFC
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
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021D74F8 0x021D74F8 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D75EC 0x021D75EC thumb ov093
 *   func_021D70F0 0x021D70F0 thumb ov093
 *   func_021D7540 0x021D7540 thumb ov093
 *   func_02018480 0x02018480 thumb
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021B8DDC 0x021B8DDC thumb ov093
 *   func_021B8FF4 0x021B8FF4 thumb ov093
 *   func_021D5844 0x021D5844 thumb ov093
 *   func_021B871C 0x021B871C thumb ov093
 *   func_021B85A0 0x021B85A0 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D78AC 0x021D78AC thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_02018488 0x02018488 thumb
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021BCA08  0x021BCA08  thumb  ov093
 *   func_021BCA50  0x021BCA50  thumb  ov093
 *   func_021D8454  0x021D8454  thumb  ov093
 *   func_021BDE48  0x021BDE48  thumb  ov093
 *   func_021BD138  0x021BD138  thumb  ov093
 *   func_021D82FC  0x021D82FC  thumb  ov093
 *   func_021BCCE0  0x021BCCE0  thumb  ov093
 */
struct Unk021D62A8;
struct Unk021BDE48;
struct Unk021D82FC;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef union {
    struct { u32 type:4, select:3, move:16, arg:8, rest:1; } full;
    struct { u32 type:4, select:3, move:3, rest:22; } small;
} Action;

typedef struct {
    u8 *a;      /* 0x0 */
    Action b;   /* 0x4 */
    u32 c;      /* 0x8 */
    u8 d;       /* 0xc */
    u8 done;    /* 0xd */
    u8 f;       /* 0xe */
    u8 pad;     /* 0xf */
} Entry;

typedef struct {
    u8 *f0;                         /* 0x000 */
    void *f4;                       /* 0x004 */
    void *f8;                       /* 0x008 */
    void *fC;                       /* 0x00c */
    u32 f10;                        /* 0x010 */
    u32 f14;                        /* 0x014 */
    u8 pad18[0x4b8 - 0x18];
    u8 w4b8[0x782 - 0x4b8];         /* 0x4b8 */
    u8 n;                           /* 0x782 */
    u8 pad783;
    u8 f784;                        /* 0x784 */
    u8 pad785;
    u8 f786;                        /* 0x786 */
    u8 pad787[3];
    union {
        u8 raw;
        struct { u8 b0:1, b1:1, b2:1, rest:5; } bits;
    } f78a;                         /* 0x78a */
    u8 f78b[0x7c1 - 0x78b];         /* 0x78b */
    u8 flags[0x7e0 - 0x7c1];        /* 0x7c1 */
    Entry e[6];                     /* 0x7e0 */
    Entry t;                        /* 0x840 */
    u8 pad850[0x1ab8 - 0x850];
    u8 w1ab8[0x1d74 - 0x1ab8];      /* 0x1ab8 */
    u32 lock;                       /* 0x1d74 */
    u8 pad1d78[0x1f78 - 0x1d78];
    int f1f78;                      /* 0x1f78 */
    u8 pad1f7c[0x1fe8 - 0x1f7c];
    u8 f1fe8;                       /* 0x1fe8 */
} Server;

extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern void func_021D74F8(int);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int, u32);
extern void func_021D70F0(void *a, int id);
extern void func_021D7540(int);
extern void *func_021B86B8(void ***);
extern u8 func_021B8DDC(u32);
extern u8 func_021B8FF4(u8 *);
extern void *func_021D5844(void *);
extern int func_021B871C(char *);
extern int func_02018480(void *, int);
extern u8 func_021B85A0(u8 **p);
extern int func_021D59B4(u8 *, int);
extern u32 func_021D78AC(u32);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern void func_021D7630(int key, u32 val);
extern int func_021D775C(int key);
extern Entry *func_021BCA08(Server *p, u8 x);
extern Entry *func_021BCA50(Server *p, Entry *cur, u32 x);
extern u32 func_021D8454(Action *);
extern u16 func_021BDE48(void *p, Action *m);
extern int func_021BD138(u8 *p, u32 k);
extern void func_021D82FC(Action *p, int sub);
extern u32 func_021BCCE0(Server *p, Entry *e);
void func_021BCEFC(Server *p, u8 *a, u32 k);
void func_021BCF34(Server *p, u8 *a, u32 k);
void func_021BCF70(Server *p, u8 *a, u32 k);
int func_021BCFAC(Server *p, u8 *a);
int func_021BD080(Server *p, u8 *a);
int func_021BD0C0(Server *p, u8 x, u32 y);


/*
 * interface: func_021CC8D8 returns its four-byte Lock in r0; use the
 * full-word payload spelling of matched caller func_021BC568. The entire
 * func_021CC95C body is str r1,[r0]; bx lr, retaining every payload bit.
 * Aggregate spelling added eight bytes of frame; paired fixed-flag
 * runs were DIFF (60 bytes) and EXACT (56 bytes). Calls and stores agree.
 */
void func_021BCEFC(Server *p, u8 *a, u32 k)
{
    int line = 0x854;
    u32 old = func_021CC8D8(&p->lock, line);
    func_021BCF34(p, a, k);
    func_021CC95C(&p->lock, old, line + 3);
}




void func_021BCF34(Server *p, u8 *a, u32 k)
{
    int line = 0x864;
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(12, k);
    func_021D70F0(p, 1);
    func_021D7540(line + 4);
}




void func_021BCF70(Server *p, u8 *a, u32 k)
{
    int line = 0x874;
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(12, k);
    func_021D70F0(p, 2);
    func_021D7540(line + 4);
}



/*
 * note 2026-10-05 (wD9r lane04): EXACT* (the trailing 021BD07E halfword is alignment padding). Closed
 *   with `r -= x - y; if (r < x - y) return 3;` in place of the one-expression
 *   `(u16)(r - (u16)(x - y)) < x - y`. The redefinition of r splits its live range, so the first use
 *   reloads the spilled r (`str r0,[sp]; ldr r0,[sp]`). No cast stand-in.
 * note 2026-10-05 (wD9 lane18): still DIFF 55 B (no stand-in). Reading: the first use of r must be an
 *   operation on the spilled r (the u16 to u32 widening node), not the call temp; any plain form forwards r0.
 *   Tried: a static inline u16 rnd(u32) for both random calls; operands reversed (x - y > r) in one and both
 *   compares; an int d = x - y block; r as u32 with (u16) at the def and (int)r at the compare (a real
 *   signedness cast, still forwards r0). All 55 B.
 * note 2026-10-05 (integrator): the source no longer has the (int)(u32)r stand-in cast, so it is DIFF (the plain compare drops the reload of r). With the cast it verifies EXACT*: rejected as a stand-in.
 * note 2026-10-05: witness src/matched/arm9/func_02018480.c filed (EXACT); the wildcard at +0x38 resolves after regeneration. The reload still needs the (int)(u32)r spelling, which is a no-op steering cast (stand-in, not accepted). Tried without it: u16 callee return type for func_021D78AC with plain compares, and an int local fed from the u16 return: both forward r0 and drop the ldr (200 bytes). Parked MATCH* because of the cast; reading: r is spilled for real (p,a,x,y fill r4..r7), so the original defines r with the store at the def and the reload at first use; no stand-in free source found.
 * evidence (older): every concrete byte matched (MATCH*, the trailing 021BD07E
 *   halfword is alignment padding). The one wildcard is +0x38, the bl to the
 *   ARM9 Thumb thunk func_02018480 (ldr r3,[pc]; bx r3; .word 0x02018489),
 *   which has no witness outside this range: label/sole-ref need an arm9
 *   label or a matched entry there. It is an arm9 leaf, Ilias's; its verified
 *   C is below. Once it is filed this caller re-runs to EXACT*.
 *   func_02018480 0x02018480 thumb, arm9; `one --thumb` (no --region): EXACT
 *     extern int func_02018488(void *p, int q);
 *     int func_02018480(void *p, int q)
 *     {
 *         return func_02018488(p, q);
 *     }
 *   (func_02018488 0x02018488 thumb resolves by label; it reads r0 and r1 and
 *   returns the 0/1 in r6.)
 * note: the reload `str r0,[sp]; ldr r0,[sp]` at 021BD046/021BD048 comes only
 *   from spelling the first use of r through a widening cast, `(int)(u32)r`;
 *   plain `r`, `(int)r` and u16/u32/int locals forward r0 into the compare
 *   and drop the ldr (55 bytes out), and `(u32)r` alone reloads but turns
 *   the bge into bhs.
 */
int func_021BCFAC(Server *p, u8 *a)
{
    int k;
    u32 n;
    u16 x, y;
    if ((u32)func_021B86B8((void ***)p->f4) <= 1) {
        k = func_021B8DDC(func_021D5440(a));
        if (k == func_021B8FF4((u8 *)p->f4)) {
            void *v = func_021D5844(a);
            if (func_02018480(v, func_021B871C((char *)p->f4)) == 0) {
                n = func_021B85A0((u8 **)p->f4);
                if (n < 8) {
                    u16 r;
                    x = (u16)func_021D59B4(a, 15);
                    y = (u16)(10 * (n + 1));
                    if (x <= y) return 0;
                    if ((u16)func_021D78AC(x + y + 1) < y) return 0;
                    if (func_021D62C4((struct Unk021D62A8 *)a, 2) != 0) return 4;
                    r = func_021D78AC(256);
                    if (r < x - y && func_021BD080(p, a) == 0) return 2;
                    r -= x - y;
                    if (r < x - y) return 3;
                    return 4;
                }
            }
        }
    }
    return 0;
}



int func_021BD080(Server *p, u8 *a)
{
    int r;
    func_021D74F8(2256);
    func_021D75EC(2, func_021D5440(a));
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0xe);
    r = func_021D775C(0x41);
    func_021D7540(2261);
    return r;
}



int func_021BD0C0(Server *p, u8 x, u32 y)
{
    Entry *e = func_021BCA08(p, x);
    if (e) {
        if (e->done != 0 && func_021D8454(&e->b) == 6) {
            e = func_021BCA50(p, e, x);
        }
        if (e->done == 0) {
            if (func_021BDE48(e->a, &e->b)) return 0;
            if (func_021D8454(&e->b) == 6) return 0;
            func_021D82FC(&e->b, func_021BD138(p->w1ab8, y));
            func_021BCCE0(p, e);
            return 1;
        }
    }
    return 0;
}
