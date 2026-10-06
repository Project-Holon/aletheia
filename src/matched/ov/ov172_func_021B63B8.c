/*
 * function: func_021B63B8
 * address: 0x021B63B8
 * packet: pkt_ov172_021B63B8
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020351F8 0x020351F8 arm
 *   func_02085D3C 0x02085D3C arm
 *   func_021B6424 0x021B6424 arm ov172
 *   func_021B642C 0x021B642C arm ov172
 *   func_021B6434 0x021B6434 arm ov172
 *   func_021B643C 0x021B643C arm ov172
 *   func_021B6444 0x021B6444 arm ov172
 *   func_021B6868 0x021B6868 thumb ov172
 *   func_021B65C4 0x021B65C4 thumb ov172
 *   func_021B67BC 0x021B67BC thumb ov172
 *   func_02034FB8 0x02034FB8 arm
 *   func_020307B0 0x020307B0 arm
 *   g_021C88E0 0x021C88E0 data a4
 */
typedef unsigned int   u32;
extern void func_020351F8(u32 a, u32 b);
extern int func_02085D3C(void);
extern void func_021B6424(void);
extern void func_021B642C(void);
extern void func_021B6434(void);
extern void func_021B643C(int);
extern void func_021B6444(void);
extern void func_021B6868(char *);
extern void func_021B65C4(void *);
extern void func_021B67BC(char *);
extern void func_02034FB8(u32 v);
extern u32 func_020307B0(void *p);
extern void *g_021C88E0;
void func_021B63B8(char *p)
{
    func_020351F8(0, 0);
    if (func_02085D3C() != 0) func_021B6424();
    if (func_02085D3C() != 0) func_021B642C();
    func_021B6868(p);
    if (func_02085D3C() == 1) func_021B6434();
    func_021B643C(1);
    if (func_02085D3C() == 1) func_021B6444();
    func_021B65C4(p);
    func_021B67BC(p);
    func_02034FB8(0x40);
    func_020307B0(p);
    g_021C88E0 = 0;
}
