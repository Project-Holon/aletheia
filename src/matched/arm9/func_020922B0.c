/*
 * function: MSL_C_LIB_CallFormatHook
 * address:  0x020922B0
 * packet:   pkt_02092144
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gMslFormatHook     0x020A8878  data
 */

typedef unsigned int u32;

extern unsigned char gMslFormatHook[];

typedef struct {
    unsigned char pad[4];
    u32 (*fn)(u32 *dst, u32 c);
} FuncTable;

typedef struct {
    unsigned char pad[8];
    FuncTable *table;
} Holder;

u32 MSL_C_LIB_CallFormatHook(u32 *dst, u32 c)
{
    return ((Holder *)gMslFormatHook)->table->fn(dst, c);
}
