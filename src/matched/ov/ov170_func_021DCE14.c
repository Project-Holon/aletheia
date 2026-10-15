/*
 * function: BOX2_MAIN_CreateTextSystem
 * address: 0x021DCE14
 * packet: pkt_ov170_021DCE14
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   PRINTSYS_QUE_CreateEx 0x0201C450 thumb
 *   STRBUF_Create 0x020457B0 arm
 */
typedef unsigned int   u32;
struct GfFont;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern void *PRINTSYS_QUE_CreateEx(unsigned short,unsigned);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
#define PTR(p,n) (*(void **)(*(char **)((p)+0x2c)+(n)))
void BOX2_MAIN_CreateTextSystem(char *p)
{
    PTR(p,0x80) = func_02045B38(0,2,9,0x4c);
    PTR(p,0x78) = GF_FONT_Create(0x17,0,1,0,0x4c);
    PTR(p,0x7c) = GF_FONT_Create(0x17,3,0,0,0x4c);
    PTR(p,0x84) = WORDSET_CreateDefault(0x4c);
    PTR(p,0x8c) = PRINTSYS_QUE_CreateEx(0x800,0x4c);
    PTR(p,0x88) = STRBUF_Create(0x400,0x4c);
}
