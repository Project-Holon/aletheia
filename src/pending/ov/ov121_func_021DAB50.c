/*
 * function: func_021DAB50
 * address: 0x021DAB50
 * packet: pkt_ov121_021DAB50
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * residual: 147/200 bytes differ (older draft 123/200 but with a worse loop shape). One instruction of shape: the original keeps the weight as `asrs r0,#1; lsls r0,#0x10; asrs r2,r0,#0x10`, every compile folds it to `lsls r0,#0xf; asrs r4,r0,#0x10`. The rest of the body is the same instruction stream, shifted one slot, with weight in r4 instead of r2.
 * note 2026-10-05 (recoup, lane A9): twin is ov104 func_021B89DC (EXACT, same blend, factor from d_020A1B38). Its blend spelling in a 16 pixel loop (weight hoisted by the compiler) gives the original loop shape (i in r6, ip mask, [sp,#0xc] mask, same pack). Tried for the unfolded weight, all folded: s16 local (c99 and c); int local passed to an s16 parameter; int parameter narrowed inside blend; (s16) cast at each use; weight in an inline returning s16; expression passed straight as the argument; weight written back into the angle parameter (152 bytes, also swaps the entry stores); s16 local from s16 c then /2; two-step s16 factor/2 (204 bytes, ext after the add); int factor with u32 counter. Pragmas peephole, opt_lifetimes, opt_common_subs, scheduling off: unchanged 147; opt_propagation off 212 bytes; opt_dead_assignments off 208 bytes. arm9 func_0202EA40 (same fade, scale a plain s32) has no extension at all, so the original here has a real s16 weight whose division result is kept in a register before the extension. Open idea: find what keeps the division result unfolded (a second use of the quotient).
 * note final push 2026-10-05 G8L8: 147/200 unchanged after 34 more compiles (also store-and-reload forms: array element, file static, output pointer, volatile: size changes only). The fold shl16(sra1(x)) -> lsls #0xf is generic: explicit (q<<16)>>16, u16 conversion, int parameter narrowed inside blend (double extension), opt_propagation off with do-while, a dead second use of the quotient, non-const table, one-field struct weight, int and s16 inline helpers, weight assigned inside the loop, block-local weight, (int) casts, sum local, u16 parameter: all fold or grow. Only this function in all listings (Thumb and ARM) has asrs #1; lsls #0x10; asrs #0x10 after lsrs #0x1f. Residue is instruction selection; a missing extra consumer of the quotient is the only unexplored lever.
 * note final push 2026-10-05 G10L9: 147/200 unchanged after 27 more target compiles (ov091 021B6B24 and ov132 021F91CC levers: int/u16 pixel types, red-first deltas, shared-int clamp into u8 locals, u8 i first, direct array reads per channel; FX_CosIdx helper and weight inside blend; for-init, call-argument, while and compound-int weight spellings; u16/s16 angle; pragmas opt_loop_invariants, opt_strength_reduction, opt_unroll_loops, opt_vectorize_loops, opt_dead_code; --lang c). Micro tests on the fold: shl16(sra1(x)) is fused to lsls #0xf whenever the quotient has a single consumer chain, including two (s16) casts, struct-free copies, assignment expressions, inline returns and equal if/else arms. It stays as asrs #1 / lsls #0x10 / asrs #0x10 only when the int quotient has a second real int use (f3: `o[0]=h`, g3: `h*x`) or sits behind a merge (ternary, n5/n6), neither of which the image shows (no later r0 use, no branch). The remaining unexplored lever is a second consumer of the int quotient that disappears after the fold decision; no human spelling found.
 * symbols:
 *   d_020A1B38 0x020A1B38 data a4
 *   func_02061CA4 0x02061CA4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef signed int s32;
extern const s16 d_020A1B38[];
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
static inline u16 blend(u16 c1,u16 c2,s16 factor) {
 u8 g1,r1,b1; int db,dr,dg;
 g1=(c1&0x3e0)>>5;
 r1=c1&31;
 b1=(c1&0x7c00)>>10;
 db=(factor*((u8)((c2&0x7c00)>>10)-b1))>>12;
 dr=(factor*((u8)(c2&31)-r1))>>12;
 dg=(factor*((u8)((c2&0x3e0)>>5)-g1))>>12;
 return ((u8)(b1+db)<<10)|((u8)(r1+dr)|((u8)(g1+dg)<<5));
}
void func_021DAB50(void *a,u16 *p,int angle,int bank,const u16 *first,const u16 *last) {
 int i;
 s16 factor=(s16)((d_020A1B38[((angle>>4)*2)+1]+0x1000)/2);
 for(i=0;i<16;i++) p[i]=blend(first[i],last[i],factor);
 func_02061CA4(a,bank*32,(u32)p,32);
}
