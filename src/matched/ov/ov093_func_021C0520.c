/*
 * function: func_021C0520
 * address: 0x021C0520
 * packet: pkt_ov093_021C0520
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: a u8 local for the random result narrows in r0 before copying to r2.
 * symbols:
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021CD64C 0x021CD64C thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021D78AC 0x021D78AC thumb ov093
 *   func_021C5604 0x021C5604 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 func_021D5440(u8 *p);
extern void func_021CD64C(void *, u8, ...);
extern void func_021CD4B0(void *, u32, ...);
extern int func_021D62C4(u8 *, int);
extern u32 func_021D78AC(int);
extern void func_021C5604(u8 *, u8 *, u16);
void func_021C0520(u8 *p, u8 *a, u16 b, u32 c)
{
    u32 id = func_021D5440(a);
    switch (c) {
    case 2: func_021CD64C(*(void **)(p + 12), 0x5b, 0x135, id, 0xffff0000); break;
    case 3: func_021CD64C(*(void **)(p + 12), 0x5b, 0x114, id, 0xffff0000); break;
    case 4: func_021CD64C(*(void **)(p + 12), 0x5b, 0x123, id, 0xffff0000); break;
    case 6: func_021CD64C(*(void **)(p + 12), 0x5b, 0x16b, id, 0xffff0000); break;
    case 7: func_021CD64C(*(void **)(p + 12), 0x5b, 0x16e, id, 0xffff0000); break;
    case 8: func_021CD64C(*(void **)(p + 12), 0x5b, 0x150, id, 0xffff0000); break;
    case 9: func_021CD64C(*(void **)(p + 12), 0x5b, 0x253, id, b, 0xffff0000); break;
    case 18: func_021CD64C(*(void **)(p + 12), 0x5b, 0x1bd, id, 0xffff0000); break;
    case 10: func_021CD64C(*(void **)(p + 12), 0x5b, 0x23b, id, b, 0xffff0000); break;
    case 11: func_021CD64C(*(void **)(p + 12), 0x5b, 0x244, id, b, 0xffff0000); break;
    case 12: func_021CD64C(*(void **)(p + 12), 0x5b, 0x24d, id, b, 0xffff0000); break;
    case 13: func_021CD64C(*(void **)(p + 12), 0x5b, 0x37a, id, b, 0xffff0000); break;
    case 14: func_021CD64C(*(void **)(p + 12), 0x5b, 0x37d, id, 0xffff0000); break;
    case 15:
        func_021CD4B0(*(void **)(p + 12), 0x57, id);
        func_021CD64C(*(void **)(p + 12), 0x5b, 0x1c3, id, 0xffff0000);
        func_021CD4B0(*(void **)(p + 12), 0x58, id);
        break;
    case 20: func_021CD64C(*(void **)(p + 12), 0x5b, 0x43e, id, b, 0xffff0000); break;
    case 22:
        if (func_021D62C4(a, 2) != 0) {
            func_021CD64C(*(void **)(p + 12), 0x5a, 0xc2, id, 0xffff0000);
        } else {
            u8 rand = func_021D78AC(4);
            func_021CD64C(*(void **)(p + 12), 0x5a, rand + 0xbc, id, 0xffff0000);
        }
        break;
    case 23: func_021CD64C(*(void **)(p + 12), 0x5a, 0xc1, id, 0xffff0000); break;
    case 1:
        func_021C5604(p, a, b);
        func_021CD64C(*(void **)(p + 12), 0x5a, 0x52, id, 0xffff0000);
        break;
    default: func_021CD64C(*(void **)(p + 12), 0x5a, 0x47, id, 0xffff0000); break;
    case 19:
    case 25:
        break;
    }
}
