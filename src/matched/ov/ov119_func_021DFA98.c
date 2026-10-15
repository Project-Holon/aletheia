/*
 * function: POKETRADE_NEGO_PlaySeByKeyB
 * address: 0x021DFA98
 * packet: pkt_ov119_021DFA98
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gPlaySeByKeyBTable 0x021E7794 data a4
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
typedef struct { int id; int key; } Ent;
typedef struct { Ent e[22]; } Tbl;
extern const Tbl gPlaySeByKeyBTable;
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
void POKETRADE_NEGO_PlaySeByKeyB(int key)
{
    Tbl t = gPlaySeByKeyBTable;
    unsigned i;
    for (i = 0; i < 22; i++) {
        if (key == t.e[i].key) {
            GFL_USE_PlaySeDefaultVolume(t.e[i].id);
        }
    }
}
