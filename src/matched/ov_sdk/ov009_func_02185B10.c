/*
 * function: gpProfileSearchA
 * address:  0x02185B10
 * packet:   pkt_ov009_02185B10
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpProfileSearchA (gp.o)
 *
 * symbols:
 *   gpiSetErrorString  0x02193734  arm   ov009
 *   gpiProfileSearch  0x021906E0  arm   ov009
 *   g_021A4010     0x021A4010  data  ov009
 */

typedef struct GPIConnection {
    unsigned char pad0[0x108];
    int f108;
} GPIConnection;

typedef struct GPProfileSearchResponseArg {
    int a;
    int b;
    int c;
    int d;
} GPProfileSearchResponseArg;

typedef void (*GPCallback)(void **, void *, void *);

extern void gpiSetErrorString(int *p, int b);
extern int gpiProfileSearch(int *connection, char *nick, char *uniquenick, char *email, char *firstname, char *lastname, int icquin, int skip, int blocking, int callback, int param);
extern char g_021A4010[];

int gpProfileSearchA(void **connection, char *nick, char *uniquenick, char *email,
                  char *firstname, char *lastname, int icquin, int blocking,
                  GPCallback callback, void *param)
{
    GPIConnection *iconnection;

    if (connection == 0 || (iconnection = (GPIConnection *)*connection) == 0)
        return 2;
    if (callback == 0) {
        gpiSetErrorString((int *)connection, (int)g_021A4010);
        return 2;
    }
    if (iconnection->f108 != 0) {
        GPProfileSearchResponseArg arg = {0};
        arg.c = 0x601;
        callback(connection, &arg, param);
        return 0;
    }
    return gpiProfileSearch((int *)connection, nick, uniquenick, email, firstname, lastname, icquin, 0,
                         blocking, (int)callback, (int)param);
}
