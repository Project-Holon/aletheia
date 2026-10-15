/*
 * function: ZUKAN_TOROKU_GRAPHIC_DeleteDisplay
 * address: 0x0220B3B8
 * packet: pkt_ov207_0220B3B8
 * region: ov207
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware accesses at 0x0220B3D6-0x0220B3EC.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   ZUKAN_TOROKU_GRAPHIC_DeleteActors 0x0220B52C thumb ov207
 *   ZUKAN_TOROKU_GRAPHIC_ExitBg 0x0220B4A8 thumb ov207
 *   func_0201DD68 0x0201DD68 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   func_020307B0 0x020307B0 arm
 */
struct Node;
extern void func_02030EAC(struct Node *n);
struct Bank;
extern void ZUKAN_TOROKU_GRAPHIC_DeleteActors(struct Bank **p);
extern void ZUKAN_TOROKU_GRAPHIC_ExitBg(void *);
extern void func_0201DD68(void);
extern void MI_CpuFill8(void *,int,int);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void ZUKAN_TOROKU_GRAPHIC_DeleteDisplay(unsigned *p)
{
    func_02030EAC((void *)p[3]);
    ZUKAN_TOROKU_GRAPHIC_DeleteActors((struct Bank **)(p+1));
    ZUKAN_TOROKU_GRAPHIC_ExitBg(p);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    MI_CpuFill8(p,0,16);
    func_020307B0(p);
}
