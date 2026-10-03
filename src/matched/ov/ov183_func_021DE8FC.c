/*
 * function: func_021DE8FC
 * address: 0x021DE8FC
 * packet: pkt_ov183_021DE8FC
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
typedef unsigned short u16;
extern void func_021FC734(void *);
extern void func_021FB494(void *);
extern void func_021FC0C8(int, int);
extern void func_021FBDA4(int, int);
void func_021DE8FC(char *p, char *q)
{
    int i;
    for (i = 0; i < 3; i++) {
        char *slot = p + i * 4;
        if (*(void **)(slot + 0x10)) {
            func_021FC734(*(void **)(slot + 0x10));
            *(void **)(slot + 0x10) = 0;
        }
    }
    if (*(void **)(p + 0xc)) {
        func_021FB494(*(void **)(p + 0xc));
        *(void **)(p + 0xc) = 0;
    }
    func_021FC0C8(*(int *)(q + 8), 6);
    func_021FBDA4(*(int *)(q + 8), 15);
}
