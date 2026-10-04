/*
 * function: func_02159F28
 * address: 0x02159F28
 * packet: pkt_ov010_02159F28
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding at 0x02159F52.
 * symbols:
 *   func_02159F04 0x02159F04 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Ent { u8 f00; u8 f01; u16 f02; u16 f04; } Ent;
extern Ent *func_02159F04(int, int);
struct BigObj;
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020143CC(u32, u32);
void func_02159F28(int a, int b, int flag)
{
    Ent *p = func_02159F04(a, b);
    u16 *q;
    if (p) {
        q = (u16 *)func_020143CC(func_0201296C((const struct BigObj *)a), p->f02);
        if (flag)
            *q = p->f04;
        else
            *q = 0;
    }
}
