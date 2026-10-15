/*
 * function: BR_PROC_SYS_LoadRecords
 * address: 0x021F98F8
 * packet: pkt_ov186_021F98F8
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 recoup. The old draft had the save and tag spill slots swapped
 *   (4 bytes). Declaring the heap parameter of BATTLE_REC_Load as u16 and keeping the
 *   tag as a plain u32 local `(heap & 0x7fff) | 0x8000` (no u16 cast) gives EXACT in
 *   c99 and c. Other forms tried: u16 or int tag, tag inline in the call, tag set
 *   before save, declaration order of tag and save, tag in the loop body, heap
 *   reassigned, u32 heap parameter, all six per-function pragmas: all 4 bytes off.
 * symbols:
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   STRBUF_Delete 0x02045808 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BATTLE_REC_Load 0x0200B570 thumb
 *   BATTLE_REC_GetWork 0x0200B910 thumb
 *   GDS_PROFILE_Init 0x0200D5D0 thumb
 *   GDS_PROFILE_CreateNameStr 0x0200D6D0 thumb
 *   func_0200D6EC 0x0200D6EC thumb
 *   BATTLE_REC_GetHeader 0x0200B928 thumb
 *   BATTLE_REC_GetHeaderParam 0x0200B98C thumb
 *   MUSICAL_SAVE_GetFromSave 0x0200A5F8 thumb
 *   MUSICAL_SAVE_IsShowActive 0x0200A630 thumb
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct Fields {u32 words[4];void *handles[4];u32 flags[4];u64 values[4];u32 state,ready;} Fields;
typedef unsigned char  u8;
struct Big;
struct Bits;
struct GdsProfile;
struct ObjC4;
struct RecGet;
struct U16Vec;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct ObjC4 *BATTLE_REC_GetWork(void);
extern u8 *BATTLE_REC_GetHeader(void);
extern void *MUSICAL_SAVE_GetFromSave(void *);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void MI_CpuFill8(void *,int,unsigned);
extern u32 BATTLE_REC_Load(void *,u16,u32 *,u32);
extern void GDS_PROFILE_Init(struct GdsProfile *p, void *sys);
extern void *GDS_PROFILE_CreateNameStr(const void *,u32);
extern u32 func_0200D6EC(struct RecGet *p);
extern u32 MUSICAL_SAVE_IsShowActive(struct Bits *p);
extern unsigned long long BATTLE_REC_GetHeaderParam(u8 *p, int selector, int index);
void BR_PROC_SYS_LoadRecords(char *p, int skip, void *sys, int heap)
{
    int enabled=1;
    int i;
    u32 result;
    u32 save;
    void *profile;
    if(skip && *(int *)(p+0x54)) enabled=0;
    if(enabled) {
        u32 tag;
        save=(u32)GAME_DATA_GetSaveControl(sys);
        if(*(int *)(p+0x54)) {
            for(i=0;i<4;i++) {
                if(((Fields *)p)->handles[i]) {
                    STRBUF_Delete(((Fields *)p)->handles[i]);
                    ((Fields *)p)->handles[i]=0;
                }
            }
        }
        MI_CpuFill8(p,0,0x58);
        tag=(heap&0x7fff)|0x8000;
        for(i=0;i<4;i++) {
            BATTLE_REC_Load((void *)save,tag,&result,i);
            if(result==1) {
                profile=BATTLE_REC_GetWork();
                if(i==0) GDS_PROFILE_Init(profile,sys);
                *(int *)((u32)p+(u32)i*4)=1;
                *(void **)((u32)p+(u32)i*4+0x10)=GDS_PROFILE_CreateNameStr(profile,0x59);
                *(u32 *)((u32)p+(u32)i*4+0x20)=func_0200D6EC(profile);
                *(u64 *)((u32)p+(u32)i*8+0x30)=BATTLE_REC_GetHeaderParam(BATTLE_REC_GetHeader(),4,0);
            }
        }
        *(u32 *)(p+0x50)=MUSICAL_SAVE_IsShowActive(MUSICAL_SAVE_GetFromSave(GAME_DATA_GetSaveControl(sys)));
        *(int *)(p+0x54)=1;
    }
}
