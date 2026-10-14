/*
 * function: OSi_VerifyStaticSegments
 * address:  0x01FF836C
 * packet:   pkt_01FF836C
 * region:   arm9_autoload0_ITCM
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: OSi_VerifyStaticSegments, TwlSDK/lib/ARM9-TS/Rom/libos.TWL.HYB.a
 * (os_reset.o), definition at build/libraries/os/common/src/os_reset.c:339.
 * The Rom object is ARM and is byte-identical to this 168-byte extent: its
 * .itcm section for OSi_VerifyStaticSegments is 0xA8 bytes, its
 * DW_AT_decl_line is 339, and the relocation-free code is
 * e92d40f8 e24dd020 e59f7094 e3a04001 e5d7001c ... a4: 0x02ffe000.
 *
 * Built with SDK_OS_RESET_COMPACT, so the HMAC-SHA1 is a call out to
 * OSi_VerifyStaticSegmentHash (0x01FF82A8) rather than the inline
 * SVC_HMACSHA1 sequence.  DWARF decl_file/line inside the subprogram:
 * result 341 (r4), i 345 (r0), table 356 (fbreg 16), compareDigests 357
 * (fbreg 0), address 381, size 382, and a 0x8-byte `struct Segment` with
 * `address` at +0 and `size` at +4 -- the shape the ldm {r0,r1} at +0x74
 * loads.  Decoded line map over this extent:
 *   +0x00 340  result = TRUE
 *   +0x0c 341  header = (const CARDRomHeaderTWL *)HW_TWL_ROM_HEADER_BUF
 *   +0x08 343  if (((const u8 *)header)[0x1C] & 1)
 *   +0x1c-0x28 358-361  table[0..3] = &ntr.main_ram_address,
 *                            &ntr.sub_ram_address, &main_ltd_ram_address,
 *                            &sub_ltd_ram_address  (0x28, 0x38, 0x1C8,
 *                            0x1D8)
 *   +0x2c-0x38 362-365  compareDigests[0..3] = &((const u8*)header)[0x3A0],
 *                            sub_static_digest 0x314,
 *                            main_ltd_static_digest 0x350,
 *                            sub_ltd_static_digest 0x364
 *   +0x5c 366  for (i = 0; i < SEGMENT_TOTAL; ++i)
 *   +0x64 381  address = table[i]->address
 *   +0x70 383  if (i == 0)
 *   +0x78 385  address += 0x4000
 *   +0x7c 386  size -= 0x4000
 *   +0x80 394  result &= OSi_VerifyStaticSegmentHash(address, size, ...)
 *   +0x94 399  while (result == FALSE) -- the fail-stop spin
 *
 * symbols:
 *   OSi_VerifyStaticSegmentHash    0x01FF82A8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int BOOL;

extern BOOL OSi_VerifyStaticSegmentHash(const u8 *src, u32 len, const void *digest);

void OSi_VerifyStaticSegments(void)
{
    BOOL result = 1;
    const u8 *header = (const u8 *)0x02FFE000;
    if ((header[0x1C] & 0x01) != 0)
    {
        int i;
        struct Segment { const u8 *address; u32 size; } *(table[4]);
        const void *(compareDigests[4]);

        table[0] = (struct Segment *)&header[0x28];
        table[1] = (struct Segment *)&header[0x38];
        table[2] = (struct Segment *)&header[0x1C8];
        table[3] = (struct Segment *)&header[0x1D8];

        compareDigests[0] = &header[0x3A0];
        compareDigests[1] = &header[0x314];
        compareDigests[2] = &header[0x350];
        compareDigests[3] = &header[0x364];

        for (i = 0; i < 4; ++i)
        {
            const u8 *address = table[i]->address;
            u32 size = table[i]->size;
            if (i == 0)
            {
                address += 0x4000;
                size -= 0x4000;
            }
            result &= OSi_VerifyStaticSegmentHash(address, size, compareDigests[i]);
        }
    }
    while (result == 0)
    {
    }
}
