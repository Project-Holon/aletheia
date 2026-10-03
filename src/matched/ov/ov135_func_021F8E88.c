/*
 * function: func_021F8E88
 * address: 0x021F8E88
 * packet: pkt_ov135_021F8E88
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F8A74 0x021F8A74 thumb ov135
 *   func_021F8A80 0x021F8A80 thumb ov135
 *   func_021F8AB0 0x021F8AB0 thumb ov135
 *   func_021F8AF4 0x021F8AF4 thumb ov135
 *   func_021F8B0C 0x021F8B0C thumb ov135
 *   func_021F8BBC 0x021F8BBC thumb ov135
 *   func_021F8BE8 0x021F8BE8 thumb ov135
 *   func_021F8F84 0x021F8F84 thumb ov135
 *   func_021F9024 0x021F9024 thumb ov135
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021F8A74(u8 *);
extern int func_021F8A80(u8 *);
extern int func_021F8AB0(u8 **);
extern int func_021F8AF4(u8 *);
extern int func_021F8B0C(u8 *);
extern int func_021F8BBC(u8 *);
extern int func_021F8BE8(u8 *);
extern int func_021F8F84(u8 *, void *);
extern int func_021F9024(u8 *, void *);
int func_021F8E88(void *dialog, u8 *p)
{
    int result;
    switch (*(u32 *)(p + 0x12ec)) {
    case 0:
        if (func_021F8A74(p))
            (*(u32 *)(p + 0x12ec))++;
        break;
    case 1:
        result = func_021F8A80(p);
        switch (result) {
        case 1: (*(u32 *)(p + 0x12ec))++; break;
        case 2: *(u32 *)(p + 0x12ec) = 9; break;
        }
        break;
    case 2:
        if (func_021F8AB0((u8 **)p)) (*(u32 *)(p + 0x12ec))++;
        break;
    case 3:
        if (func_021F8AF4(p)) (*(u32 *)(p + 0x12ec))++;
        break;
    case 4:
        result = func_021F8B0C(p);
        switch (result) {
        case 1: (*(u32 *)(p + 0x12ec))++; break;
        case 2: *(u32 *)(p + 0x12ec) = 7; break;
        }
        break;
    case 5:
        if (func_021F8BBC(p)) (*(u32 *)(p + 0x12ec))++;
        break;
    case 6:
        result = func_021F8BE8(p);
        switch (result) {
        case 1: *(u32 *)(p + 0x12ec) = 0; return 0;
        case 2: *(u32 *)(p + 0x12ec) = 7; break;
        }
        break;
    case 7:
        if (func_021F8F84(p, dialog)) (*(u32 *)(p + 0x12ec))++;
        break;
    case 8:
        if (func_021F9024(p, dialog)) (*(u32 *)(p + 0x12ec))++;
        break;
    case 9:
        *(u32 *)(p + 0x12ec) = 0;
        return 1;
    }
    return 2;
}
