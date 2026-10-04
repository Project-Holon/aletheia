/*
 * function: func_021BA290
 * address: 0x021BA290
 * packet: pkt_ov218_021BA290
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: ABF0's legacy void return forwards AC18, whose matched full body returns its slot index; caller stores r0. 49238 visibly receives archive r0, preserved despite legacy void prototype.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned short u16;

extern void *func_020490F4(unsigned int id, u16 heap);
typedef signed int     s32;
typedef unsigned int   u32;
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern int func_0204ABF0(unsigned, unsigned, unsigned, unsigned, unsigned short);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
void func_021BA290(char *ctx)
{
    unsigned short heap = *(unsigned short *)ctx;
    void *archive;
    *(int *)(ctx + 0x2d0) = -1;
    *(int *)(ctx + 0x2d4) = -1;
    *(int *)(ctx + 0x2d8) = -1;
    archive = func_020490F4(193, heap);
    *(int *)(ctx + 0x2d0) = func_0204A6C8((void *)((unsigned)archive), 10, 0, 2, heap);
    *(int *)(ctx + 0x2d4) = func_0204ABF0((unsigned)archive, 11, 2, 96, heap);
    *(int *)(ctx + 0x2d8) = func_0204AF28((void *)((unsigned)archive), 9, 8, heap);
    func_02049238(archive);
}
