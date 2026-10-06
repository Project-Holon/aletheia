/*
 * function: func_021C40BC
 * address:  0x021C40BC
 * packet:   pkt_ov127_021C40BC
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * note (2026-10-05, wD5 lane07): EXACT. Keys: a real record array (stride 0x14 at +0x10) keeps idx*0x14 spilled
 *   and recomputes owner+row per use; the 6/1 argument as a call in each if/else arm keeps the 6 from merging with
 *   the pos[3] offset constant; const pos lets the pos[3] load schedule above the e[1] store; off = 0x2E0 local.
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
typedef struct { u32 f0, f4, f8, fC, f10; } Rec;
typedef struct {
    u32 h0;
    u8 pad4[0xC];
    Rec rec[18];        /* +0x010 */
    u8 pad178[0x10];
    Rec res[1];         /* +0x188, indexed by idx */
} Own;
struct Obj;
extern void *func_021C4604(u8 *p);
extern int func_021C4354(int);
extern struct Obj *func_0204B294(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern void func_0204B84C(u32, u32);
extern void func_0204B908(int a0, int a1);
extern int func_021C4550(int *p);
u32 *func_021C40BC(Own *owner, const s16 *pos, int idx, u32 heap)
{
    u32 *e = func_021C4604((u8 *)owner);
    Pos l;
    int off;
    int ta;
    idx = func_021C4354(idx);
    l.x = pos[0];
    l.y = pos[1];
    ta = pos[2];
    l.z = 0;
    l.a = ta;
    l.b = pos[3];
    e[1] = (u32)func_0204B294((void *)owner->h0, owner->rec[idx].f4, owner->rec[idx].f8,
                         owner->res[idx].f0, &l, 0, (u16)heap);
    func_0204B84C(e[1], (u8)pos[3]);
    if (owner->rec[idx].f10 == 1)
        func_0204B908(e[1], 6);
    else
        func_0204B908(e[1], 1);
    e[3] = 9;
    *(u16 *)(e + 5) = 0;
    e[4] = 1;
    e[0] = (u32)&owner->rec[idx];
    off = 0x2E0;
    if (func_021C4550((int *)((u8 *)owner + off))) {
        l.x = pos[0];
        l.y = pos[1];
        l.z = 0;
        l.a = *(u32 *)((u8 *)owner + off + 0x10);
        l.b = 0;
        e[2] = (u32)func_0204B294((void *)owner->h0, *(u32 *)((u8 *)owner + off), *(u32 *)((u8 *)owner + off + 4),
                             *(u32 *)((u8 *)owner + off + 8), &l, 0, (u16)heap);
        func_0204B84C(e[2], (u8)pos[3]);
    } else {
        e[2] = 0;
    }
    return e;
}
