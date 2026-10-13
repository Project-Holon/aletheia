/*
 * function: UNION_CHARA_CheckMemberUnique
 * address:  0x0217B158
 * packet:   pkt_ov019_0217B158
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   memcmp  0x0203EFC8  arm
 */

typedef unsigned short u16;
typedef unsigned char u8;

struct sub {
    u8 mac[6];
    u8 pad;
    u8 : 1;
    u8 f : 1;
    u8 : 6;
};

struct ent {
    u8 pad0[7];
    u8 : 4;
    u8 on : 1;
    u8 : 3;
    u8 pad1[0x20];
    struct sub s[5];
    u8 pad2[0x1c];
    u16 cnt;
    u8 pad3[0x1e];
};

extern int memcmp(const void *a, const void *b, int n);

int UNION_CHARA_CheckMemberUnique(char *base, struct ent *excl, u8 *mac)
{
    struct ent *q = (struct ent *)(base + 0x2910);
    int i;
    int j;

    for (i = 0; i < 10; i++, q++) {
        if (q == excl || q->on != 1) {
            continue;
        }
        for (j = 0; j < 5; j++) {
            if (q->s[j].f == 1 && memcmp(mac, q->s[j].mac, 6) == 0) {
                if (q->cnt != 0) {
                    q->cnt = 1;
                }
                return 0;
            }
        }
    }
    return 1;
}
