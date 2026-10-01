/*
 * function: func_021E237C
 * address: 0x021E237C
 * packet: pkt_ov093_021E237C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Word return from func_021E896C reserves the unused aggregate slot;
 * u8 c schedules its stack reload after the zero store at 021E23CE.
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021D70A8 0x021D70A8 thumb ov093
 *   func_021E896C 0x021E896C thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   func_021C7D00 0x021C7D00 thumb ov093
 *   func_021C8120 0x021C8120 thumb ov093
 *   func_021C7F68 0x021C7F68 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Word { u32 v; } Word;
extern int func_021D775C(int);
extern void *func_021C7CF4(void *, int);
extern int func_021D62C4(void *, int);
extern u8 *func_021C88A4(void *, int, int);
extern int func_021D70A8(void *);
extern Word func_021E896C(int, int);
extern void func_021C8838(void *, int, int);
extern void func_021C8860(void *, u32);
extern void func_021C88C8(void *, void *);
extern u32 func_021C7D00(void *, int);
extern u8 *func_021C8120(void *, int);
extern int func_021C7F68(void *, u16, u8 *);
void func_021E237C(void *a, void *b, u8 c, u8 *d)
{
    u8 *p;
    u8 *buf;
    u32 flags;
    unsigned i;
    u8 *entry;
    if (c != func_021D775C(3)) return;
    if (func_021D62C4(func_021C7CF4(b, c), 25) != 0) return;
    if (*(u32 *)(d + 24) != 0) return;
    p = func_021C88A4(b, 12, c);
    *(u32 *)(p + 4) = 25;
    *(Word *)(p + 8) = func_021E896C(3, func_021D70A8(a));
    p[12] = 0;
    p[15] = c;
    func_021C88C8(b, p);
    p = func_021C88A4(b, 4, c);
    func_021C8838(p + 4, 2, 703);
    func_021C8860(p + 4, c);
    func_021C88C8(b, p);
    flags = func_021C7D00(b, c);
    buf = func_021C8120(b, 7);
    buf[0] = func_021C7F68(b, flags | 0x800, buf + 1);
    for (i = 0; i < buf[0]; i++) {
        entry = buf + i;
        if (func_021D62C4(func_021C7CF4(b, entry[1]), 2) != 0) {
            p = func_021C88A4(b, 11, c);
            *(u32 *)(p + 4) = 2;
            p[20] = 1;
            p[8] = entry[1];
            func_021C8838(p + 24, 2, 706);
            func_021C8860(p + 24, entry[1]);
            func_021C88C8(b, p);
        }
    }
    *(u32 *)(d + 24) = 1;
}
