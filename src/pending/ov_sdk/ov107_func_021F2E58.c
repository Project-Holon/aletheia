/*
 * function: func_021F2E58
 * address:  0x021F2E58
 * packet:   pkt_ov107_021F2E58
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * sdk:      MBi_calc_sendblock (mb_parent.o)
 *
 * symbols:
 *   g_021F6EEC  0x021F6EEC  data
 *   g_021F6FA0  0x021F6FA0  data
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad0[0x1d48];
    u16 a;
    u16 b;
    u16 c;
    u8 pad1[0x1d52 - 0x1d4e];
    u8 flag;
} Ent;

extern int g_021F6EEC;
extern u8 *g_021F6FA0;

void func_021F2E58(u8 file_id)
{
    Ent *e;
    if (!(g_021F6EEC & (1 << file_id)))
        return;
    e = (Ent *)(g_021F6FA0 + file_id * 0x5d4);
    if (e->flag != 0 && e->c != 0) {
        u16 x = e->a;
        u16 y = e->b;
        if (y <= x) {
            if (x <= y + 2)
                e->a = x + 1;
        } else {
            e->a = y;
        }
        return;
    }
}
