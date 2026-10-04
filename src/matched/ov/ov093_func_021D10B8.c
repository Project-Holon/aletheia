/*
 * function: func_021D10B8
 * address: 0x021D10B8
 * packet: pkt_ov093_021D10B8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * blocker: sole-ref/code and veneer evidence cannot resolve 021D121C and
 * 021D122C; their bx-pc veneers point outside known image regions to
 * 0x0689CB14 and 0x0689CB1C. All concrete bytes in the 356-byte body match.
 * follower: 021D121C and 021D122C are bx-pc interworking veneers, not C.
 * symbols:
 *   func_021EEC20 0x021EEC20 thumb ov093
 *   func_021EAF18 0x021EAF18 thumb ov093
 *   func_021EAF50 0x021EAF50 thumb ov093
 *   func_021EAF78 0x021EAF78 thumb ov093
 *   func_021EA614 0x021EA614 thumb ov093
 *   func_021EA710 0x021EA710 thumb ov093
 *   func_021EA720 0x021EA720 thumb ov093
 *   func_021EABC4 0x021EABC4 thumb ov093
 *   func_021EAC54 0x021EAC54 thumb ov093
 *   func_021D0B10 0x021D0B10 thumb ov093
 *   func_021E9A78 0x021E9A78 thumb ov093
 *   func_021E9B20 0x021E9B20 thumb ov093
 *   func_021D121C 0x021D121C thumb ov093
 *   func_021D122C 0x021D122C thumb ov093
 *   func_021D8394 0x021D8394 thumb ov093
 *   func_021D8434 0x021D8434 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021EEC20(int, u8 **);
extern void func_021EAF18(void *, int, int);
extern void func_021EAF50(void *, int);
extern void func_021EAF78(u8 *p, u8 v);
extern void func_021EA614(void *, void *);
extern int func_021EA710(u32 *p);
extern int func_021EA720(void *);
extern void func_021EABC4(void *, void *, void *, int);
extern int func_021EAC54(void *, int *);
extern void func_021D0B10(u8 *p, u32 a, u32 b, void *q, void *out);
extern void func_021E9A78(char *p, const u8 *q, int x, int y, u8 *r);
extern int func_021E9B20(u8 *p);
extern int func_021D121C(void *);
extern u32 func_021D122C(void *);
extern void func_021D8394(void *, u8, u32);
extern void func_021D8434(void *);
int func_021D10B8(u8 *p, int *state)
{
    u8 *args;
    int choice;
    u32 count;
    switch (*state) {
    case 0:
        func_021EEC20(*(int *)(p + 0x50), &args);
        if (args[0] != 0x1F) {
            func_021EAF18(p + 0x58, 1, 0x14);
            func_021EAF50(p + 0x58, 1);
            func_021EAF50(p + 0x58, args[0]);
            func_021EAF78(p + 0x58, 0xFF);
            func_021EA614(*(void **)(p + 0x54), p + 0x58);
            *state = 1;
        } else *state = 4;
        break;
    case 1:
        func_021EA710(*(void **)(p + 0x54));
        if (func_021EA720(*(void **)(p + 0x54)) != 0) {
            func_021EAF18(p + 0x58, 3, 6);
            func_021EAF18(p + 0x7C, 3, 7);
            func_021EABC4(*(void **)(p + 0x54), p + 0x58, p + 0x7C, 1);
            *state = 2;
        }
        break;
    case 2:
        if (func_021EA710(*(void **)(p + 0x54)) != 0) {
            if (func_021EAC54(*(void **)(p + 0x54), &choice) != 0) {
                if (choice == 0) {
                    func_021D0B10(p, 0, 1, p + 0x184, p + 0x190);
                    func_021E9A78(*(void **)(p + 0x54), p + 0x184, 0, 0, p + 0x190);
                    *state = 3;
                } else *state = 4;
            }
        }
        break;
    case 3:
        if (func_021E9B20(*(void **)(p + 0x54)) != 0) {
            if (func_021D121C(p + 0x190) == 0) {
                count = func_021D122C(p + 0x190);
                if (count != 0 && count < 6) {
                    func_021D8394(p + 0x124, 0, count);
                    *state = 5;
                } else {
invalid:
                    *state = 4;
                }
            } else goto invalid;
        }
        break;
    case 4:
        func_021D8434(p + 0x124);
        *state = 5;
    case 5:
        *(u8 **)(p + 0xD8) = p + 0x124;
        *(int *)(p + 0xDC) = 4;
        return 1;
    }
    return 0;
}
