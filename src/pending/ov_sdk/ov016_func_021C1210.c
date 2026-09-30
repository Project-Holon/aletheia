/*
 * function: taskFramework
 * address:  0x021C1210
 * packet:   pkt_ov016_021C1210
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker:  dispatch only. Original lowers the switch as a 0..20 jump table
 *           (21 `b` entries at +0084..+00D8) with the "gap 3" outliers
 *           23/26/29/34 kept out in a tree rooted at `cmp r0,#0x1a`
 *           (`bgt`/`bge` then `cmp #0x14`); 596 vs 632 bytes.
 *           1.1p1 will not make that split.  Giving the source a label for
 *           every table entry (empty `case 0..4,6..11,14..19: break;`, per
 *           the density-from-zero rule) makes 1.1p1 absorb the gap-3 outliers
 *           into the run: one WIDE table 0..29 (`cmp r0,#0x1d; bgt` +
 *           `cmp r0,#0; addge pc`), 616 B; filling all of 0..20 yields a
 *           single table 0..34 (`cmp r0,#0x22; addls pc`), 612 B.  1.1p1's
 *           dense-run threshold extends across a gap of 3; the original
 *           stops the run at 20.  Writing the outliers as an if-chain after
 *           the switch gives the right 0..20 table but routes the empty arms
 *           through the ifs (608 B, recoloured).  Reordering the source arms
 *           does not move the dispatch.
 *
 *           This is a source-shape dead end at 1.1p1: the whole value set is
 *           {0..20,23,26,29,34} and no grouping/ordering of it makes 1.1p1
 *           emit a 0..20 table plus a 23/26/29/34 tree.
 *
 * sdk:      taskFramework (libdwcutil.TWL.HYB.a(move.o))
 *
 * symbols:
 *   DWCi_MOVFramework  0x021D3DC0  arm  ov016
 *   DWCi_MOVGetStatus  0x021D40F4  arm  ov016
 *   DWCi_GetChildInfo  0x021D4138  arm  ov016
 *   MIi_CpuCopy16      0x02082A60  arm
 *   DWCi_TSKlDelete    0x021D7724  arm  ov016
 *   DWCi_HEAPlFree_    0x021D6438  arm  ov016
 *   g_021DE590         0x021DE590  data
 */
extern void DWCi_MOVFramework(void);
extern void DWCi_MOVGetStatus(unsigned char *stt, unsigned char *change_f);
extern void *DWCi_GetChildInfo(void);
extern void MIi_CpuCopy16(void *srcp, void *destp, unsigned long size);
extern void DWCi_TSKlDelete(int kind, void *task);
extern void DWCi_HEAPlFree_(void **mem);
extern unsigned char *g_021DE590;

void taskFramework(void *task)
{
	unsigned char state;
	unsigned char change;
	void (*func)(int);
	void *p;

	DWCi_MOVFramework();
	if (g_021DE590[0x1e2a0] != 0) {
		if (g_021DE590[0x1e2a1] == 0) {
			func = *(void (**)(int))(g_021DE590 + 0x1e298);
			if (func != 0)
				func(0);
			return;
		}
	}
	DWCi_MOVGetStatus((unsigned char *)&state, &change);
	switch (state) {
	case 5:
		if (change != 0) {
			p = g_021DE590 + 0x2280;
			MIi_CpuCopy16(DWCi_GetChildInfo(), (char *)p + 0x1c000, 0x16);
			func = *(void (**)(int))(g_021DE590 + 0x1e298);
			if (func == 0) {
				g_021DE590[0x1e2a0] = 1;
				return;
			}
			func(0);
		}
		break;
	case 12:
		if (change != 0) {
			func = *(void (**)(int))(g_021DE590 + 0x1e298);
			if (func == 0) {
				g_021DE590[0x1e2a0] = 1;
				return;
			}
			func(2);
		}
		break;
	case 13:
		if (change != 0) {
			func = *(void (**)(int))(g_021DE590 + 0x1e298);
			if (func == 0) {
				g_021DE590[0x1e2a0] = 1;
				return;
			}
			func(1);
		}
		break;
	case 20:
	case 23:
		if (change != 0) {
			func = *(void (**)(int))(g_021DE590 + 0x1e298);
			if (func == 0) {
				g_021DE590[0x1e2a0] = 1;
				return;
			}
			func(3);
		}
		break;
	case 26:
	case 29:
		if (change != 0) {
			func = *(void (**)(int))(g_021DE590 + 0x1e298);
			if (func == 0) {
				g_021DE590[0x1e2a0] = 1;
				return;
			}
			func(4);
		}
		break;
	case 34:
		DWCi_TSKlDelete(0, task);
		DWCi_HEAPlFree_((void **)&g_021DE590);
		break;
	}
}
