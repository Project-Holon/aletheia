/*
 * function: func_021F6BD8
 * address: 0x021F6BD8
 * packet: pkt_ov112_021F6BD8
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   d_021F8408 0x021F8408 data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct Bank;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void *func_020490F4(u32 id, u32 heap);
extern signed int CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
typedef signed int     s32;
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);
extern const char d_021F8408[];
typedef struct { u16 heap,pad; void *a; u32 entries[4][8]; u32 other[8]; void *bank; u32 x,y,z; } Object;
Object *func_021F6BD8(u16 heap,void *a)
{
    u8 i;
    Object *p;
    void *q;
    i=0;
    p=func_02030734(heap,184,0,d_021F8408,87);
    p->heap=heap; p->a=a;
    for(;i<4;i++) p->entries[i][0]=0;
    p->other[0]=0;
    p->bank=CLACT_CreateUnit(5,0,p->heap);
    CLACT_SetUnitDefaultRenderer(p->bank);
    q=func_020490F4((unsigned int)47,p->heap);
    p->x=CLACT_RegisterPalette((void *)q,4,0,0,p->heap);
    p->y=CLACT_RegisterCharacter((void *)((u32)q),10,0,0,p->heap);
    p->z=CLACT_RegisterCellAnim((void *)((u32)q),20,23,p->heap);
    ARC_TOOL_DeleteHandle(q);
    return p;
}
