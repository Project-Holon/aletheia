/*
 * function: BTL_MAIN_StoreRecorderEntry
 * address:  0x021BA6C0
 * packet:   pkt_ov093_021BA6C0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_IsRecordingActive  0x021B90F8  thumb  ov093
 *   BTL_CLIENT_ReadRecorderEntry  0x021CD924  thumb  ov093
 *   MI_CpuCopy8  0x02082D44  arm
 */
#include "../include/Obj00324.h"
#include "../include/Obj21018.h"
#include "../include/Obj21019.h"

typedef unsigned char u8;

struct T {
    int w[6];
};

typedef unsigned short u16;
typedef unsigned int   u32;
extern int BTL_MAIN_IsRecordingActive(u8 *p);
extern u16 *BTL_CLIENT_ReadRecorderEntry(u8 *p, u32 *out);
extern void MI_CpuCopy8(void *, void *, int);

void BTL_MAIN_StoreRecorderEntry(char *p)
{
    int n;
    void *src;

    if (BTL_MAIN_IsRecordingActive((u8 *)p)) {
        src = BTL_CLIENT_ReadRecorderEntry(*(void **)(p + (u8)p[0x46c] * 4 + 0x10), (u32 *)(&n));
        if (src) {
            MI_CpuCopy8(src, ((struct Obj21018 *)(*(char * *)&((struct Obj00324 *)p)->f0))->f94, n);
            ((struct Obj21019 *)(*(char * *)&((struct Obj00324 *)p)->f0))->f98 = n;
            *(struct T *)(*(char * *)&((struct Obj00324 *)p)->f0 + 0x9c) = *(struct T *)(p + 0x3f0);
        }
    }
}
