/*
 * function: STA_ACTING_Create
 * address: 0x021F8480
 * packet: pkt_ov132_021F8480
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ABS32 callback STA_ACTING_VBlankCallback (ov132) at +0x1B8 has no code
 * witness. Original 0x021F8994..0x021F899C is 00 4B 18 47 48 A6 04 02:
 * Thumb ldr r3,[pc,#0]; bx r3; ARM target 0x0204A648. Its matched ARM9
 * source proves void(void); no ARM9 C was compiled or embedded here.
 * This stub is inside handed lead 0x021F879C's extent and must be filed
 * in that lead's unit, never as a duplicate standalone file. Root denied
 * a standalone extension. The lead was returned after fresh CFG review.
 * budget: two one runs, shrinking 8 concrete bytes to zero; no capped
 * iteration, mandatory DIFF checks, sweeps or permuter consumed.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020056A0 0x020056A0 thumb
 *   STA_ACTING_VBlankCallback 0x021F8994 thumb ov132
 *   STA_NET_GetCurrentSlotValue 0x021FD8D4 thumb ov132
 *   STA_ACTING_RankScores 0x021F95F0 thumb ov132
 *   func_020490F4 0x020490F4 arm
 *   STA_ACTING_InitDisplay 0x021F899C thumb ov132
 *   STA_ACTING_UploadPalettes 0x021F8BD4 thumb ov132
 *   STA_ACTING_CreateText 0x021F92CC thumb ov132
 *   STA_ACTING_CreateActors 0x021F8DC4 thumb ov132
 *   STA_ACTING_CreateActObj 0x021F8E58 thumb ov132
 *   STA_ACTING_CreateActorSys 0x021F8E88 thumb ov132
 *   STA_ACT_LIGHT_CreateUnit 0x021F6BD8 thumb ov112
 *   STA_ACT_AUDIENCE_Create 0x021F9FEC thumb ov132
 *   STA_ACT_BUTTON_Create 0x021FA5B0 thumb ov132
 *   STA_ACT_SCRIPT_Create 0x021FAAF4 thumb ov132
 *   STA_ACTING_CreateAnimHandle 0x021F9CF4 thumb ov132
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   STA_ACTING_SetBaseProgram 0x021F8D88 thumb ov132
 *   d_021FDCA0 0x021FDCA0 data a1
 *   g_02FFFC3C 0x02FFFC3C data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern const char d_021FDCA0[];
extern u32 g_02FFFC3C;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020056A0(void (*)(void),void *,u32);
extern void STA_ACTING_VBlankCallback(void);
extern u32 STA_NET_GetCurrentSlotValue(char *p);
extern void STA_ACTING_RankScores(u8 *);
extern void *func_020490F4(u32 id, u32 heap);
extern void STA_ACTING_InitDisplay(u8 *);
extern void STA_ACTING_UploadPalettes(u8 *);
extern void STA_ACTING_CreateText(u8 *);
extern void STA_ACTING_CreateActors(u8 *);
extern void STA_ACTING_CreateActObj(char *p);
extern void STA_ACTING_CreateActorSys(char *p);
extern void *STA_ACT_LIGHT_CreateUnit(u16,void *);
extern char *STA_ACT_AUDIENCE_Create(u32,void *,u32);
extern char *STA_ACT_BUTTON_Create(u32,void *,char *);
extern void *STA_ACT_SCRIPT_Create(u32,void *);
extern void STA_ACTING_CreateAnimHandle(char *);
extern void GFL_NET_RefreshWmIconAtTopRight(u32,u32);
extern void STA_ACTING_SetBaseProgram(u8 *,u32);
u8 *STA_ACTING_Create(u8 *input, int heap)
{
    u8 *p;
    u8 i;
    p=func_02030734(heap,0x1f0,1,d_021FDCA0,0x11a);
    *(u16 *)p=heap;
    *(void **)(p+0x30)=input;
    i=0;
    *(u16 *)(p+2)=0;
    *(u16 *)(p+4)=127;
    *(u16 *)(p+6)=128;
    *(u16 *)(p+8)=0;
    *(u32 *)(p+0xb4)=0;
    *(u32 *)(p+0x1c)=0;
    *(u32 *)(p+0x164)=0;
    *(u32 *)(p+0xc)=1;
    *(u32 *)(p+0x14)=0;
    *(u32 *)(p+0x10)=0;
    *(u32 *)(p+0x24)=0;
    *(u32 *)(p+0x28)=0;
    *(u32 *)(p+0x2c)=0;
    *(void **)(p+0x20)=func_020056A0(STA_ACTING_VBlankCallback,p,64);
    if(**(u32 **)(p+0x30)==0){
        for(;i<4;i++){
            if(**(u32 **)(*(u8 **)(p+0x30)+4+i*4)==0){p[0xa]=i;break;}
        }
        if(i==4)p[0xa]=1;
    }else p[0xa]=STA_NET_GetCurrentSlotValue((void *)**(u32 **)(p+0x30));
    for(i=0;i<4;i++)p[0xf7+i]=0;
    STA_ACTING_RankScores(p);
    *(u32 *)(p+0xec)=1;
    p[0xf0]=4;
    p[0xf1]=4;
    p[0xf2]=4;
    p[0x11c]=4;
    *(u16 *)(p+0x11e)=0;
    *(u32 *)(p+0x15c)=0;
    *(u16 *)(p+0x168)=0;
    for(i=0;i<4;i++){
        *(u32 *)(p+0xfc+i*4)=0;
        *(u16 *)(p+0x124+i*2)=0;
        *(u32 *)(p+0x13c+i*8)=0;
        *(u32 *)(p+0x140+i*8)=0;
    }
    *(void **)(p+0x18)=func_020490F4(47,*(u16 *)p);
    STA_ACTING_InitDisplay(p);
    STA_ACTING_UploadPalettes(p);
    STA_ACTING_CreateText(p);
    STA_ACTING_CreateActors(p);
    STA_ACTING_CreateActObj((char *)p);
    STA_ACTING_CreateActorSys((char *)p);
    *(void **)(p+0x90)=STA_ACT_LIGHT_CreateUnit(*(u16 *)p,p);
    *(void **)(p+0xb8)=STA_ACT_AUDIENCE_Create(*(u16 *)p,p,*(u32 *)(p+0x30));
    *(void **)(p+0xa4)=STA_ACT_BUTTON_Create(*(u16 *)p,p,*(char **)(*(u8 **)(p+0x30)+p[0xa]*4+4));
    *(void **)(p+0xb0)=STA_ACT_SCRIPT_Create(*(u16 *)p,p);
    STA_ACTING_CreateAnimHandle((char *)p);
    GFL_NET_RefreshWmIconAtTopRight(0,*(u16 *)p);
    STA_ACTING_SetBaseProgram(p,0);
    *(u32 *)(p+0x1dc)=*(u32 *)((*(u8 ***)(p+0x30))[6]+0x14);
    *(u32 *)(p+0x1e0)=*(u32 *)((*(u8 ***)(p+0x30))[6]+0x18);
    *(u32 *)(p+0x1e4)=*(u32 *)((*(u8 ***)(p+0x30))[6]+0x1c);
    *(u32 *)(p+0x1ec)=g_02FFFC3C;
    return p;
}
