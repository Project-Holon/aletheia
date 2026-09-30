/*
 * function: func_0219FE44
 * address:  0x0219FE44
 * packet:   pkt_ov009_0219FE44
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF (capped - see residue)
 *
 * residue (lane T3, 2026-09-30, measured): 4 concrete bytes: the last two eors of the oddmode chain. +007C image `eor r0, r0, r2` | ours `eor r0, r2, r0`; +0080 image `eor r8, r0, r1` | ours `eor r8, r1, r0`. Pin/flag sweep (9 pins x 7 flag sets) best -O4,p at 4 diffs, every other cell worse (D176-D251). Three body shapes tried: flat left-assoc chain (38 diffs), named a/b/c/d/e left-nested tree (4 diffs = identical to committed), sequential compound-assign (40 diffs). CW canonicalises the XOR tree, so the accumulator/operand order is not reachable from the source: capped, register allocation.
 *
 * near miss (w3_s4): 4 bytes differ, the last two eors of the oddmode expression have their operands swapped (original: eor r0,r0,r2; eor r8,r0,r1). All five terms reordered in left and right chains (about 400 forms); best is the committed right-nested D ^ (E ^ (A ^ (B ^ C))).
 *
 * sdk:      SetupListChallenge (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   func_02094694  0x02094694  arm
 */

struct SBL { char pad0[0x74]; char chal[8]; };
extern int func_02094694(void);
void func_0219FE44(struct SBL *slist)
{
	int i;
	int oddmode;
	slist->chal[0] = func_02094694() % 93 + 33;
	oddmode = 0;
	for (i = 1; i < 8; i++) {
		oddmode = (slist->chal[i - 1] < slist->chal[0]) ^ ((slist->chal[0] < 79) ^ ((slist->chal[0] & 1) ^ (oddmode ^ ((i ^ slist->chal[i - 1]) & 1))));
		slist->chal[i] = func_02094694() % 93 + 33;
		if ((oddmode && (slist->chal[i] & 1) == 0) || (!oddmode && (slist->chal[i] & 1) == 1))
			slist->chal[i]++;
	}
}
