/*
 * function: func_021BE948
 * address: 0x021BE948
 * packet: pkt_ov203_021BE948
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BE7A8 0x021BE7A8 thumb ov203
 */
extern unsigned char *func_021BE7A8(void *);
typedef struct Flags { unsigned short doubled:1; unsigned short rest:15; } Flags;
void func_021BE948(void *ctx, int mode, unsigned char *width, unsigned char *height)
{
    unsigned char *record = func_021BE7A8(ctx);
    if (mode == 0) {
        *width = record[0x4e];
        *height = record[0x4f] * (((Flags *)(record + 6))->doubled + 1);
    } else {
        *width = record[0x50];
        *height = record[0x51] * (((Flags *)(record + 6))->doubled + 1);
    }
}
