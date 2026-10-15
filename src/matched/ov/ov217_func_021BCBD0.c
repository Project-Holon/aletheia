/*
 * function: RESEARCH_LIST_LoadListBackground
 * address: 0x021BCBD0
 * packet: pkt_ov217_021BCBD0
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   RESEARCH_LIST_GetEntryCount 0x021BC6DC thumb ov217
 *   func_020490F4 0x020490F4 arm
 *   ARC_TOOL_LoadHandleMember 0x02049250 arm
 *   func_02062B30 0x02062B30 arm
 *   func_02041090 0x02041090 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020307B0 0x020307B0 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S { char pad0[8]; u16 h8; };
struct ArcFile;
extern u32 RESEARCH_LIST_GetEntryCount(void *p);
extern void *func_020490F4(u32 id, u32 heap);
extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *arc, u32 member, u32 heap);
extern int func_02062B30(void *file, void **out);
extern void func_02041090(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);
extern void func_02041B6C(u32 bg);
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(void *h);

void RESEARCH_LIST_LoadListBackground(struct S *p)
{
    void *heap = func_020490F4(0xc0, (u16)((p->h8 & 0x7fff) | 0x8000));
    int v = RESEARCH_LIST_GetEntryCount(p) * 3;
    void *res = ARC_TOOL_LoadHandleMember(heap, 5, p->h8);
    char *q;
    func_02062B30(res, (void **)(&q));
    func_02041090(2, (u32)(q + 0xc), 0, 0, 0x20, (u8)v);
    func_02041B6C(2);
    func_020307B0(res);
    ARC_TOOL_DeleteHandle(heap);
}
