/*
 * function: func_0216928C
 * address:  0x0216928C
 * packet:   pkt_ov010_0216928C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021693A0  0x021693A0  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   d_020A814C     0x020A814C  data   a4
 *   d_020A8144     0x020A8144  data   a4
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void func_021693A0(int a0);
extern void func_020307B0(void *p);
extern void (*d_020A814C)(u32);
extern void (*d_020A8144)(u32);

#define F(o) (*(u32 *)((char *)p + (o)))

void func_0216928C(void *p)
{
    func_021693A0((int)p);
    if (F(0x20) != 0) {
        d_020A814C(F(0x90));
        d_020A8144(F(0x8c));
    }
    func_020307B0((void *)F(0x88));
    func_020307B0((void *)F(0x84));
    func_020307B0((void *)F(0xd4));
    if (*(u16 *)((char *)p + 0xa4) != 0)
        func_020307B0((void *)F(0x9c));
    if (*(u16 *)((char *)p + 0xa6) != 0)
        func_020307B0((void *)F(0xa0));
    func_020307B0((void *)((u32)p));
}
