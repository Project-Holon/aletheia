/*
 * file:     btlv_bg_p03.c
 * unit:     yes
 * function: func_022094BC, func_02209500, func_02209540, func_02209744
 * address:  0x022094BC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020870D0  0x020870D0  arm
 *   func_0204B22C  0x0204B22C  arm
 *   _ll_udiv       0x0209C00C  arm
 *   d_0220ABB8  0x0220ABB8  data  a4
 */
struct Bank;
struct Timer;
struct Obj;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned long long u64;

typedef struct {
    int h[2];
    char pad8[0x4c - 8];
    int x4c[2];
    u64 t[2];
    int x64[2];
} W_022094BC;

typedef struct {
    int h[2];
    char pad8[0x4c - 8];
    int x4c[2];
    u64 t[2];
} W_02209500;

typedef unsigned short u16;

typedef struct Digits { void *icon; void *m10; void *m1; void *colon; void *s10; void *s1; void *pad; } Digits;

typedef struct Timer {
    int pad0;
    int pad4;
    Digits d[2];
    int pad40[3];
    int limit[2];
    u64 start[2];
    int base[2];
} Timer;

typedef enum { B_FALSE, B_TRUE } Bool;

typedef struct Pair { int v[2]; } Pair;

extern u64 func_020870D0(void);
extern void func_0204B22C(struct Bank *bank, u32 mode);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B3DC(struct Obj *p, u32 v);
void func_022094BC(u8 *p, int i, int a, int b);
int func_02209500(W_02209500 *w, int i);
void func_02209540(Timer *p, int idx);
void func_02209744(int unused, int x);
extern const Pair d_0220ABB8;


void func_022094BC(u8 *p, int i, int a, int b)
{
    W_022094BC *w = (W_022094BC *)p;

    if (*(int *)(p + i * 0x1c + 8) != 0) {
        if (a == 1 && b == 1) {
            w->t[i] = func_020870D0();
            w->x64[i] = 0;
            func_02209540((struct Timer *)w, i);
        }
        func_0204B22C((struct Bank *)w->h[i], a);
    }
}


int func_02209500(W_02209500 *w, int i)
{
    u64 d;

    d = func_020870D0() - w->t[i];
    d = (d << 6) / 33514000ULL;
    return w->x4c[i] - (int)d <= 0;
}


/*
 * note: the 0/1 icon offset is an enum-constant ternary (an int spelling flips the bne polarity).
 */
void func_02209540(Timer *p, int idx)
{
    Pair tbl = d_0220ABB8;
    int icon = idx == 0 ? B_FALSE : B_TRUE;
    int r = p->limit[idx] - (int)(((func_020870D0() - p->start[idx]) * 64) / 33514000);
    int min, sec, m10, m1, s10, s1;
    if (p->d[idx].icon == 0)
        return;
    if (r < 0)
        r = 0;
    min = r / 60;
    sec = r % 60;
    m10 = min / 10;
    m1 = min % 10;
    s10 = sec / 10;
    s1 = sec % 10;
    if (r == tbl.v[idx])
        p->base[idx] = 13;
    func_0204B878(p->d[idx].icon, icon + p->base[idx]);
    if (m10 == 0) {
        func_0204B3DC(p->d[idx].m10, 0);
    } else {
        func_0204B3DC(p->d[idx].m10, 1);
        func_0204B878(p->d[idx].m10, m10 + 3 + p->base[idx]);
    }
    if (m10 == 0 && m1 == 0) {
        func_0204B3DC(p->d[idx].m1, 0);
        func_0204B3DC(p->d[idx].colon, 0);
    } else {
        func_0204B3DC(p->d[idx].m1, 1);
        func_0204B3DC(p->d[idx].colon, 1);
        func_0204B878(p->d[idx].m1, m1 + 3 + p->base[idx]);
        func_0204B878(p->d[idx].colon, p->base[idx] + 2);
    }
    if (m10 == 0 && m1 == 0 && s10 == 0) {
        func_0204B3DC(p->d[idx].s10, 0);
    } else {
        func_0204B3DC(p->d[idx].s10, 1);
        func_0204B878(p->d[idx].s10, s10 + 3 + p->base[idx]);
    }
    func_0204B878(p->d[idx].s1, s1 + 3 + p->base[idx]);
}


/*
 * lane O10 candidate
 */
void func_02209744(int unused, int x)
{
    func_02209540((struct Timer *)x, 0);
    func_02209540((struct Timer *)x, 1);
}
