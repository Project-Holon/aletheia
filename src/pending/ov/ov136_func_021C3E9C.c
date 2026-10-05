/*
 * function: func_021C3E9C
 * address: 0x021C3E9C
 * packet: pkt_ov136_021C3E9C
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * 2026-10-05 (wD4 lane16): original stores the next state through one shared `str r0,[r5]` (arms do `movs r0,#2; b end`), and the v==4 / v==0xFFFF test ends with a `b` to the next instruction. Tried `if (v==4||v==0xFFFF){*state=2;break;}*state=3;`, inverted nested ifs, goto s2/s3 and an empty then-arm: all 248 bytes (4 short), so the extra branch is not reproduced. Case 2 r1 load untouched.
 * note: 2026-10-04 Residue: 12 bytes plus the shift they cause. (1) Original compiles the v==4 || v==0xFFFF test as 'beq L2; ldr pool; cmp; bne L3; b L2' with a branch to the next instruction; ours (else-if form kept here) emits 'bne X; b L2; X:' and the || and switch forms drop the extra b (2 bytes short). (2) Case 2: original loads ctx->10 into r1 ('ldr r1,[r4,#0x10]; ldrh r0,[r1]'), ours uses r0. Tried: ||, ternary, switch (several layouts), nested if, u32/int/u16 v, pointer locals. Case 4 matches with a local h = ctx->8 read after q.
 *   2026-10-04 (D2): goto form (if (v==4) goto s2; if (v==0xFFFF) goto s2; else goto s3; s2/s3 blocks after) gives the
 *   original beq L2 / ldr / cmp / bne L3 order but drops the trailing b-to-next, so the function is 2 bytes short.
 *   Local q/w pointer for case 2 did not move the r1 load. Both residues stay open.
 * 2026-10-05 (wD5 lane16): the extra `b` to the next instruction is closed: case 1 is
 *   `if (v != 4) { if (v == 0xFFFF) *state = 2; else goto s3; } else *state = 2; break; s3: *state = 3;`
 *   (the inner store 2 is cross-jumped onto the outer one and leaves the `b`). 252 bytes, only the case 2
 *   residue is left: original `ldr r1,[r4,#0x10]; ldrh r0,[r1]`, ours uses r0. Tried for it: function-scope v,
 *   function-scope pointer p shared with case 1, `r = 0` default then set 1, ternary with comma calls, the value read
 *   into `ret` (r0 holder), one pointer local shared with the case 4 strh base (r1 there), the case 2 body as a static
 *   inline `Finish(msg, ptr)` helper. None move it.
 * 2026-10-05 (wD6 lane12): still DIFF, 2 bytes (case 2 `ldr r1,[r4,#0x10]; ldrh r0,[r1]`, ours r0/r0). For r1 the
 *   pointer must interfere with a value in r0 there; nothing in our case 2 is live in r0 (ret is dead). Tried: the
 *   *(msg+2) store written in each arm (rule 2), an inner switch on the halfword with case 4 / default, the
 *   halfword read as `*(u16 *)*(u32 *)(ctx + 0x10)`, *msg in a local returned at the end (wrong logic, moves *msg to
 *   r5 only). None move the pointer to r1.
 * symbols:
 *   func_02031330 0x02031330 arm
 *   func_02031348 0x02031348 arm
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_0202411C 0x0202411C thumb
 *   func_02024134 0x02024134 thumb
 *   func_02024124 0x02024124 thumb
 *   func_020240FC 0x020240FC thumb
 *   func_02008C58 0x02008C58 thumb
 *   func_02008DF0 0x02008DF0 thumb
 *   func_021C414C 0x021C414C thumb ov136
 *   func_021C3FC8 0x021C3FC8 thumb ov136
 *   ov136_id 0x0000006E data
 *   D_021C7750 0x021C7750 data
 *   D_021C775C 0x021C775C data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_02031330(void *p);
extern void func_02031348(void *h, u32 id, void *a, void *b);
extern int func_02034AC4(int handle);
extern void func_02034A5C(int handle);
extern int func_0202411C(void *a);
extern void func_02024134(void *a, void *b);
extern u16 func_02024124(void);
extern void func_020240FC(void *a);
extern void *func_02008C58(void *sys);
extern u32 func_02008DF0(void *obj, int i);
extern void func_021C414C(void *a);
extern void func_021C3FC8(void *a, void *b);
extern u8 ov136_id[];
extern u8 D_021C7750[];
extern u8 D_021C775C[];
int func_021C3E9C(int unused, u32 *state, u16 *msg, u8 *ctx)
{
    u32 ret = func_02031330(*(void **)(ctx + 0x1C));
    switch (*state) {
    case 0:
        **(u16 **)(ctx + 0x10) = *msg;
        func_02031348(*(void **)(ctx + 0x1C), (u32)-1, D_021C7750, *(void **)(ctx + 0x10));
        *state = 1;
        break;
    case 1: {
        u16 v;
        if (ret == 1)
            break;
        v = **(u16 **)(ctx + 0x10);
        if (v != 4) {
            if (v == 0xFFFF)
                *state = 2;
            else
                goto s3;
        } else
            *state = 2;
        break;
    s3:
        *state = 3;

        break;
    }
    case 2:
        if (*msg == 1) {
            u32 r;
            if (**(u16 **)(ctx + 0x10) == 4) {
                func_021C414C(*(void **)(msg + 10));
                func_02008DF0(func_02008C58(*(void **)(msg + 8)), 0x1D);
                r = 1;
            } else {
                r = 0;
            }
            *(u32 *)(msg + 2) = r;
        }
        return 1;
    case 3:
        func_02034AC4((int)ov136_id);
        func_021C3FC8(ctx, msg);
        func_02031348(*(void **)(ctx + 0x1C), (u32)-1, D_021C775C, *(void **)(ctx + 8));
        *state = 4;
        break;
    case 4:
        if (ret == 1)
            break;
        if (func_0202411C(*(void **)(ctx + 8)) == 0) {
            u8 *q = *(u8 **)(ctx + 0x10);
            void *h = *(void **)(ctx + 8);
            if (q[2] < 3)
                func_02024134(h, q + 0x16 + q[2] * 8);
            else
                *(u16 *)(*(u8 **)(ctx + 0x10) + 0x32) = func_02024124();
        }
        func_020240FC(*(void **)(ctx + 8));
        func_02034A5C((int)ov136_id);
        *state = 0;
        break;
    }
    return 0;
}
