/*
 * function: func_021D6B84
 * address: 0x021D6B84
 * packet: pkt_ov120_021D6B84
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero alignment padding follows.
 * lever: compute the callee result before initializing mode; the original
 * signed BLT at 0x021D6B96 requires a signed full-word result declaration.
 * symbols:
 *   func_0204B898 0x0204B898 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_0204B898(void *);
extern void func_0204B878(void *,u16);
extern void func_0204B92C(void *,u32);
void func_021D6B84(u8 *p,u32 n){int got;int mode;got=func_0204B898(*(void **)(p+0xc4+n*4));mode=1;if(got>=2)mode=3;func_0204B878(*(void **)(p+0xc4+n*4),mode);func_0204B92C(*(void **)(p+0xc4+n*4),1);}
