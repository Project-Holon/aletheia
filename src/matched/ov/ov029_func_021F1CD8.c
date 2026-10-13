/*
 * function: func_021F1CD8
 * address:  0x021F1CD8
 * packet:   pkt_ov029_021F1CD8
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021F05B4  0x021F05B4  thumb  ov029
 *   GAME_BEACON_GetReceiveCount  0x02026C8C  thumb
 *   GAME_BEACON_GetNextNewLogIndex  0x02026CA0  thumb
 *   GAME_BEACON_GetLogByReceiveNo  0x02026C78  thumb
 *   func_02165CD8  0x02165CD8  thumb  ov010
 *   PALANM_CopyToSlot  0x020215BC  thumb
 *   d_021F33CC     0x021F33CC  data  ov029  a4
 */
#include "../include/Obj00042.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct PalAnmSlot;
extern int func_021F05B4(unsigned char *p);
struct S;
extern u32 GAME_BEACON_GetReceiveCount(void);
extern int GAME_BEACON_GetNextNewLogIndex(int *p);
extern void *GAME_BEACON_GetLogByReceiveNo(int n);
extern u8 func_02165CD8(struct S *p);
extern void PALANM_CopyToSlot(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);
extern const int d_021F33CC[];

void func_021F1CD8(char *p)
{
    int n;
    int cnt;
    int k;
    int tmp;
    void *e;

    cnt = 0;
    if (((struct Obj00042 *)p)->f45A == 0) {
        return;
    }
    if (func_021F05B4((unsigned char *)p) != 0) {
        return;
    }
    n = GAME_BEACON_GetReceiveCount();
    if (((struct Obj00042 *)p)->f450 == 0) {
        tmp = 0;
        if (GAME_BEACON_GetNextNewLogIndex(&tmp) != 30) {
            ((struct Obj00042 *)p)->f450 = 1;
        }
    }
    n--;
    for (k = 0; k < 30; k++) {
        if (cnt >= 10) {
            break;
        }
        if (n < 0) {
            PALANM_CopyToSlot((struct PalAnmSlot *)(*(int *)&((struct Obj00042 *)p)->f210), p + 0x1f8, (int)3, (u16)(d_021F33CC[cnt] * 2 + 0x60), 4);
            cnt++;
        } else {
            e = GAME_BEACON_GetLogByReceiveNo(n);
            if (e != 0) {
                PALANM_CopyToSlot((struct PalAnmSlot *)(*(int *)&((struct Obj00042 *)p)->f210), (u32 *)(p + 0x1b8) + func_02165CD8(e), (int)3,
                              (u16)(d_021F33CC[cnt] * 2 + 0x60), 4);
                cnt++;
            }
            n--;
        }
    }
}
