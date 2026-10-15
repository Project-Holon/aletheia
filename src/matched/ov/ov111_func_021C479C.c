/*
 * function: func_021C479C
 * address:  0x021C479C
 * packet:   pkt_ov111_021C479C
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C4530  0x021C4530  thumb  ov111
 *   func_021C4754  0x021C4754  thumb  ov111
 *   func_021C5938  0x021C5938  thumb  ov111
 *   func_0204989C  0x0204989C  arm
 *   BG_SYS_ClearSlot  0x020414EC  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 kind;
} Info;

typedef struct {
    u16 heap;
    u8 pad2[0x28 - 2];
    Info *info;
    u8 pad2C[0x3034 - 0x2C];
    u32 f3034;
} Work;

extern int func_021C4530(int x);
extern void func_021C4754(Work *p, int kind);
extern void func_021C5938(void *p);
extern void func_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);
extern void BG_SYS_ClearSlot(u32 i);

void func_021C479C(Work *p)
{
    if (p->f3034 == 0) {
        func_0204989C(0x28, func_021C4530(p->info->kind), 6, 0, 0, 0, p->heap);
        BG_SYS_ClearSlot(7);
    } else {
        func_021C4754(p, p->info->kind);
        func_021C5938(p);
        BG_SYS_ClearSlot(7);
    }
}
