/*
 * function: TEXT_TEXTURE_UploadTextTexture
 * address: 0x0216FD54
 * packet: pkt_ov010_0216FD54
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * EXACT in --lang c99 and --lang c, 176/176 bytes, all 12 relocations resolved.
 * recoup 2026-10-05 (lane C1, ~27 compiles): the older draft (docs/notes) was 110 B off at 172 B.
 * Fixes: hi and wi are plain u32 with an unsigned shift, no u16 or enum (no lsls/lsrs pairs),
 * the area is signed (int)(wi * h) / 8 with h the raw table halfword, and n is an int (a u32 n
 * lets mwcc sink the divide chain below func_0207F7A0; int n keeps it before the call as the
 * original does). Table const, order of wi/hi loads, n position, int/u16 h, callee u32 params,
 * and the six per-function pragmas (on the earlier form) did not help.
 * Residue: (1) entry spills: the original stores r2, r3, r1 with the table index load between;
 * ours stores r1, r2, r3 and loads the u16 argument f before the h spill. (2) base (a+0xc) is
 * loaded early into r4 and off into r5 in the original; ours loads base after the chain into r5
 * and off into r4, so the final add is r5,r4 instead of r4,r5.
 *
 * final push 2026-10-05 G5L10 (40 compiles, 3 rounds): 23 -> 7 B. Fixes: (1) c and d are u16
 * here and u16 in TEXT_TEXTURE_PrintToClearedBitmap (the caller WAZA_OSHIE_LoadTexPlttByName declares them u16): the entry
 * spills come out r2, r3, r1 as in the original; b is u32 (FAB4 passes u32). (2) the tail
 * mirrors the matched sibling WAZA_OSHIE_UploadPalette (u32 b,a; a = base field first, then b = (u16)field*8):
 * base is read BEFORE off and declared AFTER it (u32 off; u32 base;), which gives the base load
 * right after the offset load and the final add r4,r5.
 * Residue (7 B): the original loads the heap halfword f (add r3,sp,#0x38; ldrh r3,[r3,#4])
 * after the wi index load (ldrh r0,[r5]) and after the h spill and lsrs; ours hoists it above
 * the h spill. Tried without effect: const a, struct view of a, inline alloc helper, u16 heap
 * local, *(u16 *)&f, w local, wi/hi inline or reordered (wi before hi or h declared last
 * moves spill slots, 154 B), u32 heap callee param (117 B), five opt_ pragmas, peephole off.
 * pass 2 2026-10-06 P2L15 (40 compiles, 3 rounds, no change to the form, still 7 B): cause found.
 * The image's heap load waits for `str h` because that store goes to a memory OBJECT; a spill
 * store never blocks a stack-parameter load. Diagnostic `BMP_Delete(&h)` puts the f load at
 * +0x20 exactly; `&vram, &buf, &h` with declarations vram, buf, h also gives the image frame
 * (h 0x14, buf 0x18, vram 0x1c), so the original keeps h, buf and vram in memory. Every memory
 * form tried (aggregate {h,buf,vram} with an address use, value temp, wi first, u32 c/d, u16 b)
 * also flips the entry (str r1,[sp,#8] first, index in r1). Forms that do not keep h in memory:
 * inline out-pointer helper, hp = &h, unused &w, union, one-member struct/array, nested blocks
 * (all folded or scalarised). optimization_level 1 shows the f load is textually last.
 * pass 3 2026-10-06 P3L08 (3 compiles): EXACT. h is a u16 local (the table halfword) and
 * hi = (u32)h >> 3 keeps lsrs. mwcc keeps the u16 stack parameter f load behind the spill
 * store of a narrow local, but hoists it above the spill of a u32 local (docs/idioms
 * a-u16-stack-parameter-passed-to-a-u16-callee-stays-behind-a-spill-store.md, SHINKA_CHECK_CheckEvolution
 * pidHigh; a-reload-kept-below-outgoing-stack-stores-is-a-narrow-local.md for the (u32) widen).
 * The earlier u16 h try (154 B) used h >> 3, which promotes to int and gives asrs.
 * symbols:
 *   d_021726A0     0x021726A0  data  ov010
 *   BMP_Create  0x02043678  arm
 *   TEXT_TEXTURE_PrintToClearedBitmap  0x0216FC74  thumb  ov010
 *   TEXT_TEXTURE_ConvertToTileOrder  0x0216FCA0  thumb  ov010
 *   BMP_GetPixels  0x020437D4  arm
 *   func_0207F7A0  0x0207F7A0  arm
 *   DC_FlushRange  0x020862F0  arm
 *   func_0207F7FC  0x0207F7FC  arm
 *   func_0207F9B4  0x0207F9B4  arm
 *   BMP_Delete  0x020437AC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 w;
    u8 pad[10];
} TE;

extern TE d_021726A0[];

struct Bmp;
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
extern void TEXT_TEXTURE_PrintToClearedBitmap(void *a, u16 b, u16 c, u16 d, void *e, void *f);
extern void TEXT_TEXTURE_ConvertToTileOrder(void *a, void *b);
struct Bmp;
struct Obj020437AC;
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern void func_0207F7A0(void);
extern void DC_FlushRange(void *p, int n);
extern void func_0207F7FC(void *p, int src, int n);
extern void func_0207F9B4(void);
extern void BMP_Delete(struct Obj020437AC *p);

void TEXT_TEXTURE_UploadTextTexture(char *a, u32 b, u16 c, u16 d, u16 e, u16 f)
{
    u16 h;
    u32 hi;
    u32 wi;
    void *buf;
    void *tmp;
    void *vram;
    int n;
    u32 off;
    u32 base;

    h = d_021726A0[*(u16 *)(a + 2)].w;
    hi = (u32)h >> 3;
    wi = (u32)d_021726A0[*(u16 *)a].w >> 3;
    tmp = BMP_Create(wi, hi, 0x20, f);
    buf = BMP_Create(wi, hi, 0x20, f);
    TEXT_TEXTURE_PrintToClearedBitmap((void *)b, c, d, e, buf, *(void **)(a + 0x14));
    TEXT_TEXTURE_ConvertToTileOrder(buf, tmp);
    vram = BMP_GetPixels(tmp);
    base = *(u32 *)(a + 0xc);
    off = (u16)*(int *)(a + 4) << 3;
    n = ((int)(wi * h) / 8) << 5;
    func_0207F7A0();
    DC_FlushRange(vram, n);
    func_0207F7FC(vram, base + off, n);
    func_0207F9B4();
    BMP_Delete(buf);
    BMP_Delete(tmp);
}
