/*
 * unit: yes
 * function: func_021C51C8, func_021C522C, func_021C5230
 * address: 0x021C51C8
 * packet: pkt_ov127_021C51C8
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: handed 021C51CA is the second push after 0F B4 at 021C51C8.
 * symbols:
 *   func_021C4B90 0x021C4B90 thumb ov127
 *   func_021C4B7C 0x021C4B7C thumb ov127
 *   func_021C4A00 0x021C4A00 thumb ov127
 *   func_021C5300 0x021C5300 thumb ov127
 */
typedef unsigned short u16;
typedef struct { u16 x, y; } Pos;
extern void func_021C4B90(void *, Pos);
extern void func_021C4B7C(void *, Pos);
extern void func_021C4A00(void *, unsigned int, int);
extern int func_021C5300(void *);
void func_021C51C8(void *p, Pos v, int n)
{
    func_021C4B90(p, v);
    func_021C4B7C(p, v);
    func_021C4A00(p, 6, n);
    func_021C4A00(p, 5, 11);
    func_021C4A00(p, 8, 0);
    func_021C4A00(p, 9, 16);
}
int func_021C522C(void) { return 0; }
int func_021C5230(void *p) { return func_021C5300(p); }
