/*
 * function: func_02178144
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
 *   func_02179CF4  0x02179CF4  arm
 *   g_021AB184     0x021AB184  data
 */

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

struct DWCAuthGlobal {
	int pad;
	struct DWCAuthCtx *ctx;
};

extern struct DWCAuthGlobal g_021AB184;

extern void func_02179CF4(char *http);

void func_02178144(void)
{
	void (*free)(unsigned long, void *, long);

	if (g_021AB184.ctx == 0)
		return;
	free = g_021AB184.ctx->free_fn;
	if (g_021AB184.ctx->http != 0)
		func_02179CF4(g_021AB184.ctx->http);
	free(0, g_021AB184.ctx, 0);
	g_021AB184.ctx = 0;
}
