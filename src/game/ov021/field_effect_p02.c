/*
 * function: func_021A8E14
 * address:  0x021A8E14
 * packet:   pkt_021A8E14
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * TwlSDK libel elf_loader.o: EL_GetLibSize(my_dlld) returns 0 for a null
 * handle, else the size word at +8 of the dlld structure.
 *
 * symbols:
 */

typedef unsigned long u32;

u32 func_021A8E14(u32 p)
{
    if (p == 0)
    {
        return 0;
    }
    return *(u32 *)(p + 8);
}
