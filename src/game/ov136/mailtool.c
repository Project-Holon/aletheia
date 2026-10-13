/*
 * file:     mailtool.c
 * unit:     yes
 * function: func_021C3CC0, func_021C3D44, func_021C3DA4, func_021C3E00, func_021C3E04, func_021C3E24, func_021C3E3C, func_021C3E9C, func_021C3F98, func_021C3FC8, func_021C409C, func_021C4134, func_021C414C, func_021C4184, func_021C41E0, func_021C427C, func_021C4290, func_021C42C8
 * address:  0x021C3CC0
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02008FEC 0x02008FEC thumb
 *   func_02030734 0x02030734 arm
 *   func_02082AC0 0x02082AC0 arm
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   MAIL_Create 0x02008F08 thumb
 *   func_02008EAC 0x02008EAC thumb
 *   func_02008F48 0x02008F48 thumb
 *   d_021C7EE0 0x021C7EE0 data a1
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   func_02008FA8 0x02008FA8 thumb
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   func_020307B0  0x020307B0  arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   PROCSYS_Create 0x02031324 arm
 *   PROCSYS_Main 0x02031330 arm
 *   PROCSYS_Push 0x02031348 arm
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034A5C 0x02034A5C arm
 *   PMSI_PARAM_CheckCanceled 0x0202411C thumb
 *   PMSI_PARAM_GetSentence 0x02024134 thumb
 *   PMSI_PARAM_GetWord 0x02024124 thumb
 *   PMSI_PARAM_Delete 0x020240FC thumb
 *   func_02008C58 0x02008C58 thumb
 *   func_02008DF0 0x02008DF0 thumb
 *   ov136_id 0x0000006E data
 *   D_021C7750 0x021C7750 data
 *   D_021C775C 0x021C775C data
 *   func_0203133C 0x0203133C arm
 *   func_020315D4 0x020315D4 arm
 *   func_0203084C 0x0203084C arm
 *   func_020306F0 0x020306F0 arm
 *   PMSI_PARAM_ClearSentence 0x0202428C thumb
 *   PMSI_PARAM_Create 0x02024044 thumb
 *   PMSI_PARAM_SetWord 0x02024104 thumb
 *   PMSI_PARAM_Copy 0x02024570 thumb
 *   PMSI_PARAM_IsEnabled 0x02024450 thumb
 *   PMSI_PARAM_InitSentence 0x020242A4 thumb
 *   PMSI_PARAM_SetSentence 0x02024108 thumb
 *   func_02008F80 0x02008F80 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   func_02008F84 0x02008F84 thumb
 *   STRBUF_SetString 0x02045924 arm
 *   func_02008FA4 0x02008FA4 thumb
 *   func_02008FB0 0x02008FB0 thumb
 *   func_02008FB8 0x02008FB8 thumb
 *   func_02008FC0 0x02008FC0 thumb
 *   func_02008FC8 0x02008FC8 thumb
 *   d_021C7EEC 0x021C7EEC data a1
 *   STRBUF_Delete  0x02045808  arm
 *   func_02008FD8 0x02008FD8 thumb
 *   func_02008FC4 0x02008FC4 thumb
 *   PMSI_PARAM_InitSentenceId 0x020242C0 thumb
 *   d_021C77A0 0x021C77A0 data a1
 *   func_02012FFC 0x02012FFC thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   TCBL_Create 0x0203101C arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   TCBL_Destroy 0x02031140 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   func_021C4AF8 0x021C4AF8 thumb ov136
 *   func_021C4BFC 0x021C4BFC thumb ov136
 *   func_021C4B5C 0x021C4B5C thumb ov136
 *   func_021C4D14 0x021C4D14 thumb ov136
 *   data_021C7774 0x021C7774 data
 *   WIPE_SetBrightnessFadeOut 0x0202223C thumb
 *   WIPE_ResetWndMask 0x02022224 thumb
 *   func_020056A0 0x020056A0 thumb
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   WIPE_ResetBrightness 0x02022230 thumb
 *   func_0207D63C 0x0207D63C arm
 *   func_020056BC 0x020056BC thumb
 *   PALANM_RequestFade 0x0202173C thumb
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   PMS_DRAW_Main 0x0202DBC4 thumb
 *   APP_TASKMENU_WIN_Update 0x02028178 thumb
 *   func_02030EAC 0x02030EAC arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   func_02030D28 0x02030D28 arm
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 */
#include "ov136_types.h"
struct MailToolCtx;

