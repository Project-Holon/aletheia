/*
 * function: func_02014428
 * address:  0x02014428
 * packet:   pkt_0201441C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   sBtlSetupFile  0x020A72BC  data
 *   func_02030734  0x02030734  arm
 *
 * Heap-allocates a 0x14-byte block tagged with the file string at
 * 0x020A72BC and line 0x33, then clears the u16 at +0x12.  The earlier
 * near miss in docs/notes/pkt_0201441C.c.txt declared the string at
 * 0x020A729C, 0x20 too low: the pool word in the image is the little-endian
 * bc 72 0a 02 at 0x02014440, and the one "differing byte" was bit 5 of that
 * address, not a register choice.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02030734(u32 heap, u32 size, u32 flags, const char *file,
                           u32 line);
extern u8    sBtlSetupFile;

void func_02014428(u32 heap)
{
    u8 *p = func_02030734(heap, 0x14, 1, (const char *)&sBtlSetupFile, 0x33);

    *(u16 *)(p + 0x12) = 0;
}
