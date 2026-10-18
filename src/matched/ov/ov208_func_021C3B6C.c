/*
 * function: ZUKAN_DETAIL_FORM_Init
 * address: 0x021C3B6C
 * packet: pkt_ov208_021C3B6C
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: the pool word 0x021C47B5 is a thumb function at 021C47B4 that is not in
 *   layout/function_starts.txt (an 16-byte tail-call thunk, ldr r0,[r1,#0x6ac] then bx to
 *   021BC6BC, inside the listing extent of 021C47A0). Needs a layout start and a witness
 *   (2026-10-03). Everything else matches.
 * symbols:
 *   ov208_func_021BC32C 0x021BC32C thumb ov208
 *   MI_CpuFill8 0x02082BCC arm
 *   ov208_func_021BC3A8 0x021BC3A8 thumb ov208
 *   ov208_func_021BCF4C 0x021BCF4C thumb ov208
 *   ov208_func_021BC3AC 0x021BC3AC thumb ov208
 *   func_020056A0 0x020056A0 thumb
 *   ZUKAN_DETAIL_FORM_ApplyPendingDisplay 0x021C47B4 thumb ov208
 *   ZUKAN_DETAIL_FORM_CreatePrintQueues 0x021C4AC4 thumb ov208
 *   ov208_func_021BC448 0x021BC448 thumb ov208
 *   ZUKAN_DETAIL_COMMON_InitBrightnessTarget 0x021BC518 thumb ov208
 *   ov208_func_021BC508 0x021BC508 thumb ov208
 *   ov208_func_021BC610 0x021BC610 thumb ov208
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *ov208_func_021BC32C(void *proc, u32 size, u32 heap);
extern void MI_CpuFill8(void *p, u32 v, u32 n);
extern int ov208_func_021BC3A8(int key);
extern void *ov208_func_021BCF4C(int a);
extern void *ov208_func_021BC3AC(int key);
extern void *func_020056A0(void (*fn)(void), void *p, u32 c);
extern void ZUKAN_DETAIL_FORM_ApplyPendingDisplay(void);
extern void ZUKAN_DETAIL_FORM_CreatePrintQueues(u16 *heap, u8 *p, int key);
extern void *ov208_func_021BC448(u32 heap);
extern void ZUKAN_DETAIL_COMMON_InitBrightnessTarget(void *a);
extern void ov208_func_021BC508(int flag, void *a);
extern void *ov208_func_021BC610(u32 heap);

#define W(o) (*(u32 *)(p + (o)))
#define PW(o) (*(void **)(p + (o)))

int ZUKAN_DETAIL_FORM_Init(void *proc, int *seq, u16 *heap, u8 *unused, int key)
{
    u8 *p;
    u8 i;
    p = ov208_func_021BC32C(proc, 0x6e4, *heap);
    i = 0;
    MI_CpuFill8(p, 0, 0x6e4);
    PW(0) = ov208_func_021BCF4C(ov208_func_021BC3A8(key));
    PW(4) = ov208_func_021BC3AC(key);
    for (i = 0; i < 4; i++) {
        *(u32 *)(p + i * 0x44 + 0xc) = 0;
        *(u32 *)(p + i * 0x44 + 0x10) = 0;
    }
    for (i = 0; i < 2; i++)
        *(u32 *)(p + 0x13c + i * 4) = 0;
    W(0x144) = 0;
    W(0x124) = 1;
    PW(0x6a0) = func_020056A0(ZUKAN_DETAIL_FORM_ApplyPendingDisplay, p, 1);
    ZUKAN_DETAIL_FORM_CreatePrintQueues(heap, p, key);
    PW(0x6a4) = ov208_func_021BC448(*heap);
    PW(0x6a8) = ov208_func_021BC448(*heap);
    ZUKAN_DETAIL_COMMON_InitBrightnessTarget(PW(0x6a4));
    ZUKAN_DETAIL_COMMON_InitBrightnessTarget(PW(0x6a8));
    ov208_func_021BC508(0, PW(0x6a4));
    ov208_func_021BC508(1, PW(0x6a8));
    PW(0x6ac) = ov208_func_021BC610(*heap);
    W(0x6b0) = 0;
    W(0x6b4) = 1;
    W(0x6b8) = 0;
    W(0x6d4) = 0;
    W(0x6d8) = 0;
    W(0x6dc) = 1;
    W(0x6e0) = 1;
    return 1;
}
