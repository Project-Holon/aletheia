/*
 * function: func_021C54EC
 * address: 0x021C54EC
 * packet: pkt_ov127_021C54EC
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C4AC4 0x021C4AC4 thumb ov127
 *   func_021C4A54 0x021C4A54 thumb ov127
 *   func_021C4844 0x021C4844 thumb ov127
 */
typedef unsigned short u16;
typedef struct { short x, y; } Pos;
extern Pos func_021C4AC4(void *);
extern Pos func_021C4A54(Pos, int);
typedef unsigned char  u8;
extern int func_021C4844(u8 *p, u16 x, u16 y);
int func_021C54EC(void *p, void *q, int n)
{
    Pos b = func_021C4AC4(p);
    Pos d = func_021C4A54(b, n);
    return func_021C4844(q, d.x / 16, d.y / 16);
}
