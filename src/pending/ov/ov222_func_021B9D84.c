/*
 * function: func_021B9D84
 * address: 0x021B9D84
 * packet: pkt_ov222_021B9D84
 * region: ov222
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note 2026-10-05 (P21L2): DIFF 4/76 B. Size and all other instructions match. Residue: the table base
 *   is in r1 and the first loaded halfword in r2 (original: base r2, halfword r1) at +0024, +0028, +002C, +002E.
 *   Tried (each 4 B): byte-offset reads of a char table (idiom coordinate-pair-by-byte-offset);
 *   int locals a,b for the two loads; struct-typed extern with .x/.y; y load before x store text order;
 *   all six per-function pragmas (opt_lifetimes, opt_propagation, opt_common_subs, opt_dead_assignments,
 *   scheduling, peephole). Worse: struct copy (67 B), table pointer local at function top (37 B),
 *   x load hoisted above the if (52 B), separate y -= 0x40 statement (32 B, 80 B size). Callee
 *   func_02040618 is void (ends in pop, no result). Looks like a two-load colour tie.
 * symbols:
 *   func_02040618 0x02040618 arm
 *   func_0204B404 0x0204B404 arm
 *   d_021BA1D8 0x021BA1D8 data a2
 */
typedef unsigned char u8;
typedef signed short s16;
typedef struct {s16 x,y;} Pt;
extern char d_021BA1D8[];
extern void func_02040618(unsigned,unsigned,unsigned);
extern void func_0204B404(void*,const Pt*,unsigned);
void func_021B9D84(char*p)
{
    Pt pos;
    if(*(int*)(*(char**)(p+4)+4)==0){
        func_02040618(1,3,0x40);
        func_02040618(2,3,0x40);
        pos.x=*(s16*)(d_021BA1D8+0);
        pos.y=*(s16*)(d_021BA1D8+2)-0x40;
        func_0204B404(*(void**)(p+0x54),&pos,0);
        *(u8*)(p+0x44)=0;
    }
}
