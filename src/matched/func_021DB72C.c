/*
 * function: func_021DB72C
 * address:  0x021DB72C
 * packet:   pkt_021DB72C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203F028  0x0203F028  arm
 *   d_021E2F70     0x021E2F70  data
 *
 * Storage-server records callback: forwards the records to the user callback at +0x17c, then, when no record id is pending (+0x1b0 == -1), scans every field of every record for the id field and stores its value through the pointer at +0x1464.
 */

typedef unsigned long u32;

struct Field {
    const char *name;
    u32 type;
    u32 value;
    u32 pad;
};

typedef void (*RecordsFn)(int count, struct Field **recs, u32 a, int nfields);

extern int func_0203F028(const char *s1, const char *s2);
extern const char d_021E2F70[];

void func_021DB72C(int count, struct Field **recs, char *obj)
{
    int i, j;
    struct Field *f;

    (*(RecordsFn *)(obj + 0x17c))(count, recs, *(u32 *)(obj + 0x178), *(int *)(obj + 0x198));
    if (*(int *)(obj + 0x1b0) != -1)
        return;
    for (i = 0; i < count; i++) {
        for (j = 0; j < *(int *)(obj + 0x198); j++) {
            f = &recs[i][j];
            if (func_0203F028(f->name, d_021E2F70) == 0)
                **(u32 **)(obj + 0x1464) = f->value;
        }
    }
}
