/*
 * function: ZUKAN_DETAIL_HEADBAR_Create
 * address: 0x021BE710
 * packet: pkt_ov208_021BE710
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02040618 0x02040618 arm
 *   BG_SYS_SetVisibleLayer 0x0204047C arm
 *   ZUKAN_DETAIL_HEADBAR_CreateWindows 0x021BE868 thumb ov208
 *   func_021BE920 0x021BE920 thumb ov208
 *   func_021BE864 0x021BE864 thumb ov208
 *   func_020056A0 0x020056A0 thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   d_021C8DFC 0x021C8DFC data a1
 */
typedef unsigned short u16;
struct Ov208Icon { u16 heap,pad2; unsigned f4,f8; int fc; unsigned pad10[2],f18,f1c,f20,f24,f28,f2c,f30; };
extern const char d_021C8DFC[];
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void func_02040618(unsigned,unsigned,unsigned);
extern void BG_SYS_SetVisibleLayer(int,u16);
struct Ov208Gfx;
extern void ZUKAN_DETAIL_HEADBAR_CreateWindows(struct Ov208Gfx *g);
extern void func_021BE920(struct Ov208Icon *);
extern void func_021BE864(void *);
extern void *func_020056A0(unsigned,unsigned,unsigned);
extern unsigned PRINTSYS_QUE_Create(void *);
struct Ov208Icon *ZUKAN_DETAIL_HEADBAR_Create(u16 heap,unsigned arg)
{
    struct Ov208Icon *p=func_02030734(heap,0x34,1,d_021C8DFC,120);
    p->heap=heap;p->f4=arg;p->f8=0;p->fc=5;
    func_02040618(5,3,24);
    BG_SYS_SetVisibleLayer(5,0);
    ZUKAN_DETAIL_HEADBAR_CreateWindows((struct Ov208Gfx *)p);
    func_021BE920(p);
    p->f28=(unsigned)func_020056A0((unsigned)func_021BE864,(unsigned)p,1);
    p->f2c=PRINTSYS_QUE_Create((void *)(unsigned)p->heap);
    p->f30=0;
    return p;
}
