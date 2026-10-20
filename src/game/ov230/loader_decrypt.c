/*
 * file:     loader_decrypt.c
 * unit:     yes
 * function: LOADER_DECRYPT_SyncCacheRange, LOADER_DECRYPT_ClassifyOpcode, LOADER_DECRYPT_DecodeBlocks
 * address:  0x021889E4
 * region:   ov230
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   gLoaderDecryptBssStart  0x021899A0  data  ov230
 */
#include "../types.h"

asm void LOADER_DECRYPT_SyncCacheRange(void *addr, unsigned int size);
int LOADER_DECRYPT_ClassifyOpcode(unsigned word);
void LOADER_DECRYPT_DecodeBlocks(u32 *t);
extern char gLoaderDecryptBssStart[];

/*
 * note:     cache maintenance over [r0, r0 + r1): per 32-byte line it
 *           invalidates the I-cache line, drains the write buffer and cleans
 *           and invalidates the D-cache line. CP15 writes have no C
 *           spelling, so this is an asm function like DC_StoreRange.
 */
/* hand-written in the original: cache maintenance loop with CP15 mcr writes (I-cache invalidate, write buffer drain, D-cache clean and invalidate), no C spelling */
asm void LOADER_DECRYPT_SyncCacheRange(void *addr, unsigned int size)
{
    add     r1, r1, r0
    mov     ip, #0
    bic     r0, r0, #0x1f
cacheLineLoop:
    mcr     p15, 0, r0, c7, c5, 1
    mcr     p15, 0, ip, c7, c10, 4
    mcr     p15, 0, r0, c7, c14, 1
    add     r0, r0, #0x20
    cmp     r0, r1
    blt     cacheLineLoop
    bx      lr
}

/*
 * extent: lead60B; larger loader follower02188A48..02188B48, then encoded payload through02188CB0.
 */
int LOADER_DECRYPT_ClassifyOpcode(unsigned instr)
{
    unsigned char opcode=instr>>24;
    if ((opcode&14)==10) {
        if ((opcode&240)==240) return 1;
        if (opcode&1) return 2;
        else return 3;
    }
    return 0;
}

void LOADER_DECRYPT_DecodeBlocks(u32 *desc)
{
    u32 *header;
    u32 byteCount;
    u32 *end;
    u32 key;
    u32 word;
    u32 bssBase;
    u32 *cursor;

    header = desc - 3;
    header[0] = header[1] = header[2] = 0;
    bssBase = (uptr)gLoaderDecryptBssStart;
    do {
        cursor = (u32 *)(desc[0] - 0x1600);
        byteCount = desc[1] - bssBase - 0x1600;
        end = cursor + byteCount / 4;
        key = 0xF0618C46;
        for (; cursor < end; cursor++) {
            switch (LOADER_DECRYPT_ClassifyOpcode(*cursor)) {
            case 1:
            case 3:
                word = *cursor;
                word = ((word & 0xFF000000) ^ 0x01000000) | (((word & 0xFFFFFF) + 0xFFFFFA7E) & 0xFFFFFF);
                *cursor = word;
                key = (key ^ (word >> 24)) & 0xFFFFFF;
                break;
            case 2:
                *cursor ^= 0x01000000;
            default:
                word = *cursor ^ key;
                key = (key ^ word ^ (word >> 8)) & 0xFFFFFF;
                *cursor = word;
                break;
            }
        }
        LOADER_DECRYPT_SyncCacheRange((void *)(desc[0] - 0x1600), byteCount);
        desc[1] = 0;
        desc[0] = 0;
        desc += 2;
    } while (*desc != 0);
}
