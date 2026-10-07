/*
 * file:     btlv_effvm_p28.c
 * unit:     yes
 * function: func_021F9028, func_021F903C, func_021F9154, func_021F918C, func_021F9220, func_021F9260, func_021F935C, func_021F9364
 * address:  0x021F9028
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
 *   func_02030EE8 0x02030EE8 arm
 *   func_020307B0 0x020307B0 arm
 *   d_0220AF20 0x0220AF20 data ov094 a4
 *   d_0220AC70 0x0220AC70 data a4
 *   d_0220AC78 0x0220AC78 data a4
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_021F7BEC 0x021F7BEC thumb ov094
 *   func_021F7998 0x021F7998 thumb ov094
 *   func_021F7EB4 0x021F7EB4 thumb ov094
 *   func_021BA1A8 0x021BA1A8 thumb ov093
 *   func_0203F0A8 0x0203F0A8 arm
 *   _ull_mul 0x0209C054 arm
 *   func_0207C768 0x0207C768 arm
 *   sub_0207C768  0x0207C768  arm
 *   func_02046F48  0x02046F48  arm
 *   func_0206E964  0x0206E964  arm
 *   func_02021F64  0x02021F64  thumb
 *   func_02061CA4  0x02061CA4  arm
 */
#define WORD(k) (*(int *)(d_0220AF20 + (k)))
struct S02030EE8;
struct Tagged;
typedef unsigned int   u32;

typedef unsigned long long u64;

typedef int fx32;

typedef struct {
    fx32 x, y, z;
} VecFx32;

typedef struct {
    int mode;               /* 0x00 */
    VecFx32 end;            /* 0x04 */
    VecFx32 start;          /* 0x10 */
    VecFx32 step;           /* 0x1c */
    int count;              /* 0x28 */
    int countReset;         /* 0x2c */
    int wait;               /* 0x30 */
    int waitReset;          /* 0x34 */
    int repeat;             /* 0x38 */
} Mover;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {
    u32 **a0;           /* 0 */
    u16 **a4;           /* 4 */
    u8 en;              /* 8 */
    u8 n;               /* 9 */
    u8 cur;             /* 0xA */
    u8 tgt;             /* 0xB */
    u8 cnt;             /* 0xC */
    u8 rl;              /* 0xD */
    u16 col;            /* 0xE */
} P;

typedef struct {
    char pad[0x2C];
    u32 w2c;            /* 0x2C */
    u16 h30;            /* 0x30 */
    char pad2[6];
    u32 o38;            /* 0x38 */
} Q;

typedef signed int     s32;

extern u32 func_02030EE8(struct S02030EE8 *p);
extern u32 func_020307B0(void *p);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_021F7BEC(void);
extern void func_021F7998(u32);
extern int func_021F7EB4(void);
extern int func_021BA1A8(char **p, int m);
extern u32 func_0203F0A8(void);
extern u32 func_0207C768(u32 a, u32 b);
extern u32 sub_0207C768(u32 a, u32 b);
extern void *func_02046F48(struct Tagged *p);
extern unsigned char *func_0206E964(unsigned char *p);
extern void func_02021F64(u16 *src, u16 *dst, u32 count, int weight, u16 color);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
void func_021F9028(void *h);
void func_021F903C(void);
void func_021F9154(int a, int b, int *out, int c);
void func_021F918C(const VecFx32 *a, const VecFx32 *b, VecFx32 *out, fx32 div);
void func_021F9220(int *p, int *d, int *lim, int *flag);
int func_021F9260(Mover *m, VecFx32 *out);
int func_021F935C(int x);
void func_021F9364(P *p);
extern char *d_0220AF20;
extern u32 d_0220AC70[];
extern u32 d_0220AC78[];


/*
 * EXACT*: the listing extent includes two bytes of trailing alignment padding.
 *
 * Frees the buffer at 0x10 of the current task's work, if any.
 */
void func_021F9028(void *h)
{
    void *p = *(void **)(func_02030EE8(h) + 0x10);
    if (p != 0)
        func_020307B0(p);
}


/*
 * lever: Assign table lookups to a shared local before the call; duplicated
 * calls cross-jump the indexed load and shorten the function by four bytes.
 */
