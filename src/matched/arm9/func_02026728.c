/*
 * function: GAME_BEACON_Update
 * address:  0x02026728
 * packet:   pkt_020266E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GAME_DATA_GetPlayTime  0x02012FCC  thumb
 *   func_0200864C  0x0200864C  thumb
 *   GAME_BEACON_SetPlayTime  0x020272EC  thumb
 *   GAME_BEACON_UpdateActionTime  0x02026824  thumb
 *   GAME_BEACON_Work     0x02146940  data
 */
#include "../include/Obj06914.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed int     s32;
typedef unsigned int   u32;

struct Obj;

extern char *GAME_BEACON_Work;

extern int  GFL_NET_GetRunState(void);
extern int GAME_DATA_GetPlayTime(int p0);
struct PlayTime;
extern u16 func_0200864C(const struct PlayTime *p);
extern void GAME_BEACON_SetPlayTime(s32 a);
extern void GAME_BEACON_UpdateActionTime(struct Obj *o);

void GAME_BEACON_Update(void)
{
    char *p;
    s32 v;
    s32 i;

    p = GAME_BEACON_Work;
    if (p == 0) {
        return;
    }
    if (GFL_NET_GetRunState() == 0) {
        return;
    }
    if (((struct Obj06914 *)p)->f0 != 0) {
        v = func_0200864C((const struct PlayTime *)GAME_DATA_GetPlayTime(((struct Obj06914 *)p)->f0));
        if (((struct Obj06914 *)p)->fBB0 != v) {
            switch (v) {
            case 0xa:
            case 0x1e:
            case 0x32:
            case 0x64:
                GAME_BEACON_SetPlayTime(v);
                break;
            }
        }
        ((struct Obj06914 *)p)->fBB0 = (u16)v;
    }
    GAME_BEACON_UpdateActionTime((struct Obj *)(p + 4));
    for (i = 0; i < 0x1e; i++) {
        if (*(u8 *)(p + i * 0x60 + 0x64) != 0) {
            if (*(u16 *)(p + i * 0x60 + 0xc0) < 0xffff) {
                *(u16 *)(p + i * 0x60 + 0xc0) += 1;
            }
        }
    }
}
