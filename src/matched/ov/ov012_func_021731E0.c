/*
 * function: UNION_COMM_IsNotGroupMember
 * address:  0x021731E0
 * packet:   pkt_ov012_021731E0
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   memcmp  0x0203EFC8  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 mac[6];
    u8 pad;
    u8 a : 1;
    u8 valid : 1;
} Rec;

typedef struct Entry {
    u8 head[7];
    u8 lo : 4;
    u8 used : 1;
    u8 hi : 3;
    u8 pad[0x20];
    Rec recs[5];
    u8 pad2[0x14];
    u8 mac[6];
    u8 state;
    u8 idx;
    u16 timer;
    u8 tail[0x1e];
} Entry;

extern int memcmp(const void *a, const void *b, int n);

int UNION_COMM_IsNotGroupMember(u8 *self, Entry *info, const u8 *mac)
{
    int i;
    Entry *e;
    int j;

    e = (Entry *)(self + 0x2910);

    for (i = 0; i < 10; i++, e++) {
        if (e->used == 1) {
            for (j = 0; j < 5; j++) {
                if (e->recs[j].valid == 1 && memcmp(mac, &e->recs[j], 6) == 0) {
                    if (e->timer != 0) {
                        e->timer = 1;
                    }
                    return 0;
                }
            }
        }
    }
    return 1;
}
