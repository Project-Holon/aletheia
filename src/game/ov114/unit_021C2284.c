/*
 * file:     unit_021C2284.c
 * unit:     yes
 * function: func_021C2284, func_021C22A4, func_021C22D4, func_021C22EC, func_021C2304, func_021C2310, func_021C2324, func_021C2338
 * address:  0x021C2284
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   ghiRequestToConnection  0x021C0DA4 arm ov114
 *   ghiProcessConnection    0x021C1DEC arm ov114
 *   ghiCloseConnection      0x021C0B4C arm ov114
 *   func_021C0DA4  0x021C0DA4  arm  ov114
 *   func_021C23E4  0x021C23E4  arm  ov114
 *   func_021C245C  0x021C245C  arm  ov114
 *   func_021C2490  0x021C2490  arm  ov114
 *   func_021C2584  0x021C2584  arm  ov114
 */
#include "ghttp_types.h"

typedef unsigned char u8;

typedef unsigned int u32;

extern GHIConnection *ghiRequestToConnection(int request);
extern int ghiProcessConnection(GHIConnection *connection);
extern int ghiCloseConnection(GHIConnection *connection);
extern u8 *func_021C0DA4();
extern void *func_021C23E4(void);
extern void func_021C245C(u8 *p, u32 v);
extern void func_021C2490(int, int);
extern int func_021C2584(void *post, void *xml);
int func_021C2284(int request);
void func_021C22A4(int request);
int func_021C22D4(int request);
void func_021C22EC(int a, int b);
void *func_021C2304(void);
void func_021C2310(u8 *a, u32 a1);
void func_021C2324(int a, int b);
int func_021C2338(void *post, void *xml);



/*
 * sdk:      ghttpRequestThink (ghttpmain)
 */
int func_021C2284(int request)
{
    GHIConnection *connection = ghiRequestToConnection(request);
    if (connection == 0)
        return 0;
    ghiProcessConnection(connection);
    return 1;
}



/*
 * sdk:      ghttpCancelRequest (ghttpmain)
 */
void func_021C22A4(int request)
{
    GHIConnection *connection = ghiRequestToConnection(request);
    if (connection == 0)
        return;
    connection->result = 18;
    connection->state = 11;
    connection->completed = 1;
    ghiCloseConnection(connection);
}



/*
 * Current object's +0x10 word, or 0 when nothing is selected.
 */
int func_021C22D4(int request)
{
    u8 *p = func_021C0DA4();
    if (p != 0)
        return *(u32 *)(p + 0x10);
    return 0;
}



/*
 * Stores `b` into the +0x188 field of the object selected by `a`.
 */
void func_021C22EC(int a, int b)
{
    u8 *p = func_021C0DA4(a);
    if (p != 0)
        *(u32 *)(p + 0x188) = b;
}


void *func_021C2304(void)
{
    return func_021C23E4();
}



/*
 * Null-guarded release of the object at `a`.
 */
void func_021C2310(u8 *a, u32 a1)
{
    if (a == 0)
        return;
    func_021C245C(a, a1);
}



/*
 * Null-guarded keyed apply of `b` onto object `a`.
 */
void func_021C2324(int a, int b)
{
    if (b == 0)
        return;
    func_021C2490(a, b);
}


int func_021C2338(void *post, void *xml)
{
    return func_021C2584(post, xml);
}
