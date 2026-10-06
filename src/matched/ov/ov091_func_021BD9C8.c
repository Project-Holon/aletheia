/*
 * function: func_021BD9C8
 * address: 0x021BD9C8
 * packet: pkt_ov091_021BD9C8
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x02051614, unmatched accessor; +0x70 THM_CALL has no outside witness.
 * blocker: verified EXACT (one --arm, fixed compiler, 12 B) in scratch:
 *   unsigned int func_02051614(unsigned int **p) { return (*p)[2]; }
 * symbols:
 *   func_02040588 0x02040588 arm
 *   func_021BB200 0x021BB200 thumb ov091
 *   func_02051614 0x02051614 arm
 *   func_02051574 0x02051574 arm
 *   func_02047964 0x02047964 arm
 *   func_020479D8 0x020479D8 arm
 *   func_02051534 0x02051534 arm
 *   func_02047970 0x02047970 arm
 *   func_02006BD0 0x02006BD0 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_02040588(u32,u32);
extern void func_020061E4(u32);
extern void func_021BB200(u8 *,u8 *,int,int);
extern int func_02051614(int **p);
extern int func_02006238(void);
extern u32 func_02017E1C(void *,u32,u32);
extern u32 func_02006984(u32,u32,u32,u32,u32,u32,u32,u32);
extern u32 func_02006BD0(u32 i);
extern int func_02051574(void);
extern void func_02047964(void);
extern void func_020479D8(void);
extern int func_02051534(void);
extern void func_02047970(void);
#define W(o) (*(u32 *)(p+(o)))
void func_021BD9C8(u8 *p)
{
    u32 species,form;
    if (W(0x26c) == 0) {
        p[0x268]++;
        if (p[0x268] == 1) {
            func_02040588(0,1);
            if (W(0x264)-1 <= 1) func_020061E4(0x643);
            else if (W(0x264) == 3) func_020061E4(0x644);
        }
        if (p[0x268] > p[0x269]) {
            func_021BB200(p,*(u8 **)(p+W(0x2c)*4+0x160),W(0x38),0);
            W(0x26c) = 1;
        }
    }
    if (func_02051614((int **)W(0x260)) <= 0 && func_02006238() == 0) {
        if (W(0x270) == 0) {
            species = func_02017E1C((void *)W(0x38),5,0);
            form = func_02017E1C((void *)W(0x38),0x6f,0);
            W(0x274) = func_02006984(species,form,0x40,0,0,0,0,0);
            W(0x270) = 1;
        } else {
            if (func_02006BD0(W(0x274)) == 0) p[0xc] = 0x10;
        }
    }
    func_02051574();
    func_02047964();
    func_020479D8();
    func_02051534();
    func_02047970();
}
