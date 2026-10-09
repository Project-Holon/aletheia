/*
 * file:     unit_021C2284_p01.c
 * unit:     yes
 * function: func_021C2284, func_021C22A4, func_021C22D4, func_021C22EC
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
 */
#include "ghttp_types.h"

extern GHIConnection *ghiRequestToConnection(int request);
extern int ghiProcessConnection(GHIConnection *connection);
extern int ghiCloseConnection(GHIConnection *connection);
extern u8 *func_021C0DA4();
int func_021C2284(int request);
void func_021C22A4(int request);
int func_021C22D4(int request);
void func_021C22EC(int a, int b);


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
