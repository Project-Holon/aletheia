/*
 * file:     move_3.c
 * unit:     yes
 * function: func_021C11F8, func_021C1210
 * address:  0x021C11F8
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   DWCi_MOVFramework  0x021D3DC0  arm  ov016
 *   DWCi_MOVGetStatus  0x021D40F4  arm  ov016
 *   DWCi_GetChildInfo  0x021D4138  arm  ov016
 *   MIi_CpuCopy16      0x02082A60  arm
 *   DWCi_TSKlDelete    0x021D7724  arm  ov016
 *   DWCi_HEAPlFree_    0x021D6438  arm  ov016
 *   g_021DE590         0x021DE590  data
 *   MemMovFree         0x021DE590  data
 */
extern void DWCi_MOVFramework(void);
extern void DWCi_MOVGetStatus(unsigned char *stt, unsigned char *change_f);
extern void *DWCi_GetChildInfo(void);
extern void MIi_CpuCopy16(void *srcp, void *destp, unsigned long size);
extern void DWCi_TSKlDelete(int kind, void *task);
extern void DWCi_HEAPlFree_(void **mem);
char *func_021C11F8(void);
void taskFramework(void *task);
extern unsigned char *g_021DE590;
extern void *MemMovFree;

/*
 * Address of the object behind the global pointer, +0x1e280.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C11F8.c \
 *       --func func_021C11F8 --addr 0x021C11F8 --region ov016 --cc dsi/1.1p1 --arm
 */
char *func_021C11F8(void)
{
    return *(char **)0x021DE590 + 0x1e280;
}


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
	case 1:
	case 2:
	case 3:
	case 4:
		break;
	case 5:
		if (change != 0) {
			char *dst;
			void *src;
			p = g_021DE590 + 0x2280;
			dst = (char *)p + 0x1c000;
			src = DWCi_GetChildInfo();
			MIi_CpuCopy16(src, dst, 0x16);
			func = *(void (**)(int))(g_021DE590 + 0x1e298);
			if (func == 0) {
				g_021DE590[0x1e2a0] = 1;
				return;
			}
			func(0);
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
	case 34:
		DWCi_TSKlDelete(0, task);
		DWCi_HEAPlFree_(&MemMovFree);
		break;
	}
}
