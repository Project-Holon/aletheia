/*
 * function: func_021BAC78
 * address: 0x021BAC78
 * packet: pkt_ov110_021BAC78
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: DIFF
 * note: 2026-10-04 (wD1 lane17): DIFF, 8 bytes of schedule/colour residue. Orig keeps the zero for pos.b/pos.z in r1 and folds the ternary flag (mode==2 ? 1 : 0) into the same r1 with the u16 narrowing (lsls/lsrs 16) before OS_DisableInterrupts, flag lives in r4. Ours keeps zero in r4 and narrows at the call. Tried: u16 f, int f + (u16) cast, int z shared zero, ternary, stores before/after, u32 a for the stack byte (that part is fixed).
 * symbols:
 *   OS_DisableInterrupts 0x02087988 arm
 *   OS_RestoreInterrupts 0x0208799C arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B954 0x0204B954 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { short x, y, z; u8 a, b; } Position;
struct Obj;
extern int OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(int s);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, u16, u16);
extern void func_0204B92C(struct Obj *, u32);
extern void func_0204B954(struct Obj *, u32);
struct Obj *func_021BAC78(char *p, u32 *r, short x, short y, u32 a, int mode)
{
    Position pos;
    struct Obj *o;
    u16 f;
    int s;
    pos.x = x;
    pos.y = y;
    pos.a = a;
    pos.b = 0;
    pos.z = 0;
    f = 0;
    if (mode == 2) f = 1;
    s = OS_DisableInterrupts();
    o = func_0204B294(*(void **)(p + 0x20), r[1], r[0], r[2], &pos, f, 42);
    OS_RestoreInterrupts(s);
    if (o) {
        func_0204B92C(o, 1);
        func_0204B954(o, 1 << 12);
    }
    return o;
}
