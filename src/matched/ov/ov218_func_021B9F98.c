/*
 * function: func_021B9F98
 * address:  0x021B9F98
 * packet:   pkt_ov218_021B9F98
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   tbl_021BAC80 0x021BAC80 data ov218 a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int tbl_021BAC80[];
void func_021B9F98(u8 *p, int mode)
{
    switch (mode) {
    case 0: {
        int idx = *(int *)(p + 0x30);
        *(u8 *)(*(u8 **)(p + 0x20) + 1) = 0x83 - idx;
        *(u16 *)(*(u8 **)(p + 0x20) + 2) = tbl_021BAC80[idx];
        *(u32 *)(*(u8 **)(p + 0x20) + 4) = 1;
        break;
    }
    case 1:
        *(u8 *)(*(u8 **)(p + 0x20) + 1) = 0;
        *(u16 *)(*(u8 **)(p + 0x20) + 2) = 0;
        *(u32 *)(*(u8 **)(p + 0x20) + 4) = 0;
        break;
    }
}
