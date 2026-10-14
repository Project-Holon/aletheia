/*
 * function: PDC_MAIN_Create
 * address: 0x021B61E8
 * packet: pkt_ov098_021B61E8
 * region: ov098
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 EXACT. heap is a u8 parameter (TCBL_Create takes it as u16 with no
 *   narrowing). BTLV_INPUT_CreateDefault (ov094) returns its callee's pointer, but ov094_func_02202058.c
 *   declares it void; this file declares it int. Owner file needs the return fixed.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   PDC_MAIN_InitGraphics 0x021B636C thumb ov098
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PDC_GetScene 0x021B6144 thumb ov098
 *   BTLV_EFFECT_CreateSetup 0x021F73F0 thumb ov094
 *   BTLV_EFFECT_Init 0x021F7544 thumb ov094
 *   func_020307B0 0x020307B0 arm
 *   PDC_GetGameData 0x021B613C thumb ov098
 *   BTLV_EFFECT_GetPalanm 0x021F86E0 thumb ov094
 *   BTLV_INPUT_CreateDefault 0x02202058 thumb ov094
 *   TCBL_Create 0x0203101C arm
 *   PDC_GetMon 0x021B6140 thumb ov098
 *   PDC_GetConfig 0x021B6150 thumb ov098
 *   PDC_MSG_Create 0x021B67D4 thumb ov098
 *   func_02008254 0x02008254 thumb
 *   PDC_MAIN_SetStep 0x021B6364 thumb ov098
 *   gPdcMainSrcName 0x021B6E68 data a1
 *   gPdcViewParams 0x021B6D80 data a2
 *   PDC_MAIN_StepIntro 0x021B644C thumb ov098
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct GfFont;
struct Tcbl;
struct Halves { u16 a,b,c,d; };
extern const char gPdcMainSrcName[];
extern const struct Halves gPdcViewParams;
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void PDC_MAIN_InitGraphics(u16);
extern struct GfFont *GF_FONT_Create(int,int,int,int,u32);
extern int PDC_GetScene(void *);
extern void *BTLV_EFFECT_CreateSetup(int,int,void *,int,u16 *,int,int,u16);
extern void BTLV_EFFECT_Init(void *,int,u16);
extern u32 func_020307B0(void *p);
extern int PDC_GetGameData(void *);
extern int BTLV_EFFECT_GetPalanm(void);
struct Obj;
extern struct Obj *BTLV_INPUT_CreateDefault(int a, int b, int c, int d, int e, u16 k);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern int PDC_GetMon(void *);
extern u32 PDC_GetConfig(u8 *);
extern u8 *PDC_MSG_Create(void *,void *,void *,u32);
extern void *func_02008254(u32);
extern void PDC_MAIN_SetStep(u8 *,u32);
extern int PDC_MAIN_StepIntro(char *p);
#define P(k) (*(void **)(p+(k)))
#define H(k) (*(u16 *)(p+(k)))
u8 *PDC_MAIN_Create(void *input,u8 heap)
{
    u8 *p;
    struct Halves h;
    void *q;
    int ctx;
    p=func_02030734(heap,0x78,1,gPdcMainSrcName,0x5e);
    H(0x6c)=heap;
    P(0)=input;
    PDC_MAIN_InitGraphics(H(0x6c));
    P(8)=GF_FONT_Create(23,0,0,0,H(0x6c));
    P(12)=GF_FONT_Create(23,2,0,0,H(0x6c));
    *(u32 *)(p+0x60)=0;
    h=gPdcViewParams;
    q=BTLV_EFFECT_CreateSetup(0,0,(void *)PDC_GetScene(input),0,(u16 *)&h,0,0,H(0x6c));
    BTLV_EFFECT_Init(q,(int)P(12),H(0x6c));
    func_020307B0(q);
    ctx=PDC_GetGameData(input);
    P(16)=(void *)BTLV_INPUT_CreateDefault(ctx,0,BTLV_EFFECT_GetPalanm(),(int)P(8),(int)(p+0x74),H(0x6c));
    P(24)=TCBL_Create(heap,heap,64,128);
    *(int *)(p+4)=PDC_GetMon(input);
    P(20)=PDC_MSG_Create(P(8),(void *)PDC_GetConfig(input),P(24),H(0x6c));
    P(0x70)=func_02008254(H(0x6c));
    PDC_MAIN_SetStep(p,(u32)PDC_MAIN_StepIntro);
    return p;
}
