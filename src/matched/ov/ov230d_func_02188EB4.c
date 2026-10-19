/*
 * function: OV230_ReadCardBytes
 * address:  0x02188EB4
 * packet:   pkt_ov230d_02188EB4
 * region:   ov230d
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     from src/game/ov230/sealed_checks_card.c (decrypted view of overlay 230, region ov230d)
 * symbols:
 *   OV230_ReadCardBytes  0x02188EB4  arm  ov230d
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef volatile u8 vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;

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
    u32 io = 1;
    u32 romCtrl;
    s32 pos;
    u16 exmem;
    u32 maskBias;
    int i;
    u8 *p;

    maskBias = 5;
    io <<= 26;
    exmem = *(vu16 *)0x04000204;
    *(vu16 *)0x04000204 &= ~0x800;
    romCtrl = (*(u32 *)((((((*(vu8 *)(io + 0x4000)) & 1) + 5) << 18) - 13) << 5) & ~0x07000000) | 0xA1000000;
    pos = -(s32)(offset & (0x204 - maskBias));
    while (*(vu32 *)(io + 0x1A4) & 0x80000000) {
    }
    *(vu8 *)(io + 0x1A1) = 0x80;
    p = savedCmd;
    i = 0;
    do {
        *p++ = *(vu8 *)(0x04000000 + i + 0x1A8);
        i++;
    } while (i < 8);
    offset += pos;
    if (pos < size) {
        do {
            SetRomCommand((vu8 *)0x04000000, offset);
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
        *(vu8 *)(0x04000000 + i + 0x1A8) = *p++;
        i++;
    } while (i < 8);
    *(vu16 *)(io + 0x204) = exmem;
}
