/*
 * function: func_021DDF5C
 * address: 0x021DDF5C
 * packet: pkt_ov183_021DDF5C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_021FB494 0x021FB494 thumb ov186
 *   func_021FC0C8 0x021FC0C8 thumb ov186
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 */
typedef unsigned char  u8;
extern void func_021FC734(u8 *p);
extern void func_021FB494(char *p);
extern void func_021FC0C8(char *p, unsigned i);
extern void func_021FBDA4(int a, unsigned mode);
void func_021DDF5C(char *p, char *q)
{
    int i;
    char *slot;
    for (i = 0; i < 4; i++) {
        slot = p + i * 4;
        if (*(void **)(slot + 0x24)) {
            func_021FC734(*(void **)(slot + 0x24));
            *(int *)(slot + 0x24) = 0;
        }
    }
    if (*(void **)(p + 0x20)) {
        func_021FB494(*(void **)(p + 0x20));
        *(int *)(p + 0x20) = 0;
    }
    func_021FC0C8((char *)(*(int *)(q + 8)), 6);
    func_021FBDA4(*(int *)(q + 8), 9);
}
