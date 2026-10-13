/*
 * function: PMS_WORD_SetSaveEntry
 * address:  0x02024918
 * packet:   pkt_02024838
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed int    s32;

struct Item {
    u8 bytes[8];
};

struct Obj02024838 {
    u8          pad[8];
    struct Item items[20];
};

extern void MI_CpuCopy8(void *dest, const void *src, u32 size);

void PMS_WORD_SetSaveEntry(const struct Obj02024838 *p, s32 idx, void *dest)
{
    if (idx < 0 || idx >= 20) {
        return;
    }

    MI_CpuCopy8(dest, &p->items[idx], 8);
}
