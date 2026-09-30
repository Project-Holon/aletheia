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
 * u1: two more left-nested spellings of the same grouping and a tail-moved variant - all reassociate (38-45 B) and break the schedule before +007C; the committed right-nested form stays the best (4 B). ../2.0/* 30 B, ../1.2/sp3 238 B.
 *
 * residue (lane T3, 2026-09-30, measured): 4 concrete bytes: the last two eors of the oddmode chain. +007C image `eor r0, r0, r2` | ours `eor r0, r2, r0`; +0080 image `eor r8, r0, r1` | ours `eor r8, r1, r0`. Pin/flag sweep (9 pins x 7 flag sets) best -O4,p at 4 diffs, every other cell worse (D176-D251). Three body shapes tried: flat left-assoc chain (38 diffs), named a/b/c/d/e left-nested tree (4 diffs = identical to committed), sequential compound-assign (40 diffs). CW canonicalises the XOR tree, so the accumulator/operand order is not reachable from the source: capped, register allocation.
 * extra (lane T3, second pass): extra spellings (lane T3, second pass): ten more inline trees, all worse than the committed 4-diff form - left-nested ((C^(D^E))^B)^A 38, D^E^C^B^A 38, (D^E)^(C^(B^E)) 43, (D^E)^((C^B)^A) 39, ((D^E)^(C^B))^A 35, (C^(D^E))^(B^A) 44, D^((E^C)^B)^A 132, flat D^E^C^B^A 38, A^(B^C^D^E) 33. First divergence is +007C `eor r0, r0, r2` | ours `eor r0, r2, r0` and +0080 `eor r8, r0, r1` | ours `eor r8, r1, r0`: the image's accumulator is the Rn slot of the last two eors, ours puts the fresh term there. Capped.
 *
 * near miss (w3_s4): 4 bytes differ, the last two eors of the oddmode expression have their operands swapped (original: eor r0,r0,r2; eor r8,r0,r1). All five terms reordered in left and right chains (about 400 forms); best is the committed right-nested D ^ (E ^ (A ^ (B ^ C))).
 *
 * u32: CLOSED this wave as src/matched/ov_sdk/ov009_func_0219FE44.c (EXACT, 236 bytes,
 *      shard layout/matched/ov009/pkt_ov009_0219FE44.json).  Pending copy kept for reference: the fix was the vendor macro CALCULATEODDMODE spelled exactly as upstream (flat left-assoc chain) with (char)(33 + rand() % 93).
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
