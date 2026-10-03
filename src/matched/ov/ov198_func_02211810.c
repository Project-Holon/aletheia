/*
 * function: func_02211810
 * address: 0x02211810
 * packet: pkt_ov198_02211810
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02211420 0x02211420 thumb ov198
 *   func_0221189C 0x0221189C thumb ov198
 *   func_0220BBF0 0x0220BBF0 thumb ov198
 *   func_0220C67C 0x0220C67C thumb ov198
 *   func_0220E27C 0x0220E27C thumb ov198
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_02211420(u8 *);
extern int func_0221189C(u8 *);
extern void func_0220BBF0(u8 *);
extern void func_0220C67C(u8 *);
extern void func_0220E27C(u8 *p);
int func_02211810(u8 *p)
{
    if (func_02211420(p) == 0) {
        if (func_0221189C(p) == 0) return 31;
        func_0220BBF0(p);
        func_0220C67C(p);
        func_0220E27C(p);
        return 3;
    }
    return 9;
}