struct MailToolCtx {
    unsigned int f0;
    unsigned char pad_4[4];
    void *f8;
    unsigned char pad_C[4];
    void *f10;
    unsigned short f14;
    unsigned short f16;
    unsigned short f18;
};

struct Sub02008F80Obj;
struct Big;
struct Sub02008EACObj;
struct Sub02008EACObjLayout;
struct Obj0203159C;
struct Sub02008C20Obj;
struct S020314B8;
struct S020315D4;
struct Obj;
struct Rec8;
struct Strbuf;
struct Sub02008F80Entry;
struct U16Vec;
struct GfFont;
struct Tcbl;
struct S02031140;
struct Ctx;
struct Node;
struct PrintSys;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef int (*Step021C42C8)(u8 *p);

extern struct Sub02008F80Obj *func_02008FEC(void *sys);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082AC0(unsigned, void *, unsigned);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *MAIL_Create(int a0);
extern void func_02008EAC(struct Sub02008EACObj *obj);
extern void func_02008F48(struct Sub02008EACObjLayout *obj, u8 kind, u32 unused, void *p);
extern unsigned POKE_TOOL_GetPartyValue(void *, unsigned, unsigned);
extern void func_02008FA8(struct Sub02008F80Obj *obj, u32 value);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern u32 func_020307B0(void *p);
extern void GFL_HEAP_CreateChildHeap(unsigned, unsigned, unsigned);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void *PROCSYS_Create(int a0);
extern u32 PROCSYS_Main(void *p);
extern void PROCSYS_Push(void *h, u32 id, void *a, void *b);
extern int func_02034AC4(int handle);
extern void func_02034A5C(int handle);
extern int PMSI_PARAM_CheckCanceled(unsigned char *p);
extern void PMSI_PARAM_GetSentence(char *a, void *b);
extern unsigned int PMSI_PARAM_GetWord(unsigned short *p);
extern void PMSI_PARAM_Delete(void *a);
extern struct Sub02008C20Obj *func_02008C58(void *sys);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern void func_0203133C(struct S020314B8 *v);
extern void func_020315D4(struct S020315D4 *v);
extern void func_0203084C(u16 v);
extern void func_020306F0(u32 v);
extern void PMSI_PARAM_ClearSentence(void *p);
extern struct Obj *PMSI_PARAM_Create(u32 kind, u32 a1, void *src, u32 flag, void *sys, u32 hh);
extern void PMSI_PARAM_SetWord(u16 *p, u16 v);
extern void PMSI_PARAM_Copy(struct Rec8 *dst, const struct Rec8 *src);
extern int PMSI_PARAM_IsEnabled(const u16 *p);
extern void PMSI_PARAM_InitSentence(void *obj, u32 id);
extern void PMSI_PARAM_SetSentence(u16 *dst, const u16 *src);
extern u32 func_02008F80(const struct Sub02008F80Obj *obj);
extern void *STRBUF_Create(unsigned, u16);
extern u8 *func_02008F84(struct Sub02008F80Obj *obj);
extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);
extern u8 func_02008FA4(const struct Sub02008F80Obj *obj);
extern u8 func_02008FB0(const struct Sub02008F80Obj *obj);
extern u8 func_02008FB8(const struct Sub02008F80Obj *obj);
extern u16 func_02008FC0(const struct Sub02008F80Obj *obj);
extern struct Sub02008F80Entry *func_02008FC8(struct Sub02008F80Obj *obj, u32 i);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_02008FD8(struct Sub02008F80Obj *obj, void *arg, u32 i);
extern void func_02008FC4(struct Sub02008F80Obj *obj, u16 value);
extern void PMSI_PARAM_InitSentenceId(void *a, void *b, void *c);
extern signed char func_02012FFC(void);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern void func_0203F8F4(u16);
extern void func_0203F9B4(void);
extern void TCBL_Destroy(struct S02031140 *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void func_021C4AF8(void);
extern int func_021C4BFC(u8 *p);
extern void func_021C4B5C(void *a, u32 *p);
extern int func_021C4D14(u8 *p);
extern void WIPE_SetBrightnessFadeOut(u32 a, u32 b);
extern u32 WIPE_ResetWndMask(void *win);
extern void *func_020056A0(void *callback, void *ctx, int a2);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void WIPE_ResetBrightness(u32 a);
extern void func_0207D63C(void *reg, int a, int b, int c, int d);
extern u32 func_020056BC(void);
extern void PALANM_RequestFade(void *p, int a, int b, int c, int d, int e, int f, u32 g);
extern u32 PALANM_GetFadeRequestBits(const char *ptr);
extern void PMS_DRAW_Main(u8 *p);
extern void APP_TASKMENU_WIN_Update(u8 *p);
extern void func_02030EAC(struct Node *n);
extern void CLACT_DrawSystem(void *p);
extern void func_02030D28(struct Ctx *c);
extern void TCBL_Main(struct Tcbl *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
void *func_021C3CC0(void *a, unsigned b, unsigned c, unsigned d, unsigned heap);
void *func_021C3D44(void *a, void *b, unsigned heap);
void *func_021C3DA4(void *a, void *b, unsigned heap);
u32 func_021C3E00(u32 *p);
int func_021C3E04(u32 *p, void *q);
void func_021C3E24(struct MailViewCtx_f1C *p);
int func_021C3E3C(void *a, void *b, u8 *p);
int func_021C3E9C(int unused, u32 *state, u16 *msg, u8 *ctx);
int func_021C3F98(u32 a, void *b, void *c, u32 *p);
void func_021C3FC8(u8 *ctx, u8 *arg);
void *func_021C409C(void *a, unsigned heap);
void func_021C4134(struct MailViewCtx_f1C *p);
void func_021C414C(void *a, u8 *p);
void func_021C4184(void *a, u8 *p);
int func_021C41E0(void *a, void *b, u8 *p);
int func_021C427C(void *a, void *b, void *c, void *p);
int func_021C4290(void *a, void *b, void *c, u32 *p);
int func_021C42C8(u8 *p);
extern const char d_021C7EE0[];
extern u8 ov136_id[];
extern u8 D_021C7750[];
extern u8 D_021C775C[];
extern const char d_021C7EEC[];
extern const u8 d_021C77A0[][3];
extern Step021C42C8 data_021C7774[];


void *func_021C3CC0(void *a, unsigned b, unsigned c, unsigned d, unsigned heap)
{
    u8 *p;
    unsigned v;
    v = (unsigned int)func_02008FEC(a);
    p = func_02030734((u16)(((u16)heap & 0x7FFF) | 0x8000), 0x1C, 0, d_021C7EE0, 0x43);
    func_02082AC0(0, p, 0x1C);
    p[0xF] = d;
    p[0xE] = c;
    ((struct MbSeqCtx *)p)->f18 = v;
    *(unsigned short *)&((struct MbSeqCtx *)p)->f0 = 1;
    *(unsigned int *)&((struct MbSeqCtx *)p)->f8 = b;
    ((struct MbSeqCtx *)p)->fC = 0;
    ((struct MbSeqCtx *)p)->f10 = GAME_DATA_GetSaveControl(a);
    ((struct MbSeqCtx *)p)->f14 = MAIL_Create((unsigned)((u16)heap));
    func_02008EAC(((struct MbSeqCtx *)p)->f14);
    func_02008F48(((struct MbSeqCtx *)p)->f14, 0xFF, c, a);
    return p;
}


void *func_021C3D44(void *a, void *b, unsigned heap)
{
    u8 *p;
    p = func_02030734((u16)(((u16)heap & 0x7FFF) | 0x8000), 0x1C, 0, d_021C7EE0, 0x97);
    func_02082AC0(0, p, 0x1C);
    *(unsigned short *)&((struct MbSeqCtx *)p)->f0 = 0;
    ((struct MbSeqCtx *)p)->f10 = GAME_DATA_GetSaveControl(a);
    ((struct MbSeqCtx *)p)->f14 = MAIL_Create((unsigned)((u16)heap));
    POKE_TOOL_GetPartyValue(b, 0xA7, (u32)((struct MbSeqCtx *)p)->f14);
    return p;
}


void *func_021C3DA4(void *a, void *b, unsigned heap)
{
    u8 *p;
    p = func_02030734((u16)(((u16)heap & 0x7FFF) | 0x8000), 0x1C, 0, d_021C7EE0, 0xB9);
    func_02082AC0(0, p, 0x1C);
    *(unsigned short *)&((struct MbSeqCtx *)p)->f0 = 0;
    ((struct MbSeqCtx *)p)->f10 = GAME_DATA_GetSaveControl(a);
    ((struct MbSeqCtx *)p)->f14 = MAIL_Create((unsigned)((u16)heap));
    func_02008FA8(((struct MbSeqCtx *)p)->f14, (u32)b);
    return p;
}


u32 func_021C3E00(u32 *p)
{
    return p[1];
}


int func_021C3E04(u32 *p, void *q)
{
    if (func_021C3E00(p) == 0) return 0;
    POKE_TOOL_SetPartyValue(q, 0xa7, p[5]);
    return 1;
}



/*
 * Addresses are Black-image addresses.
 */
void func_021C3E24(struct MailViewCtx_f1C *p)
{
    if (p->f14)
        func_020307B0(p->f14);
    func_020307B0(p);
}


/*
 * tail: 021C3E9A..021C3E9C zero alignment padding.
 */
int func_021C3E3C(void *a, void *b, u8 *p)
{
    u8 *q;
    GFL_HEAP_CreateChildHeap(1, 0x63, 0x1000);
    q = PROCSYS_AllocProcWork(a, 0x20, 0x63);
    func_02082AC0(0, q, 0x20);
    ((struct MailViewCtx *)q)->f0 = 0x63;
    *(u8 * *)&((struct MailViewCtx *)q)->f10 = func_021C409C(((struct MbSeqCtx *)p)->f14, 0x63);
    if (*(unsigned short *)&((struct MbSeqCtx *)p)->f0 == 1) (*(u8 **)(q + 0x10))[0xB] = p[0xF];
    if ((*(u8 **)(q + 0x10))[0xB] >= 0xC) (*(u8 **)(q + 0x10))[0xB] = 0;
    ((struct MailViewCtx_f10 *)((struct MailViewCtx *)q)->f10)->f0 = *(unsigned short *)&((struct MbSeqCtx *)p)->f0;
    ((struct MailViewCtx *)q)->f1C = PROCSYS_Create(0x63);
    return 1;
}


/*
 * note 2026-10-05 (wD7 lane15): closed. func_021C414C takes a second argument (u8 *p, its matched
 *   definition reads r1), so case 2 keeps the ctx+0x10 pointer in r1 for that call.
 */
int func_021C3E9C(int unused, u32 *state, u16 *msg, u8 *ctx)
{
    u32 ret = PROCSYS_Main(*(void **)(ctx + 0x1C));
    switch (*state) {
    case 0:
        **(u16 **)(ctx + 0x10) = *msg;
        PROCSYS_Push(*(void **)(ctx + 0x1C), (u32)-1, D_021C7750, *(void **)(ctx + 0x10));
        *state = 1;
        break;
    case 1: {
        u16 v;
        if (ret == 1)
            break;
        v = **(u16 **)(ctx + 0x10);
        if (v != 4) {
            if (v == 0xFFFF)
                *state = 2;
            else
                goto s3;
        } else
            *state = 2;
        break;
    s3:
        *state = 3;

        break;
    }
    case 2:
        if (*msg == 1) {
            u32 r;
            u8 *p = *(u8 **)(ctx + 0x10);
            if (*(u16 *)p == 4) {
                func_021C414C(*(void **)(msg + 10), p);
                func_02008DF0(func_02008C58(*(void **)(msg + 8)), 0x1D);
                r = 1;
            } else {
                r = 0;
            }
            *(u32 *)(msg + 2) = r;
        }
        return 1;
    case 3:
        func_02034AC4((int)ov136_id);
        func_021C3FC8(ctx, (u8 *)msg);
        PROCSYS_Push(*(void **)(ctx + 0x1C), (u32)-1, D_021C775C, *(void **)(ctx + 8));
        *state = 4;
        break;
    case 4:
        if (ret == 1)
            break;
        if (PMSI_PARAM_CheckCanceled(*(void **)(ctx + 8)) == 0) {
            u8 *q = *(u8 **)(ctx + 0x10);
            void *h = *(void **)(ctx + 8);
            if (q[2] < 3)
                PMSI_PARAM_GetSentence(h, q + 0x16 + q[2] * 8);
            else
                *(u16 *)(*(u8 **)(ctx + 0x10) + 0x32) = PMSI_PARAM_GetWord(*(u16 **)(ctx + 8));
        }
        PMSI_PARAM_Delete(*(void **)(ctx + 8));
        func_02034A5C((int)ov136_id);
        *state = 0;
        break;
    }
    return 0;
}


int func_021C3F98(u32 a, void *b, void *c, u32 *p)
{
    u16 h;
    func_0203133C((struct S020314B8 *)p[7]);
    func_021C4134((void *)p[4]);
    h = (u16)p[0];
    func_020315D4((struct S020315D4 *)a);
    func_0203084C(h);
    func_020306F0(h);
    return 1;
}


/*
 * note:     2026-10-02 only unresolved arm9 Thumb leaf witnesses (02024104, 02024108, 02024450 unmanifested); C is complete
 */
void func_021C3FC8(u8 *ctx, u8 *arg)
{
    u8 *p = *(u8 * *)&((struct MailToolCtx *)ctx)->f10;
    u32 k = p[2];
    if (k == 3) {
        PMSI_PARAM_ClearSentence(ctx + 0x14);
        ((struct MailToolCtx *)ctx)->f14 = 6;
        ((struct MailToolCtx *)ctx)->f16 = 0;
        ((struct MailToolCtx *)ctx)->f18 = ((struct MailViewCtx *)((struct MailToolCtx *)ctx)->f10)->f32;
        ((struct MailToolCtx *)ctx)->f8 = PMSI_PARAM_Create(0, 0, 0, 1, ((struct MailViewCtx *)arg)->f10, ((struct MailToolCtx *)ctx)->f0);
        PMSI_PARAM_SetWord(((struct MailToolCtx *)ctx)->f8, ((struct MailViewCtx *)((struct MailToolCtx *)ctx)->f10)->f32);
    } else if (*(p + k + 0x2e) == 1) {
        PMSI_PARAM_Copy((struct Rec8 *)(ctx + 0x14), (const struct Rec8 *)(p + 0x16 + k * 8));
        ((struct MailToolCtx *)ctx)->f8 = PMSI_PARAM_Create(2, 0, ctx + 0x14, 1, ((struct MailViewCtx *)arg)->f10, ((struct MailToolCtx *)ctx)->f0);
    } else {
        ((struct MailToolCtx *)ctx)->f8 = PMSI_PARAM_Create(2, 0, 0, 1, ((struct MailViewCtx *)arg)->f10, ((struct MailToolCtx *)ctx)->f0);
        if (PMSI_PARAM_IsEnabled((u16 *)(*(u8 * *)&((struct MailToolCtx *)ctx)->f10 + 0x16 + (*(u8 * *)&((struct MailToolCtx *)ctx)->f10)[2] * 8)))
            PMSI_PARAM_Copy((struct Rec8 *)(ctx + 0x14), (const struct Rec8 *)(*(u8 * *)&((struct MailToolCtx *)ctx)->f10 + 0x16 + (*(u8 * *)&((struct MailToolCtx *)ctx)->f10)[2] * 8));
        else
            PMSI_PARAM_InitSentence(ctx + 0x14, 0);
        PMSI_PARAM_SetSentence(((struct MailToolCtx *)ctx)->f8, (const u16 *)(ctx + 0x14));
    }
}


void *func_021C409C(void *a, unsigned heap)
{
    u8 *p;
    u16 i;
    i = 0;
    p = func_02030734((u16)heap, 0x34, 0, d_021C7EEC, 0x147);
    func_02082AC0(0, p, 0x34);
    ((struct MailViewCtx_f1C *)p)->f0 = i;
    ((struct MailViewCtx_f1C *)p)->f4 = func_02008F80(a);
    ((struct MailViewCtx_f1C *)p)->fC = STRBUF_Create(0x10, heap);
    STRBUF_SetString(((struct MailViewCtx_f1C *)p)->fC, (const u16 *)func_02008F84(a));
    p[0xB] = func_02008FA4(a);
    p[9] = func_02008FB0(a);
    p[0xA] = func_02008FB8(a);
    ((struct MailViewCtx_f1C *)p)->f32 = func_02008FC0(a);
    for (; i < 3; i++) PMSI_PARAM_Copy((struct Rec8 *)(p + 0x16 + i * 8), (const struct Rec8 *)func_02008FC8(a, (u8)i));
    return p;
}



void func_021C4134(struct MailViewCtx_f1C *p)
{
    if (p->fC)
        STRBUF_Delete(p->fC);
    func_020307B0(p);
}


void func_021C414C(void *a, u8 *p)
{
    u16 i;
    for (i = 0; i < 3; i++) func_02008FD8(a, p + 0x16 + i * 8, (u8)i);
    func_02008FC4(a, ((struct MailViewCtx_f1C *)p)->f32);
    func_02008FA8(a, p[0xB]);
}


/*
 *   int PMSI_PARAM_IsEnabled(unsigned short *p) { return *p != 0xFFFF; }
 */
void func_021C4184(void *a, u8 *p)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (PMSI_PARAM_IsEnabled((const u16 *)(p + 0x16 + i * 8)) == 0) {
            if (d_021C77A0[p[0xB]][i] != 0xFF) PMSI_PARAM_InitSentenceId(p + 0x16 + i * 8, (void *)5, (void *)d_021C77A0[p[0xB]][i]);
        }
        if (d_021C77A0[p[0xB]][i] == 0xFF) p[0x2E + i] = 0;
        else p[0x2E + i] = 1;
    }
}


