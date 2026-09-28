/*
 * function: func_01FF836C
 * address:  0x01FF836C
 * packet:   itcm
 * region:   arm9_autoload0_ITCM
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_01FF82A8    0x01FF82A8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int BOOL;

extern BOOL func_01FF82A8(const u8 *src, u32 len, const void *digest);

void func_01FF836C(void)
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
            result &= func_01FF82A8(address, size, compareDigests[i]);
        }
    }
    while (result == 0)
    {
    }
}
