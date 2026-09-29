/*
 * function: func_021C6B44
 * address:  0x021C6B44
 * packet:   pkt_ov114_021C6B44
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      freeHttpParam (libdwcnd.TWL.HYB.a(dwci_nd.o))
 *
 * symbols:
 *   g_021D3B9C  0x021D3B9C  data
 */

extern int g_021D3B9C[];
#define FREE(p) ((void (*)(void *))g_021D3B9C[5])(p)

void func_021C6B44(int *hrq)
{
	if (hrq == 0)
		return;
	switch (hrq[0]) {
	case 1:
		break;
	case 2:
		if (hrq[7]) {
			FREE((void *)hrq[7]);
			hrq[7] = 0;
		}
		if (hrq[6]) {
			FREE((void *)hrq[6]);
			hrq[6] = 0;
		}
		FREE((void *)hrq[5]);
		hrq[5] = 0;
		break;
	case 3:
		FREE((void *)hrq[3]);
		hrq[3] = 0;
		break;
	}
	FREE(hrq);
}