int func_021C41E0(void *a, void *b, u8 *p)
{
    u8 *q;
    u8 v;
    GFL_HEAP_CreateChildHeap(1, 0x64, 0x20000);
    q = PROCSYS_AllocProcWork(a, 0x15C, 0x64);
    func_02082AC0(0, q, 0x15C);
    ((struct MailViewCtx *)q)->f0 = 0x64;
    ((struct MailViewCtx *)q)->f1C = p;
    q[0xB] = ((struct MailViewCtx_f1C *)p)->f0;
    q[0xC] = q[0xB];
    q[0x16] = p[2];
    q[0x17] = p[3];
    v = q[0x16];
    q[0x1A] = v;
    q[0x1B] = v;
    ((struct MailViewCtx_f1C *)p)->f0 = 0xFFFF;
    q[0x15] = func_02012FFC();
    func_021C4184(q, *(u8 * *)&((struct MailViewCtx *)q)->f1C);
    ((struct MailViewCtx *)q)->f24 = GF_FONT_Create((unsigned)0x17, (unsigned)0, (unsigned)0, (unsigned)0, (u16)(((struct MailViewCtx *)q)->f0));
    ((struct MailViewCtx *)q)->f100 = TCBL_Create((u16)(((struct MailViewCtx *)q)->f0), ((struct MailViewCtx *)q)->f0, 0x20, 0x20);
    q[0xA] = 1;
    func_0203F8F4(((struct MailViewCtx *)q)->f0);
    return 1;
}


