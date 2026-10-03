/*
 * unit: yes
 * function: func_021C5278, func_021C52B8, func_021C52BC, func_021C52C4
 * address: 0x021C5278
 * packet: pkt_ov127_021C5278
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C5300 0x021C5300 thumb ov127
 *   func_021C4AC4 0x021C4AC4 thumb ov127
 *   func_021C4B90 0x021C4B90 thumb ov127
 */
typedef unsigned short u16;
typedef struct { u16 x, y; } Pos;
typedef unsigned char  u8;
extern int func_021C5300(u8 *p);
extern Pos func_021C4AC4(void *);
extern void func_021C4B90(void *, Pos);
int func_021C5278(void *p)
{
    int r = func_021C5300(p);
    if (r == 1) {
        Pos v = func_021C4AC4(p);
        func_021C4B90(p, v);
    }
    return r;
}
int func_021C52B8(void) { return 0; }
int func_021C52BC(void *p) { return func_021C5300(p); }
int func_021C52C4(void *p) { return func_021C5300(p); }
