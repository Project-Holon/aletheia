/*
 * file:     unit_021B95A0_p14.c
 * unit:     yes
 * function: func_021BA2D4, func_021BA36C, func_021BA418, func_021BA4C8, func_021BA538
 * address:  0x021BA2D4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C57E8  0x021C57E8  thumb  ov127
 *   func_021C5834  0x021C5834  thumb  ov127
 *   func_021C5840  0x021C5840  thumb  ov127
 *   func_021C49A4  0x021C49A4  thumb  ov127
 *   func_0203F5FC  0x0203F5FC  arm
 *   _ll_mul        0x0209C054  arm
 *   func_021C5814  0x021C5814  thumb  ov127
 *   func_021C5898  0x021C5898  thumb  ov127
 *   func_021C5864  0x021C5864  thumb  ov127
 *   func_0203630C  0x0203630C  arm
 *   func_021BA594  0x021BA594  thumb  ov099
 *   func_021C57F4  0x021C57F4  thumb  ov127
 *   func_021C57D8  0x021C57D8  thumb  ov127
 *   func_021BA228  0x021BA228  thumb  ov099
 *   func_021BA5F0  0x021BA5F0  thumb  ov099
 *   func_020056EC  0x020056EC  thumb
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed int     s32;

typedef struct {
    s16 x;
    s16 y;
} P2;

typedef struct {
    void *f0;
    void *f4;
    u16 f8;
} S_021BA2D4;

typedef unsigned int   u32;

typedef struct {
    void *f0;
    void *f4;
    s16 f8;
} S_021BA36C;

typedef struct {
    char pad00[0xc];
    int fc;
} W_021BA418;

typedef struct {
    void *f0;
} S_021BA418;

typedef struct {
    char pad00[0x570];
    void **f570;
} W_021BA4C8;

typedef struct {
    void *f0;
    void *f4;
    s16 f8;
    u8 fa;
    u8 fb;
} S_021BA4C8;

typedef struct {
    void *f0;
    void *f4;
    s16 f8;
} S_021BA538;

extern void func_021C57E8(char *p);
extern int func_021C5834(char *p);
extern void func_021C5840(char *p, int a);
extern int func_021C49A4(u8 *p, unsigned int i);
extern int func_0203F5FC(u32 x);
extern void func_021C5814(void *p, P2 v);
extern void func_021C5898(void *p, P2 v);
extern void func_021C5864(u8 *p, int b);
extern unsigned int func_0203630C(void);
extern void func_021BA594(char *p, int a, int b, int c);
extern void func_021C57F4(u8 *p);
extern void func_021C57D8(u8 *p, int v);
extern void func_021BA228(void *w, u8 *s);
extern void func_021BA5F0(void *a, char *b, u8 c);
extern u32 func_020056EC(u32 range);
void func_021BA2D4(void *w, S_021BA2D4 *s);
void func_021BA36C(void *w, S_021BA36C *s);
int func_021BA418(W_021BA418 *w, S_021BA418 *s);
int func_021BA4C8(W_021BA4C8 *w, S_021BA4C8 *s);
int func_021BA520(W_021BA4C8 *w, S_021BA4C8 *s);
int func_021BA538(void *w, S_021BA538 *s);
int func_021BA578(void *w, S_021BA538 *s);
int func_021BA590(void);


void func_021BA2D4(void *w, S_021BA2D4 *s)
{
    P2 pos;
    P2 q;

    func_021C57E8(s->f4);
    if (func_021C5834(s->f4) == 0) {
        func_021C5840(s->f4, 1);
    }
    pos.x = func_021C49A4(s->f0, 0);
    pos.y = func_021C49A4(s->f0, 1);
    q = pos;
    pos.y = pos.y + (s16)((s32)(((long long)func_0203F5FC(s->f8) * -786432 + 0x800) >> 12) >> 12);
    func_021C5814(s->f4, pos);
    func_021C5898(s->f4, q);
}


/*
 * Parked at MATCH: every byte is right, the single wildcard is the
 * blx to the unlabelled arm9 leaf 0x0203F5FC (no witness outside the range;
 * an arm9 leaf is Ilias's).  Same blocker as ov099_func_021BA2D4.c.
 *
 * with `one --arm` (no --region), C:
 *
 *   typedef unsigned long u32;
 *   typedef signed short s16;
 *   extern const s16 d_020A1B38[];   (0x020A1B38 data a2)
 *   int func_0203F5FC(u32 a)
 *   {
 *       int t;
 *       if (a >= 360) {
 *           return 0;
 *       }
 *       t = (int)(a * 65535) / 360;
 *       return d_020A1B38[(t >> 4) * 2];
 *   }
 */
