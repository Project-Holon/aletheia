/*
 * function: func_0218E1CC
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
 *   func_0217EB9C  0x0217EB9C  arm  ov009
 *   closesocket  0x0217EB2C  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
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

extern int func_0217EB9C(int sock, int how);
extern int closesocket(int sock);
extern void func_0217EAE0(void *ptr);

void func_0218E1CC(void **connection, struct GPIOperation *operation)
{
    struct GPIConnection *iconnection = (struct GPIConnection *)*connection;

    if (operation->type == 3) {
        struct GPISearchData *data = (struct GPISearchData *)operation->data;

        iconnection->numSearches--;
        func_0217EB9C(data->sock, 2);
        closesocket(data->sock);
        func_0217EAE0(data->b);
        data->b = 0;
        func_0217EAE0(data->a);
        data->a = 0;
    }
    func_0217EAE0(operation->data);
    operation->data = 0;
    func_0217EAE0(operation);
}
