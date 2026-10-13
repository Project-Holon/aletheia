/*
 * function: OEKAKI_InitWork
 * address:  0x021849F8
 * packet:   pkt_ov023_021849F8
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STRBUF_Create  0x020457B0  arm
 *   OEKAKI_GetJoinedBits  0x02186558  thumb  ov023
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   OEKAKI_SetNextScene  0x02186444  thumb  ov023
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   func_02030734  0x02030734  arm
 *   gOekakiFileName     0x02186F58  data  ov023  a4
 */
#include "../include/Obj00049.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u8 e:3; u8 f:3; u8 g:2; u8 h[5]; } Rec;

extern char gOekakiFileName[];
struct MsgBank;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern int OEKAKI_GetJoinedBits(char *p);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void OEKAKI_SetNextScene(char *p, u32 v);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

void OEKAKI_InitWork(u8 *p)
{
    int i = 0;
    int z = i;

    for (; i < 5; i++) {
        *(u32 *)(p + i * 4 + 0x18) = (u32)STRBUF_Create(8, 0x28);
        ((Rec *)(p + 0x4216))[i].f = 0;
        *(u16 *)(p + i * 4 + 0x4232) = z;
        *(u32 *)(p + 0x1C8 + i * 8) = z;
        *(u32 *)(p + 0x1CC + i * 8) = z;
    }
    ((struct Obj00049 *)p)->f2C = (u32)STRBUF_Create(0xA, 0x28);
    ((struct Obj00049 *)p)->f30 = (u32)STRBUF_Create(0x50, 0x28);
    ((struct Obj00049 *)p)->f420A = z;
    ((struct Obj00049 *)p)->f420B = 1;
    ((struct Obj00049 *)p)->f9E6C = 1;
    ((struct Obj00049 *)p)->f9E70 = z;
    ((struct Obj00049 *)p)->f1AC = 2;
    ((struct Obj00049 *)p)->f1B0 = OEKAKI_GetJoinedBits((char *)p);
    ((struct Obj00049 *)p)->f9E74 = z;
    ((struct Obj00049 *)p)->f9E78 = z;
    ((struct Obj00049 *)p)->f198 = z;
    ((struct Obj00049 *)p)->f9E7C = z;
    ((struct Obj00049 *)p)->f9E80 = z;
    ((struct Obj00049 *)p)->f178 = z;
    GFL_NET_SYSTEM_GetCurrentAid();
    OEKAKI_SetNextScene((char *)p, 4);
    MSGDATA_ReadString((struct MsgBank *)(*(u32 *)&((struct Obj00049 *)p)->f14), 7, (void *)(((struct Obj00049 *)p)->f2C));
    ((struct Obj00049 *)p)->f4288 = func_02030734(0x28, 0x3C00, z, gOekakiFileName, 0x31D);
    ((struct Obj00049 *)p)->f1A8 = z;
}
