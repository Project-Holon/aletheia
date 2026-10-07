/*
 * file:     unit_021C2284_p01.c
 * unit:     yes
 * function: func_021C22A4, func_021C22D4
 * address:  0x021C22A4
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
 *   ghiCloseConnection      0x021C0B4C arm ov114
 *   func_021C0DA4  0x021C0DA4  arm  ov114
 */
typedef struct GHIConnection {
    char pad0[0x10];
    int state;
    char pad1[0x2C];
    int completed;
    char pad2[0xE0];
    int cancelled;
} GHIConnection;

typedef unsigned char u8;

typedef unsigned int u32;

extern GHIConnection *ghiRequestToConnection(int request);
extern int ghiCloseConnection(GHIConnection *connection);
extern u8 *func_021C0DA4(void);
void func_021C22A4(int request);
int func_021C22D4(int request);


/*
 * sdk:      ghttpCancelRequest (ghttpmain)
 */
void func_021C22A4(int request)
{
    GHIConnection *connection = ghiRequestToConnection(request);
    if (connection == 0)
        return;
    connection->completed = 18;
    connection->state = 11;
    connection->cancelled = 1;
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
