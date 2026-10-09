/*
 * file:     net_state_p11.c
 * unit:     yes
 * function: func_0203A634, func_0203A67C, func_0203A70C, func_0203A730, func_0203A748, func_0203A770, func_0203A7EC, func_0203A804, func_0203A81C, func_0203A858
 * address:  0x0203A634
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02039338  0x02039338  arm
 *   g_020A7AE8     0x020A7AE8  data
 *   g_020A7AE8_arr 0x020A7AE8  data
 *   g_020A7AF8     0x020A7AF8  data
 *   g_020A7B08     0x020A7B08  data
 *   g_021469D8     0x021469D8  data
 *   func_02034714  0x02034714  arm
 *   func_020399B8 0x020399B8  arm
 */
struct BaseTable;
typedef unsigned int u32;

typedef unsigned short u16;

struct BaseTable {
    void *list;
    int   listNum;
};

struct HugeRecv {
    u32 a;
    int count;
    u32 c;
    u32 key;
};

typedef unsigned char u8;

extern u16 func_02039338(void);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_020399B8(u8 *p);
u32 func_0203A634(u32 a0);
struct BaseTable *func_0203A67C(u32 cmd);
int func_0203A70C(u32 idx);
u32 func_0203A730(u32 cmd);
int func_0203A748(u32 idx);
void func_0203A770(u32 a, u32 b, int c, u32 d, u32 e, u32 f);
int func_0203A7EC(unsigned int idx);
int func_0203A804(unsigned int idx);
u32 func_0203A81C(u32 a0, u32 a1, u32 a2);
extern struct BaseTable g_020A7AE8;
extern void  *g_020A7AE8_arr[];
extern char   g_020A7AF8[];
extern char   g_020A7B08[];
extern struct HugeRecv *g_021469D8;



/*
 * Bit test against a channel mask: 0xFF is always live, otherwise the bit of
 * the argument named by the index func_02039338() reports decides, and a zero
 * index falls back to the 0x80 bit.  `1 << f()` is emitted as the shifted
 * register of a `tst`, and each success path is the conditional
 * `movne r0, #1` / `popne` pair, so the source is the return chain above a
 * final plain `return 0;`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A634.c \
 *       --func func_0203A634 --addr 0x0203A634 --cc 1.1p1 --arm
 */
u32 func_0203A634(u32 a0)
{
    if (a0 == 0xFF)
        return 1;
    if (a0 & (1 << func_02039338()))
        return 1;
    if (func_02039338() == 0 && (a0 & 0x80) != 0)
        return 1;
    return 0;
}



/*
 * net_command.c's command-record lookup.  The 16-bit command is split into
 * a group (the high byte, kept unshifted throughout: the original compares
 * the masked value, never a shifted one) and an index (the low byte).
 *
 * Group 0 is the static base table at 0x020A7AE8 -- a { void *list; int
 * listNum; } pair whose strings name it "_BaseTable" (the assert text at
 * 0x020A7B08 reads "_BaseTable.listNum > co...", 0x020A7AF8 is
 * "net_command.c", and the line number is 0x10D).  listNum is SIGNED: the
 * guard is `bgt`, not `bhi`.
 *
 * Any other group scans the four 0x10-byte records behind the pointer at
 * 0x021469D8, the _pCommandWork context src/matched/func_0203A494.c
 * allocates; the second assert string at 0x020A7B20 names those records
 * "_pCommandWork->aNetHugeRecv[index].used".
 *
 * TWO POOL WORDS FOR ONE ADDRESS.  The original spends two separate pool
 * entries on 0x020A7AE8 (at +0x78 and +0x88).  It is one object reached by
 * two declarations: the `.listNum` guard reads the struct, while the
 * returned pointer is the list base spelled as an array.  Collapsing them
 * into a single `&g_020A7AE8` makes the file 140 bytes, four short.
 *
 * DECLARATION ORDER.  `int i` must be declared BEFORE the two masks, and
 * the index must be `int`, not `u32`.  With the masks first the 3-register
 * rotation r2 -> ip -> r3 -> r2 appears and nothing else moves it (found by
 * tools/permuter.py: decl-order(lo<->i) ; decl-order(hi<->i)).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A67C.c \
 *       --func func_0203A67C --addr 0x0203A67C --cc 1.1p1 --arm
 */
struct BaseTable *func_0203A67C(u32 cmd)
{
    int i;
    u32 hi = cmd & 0xff00;
    int lo = (int)(cmd & 0xff);

    if (hi == 0) {
        if (g_020A7AE8.listNum <= lo)
            func_02034714(g_020A7AF8, 0x10D, g_020A7B08);
        return (struct BaseTable *)g_020A7AE8_arr;
    }
    for (i = 0; i < 4; i++) {
        struct HugeRecv *r = g_021469D8 + i;
        if (hi == r->key) {
            if (r->count <= lo)
                return 0;
            return (struct BaseTable *)r;
        }
    }
    return 0;
}



int func_0203A70C(u32 idx)
{
    int *p = (int *)func_0203A67C(idx);
    if (p != 0) {
        char *base = (char *)*p;
        u32 off = ((idx << 24) >> 21);
        return *(int *)(base + off);
    }
    return 0;
}



/*
 * The null-tolerant third word of the object func_0203A67C caches: the
 * conditional `ldrne` / `moveq` pair is exactly the `? :` form, not an
 * if/return, which would have needed a second epilogue.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A730.c \
 *       --func func_0203A730 --addr 0x0203A730 --cc 1.1p1 --arm
 */
u32 func_0203A730(u32 cmd)
{
    u32 *p = (u32 *)func_0203A67C(cmd);

    return p != 0 ? p[2] : 0;
}



int func_0203A748(u32 idx)
{
    int *p = (int *)func_0203A67C(idx);
    if (p != 0) {
        char *base = (char *)*p;
        u32 off = ((idx << 24) >> 21);
        return *(int *)(base + off + 4);
    }
    return 0;
}



void func_0203A770(u32 a, u32 b, int c, u32 d, u32 e, u32 f)
{
    u32 ok;
    u32 fn;

    if (func_0203A634(b) == 0) {
        return;
    }
    ok = 1;
    if (func_020399B8((u8 *)f) == 0) {
        if (c >= 0x11) {
            ok = 0;
        }
    }
    if (ok == 0) {
        return;
    }
    fn = func_0203A70C(c);
    if (fn == 0) {
        return;
    }
    ((void (*)(u32, u32, u32, u32, u32))fn)(a, d, e, func_0203A730(c), f);
}



int func_0203A7EC(unsigned int idx)
{
    return func_0203A70C(idx) != 0;
}



int func_0203A804(unsigned int idx)
{
    return func_0203A748(idx) != 0;
}



/*
 * Indirect dispatch: the first argument names a slot whose function pointer
 * comes back from func_0203A748; a null slot answers 0 with the conditional
 * `moveq`/`popeq` pair, and otherwise the pointer is called with the second
 * argument, the current value func_0203A730 reports and the third argument.
 * func_0203A730's own body ignores its parameter, but the caller still loads
 * one, so the source declares it with a parameter.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A81C.c \
 *       --func func_0203A81C --addr 0x0203A81C --cc 1.1p1 --arm
 */
u32 func_0203A81C(u32 a0, u32 a1, u32 a2)
{
    u32 (*f)(u32, u32, u32) = (u32 (*)(u32, u32, u32))func_0203A748(a0);

    if (f == 0)
        return 0;
    return f(a1, func_0203A730(a0), a2);
}


void func_0203A858(void);

void func_0203A858(void)
{
}
