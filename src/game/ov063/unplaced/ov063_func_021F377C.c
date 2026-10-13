/*
 * function: func_021F377C
 * address: 0x021F377C
 * packet: pkt_ov063_021F377C
 * region: ov063
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * checks: 1 own B7A84/B7D50 and narrowed ov010/ov021 callers confirm arities; 2 matched 36C0/3758/376C and neighbours refreshed; 3 unsigned table Cell and signed local Cell reduce DIFF1166 to 730, raw halfword buffer worse 1466/+24, const vector inputs retained; 4 grouped vector stores and reversed stack-local declarations tried (two scheduling variants), stack-object/fixed-float idioms read; 5 fresh idioms and neighbours, no new twin. Next: original height spill and frame layout; leave ov021 blockers to the integrator.
 * runs: W75 five fixed one runs plus baseline explain and first permuter300; prior four fixed runs retained as history, not repeated.
 * residual: 730 concrete bytes; compiled 1528, original code/pool ends 021F3D74 (1528, delta 0); handed 1572 includes trailing rodata. Relocations 77/79: ov021 B3D0/B388 unresolved and integrator-owned, not filed.
 * search: macro-free emitted baseline agrees DIFF730/1528. Permuter300 best DIFF663 rejected: tmp2 = s->scene lies after case0 break and is bypassed by case1; tmp = s->delta.y lies after case4 break and is bypassed by case5. Both cases read uninitialized temporaries. Search consumed; do not repeat.
 * note: recoup 2026-10-05 (P26L1): lane size 30 B was a label gap; real extent 1528 B (021F377C..021F3D74). Residue read from listing: the original keeps height (func_021B7D50 result) in a stack slot [sp,#0xc] and holds &cell (add r6,sp,#0x1c, computed inside the cell copy, used as adds r1,r6,#0 for the first func_021BB3C4 call) in r6 across that call; compiled keeps height in r6 and builds the address at the call. That one spill gives the 4-byte larger frame (sub sp,#0x74 with push r3 dropped) and shifts every later sp offset, so most of the 730 bytes are offset shift, not new logic. Tried: LocalCell *cp local for both the first call and the loop (identical output, mwcc propagates the address), pragmas opt_lifetimes/opt_propagation/opt_common_subs/scheduling off (1136/1338/1272/730, worse or equal). The two ov021 relocations: func_021BB3D0 has a matched file src/matched/ov/ov072_func_021BB3D0.c, the ov072 token resolves it but raises the diff to 734 B (the ov072 copy is a different function body at that address), so ov021 stays; func_021BB388 also unwitnessed. Next: find a source form that keeps an address live across the height call without a stand-in.
 * note: recoup 2026-10-05 P30R9 (11 compiles, all DIFF 730 or worse): real callee types from matched callers (func_021AB0F8 returns u16 takes u32, func_021BB3C4 returns u32): 730, no change. const on BB3C4 / B7D50 record pointer: 730. Inline helper blocked(scene,cell) for both attribute tests: 730. Inline fetch(&cell,s) for the cell copy-in: 730. LocalCell *cp local set before the height call and used in the first BB3C4 call, set once or set again in the loop: 730 (mwcc propagates every single-use or repeated &cell, so the early add r6,sp,#0x1c is not a pointer variable in the source; it must come from a CSE of an address expression in the copy block, no source form found). Pragmas opt_dead_assignments off 1337, peephole off 730. s->end.y store moved after the scale line: 763. Frame facts: original spill slots are bound [sp,#4], case-5 temp [sp,#8], height [sp,#0xc], terrain [sp,#0x10], scale hi word [sp,#0x14]; compiled has no height slot (r6) and bound/temp swapped, so the 4-byte frame difference is exactly the missing height spill, caused by r6 being held by the cell address across func_021B7D50.
 * note: final push 2026-10-05 G10L4 (33 compiles, 3 rounds): instruction-level residue 53 -> 35 diff ops of 472 (byte count reads 1158 only because the missing 4-byte height spill shifts the pool and jump table; code is 1524 vs 1528). New real forms: inline vset(Vec*,x,y,z) for point=s->end (loads z,y,x then stores, replaces ldm/stm); inline vset16 for s->dir=delta; one struct type LocalCell (s16 c) for both s->cell and the local with struct assignments cell=s->cell and s->cell=cell (copy-back loads become ldrh as original); named temp top=s->start.y+0xa000 before the end.y store (fixes the +B4 schedule; reusing y breaks case 5 colours). Remaining: (A) original holds &cell in r6 across func_021B7D50 (add r6,sp,#0x1c hoisted into the copy block, adds r1,r6,#0 at the first func_021BB3C4 call), so height is spilled to [sp,#0xc] and the frame is sub #0x74 with no push r3; (B) bound/temp slots swapped ([sp,#4]/[sp,#8]). Tried for (A), all unchanged: u32/pointer/param-reuse holders, cp assigned at top/before copy/inside call argument, one-element array, inline copy helper, initialised declaration, memcpy (byte loop, worse), cast u16 buffer (worse), s16 height, per-function pragmas lifetimes/common_subs/dead_assignments/scheduling/peephole (no help). Only opt_propagation off with cp=&cell; *cp=s->cell makes the address live in a register shared with the stores, but it breaks the rest of the function (1357 B) and the original stores use a different base (r5), so it is not the source form.
 * note: pass 2 2026-10-06 P2L57 (3 rounds, about 58 compiles incl. probes): declaration order `int n,terrain,height,y,valid,i,bound,...` (y before bound) fixes the bound/y spill-slot swap ([sp,#4]/[sp,#8]); nd 35 -> 32 diff ops, bytes still 1158 (the shift from the missing height spill). Spill slots follow declaration order of the spilled locals (orig: terrain 0x10, height 0xc, y 0x8, bound 0x4). Twin found: ov021 func_021B7CD8 (`Rect4 old = *r; ... f(&old)`): a struct assignment creates an address temp that is held across calls (add r7,sp,#0 in the copy). Probes show the same form holds &cell in this function's case 0 when at most 3 fx-multiply rounding sequences ((s64)a*b+0x800)>>12 come before the copy; with 4 or more (the original has 6) the temp is dropped and rebuilt at each use, even for two uses in one block. Plain int math, plain calls, 64-bit mul or shift without the +0x800 add, and the same sequences after the copy do not drop it. Tried without effect: block-scoped `LocalCell cell = s->cell` with length, height declared first/last, u8 valid, ternary clamp (1169), block-scoped top/scale, opt_loop_invariants off, valid=0 at case top (1164), macro fxmul and 0x800LL (probes), s64 scale copy (probe). Next: the source form of the six fx multiplies that leaves the copy's address temp alive (e.g. a helper or vector routine the original used for start/end).
 * note: pass 3 2026-10-06 P3L21 (21 compiles, 2 rounds): MATCH in --lang c99 and --lang c. Two source changes: (1) `u16 bound;` declared as its own u16 local and `bound=height+cell.c;` (no cast) makes the allocator spill height to [sp,#0xc] and keep &cell in r6 across func_021B7D50, as the original (closes the 4-byte frame shift); (2) case 5 pos and look sums each in their own braced block with `int y,z;` gives z r6 / y r7 as the original. Left: two ov021 callees without a witness (func_021BB3D0 and func_021BB388, both 8-byte thumb leaves in ov021: `ldr r0,[r0]; ldr r3,=func; bx r3` tail calls to 021B7D68 and to 021B79F0 with r1=1); the integrator seeds or files them.
 * symbols:
 *   func_0219E764 0x0219E764 thumb ov021
 *   func_0207CDB8 0x0207CDB8 arm
 *   func_021B8028 0x021B8028 thumb ov021
 *   func_021BB480 0x021BB480 thumb ov021
 *   func_021B7A84 0x021B7A84 thumb ov021
 *   func_021B7D50 0x021B7D50 thumb ov021
 *   func_021BB3C4 0x021BB3C4 thumb ov021
 *   func_021AB0F8 0x021AB0F8 thumb ov021
 *   func_021B7D38 0x021B7D38 thumb ov021
 *   func_0207CA00 0x0207CA00 arm
 *   func_0207CBD0 0x0207CBD0 arm
 *   func_0207CCA4 0x0207CCA4 arm
 *   func_0207C768 0x0207C768 arm
 *   func_0207D14C 0x0207D14C arm
 *   func_0218F0A8 0x0218F0A8 thumb ov021
 *   func_0218F0E8 0x0218F0E8 thumb ov021
 *   func_0218EC54 0x0218EC54 thumb ov021
 *   func_0218E13C 0x0218E13C thumb ov021
 *   func_0218E124 0x0218E124 thumb ov021
 *   func_0218ECE4 0x0218ECE4 thumb ov021
 *   func_0218ECB4 0x0218ECB4 thumb ov021
 *   func_021BB3D0 0x021BB3D0 thumb ov021
 *   func_0218EC5C 0x0218EC5C thumb ov021
 *   func_0218EC90 0x0218EC90 thumb ov021
 *   func_0218ECF4 0x0218ECF4 thumb ov021
 *   func_020061E4 0x020061E4 thumb
 *   func_0216D568 0x0216D568 thumb ov010
 *   func_021AC528 0x021AC528 thumb ov021
 *   func_021A3044 0x021A3044 thumb ov021
 *   func_0216D89C 0x0216D89C thumb ov010
 *   func_02006148 0x02006148 thumb
 *   func_020061F8 0x020061F8 thumb
 *   func_021A36B0 0x021A36B0 thumb ov021
 *   func_021A36D4 0x021A36D4 thumb ov021
 *   func_021BB260 0x021BB260 thumb ov021
 *   func_021BB388 0x021BB388 thumb ov021
 *   func_0219E2C0 0x0219E2C0 thumb ov021
 *   func_0216D570 0x0216D570 thumb ov010
 *   func_0216DB4C 0x0216DB4C thumb ov010
 *   func_0216DC98 0x0216DC98 thumb ov010
 *   func_0216DAE0 0x0216DAE0 thumb ov010
 *   func_0216DB04 0x0216DB04 thumb ov010
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
#include "../../ov021/fldmmdl_rail_types.h"
#include "../rail_slipdown_types.h"

typedef long long s64;

extern int func_0219E764(struct Mmdl *mmdl, SlipdownDir *out);
extern void func_0207CDB8(SlipdownDir *in, SlipdownDir *out);
extern void func_021B8028(struct RailWork *railWork, VecFx32 *outPos);
extern struct RailManager *func_021BB480(struct FieldNogridMapper *mapper);
extern int func_021B7A84(struct RailManager *railMan, const VecFx32 *start, const VecFx32 *end, RailLocation *outLocation, VecFx32 *outPos);
extern int func_021B7D50(struct RailManager *railMan, RailLocation *location);
extern u32 func_021BB3C4(struct FieldNogridMapper *mapper, RailLocation *location);
extern u16 func_021AB0F8(u32 attr);
extern void func_021B7D38(struct RailManager *railMan, RailLocation *location, VecFx32 *outPos);
extern void func_0207CA00(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern int func_0207CBD0(const VecFx32 *v);
extern void func_0207CCA4(VecFx32 *in, VecFx32 *out);
extern u32 func_0207C768(u32 a, u32 b);
extern int func_0207D14C(int value, int *out);
extern void func_0218F0A8(struct FieldCamera *camera);
extern u32 func_0218F0E8(struct FieldCamera *camera);
extern void func_0218EC54(struct FieldCamera *camera);
extern void func_0218E13C(struct FieldCamera *camera, u32 mode);
extern void func_0218E124(struct FieldCamera *camera, u32 mode);
extern void func_0218ECE4(struct FieldCamera *camera, VecFx32 *outEye);
extern void func_0218ECB4(struct FieldCamera *camera, VecFx32 *outTarget);
extern void func_021BB3D0(struct FieldNogridMapper *mapper, RailLocation *location);
extern u32 func_0218EC5C(struct FieldCamera *camera);
extern void func_0218EC90(struct FieldCamera *camera, VecFx32 *target);
extern void func_0218ECF4(struct FieldCamera *camera, VecFx32 *eye);
extern void func_020061E4(u32 seId);
extern void *func_0216D568(struct Mmdl *mmdl, u32 bits);
extern void func_021AC528(struct Mmdl *mmdl, struct FieldEffectSys *effectSys);
extern void func_021A3044(struct FieldPlayer *player, VecFx32 *pos);
extern void func_0216D89C(struct Mmdl *mmdl, VecFx32 *pos);
extern int func_02006148(u32 seId);
extern void func_020061F8(int seSlot);
extern void func_021A36B0(struct FieldPlayer *player, RailLocation *outLocation);
extern void func_021A36D4(struct FieldPlayer *player, VecFx32 *outPos);
extern void func_021BB260(struct FieldNogridMapper *mapper, int active);
extern int func_021BB388(struct FieldNogridMapper *mapper);
extern void func_0219E2C0(struct Mmdl *mmdl, RailLocation *location);
extern char *func_0216D570(struct Mmdl *mmdl, u32 bits);
extern int func_0216DB4C(struct Mmdl *mmdl, int value);
extern int func_0216DC98(struct Mmdl *mmdl, int value);
extern void func_0216DAE0(struct Mmdl *mmdl, unsigned int value);
extern char *func_0216DB04(struct Mmdl *mmdl);
/* Fixed-point multiply with rounding (12 fraction bits). */
static inline int fxmul(int a,int b) {return (int)(((s64)a*b+2048)>>12);}
static inline void setDir16(SlipdownDir *d,int x,int y,int z){d->x=x;d->y=y;d->z=z;}
static inline void setVec(VecFx32 *d,int x,int y,int z){d->x=x;d->y=y;d->z=z;}
/*
 * Task of RAIL_SLIPDOWN_Create. Finds the landing place below the model,
 * then slides the model (and the camera with it) from start to end in steps.
 */
