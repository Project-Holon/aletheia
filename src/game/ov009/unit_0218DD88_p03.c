/*
 * file:     unit_0218DD88_p03.c
 * unit:     yes
 * function: func_0218E2DC, func_0218E318
 * address:  0x0218E2DC
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
 *   func_0218AE9C  0x0218AE9C  arm  ov009
 *   func_0218FB68  0x0218FB68  arm  ov009
 *   func_0218FDD8  0x0218FDD8  arm  ov009
 *   func_0218BDB8  0x0218BDB8  arm  ov009
 *   func_0219305C  0x0219305C  arm  ov009
 *   func_0219316C  0x0219316C  arm  ov009
 *   func_0217D254  0x0217D254  arm  ov009
 *   g_021A4E08  0x021A4E08  data
 */
struct GPIOperation_s;
struct GPIOperation {
    int type;
    void *data;
    char pad[0x14];
    int result;
};

extern int func_0218AE9C(void **connection, struct GPIOperation_s *operation, char *input);
extern int func_0218FB68(void **connection, struct GPIOperation_s *operation, char *input);
extern int func_0218FDD8(void **connection, struct GPIOperation_s *operation, char *input);
extern int func_0218BDB8(void **connection, struct GPIOperation_s *operation, char *input);
extern int func_0219305C(void **connection, struct GPIOperation_s *operation, char *input);
extern int func_0219316C(void **connection, struct GPIOperation_s *operation, char *input);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
int func_0218E2DC(char *p);
int func_0218E318(void **connection, struct GPIOperation *operation, char *input);
extern char g_021A4E08[];

/*
 * Walks the +0x5c4 list; true as soon as a node has a non-zero +8 word and
 * a first word other than 3.
 */
int func_0218E2DC(char *p)
{
    char *q = *(char **)(*(char **)p + 0x5c4);

    while (q != 0) {
        if (*(int *)(q + 8) != 0 && *(int *)q != 3) return 1;
        q = *(char **)(q + 0x20);
    }
    return 0;
}


/*
 * sdk:      gpiProcessOperation (libdwcgsgp.TWL.HYB.a(gpioperation.o))
 */
int func_0218E318(void **connection, struct GPIOperation *operation, char *input)
{
    int result = 0;

    switch (operation->type) {
    case 0:
        result = func_0218AE9C(connection, (struct GPIOperation_s *)operation, input);
        break;
    case 1:
        result = func_0218FB68(connection, (struct GPIOperation_s *)operation, input);
        break;
    case 5:
        result = func_0218FDD8(connection, (struct GPIOperation_s *)operation, input);
        break;
    case 2:
        result = func_0218BDB8(connection, (struct GPIOperation_s *)operation, input);
        break;
    case 4:
        result = func_0219305C(connection, (struct GPIOperation_s *)operation, input);
        break;
    case 6:
        result = func_0219316C(connection, (struct GPIOperation_s *)operation, input);
        break;
    default:
        func_0217D254(1, (char *)4, 1, g_021A4E08, operation->type);
        break;
    }
    if (result != 0)
        operation->result = result;
    return result;
}
