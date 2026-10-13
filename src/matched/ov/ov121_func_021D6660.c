/*
 * function: func_021D6660
 * address: 0x021D6660
 * packet: pkt_ov121_021D6660
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034AC4 0x02034AC4 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   GAME_DATA_Create 0x020124F4 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   MYSTERY_DATA_Create 0x0200A300 thumb
 *   func_021D9624 0x021D9624 thumb ov121
 *   func_021D6924 0x021D6924 thumb ov121
 *   func_021D9744 0x021D9744 thumb ov121
 *   func_021D6AEC 0x021D6AEC thumb ov121
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_021DA854 0x021DA854 thumb ov121
 *   func_021D6D80 0x021D6D80 thumb ov121
 *   func_021D9CA4 0x021D9CA4 thumb ov121
 *   func_021D9FFC 0x021D9FFC thumb ov121
 *   func_021DE2A0 0x021DE2A0 thumb ov121
 *   func_021D91BC 0x021D91BC thumb ov121
 *   func_021D9254 0x021D9254 thumb ov121
 *   func_021D9288 0x021D9288 thumb ov121
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   ov114_id 0x00000072 data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_02034AC4(int id);
extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *, int, int);
extern void *GAME_DATA_Create(u16 id);
struct Big;
struct GfFont;
struct MsgBank;
struct WordSet;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *MYSTERY_DATA_Create(void *, void *, void *);
extern u8 *func_021D9624(int arg, u16 heap);
extern void func_021D6924(u16 *p, u16 heap);
extern unsigned func_021D9744(char *p);
extern void func_021D6AEC(char *p, void *owner, u16 heap);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern void *func_021DA854(void *, void *, u16);
extern void func_021D6D80(void *a, int b, u8 *p);
extern void *func_021D9CA4(int a, u8 b, void *c, void *d, u16 heap);
extern void func_021D9FFC(u8 *p, int a, int b);
extern void *func_021DE2A0(void *arg, int heap);
extern void func_021D91BC(u8 *p, void *q, u16 h);
extern void func_021D9254(char *p, int n);
extern void func_021D9288(unsigned *p, unsigned v);
extern void GFL_USE_CancelChangeAndPlayBgm(int, int);
extern char ov114_id[];
int func_021D6660(void *a, u32 b, u32 c)
{
    u8 *p;
    func_02034AC4((int)ov114_id);
    GFL_HEAP_CreateChildHeap(1, 29, 0xA0000);
    p = PROCSYS_AllocProcWork(a, 0x69C, 29);
    func_02082BCC(p, 0, 0x69C);
    *(u32 *)(p + 0x3B4) = c;
    *(void **)(p + 0x3B8) = GAME_DATA_Create(29);
    *(void **)(p + 0x3BC) = MYSTERY_DATA_Create(GAME_DATA_GetSaveControl(*(void **)(p + 0x3B8)), (void *)1, (void *)29);
    *(u8 **)(p + 0x394) = func_021D9624(1, 29);
    func_021D6924((u16 *)(p + 0x390), 29);
    func_021D6AEC((char *)(p + 0x294), (void *)func_021D9744((char *)*(u8 **)(p + 0x394)), 29);
    *(void **)(p + 0x398) = GF_FONT_Create(23, 0, 0, 0, 29);
    *(u32 *)(p + 0x39C) = func_0201C440((void *)29);
    *(void **)(p + 0x3A4) = func_02045B38(0, 2, 0x50, 29);
    *(void **)(p + 0x3A0) = func_02045B38(0, 3, 0x9E, 29);
    *(void **)(p + 0x3A8) = func_0201EC64(29);
    *(void **)(p + 0x290) = func_021DA854(p, (void *)func_021D6D80, 29);
    *(void **)(p + 0x284) = func_021D9CA4(1, 15, *(void **)(p + 0x39C), *(void **)(p + 0x398), 29);
    func_021D9FFC(*(u8 **)(p + 0x284), 10, 14);
    *(void **)(p + 0x3B0) = func_021DE2A0(GAME_DATA_GetSaveControl(*(void **)(p + 0x3B8)), 29);
    func_021D91BC(p + 0x138, p + 0x294, 29);
    func_021D9254((char *)p + 0x138, 0);
    func_021D9288((unsigned int *)(p + 0x138), 1);
    GFL_USE_CancelChangeAndPlayBgm(1154, 0xFFFF);
    return 1;
}
