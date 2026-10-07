/*
 * file:     fldmmdl_p30.c
 * unit:     yes
 * function: func_0216DCCC, func_0216DCE8, func_0216DD04, func_0216DD1C
 * address:  0x0216DCCC
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
 *   func_0216D568   0x0216D568  thumb  ov010
 *   func_0216D570   0x0216D570  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_0216D4F0  0x0216D4F0  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Rec {
    u8 data[0x100];
} Rec;

typedef struct Ctx {
    u8 pad[0x18];
    Rec *recs;
} Ctx;

extern void *func_0216D568(void *p, u32 v);
extern char *func_0216D570(char *p, u32 v);
extern u32 func_0216D57C(void *p, u32 v);
extern u16 func_0216D4F0(void *p);
extern int func_0216D55C(int a0, int a1);
int func_0216DCCC(void *a0, int a1);
int func_0216DCE8(void *a0, int a1);
int func_0216DD04(void *a0);
int func_0216DD1C(Ctx *c, Rec **out, u32 *iter);


/*
 * The first argument picks which of the pair of field setters
 * takes the shifted mask and the value.
 */
int func_0216DCCC(void *a0, int a1)
{
    int a2;
    if (a1 == 1)
        return (int)func_0216D568(a0, 0x100000);

    return (int)func_0216D570(a0, 0x100000);
}


int func_0216DCE8(void *a0, int a1)
{
    int a2;
    if (a1 == 1)
        return (int)func_0216D568(a0, 0x200000);

    return (int)func_0216D570(a0, 0x200000);
}


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Boolean-and-call leaf: a one-line predicate test over a
 * call whose result the compiler keeps in r0.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DD04.c \
 *       --func func_0216DD04 --addr 0x0216DD04 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DD04(void *a0)
{
    if (func_0216D57C(a0, 2097152))
        return 1;
    return 0;
}


/*
 * Iterator: advances *iter over the 0x100-byte records at +0x18 and
 * returns TRUE with *out set at the next record func_0216D55C accepts.
 */
int func_0216DD1C(Ctx *c, Rec **out, u32 *iter)
{
    u32 n;
    Rec *r;

    n = func_0216D4F0(c);
    if (*iter < n) {
        r = &c->recs[*iter];
        do {
            (*iter)++;
            if (func_0216D55C((int)r, 1)) {
                *out = r;
                return 1;
            }
            r++;
        } while (*iter < n);
    }
    return 0;
}
