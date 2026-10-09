/*
 * file:     union_comm_p04.c
 * unit:     yes
 * function: func_021730F8
 * address:  0x021730F8
 * packet:   pkt_ov012_021730F8
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   memcmp            0x0203EFC8  arm
 *   MI_CpuCopy8       0x02082D44  arm
 *   func_021731E0     0x021731E0  thumb  ov012
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Entry {
    u8 head[7];
    u8 lo : 4;
    u8 used : 1;
    u8 hi : 3;
    u8 body[0x5c];
    u8 mac[6];
    u8 state;
    u8 idx;
    u16 timer;
    u8 tail[0x1e];
} Entry;

extern int memcmp(const void *a, const void *b, int n);
extern void MI_CpuCopy8(const void *src, void *dst, int n);
extern int func_021731E0(u8 *self, Entry *info, const u8 *mac);

int func_021730F8(u8 *self, Entry *info, const u8 *mac)
{
    int i;
    Entry *tbl;

    tbl = (Entry *)(self + 0x2910);

    if (info->used != 1)
        return 0;

    for (i = 0; i < 10; i++) {
        Entry *e = &tbl[i];
        if (e->used == 1 && memcmp(mac, e->mac, 6) == 0) {
            MI_CpuCopy8(info, e, 0x64);
            if (tbl[i].state != 1)
                tbl[i].state = 2;
            tbl[i].timer = 450;
            return 1;
        }
    }

    if (func_021731E0(self, info, mac) == 0)
        return 0;

    for (i = 0; i < 10; i++) {
        if (tbl[i].used != 1) {
            u8 *dst = (u8 *)&tbl[i];
            MI_CpuCopy8(info, dst, 0x64);
            dst += 0x64;
            MI_CpuCopy8(mac, dst, 6);
            tbl[i].idx = i;
            tbl[i].state = 1;
            tbl[i].timer = 450;
            return 1;
        }
    }
    return 0;
}
