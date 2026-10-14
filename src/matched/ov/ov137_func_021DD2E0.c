/*
 * function: GURU2_RECEIPT_InitStrings
 * address: 0x021DD2E0
 * packet: pkt_ov137_021DD2E0
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * STRBUF_Create 0x020457B0 arm
 * MSGDATA_ReadString 0x02045CAC arm
 * ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
 * GURU2_RECEIPT_LoadCharBuffer 0x021DE6C0 thumb ov137
 */
#include "../include/Obj02495.h"
#include "../include/Obj23712.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct MsgBank;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void GURU2_RECEIPT_LoadCharBuffer(char *p, void *a1);
extern void *ARC_UTIL_LoadPaletteBlockFromHandle(void *a0, u32 a1, u32 a2, u32 a3);
void GURU2_RECEIPT_InitStrings(u8 *p,void *q)
{
    int i;
    u32 v;
    for(i=0;i<5;i++) {
        *(u32 *)(p+i*4+68)=(u32)STRBUF_Create(8,114);
        *(u32 *)(p+i*8+312)=0; *(u32 *)(p+i*8+316)=0;
        *(u32 *)(p+i*4+352)=0;
    }
    ((struct Obj02495 *)p)->f5C=(u32)STRBUF_Create(180,114);
    v=(u32)STRBUF_Create(40,114); ((struct Obj02495 *)p)->f60=v;
    ((struct Obj02495 *)p)->f118=0;
    MSGDATA_ReadString((struct MsgBank *)(((struct Obj02495 *)p)->f40),17,(void *)v);
    GURU2_RECEIPT_LoadCharBuffer((char *)p,q);
    ((struct Obj02495 *)p)->f18=0; ((struct Obj02495 *)p)->f20=0; ((struct Obj02495 *)p)->f1C=0;
    ((struct Obj02495 *)p)->f24=(u32)ARC_UTIL_LoadPaletteBlockFromHandle(q,2,(u32)(p+40),114);
    ((struct Obj02495 *)p)->f4804=0; ((struct Obj02495 *)p)->fE8=0;
    ((struct Obj23712 *)(*(u8 * *)&((struct Obj02495 *)p)->f10))->f2C=2;
}
