/*
 * function: GAME_BEACON_SEARCH_PollScanResult
 * address:  0x02164D6C
 * packet:   pkt_ov010_02164D6C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Per-frame poll: state 1 finishes a request; otherwise, while the 9-byte
 * record at +0x74 is empty, picks an entry with GAME_BEACON_SEARCH_PickBestScanResult and copies it in.
 *
 * symbols:
 *   GFL_NET_EndDeviceWrapper  0x0203D0FC  arm
 *   GAME_BEACON_SEARCH_PickBestScanResult  0x02164E04  thumb ov010
 *   MI_CpuFill8  0x02082BCC  arm
 *   GFL_NET_GetScanResultMac  0x0203CF3C  arm
 *   GAME_BEACON_ReceiveInfo  0x02026A60  thumb
 *   NET_WHPIPE_ReleaseEntry  0x02177BF4  thumb ov014
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09313.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Ent {
    u8 b0;
    u8 lo : 4;
    u8 hi : 4;
    u8 flag : 1;
    u8 kind : 5;
    u8 rest : 2;
} Ent;

extern void  GFL_NET_EndDeviceWrapper(int a);
extern Ent  *GAME_BEACON_SEARCH_PickBestScanResult(u8 *obj, int *out);
extern void  MI_CpuFill8(void *dst, int v, int n);
extern void *GFL_NET_GetScanResultMac(u32 a);
struct Req;
extern int GAME_BEACON_ReceiveInfo(struct Req *r);
extern void NET_WHPIPE_ReleaseEntry(unsigned int idx);

u8 *GAME_BEACON_SEARCH_PollScanResult(u8 *obj, int *arg)
{
    Ent *e;
    u8 *src;
    int i;
    u8 *rec = obj + 0x74;
    if (((struct Obj09313 *)obj)->f4 == 0) {
        return 0;
    }
    if (((struct Obj09313 *)obj)->f4 == 1) {
        GFL_NET_EndDeviceWrapper(0);
        ((struct Obj09313 *)obj)->f4 = 2;
        return 0;
    }
    if (rec[0] == 0) {
        e = GAME_BEACON_SEARCH_PickBestScanResult(obj, arg);
        if (e != 0) {
            if (e->flag != 0) {
                NET_WHPIPE_ReleaseEntry(*arg);
            } else if (e->kind == 1) {
                i = 0;
                MI_CpuFill8(rec, 0, 9);
                rec[0] = e->b0;
                rec[1] = e->lo;
                rec[2] = e->hi;
                src = GFL_NET_GetScanResultMac((u32)*arg);
                for (i = 0; i < 6; i++) {
                    rec[3 + i] = src[i];
                }
            } else if (e->kind == 2) {
                GAME_BEACON_ReceiveInfo((struct Req *)((u8 *)e + 8));
                NET_WHPIPE_ReleaseEntry(*arg);
            }
        }
    }
    if (rec[0] == 0) {
        rec = 0;
    }
    return rec;
}
