/*
 * function: func_021E8568
 * address:  0x021E8568
 * packet:   pkt_ov177_021E8568
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * note 2026-10-02: only prologue scheduling (orig spills r2,r3 before ldr r5 heap, mine
 *   after) and tail ldr r3/str order differ (10 lines). Tried u8 param, local copies,
 *   decl order, init-at-decl, heap types.
 *
 * note 2026-10-05: re-checked the listing: c and d are spilled (str r2,[sp,#0xc]; str r3,[sp,#0x10]) BEFORE
 * the heap load (ldr r5,[sp,#0x30]); ours spills r3 then r2 after the heap load, and loads r3 for the last call
 * above the w->fc store (orig after). Both are scheduler order only, 20 bytes. No source form tried this
 * round changed it (arguments are used in place, no stand-in casts). Still DIFF.
 *
 * note 2026-10-05 (wD9 lane15): 20 -> 8 bytes. `unsigned short c` (docs/idioms/a-narrow-spilled-parameter-keeps-
 *   its-reload-below-a-store.md) fixes the tail: the reload of c now stays below the w->fc store. Left: the
 *   prologue, original `str r2; str r3; ldr r5,[sp,#0x30]; adds r6`, ours `ldr r5; adds r6; str r2; str r3`.
 *   Tried: a struct-by-value (c, d) pair (pushes r0-r3, worse), K&R definition (same 20), d as u16/u8/s16/s8
 *   (10, d's store then drifts below adds r6), a and b as u16 (no change), heap u8/u16 (186, original loads it
 *   as a word), the callee third parameter u16 as in other matched callers (worse). c as u8 is 33 (the original
 *   truncates c at the call).
 *
 * note 2026-10-05 (wD9r lane17, pengy draft): still 8 bytes, prologue only. Hypothesis: c and d are address-taken
 *   so their stores block the heap load. `*&c`/`*&d` at the call: folded, 8. `*(int *)&c` with int c: 38 (homes
 *   r0-r3 in the caller area, push {r0-r3}), so the original does not take their address. Also tried: a local
 *   copy of heap (8), local copies of c and d at the top (8), heap as unsigned int (145).
 * note 2026-10-05 (wD9r lane31): still 8 bytes, prologue only. New tries: c and d as one 64-bit parameter
 *   (20), e/f/heap as a struct passed by value on the stack (8), c and d copied into an `int lc[2]` array local
 *   (8, scalarised), a or b as u8 (113/119), e as u16/u8 (8), f as u16 (158), c as short/signed char (8),
 *   d unsigned int (8), callee 4th parameter u8 with plain c (8; with d u16: 10/12), a..d all u16 (10),
 *   c,d,e u16 (10). With c and d both u16 the c store goes to the front (str r2 matches) but d's store and the
 *   heap load drift down (str r2; adds r6; str r3; movs; adds r7; ldr r5). Left DIFF.
 * note 2026-10-05 (wD9r lane39): still 8 bytes, prologue only. New tries: d as void * / u16 * with the callee
 *   third parameter a pointer (8), an extra unused 8th stack parameter (8), void * return type (8), const heap
 *   (145, heap is reloaded from the stack at each use). Left DIFF.
 * note 2026-10-05 (wD9r lane58): still 8 bytes, prologue only. New tries: the allocation and clear in a
 *   static inline Alloc(heap) helper (8, the inlined copy of heap is propagated), the last call in a static
 *   inline Frame(w, d, c) helper (27). Checked for a matched twin (callers of BMP_MENUWORK_DrawWindow and BMP_WIN_Create
 *   in src/matched): none has this shape. Left DIFF.
 * note 2026-10-05 (wD9r lane68): EXACT. Fix: heap is a u16 parameter (it is stored with strh to f1e) with the
 *   house callee prototypes (func_02030734 u32 heap, u16 tag; STRBUF_Create u32, u32; TCBL_Create u32 heap,
 *   u16 tag, so heap goes to both), and d is a u16 parameter passed to the u16 third parameter of
 *   BMP_MENUWORK_DrawWindow. The u16 heap keeps the word ldr and moves it below the c home store (8 -> 6), and the u16 d
 *   moves its home store to the front (6 -> 0). See
 *   docs/idioms/a-u16-heap-parameter-with-u16-callees-loads-as-a-word-and-keeps-the-entry-order.md.
 * symbols:
 *   func_02030734  0x02030734  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   TCBL_Create  0x0203101C  arm
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   d_021E8DD4     0x021E8DD4  data
 */

typedef struct {
    char           pad0[4];
    int            f4;
    char           pad1[4];
    int            fc;
    int            f10;
    int            f14;
    int            f18;
    unsigned short f1c;
    unsigned short f1e;
    int            f20;
    unsigned char  f24;
    char           pad2[3];
    int            f28;
    int            f2c;
} S;

extern unsigned char d_021E8DD4[];

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct Tcbl;
struct U16Vec;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  MI_CpuFill8(void *, int, int);
extern u32 PRINTSYS_QUE_Create(void *p);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);

S *func_021E8568(int a, int b, unsigned short c, unsigned short d, int e, int f, unsigned short heap)
{
    S *w;
    int h;

    w = func_02030734(heap, 0x40, 0, (const char *)d_021E8DD4, 0x5e);
    MI_CpuFill8(w, 0, 0x40);
    w->f1c = 0xf;
    w->f4 = f;
    w->f28 = PRINTSYS_QUE_Create((void *)heap);
    w->f2c = 3;
    w->f1e = heap;
    w->f18 = (int)STRBUF_Create(0x300, heap);
    w->f14 = BMP_WIN_Create((unsigned char)a, 1, 0x13, 0x1e, 4, (unsigned char)b, 1);
    w->f20 = w->f14;
    w->f24 = 0;
    BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)w->f14), (unsigned char)w->f1c);
    h = w->f14;
    BMP_WIN_TransferChars((struct Descriptor *)h);
    BMP_WIN_MakeScreen((struct Cfg *)h);
    func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)h));
    w->fc = (int)TCBL_Create(heap, heap, 1, 0x20);
    BMP_MENUWORK_DrawWindow((void *)w->f14, 0, d, (unsigned char)c);
    return w;
}
