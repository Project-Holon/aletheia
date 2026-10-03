/*
 * function: func_021DFA98
 * address: 0x021DFA98
 * packet: pkt_ov119_021DFA98
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021E7794 0x021E7794 data a4
 *   func_020061E4 0x020061E4 thumb
 */
typedef struct { int id; int key; } Ent;
typedef struct { Ent e[22]; } Tbl;
extern const Tbl d_021E7794;
typedef unsigned int   u32;
extern void func_020061E4(u32 a);
void func_021DFA98(int key)
{
    Tbl t = d_021E7794;
    unsigned i;
    for (i = 0; i < 22; i++) {
        if (key == t.e[i].key) {
            func_020061E4(t.e[i].id);
        }
    }
}
