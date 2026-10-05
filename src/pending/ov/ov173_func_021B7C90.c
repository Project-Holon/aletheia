/*
 * function: func_021B7C90
 * address: 0x021B7C90
 * packet: pkt_ov173_021B7C90
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * residual: 272/272 bytes, 37 concrete bytes differ; only p/row colour swap (original row r4, p r5; build p r4, row r5).
 * 2026-10-05 (wave P8 W10): sibling ov173 021B7DA0 (same menu, char *p, int i) gets i r4, p r5 with
 *   the same S() macro shape, so the swap comes from the top call EB0(p,0): with that call removed the build gives
 *   row r4, p r5. Tried: 7DA0 shape (char *p, S macro), plain literal -2 instead of the zero local
 *   (same 37 B, so the local is dropped), six per-function pragmas (opt_lifetimes, propagation,
 *   common_subs, dead_assignments, scheduling, peephole: all 37 B), final call 7ADC repeated in each arm
 *   (no tail merge, 312 B). Idioms read: a-colour-swap-no-source-form-fixes-can-be-opt-lifetimes-off,
 *   two-long-lived-values-in-each-others-registers, a-dying-pointer-loads-scratch-colour-can-be-an-allocator-tie,
 *   a-later-parameters-width-reorders-the-entry-spill-stores, a-no-code-self-assignment-reorders-the-register-colouring
 *   (none applies). Callee arity: EB0 (p,int) void, 7ADC takes (p,u8,3) as in 7DA0; no void-return problem.
 * symbols:
 *   func_021B7EB0 0x021B7EB0 thumb ov173
 *   func_020061E4 0x020061E4 thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_021B7438 0x021B7438 thumb ov173
 *   func_021B71C4 0x021B71C4 thumb ov173
 *   func_021B70D8 0x021B70D8 thumb ov173
 *   func_021B7F64 0x021B7F64 thumb ov173
 *   func_021B7FD0 0x021B7FD0 thumb ov173
 *   func_021B7ADC 0x021B7ADC thumb ov173
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021B7EB0(char *,int);
extern u16 func_021B7438(char **);
extern void func_021B71C4(char *,int);
extern void func_020061E4(unsigned);
extern void func_021B70D8(char *);
extern void func_021B7F64(char *);
extern void func_021B7FD0(u8 *,int);
struct Sound;
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_021B7ADC(u8 *,u8,int);
#define S(p) (*(char **)(p))
void func_021B7C90(char *p,int row,int old)
{
    
    func_021B7EB0(p,0);
    if(row<=3) {
        func_020061E4(0x54C);
        *(u16 *)(S(p)+0x14)=row;
        if(*(u16 *)(S(p)+0x16)+*(u16 *)(S(p)+0x14)<*(u8 *)(p+0x1B8)) func_021B71C4(p,func_021B7438((char **)p));
        else func_021B71C4(p,-2);
    } else if(row==6) {
        if(old==3 && *(u16 *)(S(p)+0x16)+4<*(u8 *)(p+0x1B8)) {
            func_020061E4(0x54C);
            func_020260E4(*(void **)(p+0x1C8),3);
            row=3;
            (*(u16 *)(S(p)+0x16))++;
            func_021B70D8(p);
            func_021B71C4(p,func_021B7438((char **)p));
            func_021B7F64(p);
            func_021B7FD0((u8 *)p,1);
        } else if(old==0) {
            if(*(u16 *)(S(p)+0x16)!=0) {
                func_020061E4(0x54C);
                (*(u16 *)(S(p)+0x16))--;
                func_021B70D8(p);
                func_021B71C4(p,func_021B7438((char **)p));
                func_021B7F64(p);
                func_021B7FD0((u8 *)p,-1);
            }
            row=0;
            func_020260E4(*(void **)(p+0x1C8),0);
        } else {
            row=3;
            func_020260E4(*(void **)(p+0x1C8),3);
        }
    } else func_020061E4(0x54C);
    func_021B7ADC((u8 *)p,row,3);
}
