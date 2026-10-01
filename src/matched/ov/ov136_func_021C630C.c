/*
 * function: func_021C630C
 * address: 0x021C630C
 * packet: pkt_ov136_021C630C
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_021C6230 0x021C6230 thumb ov136
 */
typedef unsigned char u8;
extern void func_02045CAC(void *, unsigned int, void *);
extern void func_021C6230(u8 *);
void func_021C630C(u8 *p, unsigned int i)
{
    switch (i) {
    case 0: func_02045CAC(*(void **)(*(u8 **)(p + 8) + 0x1d0), 10, *(void **)(*(u8 **)(p + 8) + 0x1d8)); break;
    case 1: func_02045CAC(*(void **)(*(u8 **)(p + 8) + 0x1d0), 11, *(void **)(*(u8 **)(p + 8) + 0x1d8)); break;
    case 2: func_02045CAC(*(void **)(*(u8 **)(p + 8) + 0x1d0), 12, *(void **)(*(u8 **)(p + 8) + 0x1d8)); break;
    case 3: func_02045CAC(*(void **)(*(u8 **)(p + 8) + 0x1d0), 13, *(void **)(*(u8 **)(p + 8) + 0x1d8)); break;
    case 4: func_02045CAC(*(void **)(*(u8 **)(p + 8) + 0x1d0), 14, *(void **)(*(u8 **)(p + 8) + 0x1d8)); break;
    }
    func_021C6230(p);
}
