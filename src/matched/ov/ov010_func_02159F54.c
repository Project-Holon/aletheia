/*
 * function: func_02159F54
 * address: 0x02159F54
 * packet: pkt_ov010_02159F54
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02159F04 0x02159F04 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Ent { u8 f00; u8 f01; u16 f02; u16 f04; } Ent;
extern Ent *func_02159F04(int, int);
extern u32 func_0201296C(int);
extern u32 func_020143CC(u32, u32);
int func_02159F54(int a, int b)
{
    Ent *p = func_02159F04(a, b);
    u16 *q;
    if (p) {
        q = (u16 *)func_020143CC(func_0201296C(a), p->f02);
        if (p->f04 == *q)
            return 1;
        else
            return 0;
    }
    return 0;
}
