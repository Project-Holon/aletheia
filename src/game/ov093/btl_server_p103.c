/*
 * function: func_021CA8F8
 * address: 0x021CA8F8
 * packet: pkt_ov093_021CA8F8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: Five Thumb veneers at 021CA9D4, 021CA9E4, 021CA9F4,
 * 021CAA04, 021CAA14 each target 0x0689CB49 outside the image regions;
 * no outside code witness resolves their call relocations. The 220-byte
 * function is followed by these five 16-byte linker veneers.
 * symbols:
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021B8D8C 0x021B8D8C thumb ov093
 *   func_021CB174 0x021CB174 thumb ov093
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021CA9D4 0x021CA9D4 thumb ov093
 *   func_021CA9E4 0x021CA9E4 thumb ov093
 *   func_021CA9F4 0x021CA9F4 thumb ov093
 *   func_021CAA04 0x021CAA04 thumb ov093
 *   func_021CAA14 0x021CAA14 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 func_021D5440(u8 *);
extern int func_021B8D8C(void *, void *, u32);
extern void *func_021CB174(u8 *p, unsigned int n, int k);
extern u8 *func_021B9934(char *p, int i);
extern void func_021CA9D4(void *, void *);
extern void func_021CA9E4(void *, void *);
extern void func_021CA9F4(void *, void *);
extern void func_021CAA04(void *, void *);
extern void func_021CAA14(void *, void *);
int func_021CA8F8(u8 *p, u8 *a, int unused, u8 *q, int id, void *out)
{
    int n = func_021B8D8C(*(void **)(p + 4), *(void **)(p + 8), func_021D5440(a));
    u8 *b;
    switch (*(u32 *)(q + 12)) {
    case 0: case 3: case 4: case 5: case 9:
        if (id == 31) b = func_021CB174(p, n, 0);
        else b = (u8 *)func_021B9934(*(char **)(p + 8), id);
        func_021CA9D4(out, b);
        return 1;
    case 1: case 7:
        if (id == 31) func_021CA9E4(out, a);
        else func_021CA9E4(out, (void *)func_021B9934(*(char **)(p + 8), id));
        return 1;
    case 8:
        func_021CA9F4(out, a);
        func_021CAA04(out, func_021CB174(p, n, 0));
        return 2;
    case 13:
        if (id != 31) {
            func_021CAA14(out, (void *)func_021B9934(*(char **)(p + 8), id));
            return 1;
        }
        return 0;
    case 2: case 6: case 10: case 11: case 12: default:
        return 0;
    }
}
