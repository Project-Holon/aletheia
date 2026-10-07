/*
 * file:     fldmmdl_p27.c
 * unit:     yes
 * function: func_0216D9A0, func_0216D9E4, func_0216DA20, func_0216DA30, func_0216DA44, func_0216DA50, func_0216DA5C, func_0216DA70, func_0216DA7C
 * address:  0x0216D9A0
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
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216DC80  0x0216DC80  thumb  ov010
 *   func_0216DAF8  0x0216DAF8  thumb  ov010
 *   func_0216D4DC  0x0216D4DC  thumb  ov010
 *   func_0216DB04  0x0216DB04  thumb  ov010
 *   func_0216D4E4  0x0216D4E4  thumb  ov010
 *   func_0216D67C 0x0216D67C thumb ov010
 *   func_0216D4D4 0x0216D4D4 thumb ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 */
struct Ctx;
struct Rec;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed char    s8;

extern int func_0216DD1C(struct Ctx *c, struct Rec **out, u32 *iter);
extern int func_0216DC80(void *it);
extern void func_0216DAF8(void *it);
extern void func_0216D4DC(void *map, u32 flag);
extern char *func_0216DB04(void *a0);
extern u32 *func_0216D4E4(u32 *p, u32 v);
extern void *func_0216D67C(void *p);
extern int func_0216D4D4(int a0, int a1);
extern int func_0216D55C(int a0, int a1);
extern void *func_0216D568(void *p, u32 v);
extern char *func_0216D570(char *p, u32 v);
extern u32 func_0216D57C(void *p, u32 v);
void func_0216D9A0(void *map);
u32 *func_0216D9E4(void *c);
int func_0216DA20(void *p, unsigned int v);
int func_0216DA30(int a0, int a1);
void func_0216DA44(u32 a);
void func_0216DA50(u8 *p);
int func_0216DA5C(void *a0);
void func_0216DA70(void *a0);
void func_0216DA7C(u8 *p);


void func_0216D9A0(void *map)
{
    u32 pos = 0;
    void *it;

    while (func_0216DD1C(map, (struct Rec **)(&it), &pos) == 1) {
        if (func_0216DC80(it) == 0)
            func_0216DAF8(it);
    }
    func_0216D4DC(map, 0x20);
}


/*
 * Releases every record func_0216DD1C yields, then func_0216D4E4(c, 0x20).
 */
u32 *func_0216D9E4(void *c)
{
    u32 iter;
    void *r;

    iter = 0;
    while (func_0216DD1C(c, (struct Rec **)(&r), &iter) == 1)
        func_0216DB04(r);
    return func_0216D4E4(c, 0x20);
}

int func_0216DA20(void *p, unsigned int v)
{
    return func_0216D4D4((int)func_0216D67C(p), v);
}


int func_0216DA30(int a0, int a1)
{
    int t4;

a1 = 1;
t4 = 1;
    a0 = func_0216D55C(a0, a1);
loc_0216DA3A:
    if (a0 != 0) goto loc_0216DA40;
loc_0216DA3E:
t4 = 0;
loc_0216DA40:
a0 = t4 + 0;
    return a0;}



/*
 * Tail call to func_0216D568 with a masked second argument.
 *
 * Addresses are Black-image addresses.
 */
void func_0216DA44(u32 a)
{
    func_0216D568((void *)a, 0x10);
}


/*
 * Thin wrapper: clear bit 4 of the word at +4 (tail call to func_0216D570).
 *
 * Addresses are Black-image addresses.
 */
void func_0216DA50(u8 *p)
{
func_0216D570((char *)p, 0x10);
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
 *   python tools/match.py one --src src/matched/func_0216DA5C.c \
 *       --func func_0216DA5C --addr 0x0216DA5C --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DA5C(void *a0)
{
    if (func_0216D57C(a0, 16))
        return 1;
    return 0;
}


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_0216D568, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DA70.c \
 *       --func func_0216DA70 --addr 0x0216DA70 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216DA70(void *a0)
{

    func_0216D568(a0, 32);
}


/*
 * Thin wrapper: clear bit 6 of the word at +4 (tail call to func_0216D570).
 *
 * Addresses are Black-image addresses.
 */
void func_0216DA7C(u8 *p)
{
func_0216D570((char *)p, 0x40);
}
