/*
 * function: func_021C40BC
 * address:  0x021C40BC
 * packet:   pkt_ov127_021C40BC
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * note (2026-10-04, wD2 lane07): first draft, DIFF. Semantics read from the listing; callees are matched (func_021C4354 is a bx lr
 *   identity, declared int f(int) as its callers do). The 8-byte stack Pos init matches through +0x2C (a temp for pos[2] puts the z store
 *   between its load and store). Residue: (1) the compiler keeps the constant 6 (pos[3] offset) in [sp,#0x10] and reloads it, so the frame is 0x20 and
 *   push has r3; original rematerialises `movs r1,#6` before each pos[3] read and uses frame 0x1c; (2) owner/idx colours swapped (original owner r7, idx r6);
 *   (3) original computes row = owner + idx*0x14 once into ip and copies it to r1/r2/r6 for the f14/f18/f188 loads. Aggregate initialiser for Pos is worse.
 *
 * 2026-10-05 (D4-18): still DIFF (240-248 vs 256). Tried: second pos[3] read as *(s16 *)((u8 *)pos + 6) (no change, constant 6 still spilled to [sp,#0x10]); row as u8 * (owner + idx*0x14) shared by the f14/f18/f188/f20 loads (240 bytes, 193 out, the 0x20 read now uses the pointer and owner/idx stay swapped). Residue unchanged: original rematerialises movs r1,#6 and keeps only the row offset in [sp,#0x10], recomputing owner+off after the call.
 *
 * symbols:
 *   func_021C4604  0x021C4604  thumb ov127
 *   func_021C4354  0x021C4354  thumb ov127
 *   func_0204B294  0x0204B294  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_0204B908  0x0204B908  arm
 *   func_021C4550  0x021C4550  thumb ov127
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { s16 x, y, z; u8 a, b; } Pos;
extern u32 *func_021C4604(u8 *);
extern int func_021C4354(int);
extern u32 func_0204B294(u32, u32, u32, u32, const Pos *, u16, u16);
extern void func_0204B84C(u32, u32);
extern void func_0204B908(u32, u32);
extern int func_021C4550(u8 *);
u32 *func_021C40BC(u8 *owner, s16 *pos, int idx, u32 heap)
{
    u32 *e = func_021C4604(owner);
    Pos l;
    int ta;
    int row;
    idx = func_021C4354(idx);
    l.x = pos[0];
    l.y = pos[1];
    ta = pos[2];
    l.z = 0;
    l.a = ta;
    l.b = pos[3];
    row = idx * 0x14;
    e[1] = func_0204B294(*(u32 *)owner, *(u32 *)(owner + row + 0x14), *(u32 *)(owner + row + 0x18),
                         *(u32 *)(owner + row + 0x188), &l, 0, (u16)heap);
    func_0204B84C(e[1], (u8)pos[3]);
    func_0204B908(e[1], (*(u32 *)(owner + row + 0x20) == 1) ? 6 : 1);
    e[3] = 9;
    *(u16 *)(e + 5) = 0;
    e[4] = 1;
    e[0] = (u32)(owner + 0x10 + row);
    if (func_021C4550(owner + 0x2E0)) {
        l.x = pos[0];
        l.y = pos[1];
        l.z = 0;
        l.a = *(u32 *)(owner + 0x2F0);
        l.b = 0;
        e[2] = func_0204B294(*(u32 *)owner, *(u32 *)(owner + 0x2E0), *(u32 *)(owner + 0x2E4),
                             *(u32 *)(owner + 0x2E8), &l, 0, (u16)heap);
        func_0204B84C(e[2], (u8)pos[3]);
    } else {
        e[2] = 0;
    }
    return e;
}
