/*
 * function: func_021DE840
 * address:  0x021DE840
 * packet:   pkt_ov175_021DE840
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      sakeiFreeOutputRecord (libdwcgssake.TWL.HYB.a(sakerequestread.o))
 *
 * symbols:
 *   func_0217EAE0  0x0217EAE0  arm  ov175
 */

extern void func_0217EAE0(void *ptr);

struct SAKEField {
    char *name;
    int type;
    void *value;
    int pad;
};

void func_021DE840(int numFields, struct SAKEField *record)
{
    int i;

    if (record == 0)
        return;
    for (i = 0; i < numFields; i++) {
        if (record[i].type == 8 && record[i].value != 0)
            func_0217EAE0(record[i].value);
        if (record[i].type == 5)
            func_0217EAE0(record[i].value);
    }
    func_0217EAE0(record);
}
