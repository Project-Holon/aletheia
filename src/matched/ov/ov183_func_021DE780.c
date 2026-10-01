/*
 * function: func_021DE780
 * address: 0x021DE780
 * packet: pkt_ov183_021DE780
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two trailing zero bytes are alignment padding before the next labelled function.
 * symbols:
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_021FD15C 0x021FD15C thumb ov186
 */
extern void func_021FC734(void *);
extern void func_021FBDA4(int, int);
extern void func_021FD15C(void *, int);
void func_021DE780(char *p, char *q)
{
    int i;
    for (i = 0; i < 18; i++) {
        char *slot = p + i * 4;
        if (*(void **)(slot + 0x1C) != 0) {
            func_021FC734(*(void **)(slot + 0x1C));
            *(void **)(slot + 0x1C) = 0;
        }
    }
    func_021FBDA4(*(int *)(q + 8), 17);
    if (*(void **)(p + 8) != 0) {
        func_021FD15C(*(void **)(p + 8), *(int *)(q + 8));
        *(void **)(p + 8) = 0;
    }
}
