/*
 * function: func_021C3CC0
 * address: 0x021C3CC0
 * packet: pkt_ov136_021C3CC0
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02008FEC 0x02008FEC thumb
 *   func_02030734 0x02030734 arm
 *   func_02082AC0 0x02082AC0 arm
 *   func_02012EBC 0x02012EBC thumb
 *   func_02008F08 0x02008F08 thumb
 *   func_02008EAC 0x02008EAC thumb
 *   func_02008F48 0x02008F48 thumb
 *   d_021C7EE0 0x021C7EE0 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern const char d_021C7EE0[];
extern unsigned func_02008FEC(void *);
extern void *func_02030734(unsigned, unsigned, unsigned, const char *, unsigned);
extern void func_02082AC0(unsigned, void *, unsigned);
extern void *func_02012EBC(void *);
extern void *func_02008F08(unsigned);
extern void func_02008EAC(void *);
extern void func_02008F48(void *, unsigned, unsigned, void *);
void *func_021C3CC0(void *a, unsigned b, unsigned c, unsigned d, unsigned heap)
{
    u8 *p;
    unsigned v;
    v = func_02008FEC(a);
    p = func_02030734((u16)(((u16)heap & 0x7FFF) | 0x8000), 0x1C, 0, d_021C7EE0, 0x43);
    func_02082AC0(0, p, 0x1C);
    p[0xF] = d;
    p[0xE] = c;
    *(unsigned *)(p + 0x18) = v;
    *(u16 *)p = 1;
    *(unsigned *)(p + 8) = b;
    *(u16 *)(p + 0xC) = 0;
    *(void **)(p + 0x10) = func_02012EBC(a);
    *(void **)(p + 0x14) = func_02008F08((u16)heap);
    func_02008EAC(*(void **)(p + 0x14));
    func_02008F48(*(void **)(p + 0x14), 0xFF, c, a);
    return p;
}
