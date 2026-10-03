/*
 * function: func_021C38F4
 * address:  0x021C38F4
 * packet:   pkt_ov021_021C38F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Day-care offspring builder: runs every step of the 0x8C-byte work
 * record over the parent pair m and hands the result to func_021C4340.
 * Callee prototypes without a matched file are written from the call
 * site's argument registers.
 * symbols:
 *   func_021C3A00  0x021C3A00  thumb  ov021
 *   func_021C3A44  0x021C3A44  thumb  ov021
 *   func_021C3A7C  0x021C3A7C  thumb  ov021
 *   func_021C3A90  0x021C3A90  thumb  ov021
 *   func_021C3AAC  0x021C3AAC  thumb  ov021
 *   func_021C3ADC  0x021C3ADC  thumb  ov021
 *   func_021C3B0C  0x021C3B0C  thumb  ov021
 *   func_021C3B2C  0x021C3B2C  thumb  ov021
 *   func_021C3BCC  0x021C3BCC  thumb  ov021
 *   func_021C3BD4  0x021C3BD4  thumb  ov021
 *   func_021C3C04  0x021C3C04  thumb  ov021
 *   func_021C3C30  0x021C3C30  thumb  ov021
 *   func_021C3C78  0x021C3C78  thumb  ov021
 *   func_021C3C88  0x021C3C88  thumb  ov021
 *   func_021C3D1C  0x021C3D1C  thumb  ov021
 *   func_021C3DA8  0x021C3DA8  thumb  ov021
 *   func_021C3DE4  0x021C3DE4  thumb  ov021
 *   func_021C3E38  0x021C3E38  thumb  ov021
 *   func_021C3E64  0x021C3E64  thumb  ov021
 *   func_021C3F60  0x021C3F60  thumb  ov021
 *   func_021C3FC0  0x021C3FC0  thumb  ov021
 *   func_021C4018  0x021C4018  thumb  ov021
 *   func_021C4024  0x021C4024  thumb  ov021
 *   func_021C4030  0x021C4030  thumb  ov021
 *   func_021C4084  0x021C4084  thumb  ov021
 *   func_021C40F8  0x021C40F8  thumb  ov021
 *   func_021C4160  0x021C4160  thumb  ov021
 *   func_021C4238  0x021C4238  thumb  ov021
 *   func_021C42BC  0x021C42BC  thumb  ov021
 *   func_021C4340  0x021C4340  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { u32 w[0x23]; } S;

extern void func_021C3A00(u32 *m);
extern void func_021C3A44(u32 *m);
extern void func_021C3A7C(S *s);
extern void func_021C3A90(u32 *m, S *s);
extern void func_021C3AAC(u32 *m, S *s);
extern void func_021C3ADC(u32 *m, S *s);
extern void func_021C3B0C(u32 *m, S *s);
extern void func_021C3B2C(u32 *m, S *s);
extern void func_021C3BCC(u32 *m, S *s);
extern void func_021C3BD4(u32 *m, S *s);
extern void func_021C3C04(u32 *m, S *s);
extern void func_021C3C30(u32 *m, S *s);
extern void func_021C3C78(u32 *m, S *s);
extern void func_021C3C88(u32 *m, S *s);
extern void func_021C3D1C(u32 *m, S *s, u32 heap);
extern void func_021C3DA8(u32 *m, S *s);
extern void func_021C3DE4(u32 *m, u32 *s, u32 heap);
extern void func_021C3E38(S *s, u32 heap);
extern void func_021C3E64(u32 *m, S *s);
extern void func_021C3F60(u32 *m, S *s);
extern void func_021C3FC0(u32 *m, S *s);
extern void func_021C4018(void *b, S *s);
extern void func_021C4024(u32 *m, S *s);
extern void func_021C4030(u32 *m, S *s);
extern void func_021C4084(S *s);
extern void func_021C40F8(u32 *m, S *s, u32 heap);
extern void func_021C4160(u32 *m, S *s);
extern void func_021C4238(u32 *m, S *s, u32 heap);
extern void func_021C42BC(u32 *m, S *s);
extern void func_021C4340(void *mon, S *s, void *b, void *c, u16 heap);

void func_021C38F4(u16 heap, void *b, void *c, u32 m0, u32 m1, void *mon)
{
    S s;
    u32 m[2];

    m[0] = m0;
    m[1] = m1;
    func_021C3A00(m);
    func_021C3A44(m);
    func_021C3A7C(&s);
    func_021C3A90(m, &s);
    func_021C3AAC(m, &s);
    func_021C3ADC(m, &s);
    func_021C3B0C(m, &s);
    func_021C3B2C(m, &s);
    func_021C3BCC(m, &s);
    func_021C3BD4(m, &s);
    func_021C3C04(m, &s);
    func_021C3C30(m, &s);
    func_021C3C78(m, &s);
    func_021C3C88(m, &s);
    func_021C3D1C(m, &s, heap);
    func_021C3DA8(m, &s);
    func_021C3DE4(m, (u32 *)&s, heap);
    func_021C3E38(&s, heap);
    func_021C3E64(m, &s);
    func_021C3F60(m, &s);
    func_021C3FC0(m, &s);
    func_021C4018(b, &s);
    func_021C4024(m, &s);
    func_021C4030(m, &s);
    func_021C4084(&s);
    func_021C40F8(m, &s, heap);
    func_021C4160(m, &s);
    func_021C4238(m, &s, heap);
    func_021C42BC(m, &s);
    func_021C4340(mon, &s, b, c, heap);
}
