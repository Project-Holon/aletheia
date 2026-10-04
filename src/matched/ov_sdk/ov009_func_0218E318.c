/*
 * function: func_0218E318
 * address:  0x0218E318
 * packet:   pkt_ov009_0218E318
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiProcessOperation (libdwcgsgp.TWL.HYB.a(gpioperation.o))
 *
 * symbols:
 *   func_0218AE9C  0x0218AE9C  arm  ov009
 *   func_0218FB68  0x0218FB68  arm  ov009
 *   func_0218FDD8  0x0218FDD8  arm  ov009
 *   func_0218BDB8  0x0218BDB8  arm  ov009
 *   func_0219305C  0x0219305C  arm  ov009
 *   func_0219316C  0x0219316C  arm  ov009
 *   func_0217D254  0x0217D254  arm  ov009
 *   g_021A4E08  0x021A4E08  data
 */

struct GPIOperation {
    int type;
    void *data;
    char pad[0x14];
    int result;
};

extern int func_0218AE9C(void **connection, struct GPIOperation *operation, char *input);
extern int func_0218FB68(void **connection, struct GPIOperation *operation, char *input);
extern int func_0218FDD8(void **connection, struct GPIOperation *operation, char *input);
extern int func_0218BDB8(void **connection, struct GPIOperation *operation, char *input);
extern int func_0219305C(void **connection, struct GPIOperation *operation, char *input);
extern int func_0219316C(void **connection, struct GPIOperation *operation, char *input);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern char g_021A4E08[];

int func_0218E318(void **connection, struct GPIOperation *operation, char *input)
{
    int result = 0;

    switch (operation->type) {
    case 0:
        result = func_0218AE9C(connection, operation, input);
        break;
    case 1:
        result = func_0218FB68(connection, operation, input);
        break;
    case 5:
        result = func_0218FDD8(connection, operation, input);
        break;
    case 2:
        result = func_0218BDB8(connection, operation, input);
        break;
    case 4:
        result = func_0219305C(connection, operation, input);
        break;
    case 6:
        result = func_0219316C(connection, operation, input);
        break;
    default:
        func_0217D254(1, (char *)4, 1, g_021A4E08, operation->type);
        break;
    }
    if (result != 0)
        operation->result = result;
    return result;
}
