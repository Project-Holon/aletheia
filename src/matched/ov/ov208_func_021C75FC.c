/*
 * function: ZUKAN_DETAIL_FORM_UpdateSlideRight
 * address:  0x021C75FC
 * packet:   pkt_ov208_021C75FC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZUKAN_DETAIL_FORM_CopyModelPosition        0x021C80CC  thumb
 *   ZUKAN_DETAIL_FORM_SelectModelPosition        0x021C80AC  thumb
 *   MCSS_GetPosition        0x02015C30  thumb
 *   MCSS_SetPosition        0x02015C48  thumb
 *   ZUKAN_DETAIL_FORM_HandleStateEvent  0x021C5F34  thumb
 *   func_021C7D80        0x021C7D80  thumb
 *   ZUKAN_DETAIL_FORM_SignalAnimDone        0x021C5200  thumb
 *   func_021C5CF0        0x021C5CF0  thumb
 *   func_021C4E54        0x021C4E54  thumb
 *   func_021C4EAC        0x021C4EAC  thumb
 *   ZUKAN_DETAIL_FORM_UpdateCursorMarkers  0x021C6A10  thumb
 *   ZUKAN_DETAIL_COMMON_GetCurrentEntry        0x021BC3C0  thumb
 *   ZUKAN_DETAIL_COMMON_GetSource        0x021BC3A4  thumb
 *   ZUKAN_SAVE_GetFromGameData        0x0200CA1C  thumb
 *   ZUKAN_SAVE_UpdateViewFlags        0x0200CA98  thumb
 *   ov208_func_021C7448  0x021C7448  thumb
 *   _fflt                0x0209BDBC  arm
 *   _fdiv                0x0209CE10  arm
 *   _fgr                 0x0209BBB0  arm
 *   _fmul                0x0209C77C  arm
 *   _fadd                0x0209C95C  arm
 *   _fsub                0x0209CB8C  arm
 *   _ffix                0x0209C494  arm
 *   _fgeq                0x0209BB54  arm
 *   _fleq                0x0209BC0C  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     fx32;

typedef struct {
    fx32 x;
    fx32 y;
    fx32 z;
} Vec;

typedef struct {
    float x;
    float y;
    float z;
} VecF;

extern void ZUKAN_DETAIL_FORM_CopyModelPosition(void *u, int k, VecF *v);
extern void ZUKAN_DETAIL_FORM_SelectModelPosition(int a, int b, int c);
extern void MCSS_GetPosition(void *p, u32 *out);
extern void MCSS_SetPosition(void *p, u32 *src);
extern void ZUKAN_DETAIL_FORM_HandleStateEvent(void *a0, u8 *p, void *ctx, int ev);
extern void func_021C7D80(void *a0, u8 *p, void *ctx);
extern void ZUKAN_DETAIL_FORM_SignalAnimDone(int *p);
extern void func_021C5CF0(void *a0, u8 *p, void *ctx);
extern void func_021C4E54(void *a0, u8 *p, void *ctx);
extern void func_021C4EAC(void *a0, u8 *p, void *ctx);
extern void ZUKAN_DETAIL_FORM_UpdateCursorMarkers(void *a0, u8 *p, void *ctx);
extern u16  ZUKAN_DETAIL_COMMON_GetCurrentEntry(void *ctx);
struct Blk37;
extern int ZUKAN_DETAIL_COMMON_GetSource(int *p);
extern void *ZUKAN_SAVE_GetFromGameData(void *a);
extern void ZUKAN_SAVE_UpdateViewFlags(struct Blk37 *p, u16 id, u32 sel, u32 alt, u32 form);
extern void ov208_func_021C7448(void *a0, u8 *p, void *ctx);

#define W(o) (*(u32 *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))

#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? \
                                  ((x) * (1 << 12) + 0.5f) : \
                                  ((x) * (1 << 12) - 0.5f)))

void ZUKAN_DETAIL_FORM_UpdateSlideRight(void *a0, u8 *p, void *ctx)
{
    Vec v;
    VecF a;
    Vec u;
    Vec w;
    float x;
    float tx;
    int done;
    int idx;
    u16 id;
    void *obj;
    u32 f;
    u32 sh;

    if (W(0x6c4) == 1) {
        done = 0;
        idx = W(0x124) != 0 ? 2 : 3;
        ZUKAN_DETAIL_FORM_CopyModelPosition(p + 0xc + idx * 0x44, 0, &a);
        tx = a.x;
        MCSS_GetPosition((void *)(*(u32 *)(p + 0xc + idx * 0x44)), (u32 *)(&v));
        x = v.x / 4096.0f;
        if (W(0x6c8) == 0) {
            x += 2.0f;
            if (x >= tx)
                done = 1;
        } else {
            x -= 2.0f;
            if (x <= tx)
                done = 1;
        }
        if (done) {
            x = tx;
            W(0x6c4) = 2;
        }
        v.x = FX_F32_TO_FX32(x);
        if (W(0x94) != 0)
            MCSS_SetPosition((void *)W(0x94), (u32 *)(&v));
        if (W(0xd8) != 0)
            MCSS_SetPosition((void *)W(0xd8), (u32 *)(&v));
        idx = 0;
        if (W(0x124) == 0)
            idx = 1;
        MCSS_GetPosition((void *)(*(u32 *)(p + idx * 0x44 + 0xc)), (u32 *)(&v));
        x = v.x / 4096.0f;
        if (W(0x6c8) == 0)
            x += 2.0f;
        else
            x -= 2.0f;
        v.x = FX_F32_TO_FX32(x);
        if (W(0xc) != 0)
            MCSS_SetPosition((void *)W(0xc), (u32 *)(&v));
        if (W(0x50) != 0)
            MCSS_SetPosition((void *)W(0x50), (u32 *)(&v));
    } else if (W(0x6c4) == 2) {
        sh = 0;
        ZUKAN_DETAIL_FORM_HandleStateEvent(a0, p, ctx, 0);
        func_021C7D80(a0, p, ctx);
        ZUKAN_DETAIL_FORM_SignalAnimDone((int *)(p + 0x94));
        ZUKAN_DETAIL_FORM_SignalAnimDone((int *)(p + 0xd8));
        func_021C5CF0(a0, p, ctx);
        func_021C4E54(a0, p, ctx);
        func_021C4EAC(a0, p, ctx);
        ZUKAN_DETAIL_FORM_UpdateCursorMarkers(a0, p, ctx);
        id = ZUKAN_DETAIL_COMMON_GetCurrentEntry(ctx);
        obj = ZUKAN_SAVE_GetFromGameData((void *)ZUKAN_DETAIL_COMMON_GetSource(ctx));
        f = *(p + H(0x54e) * 16 + 0x152);
        if (*(p + H(0x54e) * 16 + 0x153) != 0)
            sh = 1;
        ZUKAN_SAVE_UpdateViewFlags(obj, id, f, sh, *(u16 *)(p + H(0x54e) * 16 + 0x154));
        if (W(0xc) != 0) {
            ZUKAN_DETAIL_FORM_SelectModelPosition((int)(p + 0xc), 0, (int)(&u));
            MCSS_SetPosition((void *)W(0xc), (u32 *)(&u));
        }
        if (W(0x50) != 0) {
            ZUKAN_DETAIL_FORM_SelectModelPosition((int)(p + 0x50), 0, (int)(&w));
            MCSS_SetPosition((void *)W(0x50), (u32 *)(&w));
        }
        W(0x6c8) = 1;
        ov208_func_021C7448(a0, p, ctx);
        W(0x6c4) = 0;
    }
}
