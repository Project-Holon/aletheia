/*
 * function: func_021780A8
 * address:  0x021780A8
 * packet:   pkt_ov009_021780A8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Auth_Abort (libdwcauth.TWL.HYB.a(dwc_auth.o))
 *
 * symbols:
 *   func_02086028  0x02086028  arm
 *   func_02086078  0x02086078  arm
 *   func_021797D4  0x021797D4  arm  ov009
 *   func_0208574C  0x0208574C  arm
 *   func_02085710  0x02085710  arm
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
extern void func_021797D4(void *http);
extern int func_0208574C(void *thread);
extern void func_02085710(void *thread);

void func_021780A8(void)
{
	if (g_021AB184.ctx == 0)
		return;
	func_02086028(&g_021AB184.ctx->mutex);
	g_021AB184.ctx->abort_flag = 1;
	func_02086078(&g_021AB184.ctx->mutex);
	if (g_021AB184.ctx->http != 0)
		func_021797D4(g_021AB184.ctx->http);
	if (g_021AB184.ctx->started == 0)
		return;
	if (func_0208574C(g_021AB184.ctx->thread) != 0)
		return;
	func_02085710(g_021AB184.ctx->thread);
}
