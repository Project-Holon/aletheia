/*
 * function: func_021C5C74
 * address: 0x021C5C74
 * packet: pkt_ov093_021C5C74
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021CD64C 0x021CD64C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 func_021D5440(u8 *);
extern void func_021CD64C(void *, u8, ...);
void func_021C5C74(u8 *p, u8 *a, int kind, u32 v)
{
    u8 n = func_021D5440(a);
    switch (kind) {
    case 1:
        switch (v) {
        case 5: func_021CD64C(*(void **)(p + 12), 0x5b, 0xf9, n, 0xffff0000); break;
        case 4: func_021CD64C(*(void **)(p + 12), 0x5b, 0x10b, n, 0xffff0000); break;
        case 1: func_021CD64C(*(void **)(p + 12), 0x5b, 0x11a, n, 0xffff0000); break;
        case 2: func_021CD64C(*(void **)(p + 12), 0x5b, 0x13b, n, 0xffff0000); break;
        case 3: func_021CD64C(*(void **)(p + 12), 0x5b, 0x129, n, 0xffff0000); break;
        case 6: func_021CD64C(*(void **)(p + 12), 0x5b, 0x162, n, 0xffff0000); break;
        case 15: func_021CD64C(*(void **)(p + 12), 0x5b, 0x18, n, 0xffff0000); break;
        case 20: return;
        default: func_021CD64C(*(void **)(p + 12), 0x5a, 0x47, 0xffff0000); break;
        }
        p[0x78a] |= 0x10;
        break;
    case 2:
        func_021CD64C(*(void **)(p + 12), 0x5b, 0xd2, n, 0xffff0000);
        p[0x78a] |= 0x10;
        break;
    default:
        func_021CD64C(*(void **)(p + 12), 0x5a, 0x47, 0xffff0000);
        p[0x78a] |= 0x10;
        break;
    }
}
