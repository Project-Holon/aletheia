/*
 * function: WIFI_BSUBWAY_Create
 * address: 0x021D6660
 * packet: pkt_ov116_021D6660
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 02012EF0 and 02012EFC lack an outside code witness.
 * blocker: 0x02012EF0 verified EXACT in 12EF0-r1.log (Thumb, dsi/1.1p1 -O4,p).
 *   extern int func_020071CC(void *,int);
 *   int GAME_DATA_GetSaveBlock3A(void **p) { return func_020071CC(*p,58); }
 * blocker: 0x02012EFC verified EXACT in 12EFC-r1.log (Thumb, dsi/1.1p1 -O4,p).
 *   extern int func_020071CC(void *,int);
 *   int GAME_DATA_GetSaveBlock3B(void **p) { return func_020071CC(*p,59); }
 * symbols:
 *   func_02034AC4 0x02034AC4 arm
 *   ov_id 0x00000072 data
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GAME_DATA_GetSaveBlock3B 0x02012EFC thumb
 *   GAME_DATA_GetSaveBlock3A 0x02012EF0 thumb
 *   func_02008B08 0x02008B08 thumb
 *   WIFI_BSUBWAY_ClearTrainers 0x021D6998 thumb ov116
 *   WIFI_BSUBWAY_StatusInit 0x021D6B50 thumb ov116
 *   WIFI_BSUBWAY_AsyncInit 0x021D70D8 thumb ov116
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb  arm9
 *   ICA_ANIME_GetField1C  0x020120F4  thumb  arm9
 *   GAME_DATA_GetField1A0  0x0201283C  thumb  arm9
 *   GAME_DATA_GetMyStatus  0x02012944  thumb  arm9
 */
typedef unsigned char u8;
extern u8 ov_id[];
typedef signed int     s32;
typedef unsigned int   u32;
struct Big;
struct BigObj;
struct Ctx;
struct Sub02008AECObj;
extern int func_02034AC4(s32 handle);
extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,unsigned);
extern void *ICA_ANIME_GetField1C(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02008AECObj *func_02008B08(void *sys);
extern u32 GAME_DATA_GetField1A0(const struct BigObj *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void *GAME_DATA_GetSaveBlock3B(void **p);
extern void *GAME_DATA_GetSaveBlock3A(void **p);
extern void WIFI_BSUBWAY_ClearTrainers(void *);
extern void WIFI_BSUBWAY_StatusInit(unsigned char *a, int b);
extern void WIFI_BSUBWAY_AsyncInit(void *);
int WIFI_BSUBWAY_Create(void *ctx,int unused,u8 *q) {
    u8 *p;
    void *save;
    func_02034AC4((s32)ov_id);
    GFL_HEAP_CreateChildHeap(1,125,0x18000);
    p=PROCSYS_AllocProcWork(ctx,0x185c,125);
    MI_CpuFill8(p,0,0x185c);
    *(u8 **)p=q;
    *(int *)(q+8)=1;
    save=ICA_ANIME_GetField1C(*(void **)(*(u8 **)p+4));
    q=GAME_DATA_GetSaveControl(save);
    *(void **)(p+0x1844)=save;
    *(int *)(p+0x1848)=(int)func_02008B08(q);
    *(int *)(p+0x184c)=GAME_DATA_GetField1A0(save);
    *(int *)(p+0x1850)=(int)GAME_DATA_GetMyStatus(save);
    *(int *)(p+0x1854)=(int)GAME_DATA_GetSaveBlock3B(save);
    *(int *)(p+0x1858)=(int)GAME_DATA_GetSaveBlock3A(save);
    WIFI_BSUBWAY_ClearTrainers(p+0xb74);
    WIFI_BSUBWAY_StatusInit(p+0x1610,125);
    WIFI_BSUBWAY_AsyncInit(p+0x182c);
    return 1;
}
