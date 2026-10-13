/*
 * function: POKE_TOOL_PushBoxMove
 * address:  0x020180FC
 * packet:   pkt_020180FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: the listing extent runs 10 bytes past the body to 0x02018196
 * because the follower there is unlabelled -- 0x02018196 is two bytes of
 * padding and then a 4-byte ARM `ldr r3, [pc]; bx r3` veneer at 0x02018198.
 * No byte differs; the compiler's 154 bytes are byte-identical.
 *
 * symbols:
 *   func_02017DBC  0x02017DBC  thumb
 *   func_02017E88  0x02017E88  thumb
 *   func_0201BD28  0x0201BD28  thumb
 *   POKE_TOOL_SetBoxValue  0x02017E64  thumb
 *   func_02017DE4  0x02017DE4  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sav;
extern u32 func_02017DBC(struct Sav *p);
extern u32 func_02017E88(void *p, u32 k, u32 x);
extern u32 func_0201BD28(u16 id, u32 field);
extern void POKE_TOOL_SetBoxValue(void *p, u32 k, u32 v);
extern u32 func_02017DE4(struct Sav *p, u32 f);

/* Three parallel 4-entry channel tables.  They are three separate locals, NOT
 * one 16-byte struct: as a struct mwcc folds the member offset into the store
 * (`add r1, sp, #8 / adds r1, r1, r2 / strh r0, [r1, #8]`, three instructions
 * per element) where three arrays let it hoist `add r7, sp, #0x10` out of the
 * loop and emit `lsls r1, r4, #1 / strh r0, [r7, r1]`.  Declaration order
 * a, b, c (later declarator at the lower stack address) is what puts them at
 * sp+0x10 / sp+0xc / sp+8.  The fourth entry of each table is filled from a
 * different source: a[3] the parameter, b[3] a lookup, c[3] zero. */
void POKE_TOOL_PushBoxMove(void *p, u16 v)
{
    u16 a[4];
    u8  b[4];
    u8  c[4];
    u32 h;
    int i;
    int j;

    h = func_02017DBC(p);

    for (i = 0; i < 3; i++) {
        a[i] = func_02017E88(p, i + 0x37, 0);
        b[i] = func_02017E88(p, i + 0x3b, 0);
        c[i] = func_02017E88(p, i + 0x3f, 0);
    }

    a[3] = v;
    b[3] = func_0201BD28(v, 5);
    c[3] = 0;

    for (j = 0; j < 4; j++) {
        POKE_TOOL_SetBoxValue(p, j + 0x36, a[j]);
        POKE_TOOL_SetBoxValue(p, j + 0x3a, b[j]);
        POKE_TOOL_SetBoxValue(p, j + 0x3e, c[j]);
    }

    func_02017DE4(p, h);
}