int func_021C427C(void *a, void *b, void *c, void *p)
{
    if (func_021C42C8(p)) return 1;
    return 0;
}


int func_021C4290(void *a, void *b, void *c, u32 *p)
{
    u32 h;
    func_0203F9B4();
    TCBL_Destroy((struct S02031140 *)p[0x40]);
    GF_FONT_Delete((void *)p[9]);
    h = p[0];
    func_020315D4(a);
    func_0203084C(h);
    func_020306F0((u16)h);
    return 1;
}



int func_021C42C8(u8 *p)
{
    int r = 0;
    u32 t;

    switch (((struct MailViewCtx *)p)->f4) {
    case 0:
        func_021C4AF8();
        WIPE_SetBrightnessFadeOut(0, 0);
        WIPE_SetBrightnessFadeOut(1, 0);
        WIPE_ResetWndMask(0);
        WIPE_ResetWndMask((void *)1);
        (((struct MailViewCtx *)p)->f4)++;
        break;
    case 1:
        if (func_021C4BFC(p)) {
            ((struct MailViewCtx *)p)->f104 = func_020056A0((void *)func_021C4B5C, p, 0x10);
            BG_SYS_SetMainPlaneVisible(0x10, 1);
            WIPE_ResetBrightness(0);
            func_0207D63C((void *)0x04000050, 4, 8, 0x1C, 4);
            t = func_020056BC();
            PALANM_RequestFade(((struct MailViewCtx *)p)->f38, 5, 0xFFFF, -1, 0x10, 0, 0, t);
            (((struct MailViewCtx *)p)->f4)++;
        }
        break;
    case 2:
        if (!PALANM_GetFadeRequestBits(((struct MailViewCtx *)p)->f38))
            (((struct MailViewCtx *)p)->f4)++;
        PMS_DRAW_Main(((struct MailViewCtx *)p)->f148);
        break;
    case 3:
        if (data_021C7774[p[0xB]](p) == 1) {
            (((struct MailViewCtx *)p)->f4)++;
            t = func_020056BC();
            PALANM_RequestFade(((struct MailViewCtx *)p)->f38, 5, 0xFFFF, -1, 0, 0x10, 0, t);
        }
        PMS_DRAW_Main(((struct MailViewCtx *)p)->f148);
        if (((struct MailViewCtx *)p)->f128) {
            APP_TASKMENU_WIN_Update(((struct MailViewCtx *)p)->f128);
            APP_TASKMENU_WIN_Update(((struct MailViewCtx *)p)->f12C);
        }
        break;
    case 4:
        if (!PALANM_GetFadeRequestBits(((struct MailViewCtx *)p)->f38)) {
            WIPE_SetBrightnessFadeOut(0, 0);
            WIPE_SetBrightnessFadeOut(1, 0);
            func_02030EAC(((struct MailViewCtx *)p)->f104);
            func_021C4AF8();
            (((struct MailViewCtx *)p)->f4)++;
        }
        PMS_DRAW_Main(((struct MailViewCtx *)p)->f148);
        break;
    case 5:
        if (func_021C4D14(p))
            r = 1;
        break;
    }
    if (((struct MailViewCtx *)p)->fA0)
        CLACT_DrawSystem(((struct MailViewCtx *)p)->fA0);
    if (((struct MailViewCtx *)p)->fF8)
        func_02030D28(((struct MailViewCtx *)p)->fF8);
    if (((struct MailViewCtx *)p)->f100)
        TCBL_Main(((struct MailViewCtx *)p)->f100);
    if (((struct MailViewCtx *)p)->f98)
        PRINTSYS_QUE_Main(((struct MailViewCtx *)p)->f98);
    if (((struct MailViewCtx *)p)->f158)
        PRINTSYS_QUE_Main(((struct MailViewCtx *)p)->f158);
    return r;
}
