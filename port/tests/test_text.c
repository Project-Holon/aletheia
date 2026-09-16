/*
 * port/tests/test_text.c -- the message-text loader path, on the host,
 * against the player's own a/0/0/2.
 *
 * What is matched game C here, compiled unchanged out of src/matched/:
 *
 *   func_02049578   given an archive and a member index, the member's
 *                   absolute byte position:  imageBase + 8 + FAT[member].start
 *   func_0204944C   the same lookup plus a seek-and-read of a range inside
 *                   the member (used here to pull the whole bank)
 *   func_020495F4   the read itself, a forward to FS_ReadFile
 *   func_02045E3C   the cipher: key = (u16)((index + 3) * 0x2983), xor each
 *                   code unit, rotate the key left 3, stop at the
 *                   end-of-string unit, return the decoded length
 *
 * What is port code: opening the file (bw_arc_open), the FS shim underneath,
 * and the message-file header walk below.  The header walk is port code
 * because the function that does it on the DS, func_02046110, is a
 * documented near miss and is not matched yet
 * (docs/notes/func_02046110.c.txt); its layout is the one
 * tools/assets/text.py reconstructed and round-trips every sub-file with.
 *
 * The expected code units come from tools/port/fixtures.py via
 * tools/assets/text.py.  The test is therefore a check that the compiled
 * matched C, on a little-endian or big-endian host, reproduces the same
 * decode the asset tool does, including the descriptor arithmetic and the
 * terminator search, over the real archive.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../sdk/port.h"
#include "port_test.h"
#include "bw_fixtures.h"

/* --- the matched game functions under test ------------------------- */

extern u32  func_02049578(void *arc, u32 member);
extern void func_020495F4(void *arc, u32 size, void *dst);
extern void func_0204960C(void *arc, u32 pos);
extern u32  func_02045E3C(u16 *str, u32 count, u32 msgIndex);

/* --- the message-file container, as tools/assets/text.py documents it - */

#define MSG_HEADER_SIZE 16

typedef struct MsgFile {
    u8 *raw;
    u32 size;
    u16 section_count;
    u16 entry_count;
    u32 section_offset0;
} MsgFile;

static int msg_parse(MsgFile *mf, u8 *raw, u32 size)
{
    if (size < MSG_HEADER_SIZE) {
        return -1;
    }
    mf->raw = raw;
    mf->size = size;
    mf->section_count = bw_rd16(raw + 0);
    mf->entry_count = bw_rd16(raw + 2);
    mf->section_offset0 = bw_rd32(raw + 12);
    if (mf->section_count < 1 || mf->section_count > 8) {
        return -1;
    }
    return 0;
}

/*
 * Descriptor `index`: 8 bytes at section_offset[0] + 4 + index * 8, holding
 * { u32 offset; u16 numChars; u16 flags }.  The string's raw code units
 * start at 16 + offset, and the count stored there is informational: the
 * matched cipher scans for the terminator itself.
 */
static int msg_string_start(const MsgFile *mf, u32 index, u32 *start_out)
{
    u32 pos;

    if (index >= mf->entry_count) {
        return -1;
    }
    pos = mf->section_offset0 + 4 + index * 8;
    if (pos + 8 > mf->size) {
        return -1;
    }
    *start_out = MSG_HEADER_SIZE + bw_rd32(mf->raw + pos);
    if (*start_out >= mf->size) {
        return -1;
    }
    return 0;
}

/* --- the bank read, through the matched archive readers ------------- */

static u8 *read_bank(BwArcFile *arc, u32 member, u32 *size_out)
{
    long size = bw_arc_member_size(arc, member);
    u8 *buf;
    u32 pos;

    if (size <= 0) {
        return NULL;
    }
    buf = (u8 *)malloc((size_t)size);
    if (buf == NULL) {
        return NULL;
    }

    /* matched: the member's absolute position, then the seek, then the read */
    pos = func_02049578(arc, member);
    func_0204960C(arc, pos);
    func_020495F4(arc, (u32)size, buf);

    *size_out = (u32)size;
    return buf;
}

/* --- the test ------------------------------------------------------- */

int main(int argc, char **argv)
{
    BwArcFile arc;
    u32 i;

    BW_TEST_SETUP(argc, argv);

    BW_REQUIRE("open a/0/0/2", bw_arc_open(&arc, "a/0/0/2") == 0);
    printf("a/0/0/2: %u sub-files, fat +0x%04X, image +0x%08lX\n",
           (unsigned)arc.count, (unsigned)arc.fatOffset,
           (unsigned long)arc.imageBase);

    for (i = 0; i < BW_TEXT_FIXTURE_COUNT; i++) {
        const BwTextFixture *fx = &bw_text_fixtures[i];
        char label[96];
        u8 *bank;
        u32 bank_size = 0;
        MsgFile mf;
        u32 start;
        u32 avail;
        u32 units;
        u16 *scratch;
        u32 decoded;
        u32 k;

        sprintf(label, "sub-file %u entry %u", fx->subfile, fx->entry);

        bank = read_bank(&arc, fx->subfile, &bank_size);
        BW_REQUIRE("read bank", bank != NULL);
        BW_REQUIRE("parse bank", msg_parse(&mf, bank, bank_size) == 0);
        BW_REQUIRE("locate string", msg_string_start(&mf, fx->entry, &start) == 0);

        /*
         * Copy the raw run out of the bank into a u16 scratch buffer: the
         * matched cipher decrypts in place, and it must be given aligned
         * u16 storage, not a pointer into a byte buffer that may sit on an
         * odd address.  The copy is byte-wise and little-endian, so the
         * scratch holds the same code units on any host.
         */
        avail = bank_size - start;
        units = avail / 2;
        scratch = (u16 *)malloc((size_t)(units + 1) * sizeof(u16));
        BW_REQUIRE("scratch", scratch != NULL);
        for (k = 0; k < units; k++) {
            scratch[k] = bw_rd16(bank + start + k * 2);
        }

        decoded = func_02045E3C(scratch, units, fx->entry);

        BW_CHECK_EQ(label, decoded, fx->length);
        if (decoded == fx->length) {
            int same = 1;

            for (k = 0; k < fx->length; k++) {
                if (scratch[k] != fx->units[k]) {
                    same = 0;
                    printf("  FAIL %-40s unit %u: got 0x%04X, want 0x%04X\n",
                           label, (unsigned)k, scratch[k], fx->units[k]);
                    bw_failures++;
                    break;
                }
            }
            bw_checks++;
            if (same) {
                printf("  ok   %-40s %u units\n", label, (unsigned)decoded);
            }
        }

        free(scratch);
        free(bank);
    }

    bw_arc_close(&arc);
    BW_REPORT("test_text");
}
