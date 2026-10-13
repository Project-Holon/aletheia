/*
 * function: func_021C5B00
 * address: 0x021C5B00
 * packet: pkt_ov208_021C5B00
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 (D4-11): EXACT. pose set with the goto form of sibling 021C595C;
 *   MDL(i) as one byte offset (p + 0xc + i*0x44) so MDL(1) folds to p+0x50.
 * symbols:
 *   MCSS_SetTaskSystem 0x02014CEC thumb
 *   ov208_func_021C569C 0x021C569C thumb ov208
 *   func_021C51C8 0x021C51C8 thumb ov208
 *   func_021C80AC 0x021C80AC thumb ov208
 *   MCSS_SetPosition 0x02015C48 thumb
 *   func_021C7534 0x021C7534 thumb ov208
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int fx32;
typedef struct { fx32 x; fx32 y; fx32 z; } Vec;
struct Ov208Mdl {
    u32 obj;
    u32 f4;
    u8 pos[0x3c];
};
extern void MCSS_SetTaskSystem(u8 *p, u32 value);
extern void ov208_func_021C569C(u16 *heap, u8 *p, int key, int a, int b, int pose, u16 idx);
extern void func_021C51C8(u32 st, int i, u8 *p);
extern void func_021C80AC(int a, int b, int c);
extern void MCSS_SetPosition(void *p, u32 *src);
extern void func_021C7534(u16 *heap, u8 *p, int key);
#define W(o) (*(u32 *)(p + (o)))
#define MDL(i) ((struct Ov208Mdl *)(p + 0xc + (i) * sizeof(struct Ov208Mdl)))
void func_021C5B00(u16 *heap, u8 *p, int key)
{
    Vec v;
    int a;
    int b;
    int pose;
    a = 0;
    MCSS_SetTaskSystem((u8 *)W(8), 0);
    if (MDL(0)->obj != 0) a = 4;
    b = 1;
    if (MDL(1)->obj != 0) b = 4;
    pose = 0;
    if (W(0x6B8) != 4) goto skip;
    if (*(u16 *)(p + 0x548) < 2) goto skip;
    pose = 1;
skip:
    ov208_func_021C569C(heap, p, key, a, b, pose, *(u16 *)(p + 0x54E));
    if (a != 4) func_021C51C8(MDL(0)->f4, 0, p);
    else {
        func_021C80AC((int)MDL(0), pose, (int)(&v));
        MCSS_SetPosition((void *)MDL(0)->obj, (u32 *)(&v));
    }
    if (b != 4) func_021C51C8(MDL(1)->f4, 1, p);
    else {
        func_021C80AC((int)MDL(1), pose, (int)(&v));
        MCSS_SetPosition((void *)MDL(1)->obj, (u32 *)(&v));
    }
    a = 2;
    if (MDL(2)->obj != 0) a = 4;
    b = 3;
    if (MDL(3)->obj != 0) b = 4;
    ov208_func_021C569C(heap, p, key, a, b, 2, *(u16 *)(p + 0x550));
    if (a != 4) func_021C51C8(MDL(2)->f4, 2, p);
    else {
        func_021C80AC((int)MDL(2), 2, (int)(&v));
        MCSS_SetPosition((void *)MDL(2)->obj, (u32 *)(&v));
    }
    if (b != 4) func_021C51C8(MDL(3)->f4, 3, p);
    else {
        func_021C80AC((int)MDL(3), 2, (int)(&v));
        MCSS_SetPosition((void *)MDL(3)->obj, (u32 *)(&v));
    }
    MCSS_SetTaskSystem((u8 *)W(8), W(0x120));
    if (W(0x6B8) == 0) {
        W(0x6C8) = 1;
        func_021C7534(heap, p, key);
    }
}
