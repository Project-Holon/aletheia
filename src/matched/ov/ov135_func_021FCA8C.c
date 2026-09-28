/*
 * function: func_021FCA8C
 * address:  0x021FCA8C
 * packet:   pkt_021FCA8C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020457B0  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045924  0x02045924  arm
 *   func_02017E1C  0x02017E1C  thumb
 *   func_021F91A0  0x021F91A0  thumb
 *   func_02045808  0x02045808  arm
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *win0;
    void *win1;
} Pane2;

extern void *func_020457B0(u32 size, u32 heap);
extern void *func_02045EC0(void *bank, u32 index);
extern void func_02045924(void *dst, const void *src);
extern u32 func_02017E1C(void *mon, u32 id, void *v);
extern int func_021F91A0(void *p, void *b, u32 c, u32 d, u32 e, u16 f, void *g);
extern void func_02045808(void *p);

void func_021FCA8C(void *bank, Pane2 *pane, void *name, void *mon, Pane2 *pane2, void *g)
{
    void *s0;
    void *s1;
    void *t0;
    void *t1;

    s0 = func_020457B0(0x22, 0x48);
    s1 = func_020457B0(0x22, 0x48);
    t0 = func_02045EC0(bank, 0x37);
    func_02045924(s0, name);
    t1 = func_02045EC0(bank, 0xC2);
    func_02017E1C(mon, 0x8D, s1);
    func_021F91A0(pane->win0, t0, 0, 0, 0, 0x3C40, g);
    func_021F91A0(pane->win1, s0, 0, 0, 0, 0x440, g);
    func_021F91A0(pane2->win0, t1, 0, 0, 0, 0x3C40, g);
    func_021F91A0(pane2->win1, s1, 1, 0, 0, 0x440, g);
    func_02045808(t0);
    func_02045808(s0);
    func_02045808(t1);
    func_02045808(s1);
}
