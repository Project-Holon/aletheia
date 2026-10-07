/*
 * file:     btlv_b_gauge_p04.c
 * unit:     yes
 * function: func_02207EF0, func_02207F6C, func_02208034
 * address:  0x02207EF0
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
 *   func_022080B0  0x022080B0  thumb  ov094
 *   func_022082FC  0x022082FC  thumb  ov094
 *   _u32_div_f     0x0209C2B0  arm
 */
typedef unsigned int u32;

typedef unsigned short u16;

typedef struct E {
    char p0[0x54];
    int f54;
    int f58;
    int p5c;
    int f60;
    int f64;
    char p68[8];
    u32 b0 : 1;
    u32 b1 : 1;
    u32 hi : 30;
    char p74[12];
} E;

typedef struct O {
    char pad[0x40];
    E e[8];
} O;

typedef unsigned char  u8;

extern int func_022080B0(int a, int b, int c, unsigned int d);
extern void func_022082FC(O *obj, int idx, int k);
void func_02207EF0(O *obj, int idx);
int func_02207F6C(int n, int target, int delta, int *cur, u8 x, int speed);
u8 func_02208034(u32 a, int b, int c, u32 *pp, u8 *out, u8 n);


void func_02207EF0(O *obj, int idx)
{
    E *e;
    int k;
    int q;
    int r;

    e = &obj->e[idx];
    k = func_022080B0(e->f54, e->f60, e->f58, 10);
    if (k == 0) {
        k = 1;
    }
    q = e->f60 / k;
    if (q < 0) {
        q = -q;
    }
    if (q == 0) {
        q = 1;
    }
    r = func_02207F6C(e->f58, e->f54, e->f60, &e->f64, (int)10, (u16)q);
    func_022082FC(obj, idx, 1);
    if (r == -1) {
        e->f54 = e->f54 - e->f60;
        e->b1 = 0;
        e->f64 = 0;
    }
}


int func_02207F6C(int n, int target, int delta, int *cur, u8 x, int speed)
{
    u8 lim;
    int t;
    int v;
    int d;

    lim = x * 8;
    if (*cur == (int)0x80000000) {
        if (n < lim)
            *cur = target << 8;
        else
            *cur = target;
    }
    t = target - delta;
    if (t < 0)
        t = 0;
    else if (t > n)
        t = n;
    if (n < lim) {
        if (t == (*cur >> 8) && (*cur & 0xff) == 0)
            return -1;
    } else if (t == *cur) {
        return -1;
    }
    if (n < lim) {
        d = (n << 8) / lim;
        if (delta < 0) {
            *cur += d;
            v = *cur >> 8;
            if (v >= t || speed == 0) {
                *cur = t << 8;
                return t;
            }
        } else {
            *cur -= d;
            v = *cur >> 8;
            if ((*cur & 0xff) > 0)
                v++;
            if (v <= t || speed == 0) {
                *cur = t << 8;
                return t;
            }
        }
    } else {
        if (delta < 0) {
            *cur += speed;
            if (*cur > t || speed == 0)
                *cur = t;
        } else {
            *cur -= speed;
            if (*cur < t || speed == 0)
                *cur = t;
        }
        v = *cur;
    }
    return v;
}


/*
 * Levers: n is a u8 stack parameter (ldrb [sp,#0x1c]); the return value is a
 * separate copy `ret` of the running count (declared before the loop index j
 * so ret takes r2 and j r3).
 */
u8 func_02208034(u32 a, int b, int c, u32 *pp, u8 *out, u8 n)
{
    int lim;
    int i;
    u32 total;
    u32 v;
    u32 ret;
    int j;

    lim = b - c;
    if (lim < 0) {
        lim = 0;
    } else if (lim > (int)a) {
        lim = a;
    }
    total = n * 8;
    for (i = 0; i < n; i++) {
        out[i] = 0;
    }
    if (a < total) {
        v = (*pp * total) / a >> 8;
    } else {
        v = (*pp * total) / a;
    }
    ret = v;
    if (v == 0 && lim > 0) {
        ret = 1;
        out[0] = 1;
    } else {
        for (j = 0; j < n; j++) {
            if (v >= 8) {
                out[j] = 8;
                v -= 8;
            } else {
                out[j] = v;
                break;
            }
        }
    }
    return ret;
}
