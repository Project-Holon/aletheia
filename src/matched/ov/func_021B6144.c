/*
 * function: func_021B6144
 * address:  0x021B6144
 * packet:   pkt_021B6144
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S;

typedef int (*cb_t)(struct S *s, void *arg);

struct Entry {
    cb_t cb0;
    cb_t cb1;
    cb_t cb2;
    cb_t cb3;
    cb_t cb4;
};

struct S {
    struct Entry *arr;
    void *f4;
    u16 idx;
    u16 fA;
    u8 _c;
    u8 d;
    u8 e;
};

int func_021B6144(struct S *s)
{
    struct Entry *e = (struct Entry *)((u8 *)s->arr + s->idx * 0x14);

    switch (s->d) {
    case 0:
        if (e->cb0 == 0) {
            s->d = 1;
        } else {
            if (e->cb0(s, s->f4) == 0)
                break;
            s->e = 0;
            s->d = 1;
            break;
        }
        /* fallthrough */
    case 1:
        if (e->cb1 != 0)
            e->cb1(s, s->f4);
        s->d = 2;
        /* fallthrough */
    case 2:
        if (e->cb2(s, s->f4) == 0)
            break;
        s->e = 0;
        if (e->cb3 != 0)
            e->cb3(s, s->f4);
        s->d = 3;
        break;
    case 3:
        if (e->cb4 == 0) {
            s->d = 4;
        } else {
            if (e->cb4(s, s->f4) == 0)
                break;
            s->e = 0;
            s->d = 4;
            break;
        }
        /* fallthrough */
    case 4: {
        u16 old = s->fA;

        s->fA = 0xFFFF;
        s->idx = old;
        if (old == 0xFFFE)
            return 1;
        s->d = 0;
        s->e = 0;
        break;
    }
    }
    return 0;
}
