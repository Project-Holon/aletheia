/*
 * function: WIFIBATTLEMATCH_NET_CompCreate
 * address: 0x021D6964
 * packet: pkt_ov175_021D6964
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * PROCSYS_AllocProcWork's r0 is read after the call, requiring a returning declaration.
 * symbols:
 *   ov067_id 0x00000043 data
 *   ov114_id 0x00000072 data
 *   func_02034AC4 0x02034AC4 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_COMPETITION_GetFromSave 0x0200B358 thumb
 *   REGULATION_GetCard 0x0200B1D4 thumb
 *   func_021E5440 0x021E5440 thumb ov177
 *   func_021E5548 0x021E5548 thumb ov177
 *   func_021E567C 0x021E567C thumb ov177
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   func_02045B38 0x02045B38 arm
 *   WORDSET_Create 0x0201EC74 thumb
 *   WIFIBATTLEMATCH_NET_CreateNetContext 0x021D9DC8 thumb ov175
 *   func_021E8568 0x021E8568 thumb ov177
 *   func_021E8A3C 0x021E8A3C thumb ov177
 *   WIFIBATTLEMATCH_NET_CompStepA 0x021D6BF4 thumb ov175
 *   func_021E7D20 0x021E7D20 thumb ov177
 *   func_021E7E0C 0x021E7E0C thumb ov177
 *   POKEPARTY_Create 0x0201A920 thumb
 *   WIFIBATTLEMATCH_NET_RestartNet 0x021DD008 thumb ov175
 */
typedef unsigned int u32;
extern const char ov067_id[],ov114_id[];
typedef signed int     s32;
typedef unsigned char  u8;
struct GfFont;
struct MsgBank;
struct WordSet;
extern int func_02034AC4(s32 handle);
extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,u32);
struct Big;
struct Party;
struct Rec160;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *BATTLE_COMPETITION_GetFromSave(void *sys);
extern struct Rec160 *REGULATION_GetCard(struct Rec160 *arr, u32 index);
extern int *func_021E5440(unsigned,int);
extern int func_021E5548(int *);
extern u32 *func_021E567C(int unused, int mode, int heap);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 PRINTSYS_QUE_Create(void *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *WORDSET_Create(u32 n, u32 size, unsigned short heap);
typedef unsigned short u16;
extern char *WIFIBATTLEMATCH_NET_CreateNetContext(u32 a, void *save, u32 b, u16 heap);
extern u32 func_021E8568(int,int,int,int,u32,u32,int);
extern int *func_021E8A3C(int,int,int);
extern void WIFIBATTLEMATCH_NET_CompStepA(u32,void *,char *);
extern void **func_021E7D20(void *,void *,unsigned);
extern void func_021E7E0C(void **p, int on);
extern struct Party *POKEPARTY_Create(u32 heap);
extern void WIFIBATTLEMATCH_NET_RestartNet(char *,int);
int WIFIBATTLEMATCH_NET_CompCreate(void *sys,int unused,u32 *ctx)
{
    u32 *p;
    func_02034AC4((int)ov067_id); func_02034AC4((int)ov114_id);
    GFL_HEAP_CreateChildHeap(1,87,0x30000);
    p=PROCSYS_AllocProcWork(sys,0x270,87); MI_CpuFill8(p,0,0x270);
    p[0x104/4]=(u32)ctx;
    p[0x108/4]=(u32)REGULATION_GetCard(BATTLE_COMPETITION_GetFromSave(GAME_DATA_GetSaveControl((struct Big *)(*(u32 *)ctx[2]))),0);
    p[0]=(u32)func_021E5440(1,87);
    p[1]=(u32)func_021E567C(func_021E5548((int *)p[0]),0,87);
    p[2]=(u32)GF_FONT_Create(0x17,0,0,0,87);
    p[3]=(u32)GF_FONT_Create(0x17,3,0,0,87);
    p[4]=PRINTSYS_QUE_Create((void *)87); p[5]=(u32)func_02045B38(0,2,0xd2,87);
    p[6]=(u32)WORDSET_Create(8,0x40,87);
    p[0x34/4]=(u32)WIFIBATTLEMATCH_NET_CreateNetContext(((u32 *)p[0x104/4])[0xf],(void *)(*(u32 *)ctx[2]),ctx[7],87);
    p[0x2c/4]=func_021E8568(0,15,14,10,p[4],p[2],87);
    p[0x38/4]=(u32)func_021E8A3C((int)p,(int)WIFIBATTLEMATCH_NET_CompStepA,87);
    p[0x3c/4]=(u32)func_021E8A3C((int)p,0,87);
    p[0x28/4]=(u32)func_021E7D20((void *)func_021E5548((int *)p[0]),(void *)p[1],87);
    func_021E7E0C((void **)p[0x28/4],0);
    p[0xfc/4]=(u32)POKEPARTY_Create(87); WIFIBATTLEMATCH_NET_RestartNet((char *)p[0x34/4],1);
    return 1;
}
