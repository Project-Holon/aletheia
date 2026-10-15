/*
 * function: DWCi_IsValidAID
 * address:  0x0216BC3C
 * packet:   pkt_ov009_0216BC3C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_IsValidAID (libdwcmatch.TWL.HYB.a(dwc_main.o))
 *
 * symbols:
 *   gt2GetConnectionData  0x02195E78  arm  ov009
 *   gDwcConnectionArray  0x021AA8A0  data
 */

typedef struct ConnData {
	unsigned char pad0;
	unsigned char aid;
} ConnData;

extern int gt2GetConnectionData(const int *p);
extern void *gDwcConnectionArray[];

int DWCi_IsValidAID(unsigned char aid)
{
	int i;

	for (i = 0; i < 0x20; i++) {
		if (gDwcConnectionArray[i] != 0) {
			if (aid == ((ConnData *)gt2GetConnectionData(gDwcConnectionArray[i]))->aid)
				return 1;
		}
	}
	return 0;
}
