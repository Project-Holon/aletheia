/*
 * file:     sealed_checks_card.c
 * unit:     yes
 * function: OV230_ReadCardBytes, OV230_Crc32
 * address:  0x02188EB4
 * region:   ov230d
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Second-layer bodies of overlay 230 (region ov230d, opened by tools/ovcrypt.py): the card read and the
 * checksum the card checks use.
 *
 * OV230_ReadCardBytes reads the game card ROM directly through the card registers, 0x200-byte pages with
 * command 0xB7, and keeps only the bytes from the requested offset on. It hides its register addresses: the
 * I/O base is built as 1 << 26, the page mask 0x1FF as 0x204 minus a variable that holds 5, and the ROM control
 * word comes from the card header copy at 0x027FFE60 or 0x02FFFE60, picked by bit 0 of 0x04004000. It needs
 * `#pragma opt_propagation off` (the variables keep their own registers) and the command bytes written by a
 * static inline helper that takes the register base as an argument (its constant is hoisted with 0xB7).
 *
 * OV230_Crc32 is the CRC-32 with polynomial 0xEDB88320, written with the eight bit steps unrolled, except that the
 * bit test is inverted: a set low bit shifts alone and a clear one shifts and takes the polynomial.
 *
 * symbols:
 *   OV230_ReadCardBytes  0x02188EB4  arm  ov230d
 *   OV230_Crc32  0x02189004  arm  ov230d
 */
#include "../types.h"
#include "../sdk_ioreg.h"

#pragma opt_propagation off

/* Writes the eight command bytes (MCCMD0..7, 0x040001A8) for a page read at a card ROM offset. */
static inline void SetRomCommand(vu8 *regs, u32 offset)
{
    regs[0x1A8] = 0xB7;
    regs[0x1A9] = offset >> 24;
    regs[0x1AA] = offset >> 16;
    regs[0x1AB] = offset >> 8;
    regs[0x1AC] = offset;
    regs[0x1AD] = 0;
    regs[0x1AE] = 0;
    regs[0x1AF] = 0;
}

/* Reads size bytes of the card ROM at offset into dst, a word at a time. The card bus is taken for the ARM9
 * (EXMEMCNT bit 11 cleared) and the command bytes are saved and restored around the read. */
void OV230_ReadCardBytes(u8 *dst, u32 offset, s32 size)
{
    u8 savedCmd[8];
    uptr io = 1;
    u32 romCtrl;
    s32 pos;
    u16 exmem;
    u32 maskBias;
    int i;
    u8 *p;

    maskBias = 5;
    io <<= 26;
    exmem = *(vu16 *)REG_EXMEMCNT_ADDR;
    *(vu16 *)0x04000204 &= ~0x800;
    romCtrl = (*(u32 *)(uptr)((((((*(vu8 *)(io + 0x4000)) & 1) + 5) << 18) - 13) << 5) & ~0x07000000) | 0xA1000000;
    pos = -(s32)(offset & (0x204 - maskBias));
    while (*(vu32 *)(io + 0x1A4) & 0x80000000) {
    }
    *(vu8 *)(io + 0x1A1) = 0x80;
    p = savedCmd;
    i = 0;
    do {
        *p++ = *(vu8 *)((uptr)0x04000000 + i + 0x1A8);
        i++;
    } while (i < 8);
    offset += pos;
    if (pos < size) {
        do {
            SetRomCommand((vu8 *)REG_DISPCNT_ADDR, offset);
            *(vu32 *)(io + 0x1A4) = romCtrl;
            do {
                if (*(vu32 *)(io + 0x1A4) & 0x800000) {
                    u32 data = *(vu32 *)(io + 0x100010);
                    if (pos >= 0 && pos < size) {
                        *(u32 *)(dst + pos) = data;
                    }
                    pos += 4;
                }
            } while (*(vu32 *)(io + 0x1A4) & 0x80000000);
            offset += 0x200;
        } while (pos < size);
    }
    p = savedCmd;
    i = 0;
    do {
        *(vu8 *)((uptr)0x04000000 + i + 0x1A8) = *p++;
        i++;
    } while (i < 8);
    *(vu16 *)(io + 0x204) = exmem;
}

#pragma opt_propagation reset

u32 OV230_Crc32(const u8 *data, u32 size)
{
    u32 crc = 0xFFFFFFFF;

    while (size--) {
        crc ^= *data++;
        if (crc & 1) {
            crc = crc >> 1;
        } else {
            crc = (crc >> 1) ^ 0xEDB88320;
        }
        if (crc & 1) {
            crc = crc >> 1;
        } else {
            crc = (crc >> 1) ^ 0xEDB88320;
        }
        if (crc & 1) {
            crc = crc >> 1;
        } else {
            crc = (crc >> 1) ^ 0xEDB88320;
        }
        if (crc & 1) {
            crc = crc >> 1;
        } else {
            crc = (crc >> 1) ^ 0xEDB88320;
        }
        if (crc & 1) {
            crc = crc >> 1;
        } else {
            crc = (crc >> 1) ^ 0xEDB88320;
        }
        if (crc & 1) {
            crc = crc >> 1;
        } else {
            crc = (crc >> 1) ^ 0xEDB88320;
        }
        if (crc & 1) {
            crc = crc >> 1;
        } else {
            crc = (crc >> 1) ^ 0xEDB88320;
        }
        if (crc & 1) {
            crc = crc >> 1;
        } else {
            crc = (crc >> 1) ^ 0xEDB88320;
        }
    }
    return ~crc;
}
