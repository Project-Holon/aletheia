/*
 * file:     fldmmdl_p28.c
 * unit:     yes
 * function: func_0216DA88, func_0216DA94, func_0216DAA0, func_0216DAB4, func_0216DAC8, func_0216DAE0, func_0216DAF8, func_0216DB04, func_0216DB10, func_0216DB24, func_0216DB4C, func_0216DB68, func_0216DB80, func_0216DB98, func_0216DBB4, func_0216DBCC, func_0216DBE8
 * address:  0x0216DA88
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
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216D548 0x0216D548 thumb ov010
 *   func_0216D550 0x0216D550 thumb ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D948  0x0216D948  thumb  ov010
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void *func_0216D568(void *p, u32 v);
extern char *func_0216D570(char *p, u32 v);
extern u32 func_0216D57C(void *p, u32 v);
extern int func_0216D55C(int a0, int a1);
extern unsigned int *func_0216D548(unsigned int *p, unsigned int v);
extern u32 *func_0216D550(u32 *p, u32 v);
extern void *func_0216D67C(void *a0);
extern int func_0216D948(int a0);
void func_0216DA88(void *a0, unsigned a1, unsigned a2, unsigned a3);
void func_0216DA94(void *a0);
int func_0216DAA0(void *a0);
int func_0216DAB4(void *a0);
void func_0216DAC8(unsigned int *p, unsigned int v);
void func_0216DAE0(unsigned int *p, unsigned int v);
void func_0216DAF8(void *a0);
char *func_0216DB04(void *a0);
int func_0216DB10(void *a0);
int func_0216DB24(int a0);
int func_0216DB4C(void *a0, int a1);
int func_0216DB68(void *a0);
void func_0216DB80(unsigned int *p, unsigned int v);
int func_0216DB98(void *a0, int a1);
int func_0216DBB4(void *a0);
int func_0216DBCC(void *a0, u32 a1, int a2);
int func_0216DBE8(void *a0);


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
 *   python tools/match.py one --src src/matched/func_0216DA88.c \
 *       --func func_0216DA88 --addr 0x0216DA88 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216DA88(void *a0, unsigned a1, unsigned a2, unsigned a3)
{

    func_0216D568(a0, 2);
}


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_0216D570, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DA94.c \
 *       --func func_0216DA94 --addr 0x0216DA94 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216DA94(void *a0)
{

    func_0216D570(a0, 2);
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
 *   python tools/match.py one --src src/matched/func_0216DAA0.c \
 *       --func func_0216DAA0 --addr 0x0216DAA0 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DAA0(void *a0)
{
    if (func_0216D57C(a0, 2))
        return 1;
    return 0;
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
 *   python tools/match.py one --src src/matched/func_0216DAB4.c \
 *       --func func_0216DAB4 --addr 0x0216DAB4 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DAB4(void *a0)
{
    if (func_0216D55C((int)a0, 4))
        return 1;
    return 0;
}

void func_0216DAC8(unsigned int *p, unsigned int v)
{
    if (v == 1) func_0216D548(p, 4);
    else func_0216D550(p, 4);
}

void func_0216DAE0(unsigned int *p, unsigned int v)
{
    if (v == 1) func_0216D550(p, 128);
    else func_0216D548(p, 128);
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
 *   python tools/match.py one --src src/matched/func_0216DAF8.c \
 *       --func func_0216DAF8 --addr 0x0216DAF8 --region ov010 --cc dsi/1.1p1 --thumb
 */
void func_0216DAF8(void *a0)
{

    func_0216D568(a0, 8);
}


/*
 * generated: lane O24 (ov010 leaf/wrapper sweep)
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into func_0216D570, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216DB04.c \
 *       --func func_0216DB04 --addr 0x0216DB04 --region ov010 --cc dsi/1.1p1 --thumb
 */
char *func_0216DB04(void *a0)
{

    return func_0216D570(a0, 8);
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
 *   python tools/match.py one --src src/matched/func_0216DB10.c \
 *       --func func_0216DB10 --addr 0x0216DB10 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DB10(void *a0)
{
    if (func_0216D57C(a0, 8))
        return 1;
    return 0;
}


int func_0216DB24(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = (int)func_0216D67C((void *)a0);
loc_0216DB2C:
    a0 = func_0216D948(a0);
loc_0216DB30:
    if (a0 != 0) goto loc_0216DB38;
loc_0216DB34:
a0 = 0;
    return a0;
loc_0216DB38:
a0 = t4 + 0;
    a0 = func_0216DAA0((void *)a0);
loc_0216DB3E:
    if (a0 == 0) goto loc_0216DB46;
loc_0216DB42:
a0 = 1;
    return a0;
loc_0216DB46:
a0 = 0;
    return a0;}


/*
 * The first argument picks which of the pair of field setters
 * takes the shifted mask and the value.
 */
int func_0216DB4C(void *a0, int a1)
{
    if (a1 == 1)
        return (int)func_0216D548(a0, 0x200);

    return (int)func_0216D550(a0, 0x200);
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
 *   python tools/match.py one --src src/matched/func_0216DB68.c \
 *       --func func_0216DB68 --addr 0x0216DB68 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DB68(void *a0)
{
    if (func_0216D55C((int)a0, 512))
        return 1;
    return 0;
}

void func_0216DB80(unsigned int *p, unsigned int v)
{
    if (v == 1) func_0216D548(p, 32);
    else func_0216D550(p, 32);
}


int func_0216DB98(void *a0, int a1)
{
    int a2;
    if (a1 == 1)
        return (int)func_0216D548(a0, 0x800);

    return (int)func_0216D550(a0, 0x800);
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
 *   python tools/match.py one --src src/matched/func_0216DBB4.c \
 *       --func func_0216DBB4 --addr 0x0216DBB4 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DBB4(void *a0)
{
    if (func_0216D55C((int)a0, 2048))
        return 1;
    return 0;
}


int func_0216DBCC(void *a0, u32 a1, int a2)
{
    if (a1 == 1)
        return (int)func_0216D568(a0, 0x40000);

    return (int)func_0216D570(a0, 0x40000);
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
 *   python tools/match.py one --src src/matched/func_0216DBE8.c \
 *       --func func_0216DBE8 --addr 0x0216DBE8 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DBE8(void *a0)
{
    if (func_0216D57C(a0, 262144))
        return 1;
    return 0;
}