void func_021BA36C(void *w, S_021BA36C *s)
{
    P2 pos;
    P2 q;
    int t;

    pos.x = func_021C49A4(s->f0, 0);
    pos.y = func_021C49A4(s->f0, 1);
    q = pos;
    t = (s16)(s->f8 - 16);
    if (t > 0) {
        pos.y = pos.y - (s16)((s32)(((long long)func_0203F5FC((u16)(180 * (s16)(t % 6) / 6)) * 16384 + 0x800) >> 12) >> 12);
    }
    func_021C5814(s->f4, pos);
    func_021C5898(s->f4, q);
    func_021C5864(s->f4, 1);
}


/*
 * Lever: the pad read is a named local (t) assigned before k = 2, so the
 * movs r7,#2 lands after the first blx.
 */
int func_021BA418(W_021BA418 *w, S_021BA418 *s)
{
    int a;
    int b;
    int k;
    int t;

    a = func_021C49A4(s->f0, 6);
    b = func_021C49A4(s->f0, 4);
    if (func_021C49A4(s->f0, 5) != 0) {
        return 0;
    }
    if (w->fc == 1) {
        return 0;
    }
    t = func_0203630C();
    k = 2;
    if (t & 2) {
        k = 3;
    }
    if (func_0203630C() & 0x40) {
        if (a == 0) {
            func_021BA594((char *)w, k, a, b);
        } else {
            func_021BA594((char *)w, 1, 0, b);
        }
    } else if (func_0203630C() & 0x80) {
        if (a == 1) {
            func_021BA594((char *)w, k, a, b);
        } else {
            func_021BA594((char *)w, 1, 1, b);
        }
    } else if (func_0203630C() & 0x20) {
        if (a == 2) {
            func_021BA594((char *)w, k, a, b);
        } else {
            func_021BA594((char *)w, 1, 2, b);
        }
    } else if (func_0203630C() & 0x10) {
        if (a == 3) {
            func_021BA594((char *)w, k, a, b);
        } else {
            func_021BA594((char *)w, 1, 3, b);
        }
    }
    return 0;
}


int func_021BA4C8(W_021BA4C8 *w, S_021BA4C8 *s)
{
    int a;
    int b;

    s->f8 = s->f8 - 1;
    if (s->f8 <= 0) {
        func_021C57F4(s->f4);
        func_021C57D8(s->f4, 1);
        a = func_021C49A4(*w->f570, 4);
        b = func_021C49A4(s->f0, 4);
        if (b == a) {
            func_021BA228(w, (u8 *)s);
        } else {
            func_021BA5F0(w, (char *)s, s->fb);
        }
    }
    return 0;
}


int func_021BA520(W_021BA4C8 *w, S_021BA4C8 *s)
{
    s->f8 = s->f8 + 1;
    if (s->f8 > 0x2d) {
        return 1;
    }
    return 0;
}


/*
 * func_021BA578 (counter reload leaf) and func_021BA590 (returns 0) are
 * the unlabelled leaves after the lead function (seed function_starts
 * 0x021BA578, 0x021BA590).
 */
int func_021BA538(void *w, S_021BA538 *s)
{
    int r;

    s->f8 = s->f8 - 1;
    if (s->f8 <= 0) {
        s->f8 = func_020056EC(0x400) + 0x100;
        r = func_020056EC(4);
        func_021BA594(w, 0, r, func_021C49A4(s->f0, 4));
    }
    return 0;
}


int func_021BA578(void *w, S_021BA538 *s)
{
    s->f8 = s->f8 - 1;
    if (s->f8 < 0) {
        s->f8 = 0x1c;
    }
    return 0;
}


int func_021BA590(void)
{
    return 0;
}
