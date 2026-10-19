/*
 * function: LIVEBATTLEMATCH_FLOW_Create
 * address: 0x0217B984
 * packet: pkt_ov176_0217B984
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Note 2026-10-04 (wD2 lane12): byte-correct. Only unresolved relocation: LIVEBATTLEMATCH_SAVE_GetRecord (witness). Filed src/matched/arm9/LIVEBATTLEMATCH_SAVE_GetRecord.c (EXACT) this wave; it needs a manifest/shard so the witness exists, then this file re-verifies as EXACT with no C change.
 * blocker: 0x0200EA08 Thumb EXACT (scratch one, fixed flags); ARM9 belongs to the integrator.
 *   unsigned char *LIVEBATTLEMATCH_SAVE_GetRecord(unsigned char *p) { return p; }
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BATTLE_REC_IsDataExist 0x0200B45C thumb
 *   WIFIBATTLEMATCH_VIEW_LoadBgPalette 0x021E58A4 thumb ov177
 *   WORDSET_Create 0x0201EC74 thumb
 *   func_02045B38 0x02045B38 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   WIFIBATTLEMATCH_UTIL_CreateCallback 0x021E8A3C thumb ov177
 *   LIVEBATTLEMATCH_FLOW_SelectPhase 0x0217BB58 thumb ov176
 *   LIVEBATTLEMATCH_IRC_Create 0x0217E00C thumb ov176
 *   WIFIBATTLEMATCH_GRAPHIC_GetCamera 0x021E5548 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_CreateActorArray 0x021E7D20 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_SetActorVisible 0x021E7E0C thumb ov177
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_COMPETITION_GetFromSave 0x0200B358 thumb
 *   REGULATION_GetCard 0x0200B1D4 thumb
 *   LIVEBATTLEMATCH_SAVE_GetFromSave 0x0200E9F4 thumb
 *   LIVEBATTLEMATCH_SAVE_GetRecord 0x0200EA08 thumb
 *   POKEPARTY_Create 0x0201A920 thumb
 *   UI_SetSoftResetInhibitGlobal 0x0203516C arm
 *   d_0217E600 0x0217E600 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
typedef struct {u32 w[10];} Init;
typedef enum {SIZE0=0} Size;
struct Big;
struct GfFont;
struct MsgBank;
struct Party;
struct Rec160;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *,int,u32);
extern u32 BATTLE_REC_IsDataExist(void);
extern void WIFIBATTLEMATCH_VIEW_LoadBgPalette(int,int,u32);
extern void *WORDSET_Create(u32,u32,u32);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern int *WIFIBATTLEMATCH_UTIL_CreateCallback(int,int,int);
extern void LIVEBATTLEMATCH_FLOW_SelectPhase(int p, int *state, char *q);
extern void *LIVEBATTLEMATCH_IRC_Create(int,int);
extern int WIFIBATTLEMATCH_GRAPHIC_GetCamera(int *);
extern void **WIFIBATTLEMATCH_VIEW_CreateActorArray(void *,void *,u32);
extern void WIFIBATTLEMATCH_VIEW_SetActorVisible(void **,int);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *BATTLE_COMPETITION_GetFromSave(void *);
extern struct Rec160 *REGULATION_GetCard(struct Rec160 *arr, u32 index);
extern void *LIVEBATTLEMATCH_SAVE_GetFromSave(void *);
extern int LIVEBATTLEMATCH_SAVE_GetRecord(int p);
extern struct Party *POKEPARTY_Create(u32 heap);
extern void UI_SetSoftResetInhibitGlobal(int);
extern const char d_0217E600[];
u8 *LIVEBATTLEMATCH_FLOW_Create(Init *src,u32 heap)
{
    int size=0x109;
    u8 *p;
    size=0x1dc;
    p=func_02030734(heap,size,0,d_0217E600,0x109);
    MI_CpuFill8(p,0,size);
    *(Init *)(p+0x1a0)=*src;
    *(u16 *)(p+0x1c8)=heap;
    *(u32 *)(p+0x1d0)=BATTLE_REC_IsDataExist();
    WIFIBATTLEMATCH_VIEW_LoadBgPalette(*(int *)(p+0x1b0),1,heap);
    *(void **)(p+0x2c)=WORDSET_Create(8,0x40,heap);
    *(void **)(p+0x20)=func_02045B38(0,2,0x3a,heap);
    *(void **)(p+0x24)=func_02045B38(0,2,0xd2,heap);
    *(void **)(p+0x28)=GF_FONT_Create(0x17,3,0,0,heap);
    *(int **)p=WIFIBATTLEMATCH_UTIL_CreateCallback((int)p,(int)LIVEBATTLEMATCH_FLOW_SelectPhase,heap);
    *(void **)(p+0xc)=LIVEBATTLEMATCH_IRC_Create(*(int *)(p+0x1b8),heap);
    *(void ***)(p+0x1c)=WIFIBATTLEMATCH_VIEW_CreateActorArray((void *)WIFIBATTLEMATCH_GRAPHIC_GetCamera(*(int **)(p+0x1b4)),*(void **)(p+0x1b0),heap);
    WIFIBATTLEMATCH_VIEW_SetActorVisible(*(void ***)(p+0x1c),0);
    *(void **)(p+0x38)=REGULATION_GetCard(BATTLE_COMPETITION_GetFromSave(GAME_DATA_GetSaveControl(*(void **)(p+0x1b8))),1);
    *(void **)(p+0x34)=(void *)LIVEBATTLEMATCH_SAVE_GetRecord((int)LIVEBATTLEMATCH_SAVE_GetFromSave(GAME_DATA_GetSaveControl(*(void **)(p+0x1b8))));
    *(void **)(p+0x30)=POKEPARTY_Create(heap);
    if(*(int *)(p+0x1a0)==0)UI_SetSoftResetInhibitGlobal(8);
    return p;
}
