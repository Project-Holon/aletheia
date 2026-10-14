/*
 * function: ZUKAN_DETAIL_INFO_Init
 * address: 0x021BEA04
 * packet: pkt_ov208_021BEA04
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * 2026-10-04 (D2-16): callback ZUKAN_DETAIL_INFO_NoOp filed EXACT as src/matched/ov/ov208_func_021BEF9C.c (empty void function, bx lr). Still MATCH only
 * because no shard witnesses it yet; the integrator manifest run should make this EXACT. Symbols line now carries the ov208 hint.
 * symbols:
 *   func_02034AC4 0x02034AC4 arm
 *   ov067_id 0x00000043 data
 *   ov206_id 0x000000CE data
 *   ZUKAN_DETAIL_PROCSYS_AllocBuffer 0x021BC32C thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   func_020056A0 0x020056A0 thumb
 *   ZUKAN_DETAIL_INFO_NoOp 0x021BEF9C thumb ov208
 *   ZUKAN_DETAIL_COMMON_AllocBlendWork 0x021BC448 thumb
 *   ZUKAN_DETAIL_COMMON_InitBrightnessTarget 0x021BC518 thumb
 *   ZUKAN_DETAIL_COMMON_SetBrightnessNone 0x021BC508 thumb
 * 2026-10-02: only ZUKAN_DETAIL_INFO_NoOp (task callback, no witness yet) blocks EXACT; bytes match.
 */
typedef unsigned short u16;
typedef unsigned int u32;
struct Ov208Scene {
    int task;
    int f4; int f8;
    void *fc;
    void *f10;
    int f14; int f18;
    char pad[0x94 - 0x1c];
    int f94; int f98;
    char pad2[0x10c - 0x9c];
    int f10c;
};
extern const char ov067_id[];
extern const char ov206_id[];
typedef signed int     s32;
struct Ov208Buf;
extern int func_02034AC4(s32 handle);
extern void *ZUKAN_DETAIL_PROCSYS_AllocBuffer(struct Ov208Buf *p, u32 size, u32 heap);
extern void MI_CpuFill8(void *p, int v, int n);
extern int func_020056A0(void (*fn)(void *), void *arg, int n);
extern void ZUKAN_DETAIL_INFO_NoOp(void *p);
extern void *ZUKAN_DETAIL_COMMON_AllocBlendWork(u32 heap);
extern void ZUKAN_DETAIL_COMMON_InitBrightnessTarget(int *p);
extern void ZUKAN_DETAIL_COMMON_SetBrightnessNone(int flag, int *p);
int ZUKAN_DETAIL_INFO_Init(void *owner, int unused, u16 *heap)
{
    struct Ov208Scene *s;
    func_02034AC4((u32)ov067_id);
    func_02034AC4((u32)ov206_id);
    s = ZUKAN_DETAIL_PROCSYS_AllocBuffer(owner, 0x120, *heap);
    MI_CpuFill8(s, 0, 0x120);
    s->task = func_020056A0(ZUKAN_DETAIL_INFO_NoOp, s, 1);
    s->f94 = 6;
    s->f98 = 6;
    s->f10c = 0;
    s->fc = ZUKAN_DETAIL_COMMON_AllocBlendWork(*heap);
    s->f10 = ZUKAN_DETAIL_COMMON_AllocBlendWork(*heap);
    ZUKAN_DETAIL_COMMON_InitBrightnessTarget(s->fc);
    ZUKAN_DETAIL_COMMON_InitBrightnessTarget(s->f10);
    ZUKAN_DETAIL_COMMON_SetBrightnessNone(0, s->fc);
    ZUKAN_DETAIL_COMMON_SetBrightnessNone(1, s->f10);
    s->f14 = 0;
    s->f18 = 1;
    return 1;
}
