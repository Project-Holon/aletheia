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
 *   GF_FONT_Delete 0x0201D83C thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 */
extern unsigned int func_020307B0(void *p);
typedef unsigned int   u32;
extern int func_020351A0(u32 v);
extern void func_0217D174(int *);
extern void func_0217D224(int *);
struct Rec;
struct WordSet;
extern void func_021E7DF0(int *p);
extern void func_0217E058(int *p);
extern void func_021E8A78(void *p);
extern u32 GF_FONT_Delete(void *ptr);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 func_0201ED04(struct WordSet *p);
void func_0217BA9C(int *p)
{
    func_020307B0((void *)p[12]);
    if (p[0x67] == 1) func_020351A0(8);
    func_0217D174(p);
    func_0217D224(p);
    func_021E7DF0((int *)p[7]);
    func_0217E058((int *)p[3]);
    func_021E8A78((void *)p[0]);
    GF_FONT_Delete((void *)p[10]);
    MSGDATA_Delete((struct Rec *)p[9]);
    MSGDATA_Delete((struct Rec *)p[8]);
    func_0201ED04((struct WordSet *)p[11]);
    func_020307B0(p);
}
