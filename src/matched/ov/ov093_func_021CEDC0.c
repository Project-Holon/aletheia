/*
 * function: func_021CEDC0
 * address: 0x021CEDC0
 * packet: pkt_ov093_021CEDC0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021CF8D4 0x021CF8D4 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021E9A78 0x021E9A78 thumb ov093
 *   func_021CE0BC 0x021CE0BC thumb ov093
 *   func_021E9B14 0x021E9B14 thumb ov093
 *   func_021E9B20 0x021E9B20 thumb ov093
 *   func_021CEE98 0x021CEE98 thumb ov093
 *   func_021CEEA8 0x021CEEA8 thumb ov093
 *   func_021D8394 0x021D8394 thumb ov093
 *   func_021CE150 0x021CE150 thumb ov093
 *   func_021CF220 0x021CF220 thumb ov093
 *   func_021CE4D0 0x021CE4D0 thumb ov093
 *   func_021CE3C8 0x021CE3C8 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_021CF8D4(u8 *, void *, u8 *, u16 *);
extern u8 func_021D5440(u8 *p);
extern void func_021E9A78(char *, const u8 *, int, int, u8 *);
extern int func_021CE0BC(u8 *p, void *q);
extern void func_021E9B14(unsigned int *p);
extern int func_021E9B20(u8 *p);
extern u32 func_021CEE98(u8 *);
extern u32 func_021CEEA8(u8 *);
extern void func_021D8394(void *, u8, u32);
extern void func_021CE150(u8 *p, void *q);
extern u32 func_021CF220(u8 *p, int *st);
extern u32 func_021CE4D0(u8 *);
extern int func_021CE3C8(u8 *p, int *state);

u32 func_021CEDC0(u8 *p, int *st)
{
    u8 a;
    u16 b;
    u32 r, n;
    switch (*st) {
    case 0:
        r = 0;
        if ((u8)func_021CF8D4(p, *(void **)(p + 8), &a, &b) != 4 ||
            a == func_021D5440(*(void **)(p + 8))) r = 1;
        func_021E9A78(*(char **)(p + 0x54), p + 0x184, p[0x11d], r, p + 0x190);
        ++*st;
        break;
    case 1:
        r = 0;
        if (func_021CE0BC(p, 0)) {
            func_021E9B14((unsigned int *)(*(u32 *)(p + 0x54)));
            *st = 2;
            return r;
        }
        if (func_021E9B20((u8 *)(*(u32 *)(p + 0x54)))) {
            if (func_021CEE98(p + 0x190) == 0) {
                n = func_021CEEA8(p + 0x190);
                if (n < 6) {
                    func_021D8394(*(void **)(p + 0xc), p[0x11d], n);
                    func_021CE150(p, (void *)((u32)func_021CF220));
                    break;
                }
            }
            func_021CE150(p, (void *)((u32)func_021CE4D0));
        }
        break;
    case 2:
        if (func_021E9B20((u8 *)(*(u32 *)(p + 0x54)))) func_021CE150(p, (void *)((u32)func_021CE3C8));
        break;
    }
    return 0;
}
