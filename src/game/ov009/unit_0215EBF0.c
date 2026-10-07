/*
 * file:     unit_0215EBF0.c
 * unit:     yes
 * function: func_0215EBF0, func_0215EC90, func_0215ECB8, func_0215ED60
 * address:  0x0215EBF0
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02085A38  0x02085A38  arm
 *   func_0215CDD0  0x0215CDD0  arm  ov009
 *   func_0215F0D4  0x0215F0D4  arm  ov009
 *   g_021AA444     0x021AA444  data
 *   g_021A82BC     0x021A82BC  data
 *   g_021A1CD8     0x021A1CD8  data
 *   g_021AA450     0x021AA450  data
 *   func_02157640  0x02157640  arm  ov009
 *   func_02157630  0x02157630  arm  ov009
 *   func_02157280  0x02157280  arm  ov009
 *   func_02166424  0x02166424  arm  ov009
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   func_0215E84C  0x0215E84C  arm  ov009
 *   g_021AA44C     0x021AA44C  data
 *   g_021AA4B4     0x021AA4B4  data
 *   g_021AA4B8     0x021AA4B8  data
 *   func_0215E794  0x0215E794  arm  ov009
 *   func_0215EBB4  0x0215EBB4  arm  ov009
 *   func_021575DC  0x021575DC  arm  ov009
 */
#include "../../matched/include/G_CPSConfig.h"
#include "../../matched/include/G_Sock.h"
#include "../../matched/include/G_021AA4B8.h"
#include "../../matched/include/G_Socket.h"

typedef struct {
	unsigned char pad0[0x1c];
	unsigned long field1c;
} CPSConfig;

typedef struct {
	unsigned char pad0[0x1c];
	void (*func1c)(unsigned long);
	unsigned char pad1[0x08];
	int flag28;
} SOCConfig;

typedef struct Socket Socket;

extern void func_02085A38(unsigned long msec);
extern int func_0215CDD0(void);
extern void func_0215F0D4(void);
extern void func_02157640(void);
extern void func_02157630(int v);
extern void func_02157280(int v);
extern void func_02166424(void (*callback)(unsigned char *, unsigned char *, unsigned char *, long));
extern unsigned long func_02087988(void);
extern unsigned long func_0208799C(unsigned long state);
extern int func_0215E84C(int s);
extern int func_0215E794(int s);
extern void func_0215EBB4(void);
extern int func_021575DC(void);
int func_0215EBF0(void);
void func_0215EC90(void);
int func_0215ECB8(void);
int func_0215ED60(void);
extern unsigned long g_021AA444;
extern unsigned long g_021A82BC;
extern SOCConfig *g_021A1CD8;
extern struct CPSConfig g_021AA450;
extern struct Sock *g_021AA44C;
extern struct Socket *g_021AA4B4;
extern struct G_021AA4B8 *g_021AA4B8;


/*
 * sdk:      SOCL_Cleanup (libsoc.TWL.HYB.a(socl_cleanup.o))
 */
int func_0215EBF0(void)
{
	int result;

	if (g_021AA444 == 0) {
		g_021AA444 = g_021A82BC;
	}
	result = func_0215ED60();
	while (result == -26) {
		func_02085A38(100);
		result = func_0215ED60();
	}
	result = func_0215CDD0();
	if (result >= 0) {
		func_0215EC90();
		if (g_021A1CD8->flag28 == 0) {
			g_021A1CD8->func1c(g_021AA450.field1c);
		}
		g_021A1CD8 = 0;
		func_0215F0D4();
	}
	return result;
}


/*
 * sdk:      SOCLi_CleanupCPS (libsoc.TWL.HYB.a(socl_cleanup.o))
 */
void func_0215EC90(void)
{
	func_02157640();
	func_02157630(0);
	func_02157280(0);
	func_02166424(0);
}


/*
 * sdk:      SOCL_CloseAll (libsoc.TWL.HYB.a(socl_cleanup.o))
 */
int func_0215ECB8(void)
{
	unsigned long enable;
	Socket *socket;

	for (;;) {
		enable = func_02087988();
		for (socket = ((Socket *)g_021AA4B4); socket != 0; socket = socket->next) {
			if (socket != ((Socket *)g_021AA44C) && (socket->state & 0x10) == 0) {
				break;
			}
		}
		func_0208799C(enable);
		if (socket == 0) {
			break;
		}
		func_0215E84C((int)socket);
	}
	if (((Socket *)g_021AA4B4) == 0 || (((Socket *)g_021AA4B4) == ((Socket *)g_021AA44C) && g_021AA4B4->next == 0)) {
		if (((Socket *)g_021AA4B8) == 0) {
			return 0;
		}
	}
	return -26;
}


/*
 * sdk:      SOCL_CalmDown (libsoc.TWL.HYB.a(socl_cleanup.o))
 */
int func_0215ED60(void)
{
	int result;

	if ((*(int *)&g_021AA44C)) {
		result = func_0215ECB8();
		if (result == 0) {
			func_0215E84C((*(int *)&g_021AA44C));
			if (func_0215E794((*(int *)&g_021AA44C))) {
				(*(int *)&g_021AA44C) = 0;
			}
			result = -26;
		}
		func_0215EBB4();
	} else {
		if (func_021575DC() == 0) {
			result = -26;
		} else {
			result = 0;
			func_02166424(0);
		}
	}
	return result;
}
