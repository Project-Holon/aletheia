/*
 * function: func_0219FE44
 * address:  0x0219FE44
 * packet:   pkt_ov009_0219FE44
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
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
