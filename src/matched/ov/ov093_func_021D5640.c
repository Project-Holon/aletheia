/*
 * function: func_021D5640
 * address: 0x021D5640
 * packet: pkt_ov093_021D5640
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02017E40 0x02017E40 thumb
 */
typedef unsigned char u8;
extern void func_02017E40(void *p, unsigned int id, unsigned int v);
typedef unsigned int u32;
struct Entry { u8 pad0[2]; u8 a; u8 pad3[9]; u8 flag; u8 rest; };
struct Work { void *obj; u8 pad4[0x100]; struct Entry e[]; };
void func_021D5640(struct Work *p, u32 i, u32 n)
{
    int v;
    if (p->e[i].flag == 0) {
        v = (int)((u32)p->e[i].a - n);
        if (v < 0) v = 0;
        p->e[i].a = v;
        func_02017E40(p->obj, i + 0x3a, p->e[i].a);
    }
}
