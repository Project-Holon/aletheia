/*
 * file:     fldmmdl_p29.c
 * unit:     yes
 * function: func_0216DC00, func_0216DC18, func_0216DC34, func_0216DC4C, func_0216DC64, func_0216DC80, func_0216DC98, func_0216DCB4
 * address:  0x0216DC00
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
 *   func_0216D55C  0x0216D55C  thumb  ov010
 *   func_0216D568   0x0216D568  thumb  ov010
 *   func_0216D570   0x0216D570  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_0216D548   0x0216D548  thumb  ov010
 *   func_0216D550   0x0216D550  thumb  ov010
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern int func_0216D55C(int a0, int a1);
extern void *func_0216D568(void *p, u32 v);
extern char *func_0216D570(char *p, u32 v);
extern u32 func_0216D57C(void *p, u32 v);
extern u32 *func_0216D548(u32 *p, u32 v);
extern u32 *func_0216D550(u32 *p, u32 v);
int func_0216DC00(void *a0);
int func_0216DC18(void *a0, int a1);
int func_0216DC34(void *a0);
int func_0216DC4C(void *a0);
int func_0216DC64(void *a0, int a1);
int func_0216DC80(void *a0);
int func_0216DC98(void *a0, int a1);
int func_0216DCB4(void *a0);


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
 *   python tools/match.py one --src src/matched/func_0216DC00.c \
 *       --func func_0216DC00 --addr 0x0216DC00 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DC00(void *a0)
{
    if (func_0216D55C((int)a0, 4096))
        return 1;
    return 0;
}


/*
 * The first argument picks which of the pair of field setters
 * takes the shifted mask and the value.
 */
int func_0216DC18(void *a0, int a1)
{
    int a2;
    if (a1 == 1)
        return (int)func_0216D568(a0, 0x20000);

    return (int)func_0216D570(a0, 0x20000);
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
 *   python tools/match.py one --src src/matched/func_0216DC34.c \
 *       --func func_0216DC34 --addr 0x0216DC34 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DC34(void *a0)
{
    if (func_0216D57C(a0, 131072))
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
 *   python tools/match.py one --src src/matched/func_0216DC4C.c \
 *       --func func_0216DC4C --addr 0x0216DC4C --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DC4C(void *a0)
{
    if (func_0216D57C(a0, 512))
        return 1;
    return 0;
}


int func_0216DC64(void *a0, int a1)
{
    int a2;
    if (a1 == 1)
        return (int)func_0216D568(a0, 0x80000);

    return (int)func_0216D570(a0, 0x80000);
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
 *   python tools/match.py one --src src/matched/func_0216DC80.c \
 *       --func func_0216DC80 --addr 0x0216DC80 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DC80(void *a0)
{
    if (func_0216D57C(a0, 524288))
        return 1;
    return 0;
}


int func_0216DC98(void *a0, int a1)
{
    int a2;
    if (a1 == 1)
        return (int)func_0216D548(a0, 0x400);

    return (int)func_0216D550(a0, 0x400);
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
 *   python tools/match.py one --src src/matched/func_0216DCB4.c \
 *       --func func_0216DCB4 --addr 0x0216DCB4 --region ov010 --cc dsi/1.1p1 --thumb
 */
int func_0216DCB4(void *a0)
{
    if (func_0216D55C((int)a0, 1024))
        return 1;
    return 0;
}
