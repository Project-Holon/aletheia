/*
 * port/tests/test_stats.c -- the six-stat recalculation, on the host,
 * against the player's own a/0/1/6 and extract/arm9_dec.bin.
 *
 * What is matched game C here, compiled unchanged out of src/matched/:
 *
 *   func_02018A7C   poke_tool.c's six-stat recalculation (660 bytes, the
 *                   whole formula, the nature permutation and the species
 *                   292 exception)
 *   func_02019C54   the one-entry personal-record memo
 *   sub_0201ADA4    the record read: index, seek, 0x3C-byte read
 *   sub_0201AFD4    species + form -> archive member index
 *   func_02019B04   the nature multiplier, indexed into the 25 x 5 table
 *   func_02049578 / func_020495F4   the archive lookup and read underneath
 *
 * The base stats are the first six bytes of the real 0x3C-byte personal
 * record, streamed out of a/0/1/6 by that matched chain through the port's
 * FS shim.  The nature multipliers are the real table at ARM9 0x0209E324,
 * copied out of the player's own extract/arm9_dec.bin.
 *
 * --------------------------------------------------------------------
 * WHAT IS SUBSTITUTED, AND WHY
 * --------------------------------------------------------------------
 * func_02018A7C reads and writes the Pokemon record only through the
 * dispatcher pair func_02017E1C (get field by id) and func_02017E40 (set
 * field by id), plus func_02018598 for the nature.  All three are matched,
 * but their closure reaches the record's encryption layer (func_02018D10
 * decrypt / func_02018D6C re-encrypt) and the two 200-case field
 * dispatchers, and building a valid encrypted party record is a milestone of
 * its own.  So this test defines those three itself, over a flat id-indexed
 * array, which is exactly the interface func_02018A7C uses.
 *
 * The three definitions below displace port/stubs/stub_02017E1C.c,
 * stub_02017E40.c and stub_02018598.c at link time (one symbol per archive
 * member, so nothing else is displaced with them).  Everything else in the
 * path is the real thing.
 *
 * The expected numbers come from tools/port/fixtures.py, which transcribes
 * the formula from src/matched/sub_02018A7C.c's own text and the multiplier
 * from src/matched/unit_02019B04.c, and from nothing else.
 */

#include <stdio.h>
#include <string.h>

#include "../sdk/port.h"
#include "port_test.h"
#include "bw_fixtures.h"

/* --- the matched game functions under test ------------------------- */

extern void  func_02018A7C(void *record);
extern void *func_02019C54(u32 species, u32 form);

/* --- the substituted record interface ------------------------------ */

#define BW_FIELD_COUNT 0x100

typedef struct FlatRecord {
    u32 field[BW_FIELD_COUNT];
    u32 nature;
} FlatRecord;

u32 func_02017E1C(void *p, u32 id, u32 v)
{
    FlatRecord *r = (FlatRecord *)p;

    (void)v;
    if (id >= BW_FIELD_COUNT) {
        return 0;
    }
    return r->field[id];
}

void func_02017E40(void *p, u32 id, u32 v)
{
    FlatRecord *r = (FlatRecord *)p;

    if (id < BW_FIELD_COUNT) {
        r->field[id] = v;
    }
}

u32 func_02018598(void *p)
{
    return ((FlatRecord *)p)->nature;
}

/* --- field ids, from src/matched/sub_02018A7C.c's header ------------ */

#define ID_SPECIES   0x05
#define ID_EV_BASE   0x0D   /* 0x0D..0x12, stat order                   */
#define ID_IV_BASE   0x46   /* 0x46..0x4B, stat order                   */
#define ID_FORM      0x6F
#define ID_LEVEL     0x9E
#define ID_CUR_HP    0xA0
#define ID_MAX_HP    0xA1   /* 0xA1..0xA6: hp, atk, def, spe, spa, spd  */

static const char *const kStatName[6] = {
    "max HP", "attack", "defence", "speed", "sp. attack", "sp. defence"
};

int main(int argc, char **argv)
{
    u32 i;

    BW_TEST_SETUP(argc, argv);

    BW_REQUIRE("open a/0/1/6", bw_open_personal_archive() == 0);
    BW_REQUIRE("load nature table from arm9_dec.bin", bw_load_nature_table() == 0);

    for (i = 0; i < BW_STAT_FIXTURE_COUNT; i++) {
        const BwStatFixture *fx = &bw_stat_fixtures[i];
        FlatRecord rec;
        const u8 *base;
        u32 k;

        memset(&rec, 0, sizeof(rec));
        rec.nature = (u32)fx->nature;
        rec.field[ID_SPECIES] = fx->species;
        rec.field[ID_FORM] = 0;
        rec.field[ID_LEVEL] = (u32)fx->level;
        rec.field[ID_CUR_HP] = 0;
        rec.field[ID_MAX_HP] = 0;
        for (k = 0; k < 6; k++) {
            rec.field[ID_IV_BASE + k] = (u32)fx->iv[k];
            rec.field[ID_EV_BASE + k] = (u32)fx->ev[k];
        }

        /*
         * Check the base stats the matched archive chain hands back before
         * running the formula, so a failure separates "the archive read is
         * wrong" from "the arithmetic is wrong".
         */
        base = (const u8 *)func_02019C54(fx->species, 0);
        BW_REQUIRE("personal record", base != NULL);
        for (k = 0; k < 6; k++) {
            char label[80];

            sprintf(label, "species %u base[%u]", fx->species, (unsigned)k);
            BW_CHECK_EQ(label, base[k], fx->base[k]);
        }

        func_02018A7C(&rec);

        printf("  species %u level %d nature %d\n",
               fx->species, fx->level, fx->nature);
        for (k = 0; k < 6; k++) {
            char label[96];

            sprintf(label, "species %u %s", fx->species, kStatName[k]);
            BW_CHECK_EQ(label, rec.field[ID_MAX_HP + k], fx->expect[k]);
            printf("    %-12s %4lu (want %d)\n", kStatName[k],
                   (unsigned long)rec.field[ID_MAX_HP + k], fx->expect[k]);
        }
        {
            char label[96];

            sprintf(label, "species %u current HP", fx->species);
            BW_CHECK_EQ(label, rec.field[ID_CUR_HP], fx->expect_cur);
        }
    }

    bw_close_personal_archive();
    BW_REPORT("test_stats");
}
