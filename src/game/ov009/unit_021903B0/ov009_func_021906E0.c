/*
 * function: func_021906E0
 * address:  0x021906E0
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * gpiProfileSearch: reject the call when no criterion is supplied (nick,
 * email, firstname, lastname, icquin, uniquenick all empty), otherwise
 * create a GPI_SEARCH_PROFILE search object (func_021905A4), copy the
 * criteria into it, lower-case the e-mail, and start the search.
 *
 * Symbols in the search data: nick +0x28, uniquenick +0x47, email +0xa0,
 * firstname +0xd3, lastname +0xf2, icquin +0x178, skip +0x17c.
 *
 * symbols:
 *   func_02193734  0x02193734  arm  ov009
 *   func_021905A4  0x021905A4  arm  ov009
 *   func_0219327C  0x0219327C  arm  ov009
 *   func_0217F21C  0x0217F21C  arm  ov009
 *   func_02190650  0x02190650  arm  ov009
 *   g_021A5344     0x021A5344  data ov009
 */

typedef struct {
    char *buffer;
    int size;
    int len;
    int pos;
} GPIBuffer;

typedef struct {
    int type;
    int sock;
    GPIBuffer inputBuffer;
    GPIBuffer outputBuffer;
    char nick[0x1f];
    char uniquenick[0x59];
    char email[0x33];
    char firstname[0x1f];
    char lastname[0x86];
    int icquin;
    int skip;
} GPISearchData;

extern void func_02193734(int *connection, int string);
extern int func_021905A4(int *connection, GPISearchData **out, int type);
extern void func_0219327C(char *p, int b, int n);
extern char *func_0217F21C(char *s);
extern int func_02190650(void *a, int a1, int a2, int a3, int a4);
extern char g_021A5344[];

int func_021906E0(int *connection, char *nick, char *uniquenick, char *email,
                  char *firstname, char *lastname, int icquin, int skip,
                  int blocking, int callback, int param)
{
    GPISearchData *data;
    int result;

    if ((nick == 0) || (*nick == 0))
        if ((email == 0) || (*email == 0))
            if ((firstname == 0) || (*firstname == 0))
                if ((lastname == 0) || (*lastname == 0))
                    if (icquin == 0)
                        if ((uniquenick == 0) || (*uniquenick == 0)) {
                            func_02193734(connection, (int)g_021A5344);
                            return 2;
                        }

    result = func_021905A4(connection, &data, 1);
    if (result != 0)
        return result;

    if (nick == 0)
        data->nick[0] = 0;
    else
        func_0219327C(data->nick, (int)nick, 0x1f);
    if (uniquenick == 0)
        data->uniquenick[0] = 0;
    else
        func_0219327C(data->uniquenick, (int)uniquenick, 0x15);
    if (email == 0)
        data->email[0] = 0;
    else
        func_0219327C(data->email, (int)email, 0x33);
    func_0217F21C(data->email);
    if (firstname == 0)
        data->firstname[0] = 0;
    else
        func_0219327C(data->firstname, (int)firstname, 0x1f);
    if (lastname == 0)
        data->lastname[0] = 0;
    else
        func_0219327C(data->lastname, (int)lastname, 0x1f);

    data->icquin = icquin;
    if (skip < 0)
        skip = 0;
    data->skip = skip;

    result = func_02190650(connection, (int)data, blocking, callback, param);
    if (result != 0)
        return result;
    return 0;
}
