/*
 * unit:     no
 * function: PMS_DRAW_PrintElem
 * address:  0x0202E1F0
 * packet:   pkt_0202E1F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PMSI_PARAM_Copy  0x02024570  thumb
 *   PMSI_PARAM_Validate  0x0202465C  thumb
 *   PMSI_PARAM_GetSourceString  0x0202441C  thumb
 *   func_0201D478  0x0201D478  thumb
 *   PMSI_PARAM_IsDecoWordAt  0x020244F8  thumb
 *   PMSI_PARAM_GetWordId  0x020244D4  thumb
 *   PMSI_PARAM_ToStringWords  0x02024368  thumb
 *   func_0201D528  0x0201D528  thumb
 *   func_0201D4BC  0x0201D4BC  thumb
 *   PMS_DRAW_PlaceDecoActor  0x0202E040  thumb
 *   func_02045770  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   BMP_FillRect  0x02043AF4  arm
 *   STRBUF_Delete  0x02045808  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *
 * blink_palanm: set up a message's blink palette animation.  Copy the
 * caller's MSGPARAM into a local, build the string, mark which characters
 * blink (wk->blink[i]) or are blank (mark[i]), draw the window, then start
 * a palette animation (PMS_DRAW_PlaceDecoActor) on every blinking character and clear
 * every blank one.  Only caller: PMS_DRAW_PrintOffset, which passes the five stack
 * words (param, pos, pri, pal, heap).
 *
 * Closed 2026-09-24 (wave 21, lane E12) from DIFF 2
 * (docs/notes/pkt_0202E1F0.c.txt, waves 5-21).  Two things together,
 * neither enough on its own:
 *   - the parameter `param` is reused as `param = &mp` after the copy, and
 *     every later call, including PMSI_PARAM_ToStringWords after loop 1, takes
 *     `param` (with `&mp` there the image's `adds r0, r7, #0` at +0x8E is
 *     rematerialised as `add r0, sp, #0x38`, 2 out);
 *   - the two stores after PMSI_PARAM_Validate are written msg first, then
 *     active.  In the other order the compile puts wk in r7 and param in r6
 *     (21 out).  The scheduler emits the strb before the str in both
 *     orders, so the listing only shows the order through the allocation.
 * The lane-E7 draft (callee widths read from the callees' matched bodies)
 * is the starting point; only those two lines differ from it.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/PMS_DRAW_PrintElem.c \
 *       --func PMS_DRAW_PrintElem --addr 0x0202E1F0 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct { u16 arc; u16 str; u16 code[2]; } MSGPARAM;
typedef struct { s32 x; s32 y; } BLINKPOS;

typedef struct {
    u32   msg;          /* 0x00 */
    u8    active;       /* 0x04 */
    void *act[2];       /* 0x08 */
    u32   unk10[2];     /* 0x10 */
    u32   drawn : 1;    /* 0x18 */
    u32   ready : 1;
    u32   unk1c;        /* 0x1c */
    u32   blink[2];     /* 0x20 */
} BLINKWORK;

struct Container;
struct Pos;
struct Rec8;
struct Struct_0202441C;
struct T;
extern void PMSI_PARAM_Copy(struct Rec8 *dst, const struct Rec8 *src);
extern u32 PMSI_PARAM_Validate(struct T *p, u32 a1, u32 a2);
extern void *PMSI_PARAM_GetSourceString(const struct Struct_0202441C *obj, u32 heapId);
extern u32   func_0201D478(void *str);
extern u32 PMSI_PARAM_IsDecoWordAt(struct Container *p, u32 idx);
extern u16 PMSI_PARAM_GetWordId(void *obj, u32 idx);
extern void *PMSI_PARAM_ToStringWords(u16 *slots, u32 heap, int count);
extern u32 func_0201D528(void *s, u8 b, void *c, u32 d);
extern u32   func_0201D4BC(void *s, u8 idx);
struct Descriptor;
extern void PMS_DRAW_PlaceDecoActor(void *h, struct Descriptor *cell, u32 b, u32 c, u32 n, const struct Pos *base);
struct Descriptor;
extern void *func_02045770(struct Descriptor *msg);
struct Cfg;
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void  BMP_FillRect(u32 a, u32 b, s16 c, u32 d, u32 e, u8 f);
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void  func_02041B6C(u32 bg);

void PMS_DRAW_PrintElem(BLINKWORK *wk, void *owner, u32 a2, struct Descriptor *a3,
                   const MSGPARAM *param, const BLINKPOS *pos,
                   u16 pri, u8 pal, u16 heap)
{
    u32 mark[2] = {0, 0};
    MSGPARAM mp;
    void *str;
    void *buf;
    int i;
    u16 heapID;
    int n;

    PMSI_PARAM_Copy((struct Rec8 *)(&mp), (const struct Rec8 *)param);
    param = &mp;
    PMSI_PARAM_Validate((struct T *)(&mp), 1, heap);
    wk->msg = (u32)a3;
    wk->active = 0;
    heapID = *(u16 *)&heap;
    str = PMSI_PARAM_GetSourceString((const struct Struct_0202441C *)param, heapID);
    n = (u8)func_0201D478(str);
    for (i = 0; i < n; i++) {
        if (PMSI_PARAM_IsDecoWordAt((struct Container *)param, i)) {
            wk->blink[i] = 1;
        } else if (PMSI_PARAM_GetWordId((void *)param, i) == 0xffff) {
            mark[i] = 1;
        }
    }
    buf = PMSI_PARAM_ToStringWords((u16 *)param, heapID, n);
    BMP_Clear((struct CharBuf *)((u32)func_02045770((struct Descriptor *)wk->msg)), pal);
    PRINTSYS_PrintQueColor(owner, (u32)func_02045770((struct Descriptor *)wk->msg), (s16)pos->x, (s16)pos->y, (u32)buf, a2, pri);
    wk->active = 1;
    for (i = 0; i < n; i++) {
        if (wk->blink[i] == 1) {
            u32 x = func_0201D528(buf, i, (void *)a2, 0);
            u32 y = func_0201D4BC(buf, i);
            PMS_DRAW_PlaceDecoActor(wk->act[i], a3, x, y, PMSI_PARAM_GetWordId((void *)param, i), (const struct Pos *)pos);
        } else if (mark[i] == 1) {
            u32 x = func_0201D528(buf, i, (void *)a2, 0);
            u32 y = func_0201D4BC(buf, i);
            BMP_FillRect((u32)func_02045770((struct Descriptor *)a3), x, y << 4, 0x54, 0x10, pal);
        }
    }
    STRBUF_Delete(buf);
    STRBUF_Delete(str);
    BMP_WIN_MakeScreen((struct Cfg *)wk->msg);
    func_02041B6C(func_02045730((struct Descriptor *)wk->msg));
    wk->drawn = 1;
    wk->ready = 1;
}
