/*
 * function: gpiDestroyOperation
 * address:  0x0218E1CC
 * packet:   pkt_ov009_0218E1CC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiDestroyOperation (libdwcgsgp.TWL.HYB.a(gpioperation.o))
 *
 * symbols:
 *   shutdown  0x0217EB9C  arm  ov009
 *   closesocket  0x0217EB2C  arm  ov009
 *   gsifree  0x0217EAE0  arm  ov009
 */

struct GPIConnection {
    char pad[0x238];
    int numSearches;
};

struct GPIOperation {
    int type;
    void *data;
};

struct GPISearchData {
    char pad0[4];
    int sock;
    void *a;
    char pad1[0xc];
    void *b;
};

extern int shutdown(int sock, int how);
extern int closesocket(int sock);
extern void gsifree(void *ptr);

void gpiDestroyOperation(void **connection, struct GPIOperation *operation)
{
    struct GPIConnection *iconnection = (struct GPIConnection *)*connection;

    if (operation->type == 3) {
        struct GPISearchData *data = (struct GPISearchData *)operation->data;

        iconnection->numSearches--;
        shutdown(data->sock, 2);
        closesocket(data->sock);
        gsifree(data->b);
        data->b = 0;
        gsifree(data->a);
        data->a = 0;
    }
    gsifree(operation->data);
    operation->data = 0;
    gsifree(operation);
}
