/*
 * function: func_021FD964
 * address: 0x021FD964
 * packet: pkt_ov132_021FD964
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * checks: 1 n/a no calls; 2 D938 unit excludes this getter and D974 is separately matched; 3 full-word indices retained; 4 parameter reassignment idiom fixes source order; 5 refreshed idioms and matched neighbours, no stack object.
 * matching: reassigning p before the subindex addition changes +6 from adds r0,r2,r0 to the original adds r0,r0,r2; integer and unreassigned pointer variants each DIFF1.
 * extent: getter is 14 bytes; D972..D974 alignment padding; D974 belongs to its existing matched file.
 * retry: 3 matching runs obtained EXACT14; header refresh is verified by run 4.
 */
typedef unsigned char u8;
typedef unsigned int u32;
u32 func_021FD964(char *p,u32 index,u32 subindex){p=p+index*0x30;return *(u8 *)(p+subindex+0x73);}
