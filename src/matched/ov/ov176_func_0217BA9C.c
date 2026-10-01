/*
 * function: func_0217BA9C
 * address: 0x0217BA9C
 * packet: pkt_ov176_0217BA9C
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_020351A0 0x020351A0 arm
 *   func_0217D174 0x0217D174 thumb ov176
 *   func_0217D224 0x0217D224 thumb ov176
 *   func_021E7DF0 0x021E7DF0 thumb ov177
 *   func_0217E058 0x0217E058 thumb ov176
 *   func_021E8A78 0x021E8A78 thumb ov177
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 */
extern void func_020307B0(void *);
extern void func_020351A0(int);
extern void func_0217D174(int *);
extern void func_0217D224(int *);
extern void func_021E7DF0(int);
extern void func_0217E058(int);
extern void func_021E8A78(int);
extern void func_0201D83C(int);
extern void func_02045C04(int);
extern void func_0201ED04(int);
void func_0217BA9C(int *p)
{
    func_020307B0((void *)p[12]);
    if (p[0x67] == 1) func_020351A0(8);
    func_0217D174(p);
    func_0217D224(p);
    func_021E7DF0(p[7]);
    func_0217E058(p[3]);
    func_021E8A78(p[0]);
    func_0201D83C(p[10]);
    func_02045C04(p[9]);
    func_02045C04(p[8]);
    func_0201ED04(p[11]);
    func_020307B0(p);
}
