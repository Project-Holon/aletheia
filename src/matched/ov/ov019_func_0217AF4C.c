/*
 * function: UNION_CHARA_CheckTalkable
 * address:  0x0217AF4C
 * packet:   pkt_ov019_0217AF4C
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad[0x6b];
    u8 f6b;
    u16 f6c;
} Obj;

typedef struct {
    Obj *f0;
    u8 pad4[2];
    u8 f6, f7, f8, f9;
    u8 pad[2];
} Ent;

int UNION_CHARA_CheckTalkable(char *a, u16 key)
{
    Ent *p;
    int i;

    p = (Ent *)(a + 0x2E88);
    for (i = 0; i < 50; i++, p++) {
        if (p->f7 == 1 && p->f0 != 0 && p->f0->f6c != 0
            && key == ((p->f0->f6b << 8) | (p->f6 + 0x20))) {
            if (p->f8 == 2 || p->f8 == 1 || (u8)(p->f9 + 0xff) <= 1)
                return 0;
            return 1;
        }
    }
    return 0;
}
