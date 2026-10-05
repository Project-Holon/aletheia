/*
 * function: func_021B1588
 * address: 0x021B1588
 * packet: pkt_ov013_021B1588
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: DIFF
 * residual: DIFF 26/172 bytes. Image has mask in r6 and the compare-constant temp and seg counter in r5; build has mask r5, temp and seg r6.
 * note 2026-10-05 (wave P14 C7): ldr of 0x1FDF cannot move above asrs in the image because r5 is reused (anti-dependence), so the residue is only colour order of mask vs the temp/seg pair. Tried, all 26 B unless noted: mask int / unsigned / signed char; mask declared first; plain literal 8159 (no seg alias); mask=0xff default then override; swapped store order of mask and s=-s; encode(int); dst store through a u8 local; unsigned helper counter (27); table index tab[i] (73); in-place seg loop (121); ternary mask (95-127); classic G.711 shape with in-place bias (121); ternary clip (36); if(s>=0) form (29); seg==8 test (28); sign test on a copy (28); pragmas opt_lifetimes, scheduling, peephole (26), opt_common_subs (39), opt_propagation (119), opt_dead_assignments (143). No callees, no twin (grep for 8159/0x1FDF in src/matched finds only unrelated files). Idioms read: a-colour-swap-no-source-form-fixes-can-be-opt-lifetimes-off, a-base-pointer-and-its-mask-scratch-swap-as-an-allocator-tie, a-no-code-self-assignment-reorders-the-register-colouring, a-dying-pointer-loads-scratch-colour-can-be-an-allocator-tie, two-long-lived-values-in-each-others-registers. Self-assignment not tried (stand-in rule).
 * final push 2026-10-05 G6L4: still DIFF 26/172, draft unchanged. Residue is purely the colour of the mask vs the cmp-constant temp and seg counter (the original loads 0x1FDF into r5 after asrs, so it reuses the sample register and mask gets r6; the build hoists that ldr above asrs). No twin: the pattern movmi; ldr; rsbmi exists only here in all listings. Tried (bytes off): opt_propagation off with do-while outer loop (120, 107 with do-while seg loop), sign flag with mask set after clamp (142), mask arms if/else swapped (29), long s (35), seg declared before s (26), clamp spelled 8159<s / braces / empty-then (26), s>=8160 (31), clamp repeated in each sign arm (130), s+=0x21 in place (26), table pointer local at top of encode (141), explicit seg loop with tab local (83-101), v kept apart from s (26), mask from sample<0 before shift (125), ternary clamp twice (121), encode returning u8 (55), unsigned seg (30), u8 size parameter (26), outer do-while (27), named uval (28), pointer parameter for src (26), pragmas opt_lifetimes+scheduling, opt_dead_code, opt_strength_reduction, opt_loop_invariants (26). Idioms read: of-two-equal-temps-the-later-born-one-gets-the-lower-register, opt-propagation-off-with-named-locals-pins-argument-constants-against-stack-stores, a-tail-calls-pool-word-is-scheduled-before-the-last-argument-write, a-shared-register-copy-arm-is-hoisted-above-the-compare-chain.
 *
 * symbols:
 *   d_021B3C28 0x021B3C28 data a4
 */
extern const int d_021B3C28[8];
static inline int seg_search(int v,const int *tab,int size) { int i; for(i=0;i<size;i++) if(v<=*tab++)return i; return size; }
static inline int encode(short sample) {
 int s,seg; unsigned char mask;
 s=sample>>2;
 if(s<0){mask=0x7f;s=-s;}else mask=0xff;
 seg=8159; if(s>seg)s=seg;
 seg=seg_search(s+0x21,d_021B3C28,8);
 if(seg>=8)return 0x7f^mask;
 return ((seg<<4)|(((s+0x21)>>(seg+1))&0xf))^mask;
}
void func_021B1588(unsigned char *dst,const short *src,unsigned int n) {
 unsigned int i; for(i=0;i<n;i++) dst[i]=encode(src[i]);
}
