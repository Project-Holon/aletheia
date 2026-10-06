/*
 * file:     time_icon_p11.c
 * unit:     yes
 * function: func_0202F940, func_0202F9F4, func_0202F9F8
 * address:  0x0202F940
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0207DFB4    0x0207DFB4  arm
 *   func_0207E24C    0x0207E24C  arm
 *   func_02082A48    0x02082A48  arm
 *   func_02043754    0x02043754  arm
 *   func_0201D7EC    0x0201D7EC  thumb
 *   func_02045B38    0x02045B38  arm
 *   func_02045EC0    0x02045EC0  arm
 *   func_0201C7D0    0x0201C7D0  thumb
 *   func_02045808    0x02045808  arm
 *   func_02045C04    0x02045C04  arm
 *   func_0201D83C    0x0201D83C  thumb
 *   func_020437AC    0x020437AC  arm
 *   ov088_id       0x00000058  data  a1
 *   ov179_id       0x000000B3  data  a1
 *   d_021BD8E8     0x021BD8E8  data
 *   d_021B68D8     0x021B68D8  data  ov179
 *   d_021BD574     0x021BD574  data
 *   g_02146948     0x02146948  data
 *   g_02146948_arg 0x02146948  data
 *   func_020312CC  0x020312CC  arm
 */
struct Bmp;
struct GfFont;
struct MsgBank;
struct Obj020437AC;
struct Rec;
struct U16Vec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef int s32;

typedef signed short   s16;

struct State {
    u16 f00;
    u8  f02;
    u8  f03;
    u32 f04;
};

extern void *func_0207DFB4(void);
extern u32  func_0207E24C(void);
extern void func_02082A48(u32 v, u32 dst, u32 n);
extern struct Bmp *func_02043754(void *pixels, u32 width, u32 height, u32 depth, u16 heap);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void func_020437AC(struct Obj020437AC *p);
extern void func_020312CC(u32 ovl, u32 proc, u32 arg);
void func_0202F940(u32 a0);
int func_0202F9F4(void);
int func_0202F9F8(void *unused, u32 *state);
extern u8 ov088_id[];
extern u8 ov179_id[];
extern u8 d_021BD8E8[];
extern u8 d_021B68D8[];
extern u8 d_021BD574[];
extern struct State g_02146948;
extern u8 g_02146948_arg[];


/*
 * EXACT* -- the inferred extent (184 bytes) runs 4 bytes past this
 * function's own 180, over the unlabelled 4-byte leaf at 0x0202F9F4
 * (`movs r0, #1; bx lr`, i.e. `return 1;`), which saves no lr and so gets no
 * label from disasm.py -- docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md.  That leaf is worth seeding
 * into layout/function_starts.txt by the integrator; it is not ours to edit.
 * The follower is also not covered by the manifest entry below, and no `tu`
 * range may span it.
 */
void func_0202F940(u32 a0)
{
    u16 *p;
    s32 i;
    s32 j;
    u16 v;
    u32 o1;
    u32 o2;
    u32 o3;
    u32 h;

    p = (u16 *)func_0207DFB4();
    v = 0x20;
    for (j = 4; j < 0x14; j++) {
        for (i = 1; i < 0x1f; i++) {
            p[(j << 5) + i] = v;
            v = v + 1;
        }
    }
    func_02082A48(0x7777, func_0207E24C() + 0x400, 0x3C00);
    o1 = (u32)func_02043754((void *)(func_0207E24C() + 0x400), 0x1e, 0x10, 0x20, 7);
    o2 = (u32)func_0201D7EC(0x17, 0, 0, 0, 7);
    o3 = (u32)func_02045B38(0, 2, 2, 7);
    h = (u32)func_02045EC0((struct MsgBank *)o3, a0);
    func_0201C7D0((void *)o1, 0, 0, (void *)h, (void *)o2, 0x1167);
    func_02045808((struct U16Vec *)h);
    func_02045C04((struct Rec *)o3);
    func_0201D83C((void *)o2);
    func_020437AC((struct Obj020437AC *)o1);
}

int func_0202F9F4(void)
{
    return 1;
}


/*
 * note:     wave 17 (overlay_id class): EXACT. The pooled overlay-id sites
 *           ov088_id (88) and ov179_id (179) resolve as `overlay_id` (a
 *           layout overlay index, loaded by a pc-relative load of this
 *           function, reaching the id register of a known overlay loader),
 *           which was the last blocker.
 *
 * time_icon.c.  A five-state proc driver, the net_save.c shape of
 * src/pending/func_02010AC4.c: state 0 starts overlay 0x58's proc on
 * &g_02146948.f04, states 1 to 3 (re)start overlay 0xB3's proc on the
 * record, with state 2 bailing to 4 when f03 is set, and state 4 starts
 * overlay 0x58's second proc and resets to 0.
 *
 * Two pool words both name 0x02146948 (0x0202FA9C, the base of the field
 * stores, and 0x0202FAA8, the third call argument).  mwcc merges pool words
 * per symbol and CSEs the loaded address, so one symbol gives one word and
 * reuses r2 as the store base (184 -> 172 bytes, 98 out).  Two symbols at
 * the same address reproduce both words; g_02146948_arg is that second
 * name.  The state-2 test is written with the work in the `if` and the
 * bail-out after it (fall-through arm is the source order), so its
 * `*state = 4` block is the one state 3 branches back into.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F9F8.c
 *       --func func_0202F9F8 --addr 0x0202F9F8 --cc 1.1p1 --thumb
 */
int func_0202F9F8(void *unused, u32 *state)
{
    switch (*state) {
    case 0:
        func_020312CC((u32)ov088_id, (u32)d_021BD8E8, (u32)&g_02146948.f04);
        *state = 1;
        break;
    case 1:
        g_02146948.f04 = 1;
        g_02146948.f00 = 0;
        g_02146948.f02 = 1;
        g_02146948.f03 = 0;
        func_020312CC((u32)ov179_id, (u32)d_021B68D8, (u32)g_02146948_arg);
        *state = 2;
        break;
    case 2:
        if (g_02146948.f03 == 0) {
            g_02146948.f00 = 1;
            g_02146948.f03 = 0;
            func_020312CC((u32)ov179_id, (u32)d_021B68D8, (u32)g_02146948_arg);
            *state = 3;
            break;
        }
        *state = 4;
        break;
    case 3:
        g_02146948.f00 = 2;
        g_02146948.f03 = 0;
        func_020312CC((u32)ov179_id, (u32)d_021B68D8, (u32)g_02146948_arg);
        *state = 4;
        break;
    case 4:
        func_020312CC((u32)ov088_id, (u32)d_021BD574, 0);
        *state = 0;
        break;
    }
    return 0;
}
