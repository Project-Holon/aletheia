/*
 * function: PMS_INPUT_Create
 * address: 0x021BD5C4
 * packet: pkt_ov110_021BD5C4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocked: ARM9 02024144 and02024168 have only this caller as outside
 *   branch witness; tu --suggest-split gives no viable partition. No overlay
 *   leaf filed while ARM9 caps. Scratch-only proofs below; the integrator owns filing.
 * evidence: 128-byte allocation; highest field7c ends at80. Input mode0
 *   writes one halfword to p+10, mode1 two to p+10, mode2 four to p+08;
 *   no output overlap or uninitialized output is read by the constructor
 *   outside its matching mode. Callback pointers are copied unchanged.
 * blocker: 0x02024144 Thumb EXACT4, blocker-24144-one.log terminal0:
 *   typedef unsigned char u8;
 *   typedef unsigned int u32;
 *   u32 PMSI_PARAM_GetInputMode(const u8 *p) { return p[0]; }
 * blocker: 0x02024168 Thumb EXACT50, blocker-24168-two.log terminal0:
 *   typedef unsigned char u8;
 *   typedef unsigned short u16;
 *   typedef struct Pair { u16 x,y; } Pair;
 *   typedef struct Input {
 *       u8 mode; u8 pad01[15]; u16 values10[4]; u16 values18[2];
 *   } Input;
 *   void PMSI_PARAM_GetResult(const Input *p,u16 *a,u16 *b) {
 *       Pair v;
 *       switch(p->mode) {
 *       case 0: a[0]=p->values18[0]; break;
 *       case 1:
 *           v=*(const Pair *)p->values18; *(Pair *)a=v; break;
 *       case 2:
 *           b[0]=p->values10[0]; b[1]=p->values10[1];
 *           v=*(const Pair *)(p->values10+2); *(Pair *)(b+2)=v; break;
 *       }
 *   }
 * abi: 3159C own void body stores allocation r0 at owner14 then returns
 *   with r0 live; original consumes it as p. 2421C tail-forwards to the
 *   matched singleton byte getter355C4; caller consumes returned r0.
 *   Original explicitly sets the otherwise ignored 2421C input.
 * symbols:
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   PMSI_PARAM_GetInputMode 0x02024144 thumb
 *   PMSI_PARAM_GetUiInputMode 0x0202421C thumb
 *   PMSI_PARAM_GetResult 0x02024168 thumb
 *   PMS_INPUT_InitSentenceCursor 0x021BD690 thumb ov110
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030734 0x02030734 arm
 *   func_02030CBC 0x02030CBC arm
 *   PMS_INPUT_DATA_Create 0x021B95A0 thumb ov110
 *   PMS_INPUT_VIEW_Create 0x021B9A50 thumb ov110
 *   BUTTON_MAN_Create 0x02051B84 arm
 *   PMS_INPUT_OnButton 0x021BD578 thumb ov110
 *   PMSI_SEARCH_Create 0x021BAEDC thumb ov110
 *   PMS_INPUT_SetSubHandler 0x021BF4F8 thumb ov110
 *   PMS_INPUT_SubHandleOpen 0x021BF508 thumb ov110
 *   gPmsInputButtonRects 0x021C3908 data a1
 *   gPmsInputFileName 0x021C3C78 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Proc;
struct Ctx;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern u32 PMSI_PARAM_GetInputMode(const u8 *);
extern u32 PMSI_PARAM_GetUiInputMode(void *);
struct Input;
extern void PMSI_PARAM_GetResult(const struct Input *p, u16 *a, u16 *b);
extern void PMS_INPUT_InitSentenceCursor(u8 *,u16 *);
extern u32 func_02030CB0(u32);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern struct Ctx *func_02030CBC(u32,struct Ctx *);
extern void *PMS_INPUT_DATA_Create(u32,void *);
extern void *PMS_INPUT_VIEW_Create(u8 *,void *);
extern void *BUTTON_MAN_Create(u8 *,int,int,int);
extern void PMS_INPUT_OnButton(int,u32,u8 *);
extern u8 *PMSI_SEARCH_Create(void *,void *,u16);
extern void PMS_INPUT_SetSubHandler(u8 *,u32);
extern void PMS_INPUT_SubHandleOpen(u8 *p, int *q);
extern const u8 gPmsInputButtonRects[];
extern const char gPmsInputFileName[];
u8 *PMS_INPUT_Create(struct Proc *owner,u8 *input)
{
    u8 *p;
    struct Ctx *q;
    p=PROCSYS_AllocProcWork(owner,128,41);
    *(u8 **)p=input;
    *(u32 *)(p+4)=PMSI_PARAM_GetInputMode(input);
    *(u32 *)(p+0x70)=PMSI_PARAM_GetUiInputMode(*(u8 **)p);
    PMSI_PARAM_GetResult((const struct Input *)(*(u8 **)p),(u16 *)(p+0x10),(u16 *)(p+8));
    if(*(u32 *)(p+4)==2) PMS_INPUT_InitSentenceCursor(p+0x64,(u16 *)(p+8));
    q=func_02030734(41,func_02030CB0(5),0,gPmsInputFileName,579);
    *(struct Ctx **)(p+0x78)=q;
    *(struct Ctx **)(p+0x7c)=func_02030CBC(5,q);
    *(void **)(p+0x18)=PMS_INPUT_DATA_Create(41,*(void **)p);
    *(void **)(p+0x14)=PMS_INPUT_VIEW_Create(p,*(void **)(p+0x18));
    *(void **)(p+0x44)=BUTTON_MAN_Create((u8 *)gPmsInputButtonRects,(int)PMS_INPUT_OnButton,(int)p,41);
    p[0x69]=0;
    *(u32 *)(p+0x30)=0;
    *(u32 *)(p+0x2c)=0;
    *(u16 *)(p+0x4a)=0;
    *(u16 *)(p+0x48)=0;
    *(u32 *)(p+0x3c)=1;
    *(void **)(p+0x1c)=PMSI_SEARCH_Create(p,*(void **)(p+0x18),41);
    PMS_INPUT_SetSubHandler(p,(u32)PMS_INPUT_SubHandleOpen);
    return p;
}
