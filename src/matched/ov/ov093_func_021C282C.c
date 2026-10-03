/*
 * function: func_021C282C
 * address: 0x021C282C
 * packet: pkt_ov093_021C282C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021D62A8 0x021D62A8 thumb ov093
 *   func_021C2AB0 0x021C2AB0 thumb ov093
 *   func_021D57FC 0x021D57FC thumb ov093
 *   func_021E8D24 0x021E8D24 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Slot { u32 a : 3; u32 rest : 29; };
struct Unk021D62A8 { u8 pad[0x1c]; struct Slot e[6]; };
extern int func_021D62C4(struct Unk021D62A8 *, int);
extern int func_021D62A8(struct Unk021D62A8 *);
extern int func_021C2AB0(u8 *);
extern u16 func_021D57FC(void *);
extern int func_021E8D24(u16, int);
extern int func_021D59B4(u8 *p, int k);
int func_021C282C(u8 *a, struct Unk021D62A8 *b, int c, int d, u8 e)
{
    u16 t;
    if (func_021D62C4(b, c) && e != 2) return 1;
    if (c < 6 && func_021D62A8(b) && e == 0) return 3;
    if (func_021C2AB0(a) == 1 && c == 3) return 3;
    if (c == 5) {
        t = func_021D57FC(b);
        if (func_021E8D24(t, 8) || func_021E8D24(t, 3)) return 2;
    }
    if (c == 4 && func_021E8D24(func_021D57FC(b), 9)) return 2;
    if (c == 3 && func_021E8D24(func_021D57FC(b), 14)) return 2;
    if (c == 18 && func_021E8D24(func_021D57FC(b), 11)) return 2;
    if (c == 14 && func_021D62A8(b)) return 3;
    if (c == 16 && func_021D59B4((u8 *)b, 16) == 121) return 3;
    return 0;
}
