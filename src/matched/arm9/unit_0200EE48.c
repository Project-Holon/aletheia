/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0200EE48
 * packet:   pkt_0200E684
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: FLDMMDL_GetSaveTableSize, FLDMMDL_ClearSaveTable
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *
 * alias: FLDMMDL_GetSaveTableSize returns the constant 0x1400 (5 << 10), the size of
 * some fixed buffer; FLDMMDL_ClearSaveTable zero-fills that many bytes at the given
 * pointer.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200EE48.c \
 *       --addr 0x0200EE48 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void MI_CpuFill8(void *dest, u8 data, u32 size);

u32 FLDMMDL_GetSaveTableSize(void)
{
    return 5 << 10;
}

void FLDMMDL_ClearSaveTable(void *dest)
{
    MI_CpuFill8(dest, 0, FLDMMDL_GetSaveTableSize());
}
