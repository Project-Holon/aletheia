/*
 * function: func_0215CDD0
 * address:  0x0215CDD0
 * packet:   pkt_ov009_0215CDD0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_CleanupCommandPacketQueue (libsoc.TWL.HYB.a(socl_command.o))
 *
 * symbols:
 *   g_021AA480  0x021AA480  data
 *   g_021A1CD8  0x021A1CD8  data
 */

typedef struct {
	char pad0[0x1c];
	void (*free)(void *p);
} Cfg;

typedef struct {
	void *packets;
	char pad0[0x14];
	int a;
	int pad1;
	int b;
} Cmd;

extern Cmd g_021AA480;
extern Cfg *g_021A1CD8;

int func_0215CDD0(void)
{
	if (g_021AA480.b < g_021AA480.a)
		return -1;
	g_021A1CD8->free(g_021AA480.packets);
	g_021AA480.packets = 0;
	return 0;
}
