/*
 * function: FIELD_3DBG_LoadTexture
 * address:  0x021A16EC
 * packet:   pkt_ov021_021A16EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   G3D_SYSTEM_GetResourceSize  0x02046C94  arm
 *   ARC_TOOL_LoadHandleMember  0x02049250  arm
 *   G3D_SYSTEM_InitResourceByFile  0x02046CE0  arm
 *   G3D_SYSTEM_AllocVramTexture  0x02047180  arm
 *   g_Field3dbgSourceName  0x021DDE5C  data  ov021
 * Addresses are Black-image addresses.
 * `const u8 *s` is what schedules the second (u16)n truncation ahead of the
 * store of the allocation to d+8.
 */
#include "../include/Obj02379.h"
#include "../include/Obj04231.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct S02046CE0;
extern int G3D_SYSTEM_GetResourceSize(void);
extern void *ARC_TOOL_LoadHandleMember(void *h, u32 id, u16 heap);
extern void G3D_SYSTEM_InitResourceByFile(struct S02046CE0 *out, u32 *tag);
extern int G3D_SYSTEM_AllocVramTexture(u32 *p);
extern const char g_Field3dbgSourceName[];

void FIELD_3DBG_LoadTexture(u8 *d, void *a, const u8 *s, u32 n)
{
    void *r;

    d[0] = s[2];
    d[1] = s[3];
    d[2] = s[4];
    d[3] = s[5];
    d[4] = s[6];
    d[5] = s[7];
    ((struct Obj02379 *)d)->f8 = func_02030734((u16)n, G3D_SYSTEM_GetResourceSize(), 1, g_Field3dbgSourceName, 0x2ad);
    r = ARC_TOOL_LoadHandleMember(a, *(const u16 *)&((struct Obj04231 *)s)->f0, n);
    G3D_SYSTEM_InitResourceByFile(((struct Obj02379 *)d)->f8, r);
    G3D_SYSTEM_AllocVramTexture(((struct Obj02379 *)d)->f8);
    d[6] = 1;
    d[7] = 1;
}
