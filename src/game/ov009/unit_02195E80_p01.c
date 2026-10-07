/*
 * file:     unit_02195E80_p01.c
 * unit:     yes
 * function: func_02195E80, func_02195EA0, func_02195EB4, func_02195EC4, func_02195F5C, func_02195F70
 * address:  0x02195E80
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   gti2ConnectionClosed   0x021959D0  arm  ov009
 *   gti2ConnectedCallback  0x0219500C  arm  ov009
 *   gti2ClosedCallback     0x02195158  arm  ov009
 *   func_02195EC4  0x02195EC4  arm  ov009
 *   gti2SendClosed       0x02197BB8 arm
 */
struct GTI2Connection;
typedef short s16;

struct GTI2Connection {
    char pad00[8];
    void *socket;
    int state;
    int field_10;
    int field_14;
};

extern void gti2ConnectionClosed(struct GTI2Connection *connection);
extern int gti2ConnectedCallback(struct GTI2Connection *connection, int result,
                                 unsigned char *message, int len);
extern int gti2ClosedCallback(struct GTI2Connection *connection, int reason);
extern void func_02195EC4(int a, int b, int c);
extern int gti2SendClosed(struct GTI2Connection *connection);
void func_02195EA0(char *p, int i, int v);
s16 func_02195EB4(s16 a, s16 b);
void func_02195F5C(int a);

static unsigned short gti2UShortFromBuffer(unsigned char * buffer, int pos)
{
    unsigned short s;
    s = (unsigned short)((buffer[pos] << 8) & 0xff00);
    s |= buffer[pos + 1];
    return s;
}

/*
 * Stores a word big-endian at p[i].
 */
void func_02195EA0(char *p, int i, int v)
{
    p[i] = (char)(v >> 8);
    p[i + 1] = (char)v;
}


/*
 * Halfword difference, sign extended.
 */
s16 func_02195EB4(s16 a, s16 b)
{
    return (s16)(a - b);
}


static int gti2ConnectionError(struct GTI2Connection *connection,
                               int result, int reason)
{
    if (connection->state < 5)
    {
        if (connection->field_10 != 0)
        {
            gti2ConnectionClosed(connection);
            reason = 0;
            if (gti2ConnectedCallback(connection, result, 0, 0) == 0)
                return 0;
            goto ret1;
        }
        if (connection->state == 4)
            connection->field_14 = 1;
        gti2ConnectionClosed(connection);
    }
    else
    {
        if (connection->state != 7)
        {
            gti2ConnectionClosed(connection);
            if (gti2ClosedCallback(connection, reason) == 0)
                return 0;
        }
    }
ret1:
    return 1;
}


/*
 * Tail call with the constant argument pair (7, 2).
 */
void func_02195F5C(int a)
{
    func_02195EC4(a, 7, 2);
}


static int gti2ConnectionMemoryError(struct GTI2Connection *connection)
{
    if (gti2SendClosed(connection) == 0)
        return 0;
    return gti2ConnectionError(connection, 1, 4);
}
