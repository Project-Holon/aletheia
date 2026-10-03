/*
 * function: func_021D6B38
 * address: 0x021D6B38
 * packet: pkt_ov175_021D6B38
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021E8A80 0x021E8A80 thumb ov177
 *   func_021E8A90 0x021E8A90 thumb ov177
 *   func_021D9ED0 0x021D9ED0 thumb ov175
 *   func_021E5534 0x021E5534 thumb ov177
 *   func_021E867C 0x021E867C thumb ov177
 *   func_021E7E08 0x021E7E08 thumb ov177
 *   func_021E5980 0x021E5980 thumb ov177
 *   func_021E64C0 0x021E64C0 thumb ov177
 *   func_021E7774 0x021E7774 thumb ov177
 *   func_021E84F8 0x021E84F8 thumb ov177
 */
typedef signed int     s32;
typedef unsigned int   u32;
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern void func_0201C4E4(int);
extern void func_021E8A80(unsigned);
extern int func_021E8A90(unsigned);
extern void func_021D9ED0(int);
extern void func_021E5534(int);
extern void func_021E867C(int);
extern void func_021E7E08(int);
extern void func_021E5980(int);
extern void func_021E64C0(int,int);
extern void func_021E7774(int,int);
extern void func_021E84F8(int,int);
int func_021D6B38(unsigned sys,int *state,int unused,int *p)
{
    switch(*state) {
    case 0: func_0204E720(3,16,0,0); *state=1; break;
    case 1: if(func_0204E804()==0) *state=2; break;
    case 2: func_021E8A80(p[14]); if(func_021E8A90(p[14])) *state=3; break;
    case 3: func_0204E720(3,0,16,0); *state=4; break;
    case 4: if(func_0204E804()==0) return 1; break;
    }
    func_021E5534(p[0]); func_0201C4E4(p[4]); func_021E867C(p[11]);
    func_021E7E08(p[10]); func_021E5980(p[1]); func_021D9ED0(p[13]);
    if(p[7]) func_021E64C0(p[7],p[4]);
    if(p[8]) func_021E7774(p[8],p[4]);
    if(p[9]) func_021E84F8(p[9],p[4]);
    return 0;
}
