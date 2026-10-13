/*
 * file:     os_argument.c
 * unit:     yes
 * function: OSi_SearchTitleIdFromList
 * address:  0x0273131C
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      libos.TWL.HYB.a os_application_j
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct {
    u8 count;
    u8 pad[0x4F];
    volatile u64 ent[0x76];
} MacTbl;
#define MACTBL ((MacTbl *)0x02FFD800)

u64 OSi_SearchTitleIdFromList(u64 val, u64 mask)
{
    MacTbl *t = MACTBL;
    u32 n = t->count;
    int i;
    if (n > 0x76) {
        n = 0x76;
    }
    for (i = 0; i < (int)n; i++) {
        u64 e = ((volatile u64 *)0x02FFD850)[i];
        if ((val & mask) == (mask & e)) {
            if ((e & 0x800000000ULL) == 0) {
                return t->ent[i];
            }
        }
    }
    return 0;
}
