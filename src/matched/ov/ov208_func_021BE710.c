/*
 * function: func_021BE710
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
 *   func_0204047C 0x0204047C arm
 *   func_021BE868 0x021BE868 thumb ov208
 *   func_021BE920 0x021BE920 thumb ov208
 *   func_021BE864 0x021BE864 thumb ov208
 *   func_020056A0 0x020056A0 thumb
 *   func_0201C440 0x0201C440 thumb
 *   d_021C8DFC 0x021C8DFC data a1
 */
typedef unsigned short u16;
struct Ov208Icon { u16 heap,pad2; unsigned f4,f8; int fc; unsigned pad10[2],f18,f1c,f20,f24,f28,f2c,f30; };
extern const char d_021C8DFC[];
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void func_02040618(unsigned,unsigned,unsigned);
extern void func_0204047C(int,u16);
extern void func_021BE868(struct Ov208Icon *);
extern void func_021BE920(struct Ov208Icon *);
extern void func_021BE864(void *);
extern void *func_020056A0(unsigned,unsigned,unsigned);
extern unsigned func_0201C440(void *);
struct Ov208Icon *func_021BE710(u16 heap,unsigned arg)
{
    struct Ov208Icon *p=func_02030734(heap,0x34,1,d_021C8DFC,120);
    p->heap=heap;p->f4=arg;p->f8=0;p->fc=5;
    func_02040618(5,3,24);
    func_0204047C(5,0);
    func_021BE868(p);
    func_021BE920(p);
    p->f28=(unsigned)func_020056A0((unsigned)func_021BE864,(unsigned)p,1);
    p->f2c=func_0201C440((void *)(unsigned)p->heap);
    p->f30=0;
    return p;
}
