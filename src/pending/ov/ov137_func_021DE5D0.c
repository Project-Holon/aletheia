/*
 * function: func_021DE5D0
 * address: 0x021DE5D0
 * packet: pkt_ov137_021DE5D0
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * checks: 1 own ARM9 getter/setter units and ov137 DE6EC read, exact prototypes
 *   now used (39338 returns u16, B878 pointer/u16, B3DC pointer/u32, DE6EC four);
 *   2 DD2E0/DD5AC/DE6EC neighbours read; 3 new enum flag with const p gives
 *   DIFF206/224; 4 enum/offset/overwritten-spill idioms read;
 *   5 fresh idiom directory/neighbours, scalar spills, no aggregate object.
 * prototype: original 021DE648 loads a, 021DE64C stores a to [sp], then
 *   021DE64E..021DE654 set r1, r0, r2, r3 before BL at021DE656.
 *   Own ov137 021DE6EC has four parameters and reads only r0..r3.
 *   Fifth outgoing caller value is unused by that definition; reproducing
 *   its outgoing stack requires an unused fifth parameter in the callee.
 *   Park this signature/listing conflict; do not diverge from the definition.
 * runs: wave77 renewed 1 substantive iteration; old permuter300 consumed,
 *   unsafe volatile/signature/switch-dispatch mutant was rejected, not repeated.
 * residual: DIFF216, compiled232 versus240; 10/10 relocation sites resolved.
 * recoup 2026-10-05 (lane P18L10): extent is 240 B (not 94). Callee func_021DE6EC
 *   is called with a FIFTH stack argument (a = result of func_02008550, str r0,[sp]
 *   at 021DE64C); its matched definition has 4 parameters, so the caller declares
 *   5 (stale prototype in the original TU); with that the draft goes 224 -> 232 B.
 *   Tried: int locals q0..q3 (two literal assignments or one): constants fold and
 *   mwcc hoists ALL literal offsets (0x138 too, base chain starts at 0x114), 244 B;
 *   inline Dn/Up(0x138) accessors: same; real struct W with fields: 252 B;
 *   p + 0x138 + i*8 for the handle reads: chain base becomes 0x138 as in the
 *   original but p+0x138 is hoisted into r7, 252 B; e = p + i*8 pointer local: 252 B;
 *   opt_propagation off: 240 B but 151 B differ, structure wrong; opt_lifetimes off: no change.
 *   Residue: original hoists only 0x114 and three 0x160 offsets (first stored as 0x138,
 *   then derived by subs 0x24 / adds 0x28) and rematerialises 0x138 at the 3 handle reads;
 *   no honest source form found. The enum Offset locals below are a stand-in (park).
 *   Also the original tests `if (i == f()) {} else call` (bne over a b).
 * symbols:
 *   func_020061E4 0x020061E4 thumb
 *   func_02008550 0x02008550 thumb
 *   func_02008554 0x02008554 thumb
 *   func_02039338 0x02039338 arm
 *   func_021DE6EC 0x021DE6EC thumb ov137
 *   func_0204B878 0x0204B878 arm
 *   func_0204B3DC 0x0204B3DC arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
typedef enum { FLAG_CLEAR = 0, FLAG_SET = 1 } Flag;
typedef enum { O114=0x114, O138=0x138, O160=0x160 } Offset;
extern u8 func_02008550(const void *);
extern u8 func_02008554(const void *);
extern u16 func_02039338(void);
extern void func_021DE6EC(u8 *,u8 *,int,int,int);
extern void func_0204B878(void *,u16);
extern void func_0204B3DC(void *,u32);
extern void func_020061E4(u32);
void func_021DE5D0(const u8 *p)
{
    int i;
    Flag flag=FLAG_CLEAR;
    u8 a,b;
    Offset q0,q1,q2,q3;
    q0=O138; q0=O114;
    q1=O138; q1=O160;
    q2=O138; q2=O160;
    q3=O138; q3=O160;
    for(i=0;i<5;i++) {
        switch(*(u32 *)(p+i*4+q3)) {
        case 0: break;
        case 1:
            a=func_02008550(*(void **)(p+i*8+0x138));
            b=func_02008554(*(void **)(p+i*8+0x138));
            if (i!=func_02039338()) func_021DE6EC((u8 *)p,*(u8 **)(p+q0),i,b,a);
            func_0204B878(*(void **)(p+i*4+0x9c),4);
            func_0204B3DC(*(void **)(p+i*4+0x9c),1);
            *(u32 *)(p+i*4+q2)=2;
            flag=FLAG_SET;
            break;
        case 2: break;
        case 3:
            if(i==func_02039338()) func_02008550(*(void **)(p+i*8+0x138));
            func_0204B878(*(void **)(p+i*4+0x9c),5);
            *(u32 *)(p+i*4+q1)=0;
            break;
        }
    }
    if(flag) func_020061E4(0x676);
}
