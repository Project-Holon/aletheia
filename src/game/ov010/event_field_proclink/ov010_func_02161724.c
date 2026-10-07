/*
 * function: func_02161724
 * address:  0x02161724
 * packet:   pkt_ov010_02161724
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Three-step sequence over the field map's objects: step 0 starts the
 * animations that are not yet running and records them in w->busy, step
 * 1 waits until every recorded one has finished, step 2 answers done.
 *
 * The image keeps a second object that is always NULL (`movs r6, #0;
 * beq` reuses the movs flags, and the NULL is still passed to
 * func_0216DA5C in step 1): written as a pointer local set to 0 and
 * tested. w->field is read into a local before the switch.
 *
 * symbols:
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216DEE0  0x0216DEE0  thumb  ov010
 *   func_0216DE54  0x0216DE54  thumb  ov010
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216DB04  0x0216DB04  thumb  ov010
 *   func_0216DA5C  0x0216DA5C  thumb  ov010
 *   func_0216DAF8  0x0216DAF8  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct AnimWork {
    u32 f00;
    void *field;        /* 0x04 */
    u32 f08;
    u8 busy;            /* 0x0C */
} AnimWork;

extern void *func_02188C7C(u8 *p);
extern void *func_0216DEE0(void *map);
extern void *func_0216DE54(void *map, u32 kind);
extern void func_0216D9A0(void *map);
extern int func_0216D454(void *obj);
extern char *func_0216DB04(void *a0);
extern int func_0216DA5C(void *obj);
extern void func_0216DAF8(void *obj);

int func_02161724(void *task, u32 *seq, AnimWork *w)
{
    void *map;
    void *a;
    void *b;
    void *c;
    void *field;

    field = w->field;
    switch (*seq) {
    case 0:
        map = func_02188C7C(field);
        a = func_0216DEE0(map);
        func_0216DE54(map, 0x30);
        w->busy = 0;
        func_0216D9A0(map);
        if (func_0216D454(a) == 0) {
            w->busy |= 1;
            func_0216DB04(a);
        }
        b = 0;
        if (b != 0 && func_0216DA5C(b) == 1) {
            w->busy |= 4;
            func_0216DB04(b);
        }
        (*seq)++;
        break;
    case 1:
        map = func_02188C7C(field);
        a = func_0216DEE0(map);
        func_0216DE54(map, 0x30);
        if ((w->busy & 1) && func_0216D454(a) == 1) {
            func_0216DAF8(a);
            w->busy &= ~1;
        }
        if (w->busy & 4) {
            b = 0;
            if (func_0216DA5C(b) == 0) {
                func_0216DAF8(b);
                w->busy &= ~4;
            }
        }
        if (w->busy & 2) {
            c = func_0216DE54(map, 0x30);
            if (func_0216DA5C(c) == 0) {
                func_0216DAF8(c);
                w->busy &= ~2;
            }
        }
        if (w->busy == 0)
            (*seq)++;
        break;
    case 2:
        return 1;
    }
    return 0;
}
