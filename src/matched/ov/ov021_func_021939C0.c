/*
 * function: FIELD_WFBC_DisableUnusedConnects
 * address:  0x021939C0
 * packet:   pkt_ov021_021939C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ARC_TOOL_GetHandleMemberSize  0x020493D4  arm
 *   ARC_TOOL_LoadHandleMember  0x02049250  arm
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   FIELD_WFBC_BLOCK_IsPlaced  0x02194044  thumb  ov021
 *   EVENTDATA_SYSTEM_DisableConnect  0x0216245C  thumb  ov010
 *   sConnectListMemberIds     0x021D3F60  data  a4
 *   sFieldWfbcFileName     0x021DDA60  data  a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07440.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u16 a; u16 b; u32 c; } Ent;

extern int sConnectListMemberIds[];
extern int sFieldWfbcFileName;
struct ArcFile;
extern u32 ARC_TOOL_GetHandleMemberSize(struct ArcFile *arc, u32 member);
extern Ent *ARC_TOOL_LoadHandleMember(int h, int a, u16 heap);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern int FIELD_WFBC_BLOCK_IsPlaced(u8 *p, u16 a, u16 b);
extern void EVENTDATA_SYSTEM_DisableConnect(u8 *o, u16 idx);

void FIELD_WFBC_DisableUnusedConnects(u8 *o, void *dst, int skip, u32 heap)
{
    u32 n;
    Ent *e;
    u32 *seen;
    u32 cnt;
    u32 i;
    u32 j;
    Ent *cur;

    if (skip != 0)
        return;
    n = ARC_TOOL_GetHandleMemberSize((struct ArcFile *)(((struct Obj07440 *)o)->f10), sConnectListMemberIds[*o]);
    heap = (heap & 0x7FFF) | 0x8000;
    e = ARC_TOOL_LoadHandleMember(((struct Obj07440 *)o)->f10, sConnectListMemberIds[*o], (u16)heap);
    n >>= 3;
    seen = func_02030734((u16)heap, n * 4, 1, (const char *)&sFieldWfbcFileName, 0x208);
    cnt = 0;
    for (i = 0; i < n; i++) {
        cur = &e[i];
        if (FIELD_WFBC_BLOCK_IsPlaced(o + 0x18, e[i].a, cur->b)) {
            seen[cnt] = cur->c;
            cnt++;
        } else {
            for (j = 0; j < cnt; j++) {
                if (seen[j] == e[i].c)
                    break;
            }
            if (j >= cnt) {
                for (j = i + 1; j < n; j++) {
                    if (cur->c == e[j].c)
                        break;
                }
                if (j >= n)
                    EVENTDATA_SYSTEM_DisableConnect(dst, (u16)cur->c);
            }
        }
    }
    func_020307B0(seen);
    func_020307B0(e);
}
