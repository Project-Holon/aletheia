/*
 * function: GDS_SOCKET_Connect
 * address: 0x021D7FA0
 * packet: pkt_ov125_021D7FA0
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * lever: port byte swap keeps both explicit masks; timeout casts after unsigned 64-bit subtraction, preserving the original subs before the signed comparison.
 * symbols:
 *   gGdsSocket 0x021D9E40 data a4
 *   gGdsHostTail 0x021DA040 data a4
 *   OS_GetTick 0x020870D0 arm
 *   _ll_udiv 0x0209C00C arm
 *   func_0215F480 0x0215F480 arm ov009
 *   GDS_SOCKET_Lock 0x021D7CAC arm ov125
 *   GDS_SOCKET_Unlock 0x021D7CC0 arm ov125
 *   GDS_SOCKET_Sleep 0x021D8438 arm ov125
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct { u8 size, family; u16 port; u32 address; } Address;
extern u32 gGdsSocket[];
extern u8 gGdsHostTail[];
extern u64 OS_GetTick(void);
extern int func_0215F480(int, const Address *);
extern void GDS_SOCKET_Lock(void);
extern void GDS_SOCKET_Unlock(void);
extern void GDS_SOCKET_Sleep(int);
int GDS_SOCKET_Connect(void)
{
    Address address;
    int start, result;
    address.size = 8;
    address.family = 2;
    address.port = ((*(u16 *)(gGdsHostTail + 0x40) >> 8) & 0xff) | ((*(u16 *)(gGdsHostTail + 0x40) << 8) & 0xff00);
    address.address = gGdsSocket[0x264/4];
    start = OS_GetTick() / 0x7fd88;
    for (;;) {
        result = func_0215F480(gGdsSocket[0x26c/4], &address);
        if (result >= 0) break;
        if (result == -26) {
            if (gGdsSocket[0x244/4] != 0 && (int)((OS_GetTick() / 0x7fd88) - start) >= (int)gGdsSocket[0x244/4]) {
                gGdsSocket[0x250/4] = 10;
                return 0;
            }
        } else {
            if (result == -30) break;
            gGdsSocket[0x250/4] = 7;
            return 0;
        }
        GDS_SOCKET_Lock();
        if (gGdsSocket[0x268/4] == 1) {
            gGdsSocket[0x250/4] = 13;
            GDS_SOCKET_Unlock();
            return 0;
        }
        GDS_SOCKET_Unlock();
        GDS_SOCKET_Sleep(1);
    }
    return 1;
}
