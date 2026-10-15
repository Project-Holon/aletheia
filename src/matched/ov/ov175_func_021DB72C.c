/*
 * function: WIFIBATTLEMATCH_NET_GdbSortByName
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
 *   GF_STANDARD_CompareString  0x0203F028  arm
 *   d_021E2F70     0x021E2F70  data
 *
 * Storage-server records callback: forwards the records to the user callback at +0x17c, then, when no record id is pending (+0x1b0 == -1), scans every field of every record for the id field and stores its value through the pointer at +0x1464.
 */
#include "../include/Obj06574.h"

typedef unsigned long u32;

struct Field {
    const char *name;
    u32 type;
    u32 value;
    u32 pad;
};

typedef void (*RecordsFn)(int count, struct Field **recs, u32 a, int nfields);

extern int GF_STANDARD_CompareString(const char *s1, const char *s2);
extern const char d_021E2F70[];

void WIFIBATTLEMATCH_NET_GdbSortByName(int count, struct Field **recs, char *obj)
{
    int i, j;
    struct Field *f;

    (*(RecordsFn *)(obj + 0x17c))(count, recs, ((struct Obj06574 *)obj)->f178, ((struct Obj06574 *)obj)->f198);
    if (((struct Obj06574 *)obj)->f1B0 != -1)
        return;
    for (i = 0; i < count; i++) {
        for (j = 0; j < ((struct Obj06574 *)obj)->f198; j++) {
            f = &recs[i][j];
            if (GF_STANDARD_CompareString(f->name, d_021E2F70) == 0)
                **(u32 * *)&((struct Obj06574 *)obj)->f1464 = f->value;
        }
    }
}