void func_021F377C(void *tcb, RailSlipdown *slipdown)
{
    int stepFixed;
    struct RailManager *railMan;
    int widthLimit, slideY, valid, i;
    u16 bound;
    int scale, top, slideZ;
    VecFx32 origin, slope, point, eye, target, finalPos;
    SlipdownDir facing;
    RailLocation cell;
    int length;
    switch (slipdown->state) {
    case SLIPDOWN_STATE_FIND_LANDING:
        func_0219E764(slipdown->mmdl, &facing);
        facing.y = 0;
        func_0207CDB8(&facing, &facing);
        func_021B8028(slipdown->railWork, &origin);
        slipdown->start.x = origin.x + fxmul(facing.x, 0x10000);
        slipdown->start.y = origin.y + fxmul(facing.y, 0x10000);
        slipdown->start.z = origin.z + fxmul(facing.z, 0x10000);
        top = slipdown->start.y + 0xa000;
        slipdown->end.y = -0xa000;
        scale = fxmul(top, 0x127b);
        slipdown->end.x = slipdown->start.x + fxmul(facing.x, scale);
        slipdown->end.z = slipdown->start.z + fxmul(facing.z, scale);
        railMan = func_021BB480(slipdown->nogridMapper);
        if (func_021B7A84(railMan, &slipdown->start, &slipdown->end, &slipdown->landing, &slipdown->end) == 0) {
            slipdown->state = SLIPDOWN_STATE_DONE;
            return;
        }
        cell = slipdown->landing;
        widthLimit = func_021B7D50(railMan, &slipdown->landing);
        valid = 0;
        if (!(func_021AB0F8(func_021BB3C4(slipdown->nogridMapper, &cell)) & 1)) valid = 1;
        cell.widthGrid += 2;
        if (cell.widthGrid > widthLimit) cell.widthGrid = widthLimit;
        bound = widthLimit + cell.widthGrid;
        for (i = 0; i < bound; i++) {
            cell.widthGrid--;
            if (func_021AB0F8(func_021BB3C4(slipdown->nogridMapper, &cell)) & 1) break;
            slipdown->landing = cell;
            valid = 1;
        }
        if (!valid) {
            slipdown->state = SLIPDOWN_STATE_DONE;
            return;
        }
        func_021B7D38(railMan, &slipdown->landing, &slipdown->end);
        func_0207CA00(&slipdown->end, &slipdown->start, &slope);
        length = func_0207CBD0(&slope);
        func_0207CCA4(&slope, &slope);
        setDir16(&slipdown->dir, slope.x, slope.y, slope.z);
        length = func_0207C768(length, 0x8000);
        if (func_0207D14C(length, &length) == 0) slipdown->count = length>>12;
        else slipdown->count = (length>>12) + 1;
        slipdown->step = 0;
        if (slipdown->player != 0) {
            func_0218F0A8(slipdown->camera);
            slipdown->state = SLIPDOWN_STATE_WAIT_CAMERA;
        } else slipdown->state = SLIPDOWN_STATE_START_SLIDE;
        break;
    case SLIPDOWN_STATE_WAIT_CAMERA:
        if (func_0218F0E8(slipdown->camera) != 0) break;
        func_0218EC54(slipdown->camera);
        func_0218E13C(slipdown->camera, 2);
        func_0218ECE4(slipdown->camera, &slipdown->eyeStart);
        func_0218ECB4(slipdown->camera, &slipdown->targetStart);
        func_021BB3D0(slipdown->nogridMapper, &slipdown->landing);
        if (func_0218EC5C(slipdown->camera) != 0) {
            func_0218EC90(slipdown->camera, &slipdown->end);
            func_0218EC54(slipdown->camera);
        }
        func_0218E13C(slipdown->camera, 2);
        func_0218ECE4(slipdown->camera, &slipdown->eyeDelta);
        func_0218ECB4(slipdown->camera, &slipdown->targetDelta);
        func_0207CA00(&slipdown->eyeDelta, &slipdown->eyeStart, &slipdown->eyeDelta);
        func_0207CA00(&slipdown->targetDelta, &slipdown->targetStart, &slipdown->targetDelta);
        func_021BB260(slipdown->nogridMapper, 0);
        func_0218E124(slipdown->camera, 2);
        func_0218EC54(slipdown->camera);
        func_0218EC90(slipdown->camera, &slipdown->targetStart);
        func_0218ECF4(slipdown->camera, &slipdown->eyeStart);
        slipdown->state = SLIPDOWN_STATE_START_SLIDE;
        break;
    case SLIPDOWN_STATE_START_SLIDE:
        func_020061E4(0x6ed);
        slipdown->state = SLIPDOWN_STATE_SLIDE;
        func_0216D568(slipdown->mmdl, 0x8000);
    case SLIPDOWN_STATE_SLIDE:
        slipdown->step++;
        if ((u32) slipdown->step >= (u32) slipdown->count) {
            setVec(&point, slipdown->end.x, slipdown->end.y, slipdown->end.z);
            slipdown->state = SLIPDOWN_STATE_FINISH;
        } else {
            if (slipdown->step>0) stepFixed = (int)(0.5f + (float)(slipdown->step<<12));
            else stepFixed = (int)((float)(slipdown->step<<12)-0.5f);
            scale = fxmul(stepFixed, 0x8000);
            slideZ = slipdown->start.z + fxmul(slipdown->dir.z, scale);
            slideY = slipdown->start.y + fxmul(slipdown->dir.y, scale);
            point.x = slipdown->start.x + fxmul(slipdown->dir.x, scale);
            point.y = slideY;
            point.z = slideZ;
            if (slipdown->step % 2 == 0) func_021AC528(slipdown->mmdl, slipdown->effectSys);
        }
        if (slipdown->player != 0) func_021A3044(slipdown->player, &point);
        else func_0216D89C(slipdown->mmdl, &point);
        if (slipdown->player == 0) break;
        {
            int y, z;
            z = slipdown->eyeStart.z + func_0207C768(fxmul(slipdown->eyeDelta.z, slipdown->step<<12), slipdown->count<<12);
            y = slipdown->eyeStart.y + func_0207C768(fxmul(slipdown->eyeDelta.y, slipdown->step<<12), slipdown->count<<12);
            eye.x = slipdown->eyeStart.x + func_0207C768(fxmul(slipdown->eyeDelta.x, slipdown->step<<12), slipdown->count<<12);
            eye.y = y;
            eye.z = z;
        }
        {
            int y, z;
            z = slipdown->targetStart.z + func_0207C768(fxmul(slipdown->targetDelta.z, slipdown->step<<12), slipdown->count<<12);
            y = slipdown->targetStart.y + func_0207C768(fxmul(slipdown->targetDelta.y, slipdown->step<<12), slipdown->count<<12);
            target.x = slipdown->targetStart.x + func_0207C768(fxmul(slipdown->targetDelta.x, slipdown->step<<12), slipdown->count<<12);
            target.y = y;
            target.z = z;
        }
        func_0218EC90(slipdown->camera, &target);
        func_0218ECF4(slipdown->camera, &eye);
        break;
    case SLIPDOWN_STATE_FINISH:
        func_020061F8(func_02006148(0x6ed));
        if (slipdown->player != 0) {
            func_021A36B0(slipdown->player, &slipdown->landing);
            func_021A36D4(slipdown->player, &finalPos);
            func_021A3044(slipdown->player, &finalPos);
            func_021BB260(slipdown->nogridMapper, 1);
            func_021BB388(slipdown->nogridMapper);
        } else func_0219E2C0(slipdown->mmdl, &slipdown->landing);
        func_0216D570(slipdown->mmdl, 0x8000);
        func_0216DB4C(slipdown->mmdl, 0);
        func_0216DC98(slipdown->mmdl, 0);
        func_0216DAE0(slipdown->mmdl, 1);
        func_0216DB04(slipdown->mmdl);
        slipdown->state = SLIPDOWN_STATE_DONE;
        break;
    case 2:
    case 3:
    case 6:
    case 7:
    case SLIPDOWN_STATE_DONE:
        break;
    }
}
