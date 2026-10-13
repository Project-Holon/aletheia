/*
 * function: func_0202F940
 * address:  0x0202F940
 * packet:   pkt_0202F7C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * EXACT* -- the inferred extent (184 bytes) runs 4 bytes past this
 * function's own 180, over the unlabelled 4-byte leaf at 0x0202F9F4
 * (`movs r0, #1; bx lr`, i.e. `return 1;`), which saves no lr and so gets no
 * label from disasm.py -- docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md.  That leaf is worth seeding
 * into layout/function_starts.txt by the integrator; it is not ours to edit.
 * The follower is also not covered by the manifest entry below, and no `tu`
 * range may span it.
 *
 *
 *
 * symbols:
 *   func_0207DFB4    0x0207DFB4  arm
 *   func_0207E24C    0x0207E24C  arm
 *   func_02082A48    0x02082A48  arm
 *   BMP_CreateFromVram    0x02043754  arm
 *   func_0201D7EC    0x0201D7EC  thumb
 *   func_02045B38    0x02045B38  arm
 *   func_02045EC0    0x02045EC0  arm
 *   func_0201C7D0    0x0201C7D0  thumb
 *   func_02045808    0x02045808  arm
 *   func_02045C04    0x02045C04  arm
 *   func_0201D83C    0x0201D83C  thumb
 *   func_020437AC    0x020437AC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

extern void *func_0207DFB4(void);
extern u32  func_0207E24C(void);
extern void func_02082A48(u32 v, u32 dst, u32 n);
typedef signed short   s16;
struct Bmp;
struct GfFont;
struct MsgBank;
struct Obj020437AC;
struct Rec;
struct U16Vec;
extern struct Bmp *BMP_CreateFromVram(void *pixels, u32 width, u32 height, u32 depth, u16 heap);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void func_020437AC(struct Obj020437AC *p);

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
    o1 = (u32)BMP_CreateFromVram((void *)(func_0207E24C() + 0x400), 0x1e, 0x10, 0x20, 7);
    o2 = (u32)func_0201D7EC(0x17, 0, 0, 0, 7);
    o3 = (u32)func_02045B38(0, 2, 2, 7);
    h = (u32)func_02045EC0((struct MsgBank *)o3, a0);
    func_0201C7D0((void *)o1, 0, 0, (void *)h, (void *)o2, 0x1167);
    func_02045808((struct U16Vec *)h);
    func_02045C04((struct Rec *)o3);
    func_0201D83C((void *)o2);
    func_020437AC((struct Obj020437AC *)o1);
}
