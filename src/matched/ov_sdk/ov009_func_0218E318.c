/*
 * function: gpiProcessOperation
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
 *   gpiProcessConnect  0x0218AE9C  arm  ov009
 *   gpiProcessNewProfile  0x0218FB68  arm  ov009
 *   gpiProcessDeleteProfle  0x0218FDD8  arm  ov009
 *   gpiProcessGetInfo  0x0218BDB8  arm  ov009
 *   gpiProcessRegisterUniqueNick  0x0219305C  arm  ov009
 *   gpiProcessRegisterCdKey  0x0219316C  arm  ov009
 *   gsDebugFormat  0x0217D254  arm  ov009
 *   g_021A4E08  0x021A4E08  data
 */

struct GPIOperation {
    int type;
    void *data;
    char pad[0x14];
    int result;
};

struct GPIOperation_s;
extern int gpiProcessConnect(void **connection, struct GPIOperation_s *operation, char *input);
extern int gpiProcessNewProfile(void **connection, struct GPIOperation_s *operation, char *input);
extern int gpiProcessDeleteProfle(void **connection, struct GPIOperation_s *operation, char *input);
extern int gpiProcessGetInfo(void **connection, struct GPIOperation_s *operation, char *input);
extern int gpiProcessRegisterUniqueNick(void **connection, struct GPIOperation_s *operation, char *input);
extern int gpiProcessRegisterCdKey(void **connection, struct GPIOperation_s *operation, char *input);
extern int gsDebugFormat(int index, char *table, int mask, const char *fmt, ...);
extern char g_021A4E08[];

int gpiProcessOperation(void **connection, struct GPIOperation *operation, char *input)
{
    int result = 0;

    switch (operation->type) {
    case 0:
        result = gpiProcessConnect(connection, (struct GPIOperation_s *)operation, input);
        break;
    case 1:
        result = gpiProcessNewProfile(connection, (struct GPIOperation_s *)operation, input);
        break;
    case 5:
        result = gpiProcessDeleteProfle(connection, (struct GPIOperation_s *)operation, input);
        break;
    case 2:
        result = gpiProcessGetInfo(connection, (struct GPIOperation_s *)operation, input);
        break;
    case 4:
        result = gpiProcessRegisterUniqueNick(connection, (struct GPIOperation_s *)operation, input);
        break;
    case 6:
        result = gpiProcessRegisterCdKey(connection, (struct GPIOperation_s *)operation, input);
        break;
    default:
        gsDebugFormat(1, (char *)4, 1, g_021A4E08, operation->type);
        break;
    }
    if (result != 0)
        operation->result = result;
    return result;
}
