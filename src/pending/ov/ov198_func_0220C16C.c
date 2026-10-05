/*
 * function: func_0220C16C
 * address: 0x0220C16C
 * packet: pkt_ov198_0220C16C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 *
 * note: DIFF vs 2026-10-04: 22 bytes differ, only the last 201C724 call: original stores the three stack args first and loads n and adds x0+n late (ldr r2,[sp,#0x28] after the stack stores), ours hoists the n load and add before the stack stores. Everything else matches (declaration order sets slots; x0 param reassigned; ctx and A/B locals). Tried: (s16)(x0+n), n+x0, a y local assigned before the call.
 * note 2026-10-05 (wave D4 lane 10): still DIFF (22 bytes). Tried ctx3 inlined as P->f1EAC (115 bytes) and
 *   A/B locals for the third call as in the second (no change). The sibling 0220D494 (EXACT this wave)
 *   computes its x+w1 early like ours, so the late `ldr r2,[sp,#0x28]; adds` here hints the third x is a
 *   different expression or variable in the original; not found.
 * symbols:
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Ov198P { char pad[0x1E9C]; u32 f1E9C; void *f1EA0; void *f1EA4; void *f1EA8; u32 f1EAC; };
#define P ((struct Ov198P *)p)
extern int func_022110D4(u8 *, int);
extern void *func_02045EC0(void *bank, u32 index);
extern u32 func_0201D304(void *, u32, u32);
extern void *func_02045770(void *p);
extern void func_0201C724(u32, u32, s16, s16, void *, u32, u32);
extern void func_02045808(void *);
extern void func_0201EFA4(void *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(void *ws, void *dst, void *src);

void func_0220C16C(u8 *p, int slot, int index, u8 x0, u8 extra)
{
    char *elem = (char *)(p + 4) + func_022110D4(p, index) * 0x4C;
    void *text = func_02045EC0(P->f1EA0, 12);
    u32 n = (u8)func_0201D304(text, P->f1E9C, 0);
    x0 = x0 - (n >> 1);
    u32 ctx1 = P->f1EAC;
    u8 ex = extra;
    slot = slot * 8;
    u8 *tab = p + 0x1F70;
    u8 *fl = p + 0x1F74;
    void *text2;
    void *text3;
    u32 ctx2;
    s16 y;
    u32 ctx3;
    u32 A;
    void *B;
    func_0201C724(ctx1, (u32)func_02045770(*(void **)(tab + slot)), x0, ex, text, P->f1E9C, 0x3DC0);
    fl[slot] = 1;
    func_02045808(text);
    text2 = func_02045EC0(P->f1EA0, 13);
    func_0201EFA4(P->f1EA4, 0, *(u16 *)(elem + 0x10), 3, 0, 1);
    func_0201F250(P->f1EA4, P->f1EA8, text2);
    A = P->f1E9C;
    B = P->f1EA8;
    y = x0 - func_0201D304(B, A, 0);
    ctx2 = P->f1EAC;
    func_0201C724(ctx2, (u32)func_02045770(*(void **)(tab + slot)), y, ex, B, A, 0x3DC0);
    fl[slot] = 1;
    func_02045808(text2);
    text3 = func_02045EC0(P->f1EA0, 13);
    func_0201EFA4(P->f1EA4, 0, *(u16 *)(elem + 0x12), 3, 0, 1);
    func_0201F250(P->f1EA4, P->f1EA8, text3);
    ctx3 = P->f1EAC;
    func_0201C724(ctx3, (u32)func_02045770(*(void **)(tab + slot)), x0 + n, ex, P->f1EA8, P->f1E9C, 0x3DC0);
    fl[slot] = 1;
    func_02045808(text3);
}
