/*
 * function: PMi_ProceedToExit
 * address:  0x027314A4
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   PMi_TryLockForReset 0x02731718 arm
 *   PMi_ExecuteList 0x0208C7E0 arm
 *   PM_ReadyToExit 0x027314F0 arm
 *   d_02153000 0x02153000 data
 *   d_020A8724 0x020A8724 data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct PMiGenCallbackInfo PMiGenCallbackInfo;
extern int PMi_TryLockForReset(void);
extern void PMi_ExecuteList(PMiGenCallbackInfo *listp);
extern void PM_ReadyToExit(void);
extern u32 d_020A8724[];
typedef struct {
    u8 pad[0x14];
    u32 f14;
} S2153;
extern S2153 d_02153000;
#define G2153 (&d_02153000)

void PMi_ProceedToExit(u32 x)
{
    PMiGenCallbackInfo *list;
    if (PMi_TryLockForReset() == 0) {
        return;
    }
    list = *(PMiGenCallbackInfo **)0x02732FA4;
    G2153->f14 = x;
    PMi_ExecuteList(list);
    if (d_020A8724[1] != 0) {
        PM_ReadyToExit();
    }
}
