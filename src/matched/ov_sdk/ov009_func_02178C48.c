/*
 * function: func_02178C48
 * address:  0x02178C48
 * packet:   pkt_ov009_02178C48
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Auth_SetError (libdwcauth.TWL.HYB.a(dwc_auth.o))
 *
 * symbols:
 *   func_02086028  0x02086028  arm
 *   func_02086078  0x02086078  arm
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

extern void func_02086028(void *mutex);
extern void func_02086078(void *mutex);

void func_02178C48(int error)
{
	func_02086028(&g_021AB184.ctx->mutex);
	g_021AB184.ctx->error = error;
	func_02086078(&g_021AB184.ctx->mutex);
}
