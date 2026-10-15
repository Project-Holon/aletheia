/*
 * function: DWC_Auth_Destroy
 * address:  0x02178144
 * packet:   pkt_ov009_02178144
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Auth_Destroy (libdwcauth.TWL.HYB.a(dwc_auth.o))
 *
 * symbols:
 *   DWC_Http_Destroy  0x02179CF4  arm
 *   gDwcAuthGlobal     0x021AB184  data
 */

#include "../include/G_DWCAuthGlobal.h"

struct DWCAuthCtx {
	unsigned char pad0[0x1004];
	int error;
	unsigned char result[0x1c4];
	unsigned char pad1[0x44];
	void (*free_fn)(unsigned long, void *, long);
	unsigned char pad2[0x100];
	void *http;
	unsigned char thread[0x6c];
	int started;
	unsigned char pad3[0x50];
	unsigned char mutex[0x18];
	int abort_flag;
};

extern struct DWCAuthGlobal gDwcAuthGlobal;

extern void DWC_Http_Destroy(char *http);

void DWC_Auth_Destroy(void)
{
	void (*free)(unsigned long, void *, long);

	if (gDwcAuthGlobal.ctx == 0)
		return;
	free = gDwcAuthGlobal.ctx->free_fn;
	if (gDwcAuthGlobal.ctx->http != 0)
		DWC_Http_Destroy(gDwcAuthGlobal.ctx->http);
	free(0, gDwcAuthGlobal.ctx, 0);
	gDwcAuthGlobal.ctx = 0;
}
