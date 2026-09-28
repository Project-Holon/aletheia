/*
 * function: func_0215739C
 * address:  0x0215739C
 * packet:   pkt_ov010_0215739C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Task callback of func_02157450: a 10-state sequence that pushes the
 * field-effect child tasks (the ov008 effect runner gets the effect
 * object, its direction record and a zero word) and returns 1 when done.
 *
 * symbols:
 *   func_02029BCC  0x02029BCC  thumb
 *   func_02012374  0x02012374  thumb
 *   func_020124AC  0x020124AC  thumb
 *   func_020130DC  0x020130DC  thumb
 *   func_02029C00  0x02029C00  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_02029CC0  0x02029CC0  thumb
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_021550A0  0x021550A0  thumb  ov008
 *   ov008_id       0x00000008  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Obj {
    u8 pad00[0x18];
    u16 f18;            /* 0x18 */
} Obj;

typedef struct Work {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    Obj f08;            /* 0x08 */
    u8 pad[0xF8 - 0x08 - sizeof(Obj)];
    void *fF8;          /* 0xF8 */
} Work;

typedef struct Args {
    Obj *obj;
    void *sub;
    u32 zero;
} Args;

extern u8 ov008_id[];

extern void *func_02029BCC(void *h, u16 v);
extern void func_02012374(void *evt, void *task);
extern void *func_020124AC(void *h, u32 n, u32 (*fn)(void *, u32), Args *a);
extern void func_020130DC(Obj *o);
extern void *func_02029C00(void *h);
extern void *func_020145CC(void *h);
extern void *func_02029CC0(void *h);
extern void *func_021BE92C(void *a, void *b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern u32 func_021550A0(void *p, u32 n);

int func_0215739C(void *evt, u32 *state, Work *w)
{
    void *h = w->f00;

    switch (*state) {
    case 0:
        *state = 3;
        break;
    case 1:
    case 2:
        break;
    case 3:
        func_02012374(evt, func_02029BCC(h, w->f08.f18));
        (*state)++;
        break;
    case 4: {
        Args a;

        a.obj = &w->f08;
        a.sub = w->fF8;
        a.zero = 0;
        func_02012374(evt, func_020124AC(h, (u32)ov008_id, func_021550A0, &a));
        (*state)++;
        break;
    }
    case 5:
        func_020130DC(&w->f08);
        func_02012374(evt, func_02029C00(h));
        (*state)++;
        break;
    case 6:
        func_02012374(evt, func_020145CC(h));
        (*state)++;
        break;
    case 7:
        func_02012374(evt, func_021BE92C(h, w->f04, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 8:
        func_02012374(evt, func_02029CC0(h));
        (*state)++;
        break;
    case 9:
        return 1;
    }
    return 0;
}
