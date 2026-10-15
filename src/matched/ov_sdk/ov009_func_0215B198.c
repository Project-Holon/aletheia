/*
 * function: CPSi_TcpWrite2Raw
 * address:  0x0215B198
 * packet:   pkt_ov009_0215B198
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_TcpWrite2Raw (libcps.TWL.HYB.a network.o)
 * symbols:
 *   OS_GetTick                       0x020870d0 arm
 *   tcp_write_do2                    0x0215b15c arm ov009
 *   func_02157390                    0x02157390 arm ov009
 *   gCpsNetVars                       0x021a826c data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct _CPSSoc {
    u8 pad0[8];
    u8 state;
    u8 pad1[0x34 - 9];
    u32 sndnxt;
    u16 remote_win;
    u8 pad2[2];
    u32 acked;
    u32 field40;
};

struct CPSVars {
    u8 pad0[0x18];
    int (*link_is_on)(void);
};

extern struct CPSVars gCpsNetVars;
extern unsigned long long OS_GetTick(void);
extern void tcp_write_do2(u8 *buf, u32 len, u8 *buf2, u32 len2, struct _CPSSoc *soc, int need_probe);
extern void func_02157390(void);

#define TICK() ((u32)(OS_GetTick() >> 16))

u32 CPSi_TcpWrite2Raw(u8 *buf, u32 len, u8 *buf2, u32 len2, struct _CPSSoc *soc)
{
    u32 total_written;
    u32 seqno;
    u32 start_time;
    u32 acked_len;
    int need_probe;

    total_written = 0;
    need_probe = 0;
    soc->field40 = 0;
    start_time = TICK();
    while (gCpsNetVars.link_is_on() && len != 0 && soc->state == 4 && (int)(TICK() - start_time) < 0x9f) {
        seqno = soc->sndnxt;
        tcp_write_do2(buf, len, buf2, len2, soc, need_probe);
        {
            u32 t = TICK();
            do {
                func_02157390();
                if (!gCpsNetVars.link_is_on())
                    break;
                if (soc->state != 4)
                    break;
                if (soc->sndnxt == soc->acked)
                    break;
                if ((int)(TICK() - t) >= 0xf)
                    break;
            } while (need_probe == 0 || soc->remote_win == 0);
        }
        acked_len = soc->acked - seqno;
        if (acked_len > soc->sndnxt - seqno)
            acked_len = 0;
        total_written += acked_len;
        if (acked_len != 0)
            start_time = TICK();
        soc->sndnxt = soc->acked;
        if (soc->state == 4 && soc->remote_win == 0 && acked_len == 0) {
            if (need_probe == 0) {
                u32 t = TICK();
                while (gCpsNetVars.link_is_on() && (int)(TICK() - t) < 0xf) {
                    func_02157390();
                    if (soc->remote_win != 0)
                        break;
                }
                if (soc->remote_win == 0)
                    need_probe = 1;
            }
        } else {
            need_probe = 0;
        }
        if (acked_len < len) {
            buf += acked_len;
            len -= acked_len;
        } else {
            buf = buf2 + (acked_len - len);
            len = len2 - (acked_len - len);
            buf2 = 0;
            len2 = 0;
        }
    }
    return total_written;
}
