/*
 * function: func_021D4448
 * address: 0x021D4448
 * packet: pkt_ov175_021D4448
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DD008 0x021DD008 thumb ov175
 *   func_021E7DF0 0x021E7DF0 thumb ov177
 *   func_021E8A78 0x021E8A78 thumb ov177
 *   func_021E8628 0x021E8628 thumb ov177
 *   func_021D9EA0 0x021D9EA0 thumb ov175
 *   func_021D644C 0x021D644C thumb ov175
 *   func_021D639C 0x021D639C thumb ov175
 *   func_021D65C8 0x021D65C8 thumb ov175
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_021E5868 0x021E5868 thumb ov177
 *   func_021E54E0 0x021E54E0 thumb ov177
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov114_id 0x00000072 data
 *   ov067_id 0x00000043 data
 */
extern const char ov114_id[],ov067_id[];
extern void func_021DD008(char *,int);
extern void func_021E7DF0(int);
extern void func_021E8A78(int);
extern void func_021E8628(int);
extern void func_021D9EA0(int);
extern void func_021D644C(char *);
extern void func_021D639C(char *);
extern void func_021D65C8(char *);
extern void func_0201ED04(int);
struct Rec;
extern void func_02045C04(struct Rec *rec);
extern void func_0201C4C0(int);
extern void func_0201D83C(int);
extern void func_021E5868(int);
extern void func_021E54E0(int);
extern void func_020315D4(int);
extern void func_020306F0(int);
extern void func_02034A5C(int);
int func_021D4448(int sys,int unused,int unused2,int *p)
{
    func_021DD008((char *)p[12],0);
    func_021E7DF0(p[8]);
    func_021E8A78(p[14]);
    func_021E8A78(p[13]);
    func_021E8628(p[9]);
    if(p[12]) func_021D9EA0(p[12]);
    func_021D644C((char *)p);
    func_021D639C((char *)p);
    func_021D65C8((char *)p);
    func_0201ED04(p[5]);
    func_02045C04((void *)p[4]);
    func_0201C4C0(p[3]);
    func_0201D83C(p[2]);
    func_021E5868(p[1]);
    func_021E54E0(p[0]);
    func_020315D4(sys);
    func_020306F0(0x57);
    func_02034A5C((int)ov114_id);
    func_02034A5C((int)ov067_id);
    return 1;
}