void func_021F903C(void)
{
    int a, b;
    u32 n, value;
    a = func_020362DC();
    b = func_02035C60();
    if (WORD(0x238) == 0)
        return;
    if (WORD(0x238) != 2 && WORD(0x238) != 3 && (a != 0 || b != 0)) {
        func_021F7BEC();
        func_021F7998(0x252);
        WORD(0x23c) = 0;
        WORD(0x240) = 0;
    }
    switch (WORD(0x23c)) {
    case 0:
        if (WORD(0x240) < WORD(0x244)) {
            WORD(0x240)++;
            return;
        }
        WORD(0x23c) = 1;
    case 1:
        if (func_021F7EB4() == 0) {
            if (WORD(0x238) == 3 && func_021BA1A8(*(void **)(d_0220AF20 + 0x1e4), 0x400)) {
                do {
                    n = (u32)(((u64)func_0203F0A8() * 2) >> 32);
                } while (WORD(0x248) == n);
                WORD(0x248) = n;
                value = d_0220AC70[WORD(0x248)];
            } else {
                do {
                    n = (u32)(((u64)func_0203F0A8() * 6) >> 32);
                } while (WORD(0x248) == n);
                WORD(0x248) = n;
                value = d_0220AC78[WORD(0x248)];
            }
            func_021F7998(value);
            WORD(0x1e8) = 1;
        }
        break;
    }
}


/*
 * Signed step from a to b in units of c (default 0x1000), at least one unit.
 */
void func_021F9154(int a, int b, int *out, int c)
{
    *out = 0;
    if (b - a == 0)
        return;
    if (c == 0)
        c = 0x1000;
    *out = func_0207C768(b - a, c);
    if (*out == 0) {
        if (b > a)
            *out = 1;
        else
            *out = -1;
    }
}


void func_021F918C(const VecFx32 *a, const VecFx32 *b, VecFx32 *out, fx32 div)
{
    out->x = 0;
    out->y = 0;
    out->z = 0;
    if (div == 0)
        div = 0x1000;
    if (b->x - a->x != 0) {
        out->x = sub_0207C768(b->x - a->x, div);
        if (out->x == 0)
            out->x = (b->x > a->x) ? 1 : -1;
    }
    if (b->y - a->y != 0) {
        out->y = sub_0207C768(b->y - a->y, div);
        if (out->y == 0)
            out->y = (b->y > a->y) ? 1 : -1;
    }
    if (b->z - a->z != 0) {
        out->z = sub_0207C768(b->z - a->z, div);
        if (out->z == 0)
        {
            if (b->z > a->z)
                out->z = 1;
            else
                out->z = -1;
        }
    }
}

/*
 * EXACT*: inferred extent runs two bytes long; the follower is an unlabelled
 * padding pair.
 */
void func_021F9220(int *p, int *d, int *lim, int *flag)
{
    int n = *p + *d;
    *p = n;
    if (*d < 0) {
        if (n <= *lim) {
            *p = *lim;
        } else {
            if (flag)
                *flag = 0;
        }
    } else {
        if (n >= *lim) {
            *p = *lim;
        } else {
            if (flag)
                *flag = 0;
        }
    }
}


int func_021F9260(Mover *m, VecFx32 *out)
{
    int ret = 1;

    switch (m->mode) {
    case 0:
        out->x = m->start.x;
        out->y = m->start.y;
        out->z = m->start.z;
        break;
    case 1:
    case 4:
        if (m->wait == 0) {
            m->wait = m->waitReset;
            func_021F9220(&out->x, &m->step.x, &m->start.x, &ret);
            func_021F9220(&out->y, &m->step.y, &m->start.y, &ret);
            func_021F9220(&out->z, &m->step.z, &m->start.z, &ret);
        } else {
            m->wait--;
            ret = 0;
        }
        break;
    case 2:
    case 3:
        if (m->wait == 0) {
            m->wait = m->waitReset;
            out->x += m->step.x;
            out->y += m->step.y;
            out->z += m->step.z;
            if (--m->count == 0) {
                m->repeat--;
                m->count = m->countReset;
                if (m->mode == 2 || (m->mode == 3 && (m->repeat & 1))) {
                    m->step.x *= -1;
                    m->step.y *= -1;
                    m->step.z *= -1;
                }
            }
        } else {
            m->wait--;
        }
        if (m->repeat != 0) {
            ret = 0;
        } else {
            out->x = m->end.x;
            out->y = m->end.y;
            out->z = m->end.z;
        }
        break;
    }
    return ret;
}

/*
 * lane O10 candidate
 */
int func_021F935C(int x)
{
    return 1 << x;
}


void func_021F9364(P *p)
{
    int i;
    Q *q;
    u32 sz;
    u32 off;

    if (p->en != 0) {
        if (p->cnt == 0) {
            p->cnt = p->rl;
            for (i = 0; i < p->n; i++) {
                q = (Q *)func_0206E964(func_02046F48((struct Tagged *)p->a0[i]));
                sz = q->h30 << 3;
                off = (u16)q->w2c << 3;
                func_02021F64((u16 *)((char *)q + q->o38), p->a4[i], (u16)(sz >> 1), p->cur, p->col);
                func_02061CA4((void *)1, off, (u32)p->a4[i], sz);
            }
            if (p->cur == p->tgt) {
                p->en = 0;
            } else if (p->cur > p->tgt) {
                p->cur = p->cur - 1;
            } else {
                p->cur = p->cur + 1;
            }
        } else {
            p->cnt = p->cnt - 1;
        }
    }
}
