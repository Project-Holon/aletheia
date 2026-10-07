/*
 * file:     unit_0216AB20_p04.c
 * unit:     yes
 * function: func_0216B804, func_0216B838, func_0216B880, func_0216B908, func_0216B94C, func_0216B994, func_0216B9B0, func_0216BA08, func_0216BA4C, func_0216BAF4, func_0216BB54
 * address:  0x0216B804
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
 *   func_0216C82C  0x0216C82C  arm  ov009
 *   func_0217603C  0x0217603C  arm  ov009
 *   g_021AA878     0x021AA878  data
 *   func_021763AC  0x021763AC  arm  ov009
 *   g_021AA880  0x021AA880  data
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_0217637C  0x0217637C  arm  ov009
 *   func_0216BCD0  0x0216BCD0  arm  ov009
 *   func_02176410  0x02176410  arm  ov009
 *   func_021685CC  0x021685CC  arm  ov009
 *   func_02198620  0x02198620  arm  ov009
 *   func_02195AB4  0x02195AB4  arm  ov009
 *   func_0216BE00  0x0216BE00  arm  ov009
 *   func_02195B20  0x02195B20  arm  ov009
 *   func_02195E68  0x02195E68  arm  ov009
 *   func_0216C7A8  0x0216C7A8  arm  ov009
 *   func_0216E5B0  0x0216E5B0  arm  ov009
 *   func_0216E4C0  0x0216E4C0  arm  ov009
 *   g_021AA8A0  0x021AA8A0  data
 *   func_02195E78  0x02195E78  arm  ov009
 */
#include "../../matched/include/G_DwcGlobal.h"

typedef struct DwcState {
	void *gt2Socket;
	unsigned char pad0a[0x10];
	int outSize;
	int inSize;
	unsigned char pad0[0x8];
	int state;
	unsigned char pad1[0x3c];
	int profileID;
	unsigned char pad2[0x8];
	void (*loginCallback)(int, int, void *);
	void *loginParam;
	void *updateCallback;
	void *updateParam;
	unsigned char pad3[0x58];
	unsigned char updateBuf0[0x100];
	unsigned char updateBuf1[0x100];
} DwcState;

typedef struct DwcGlobal DwcGlobal;

extern int func_0216C82C(void);
extern int func_0217603C(void);
extern char *func_021763AC(int pid);
extern void MI_CpuFill8(void *p, int v, int n);
extern unsigned char *func_0217637C(int index);
extern int func_0216BCD0(unsigned char *p, int n);
extern char *func_02176410(unsigned char aid);
extern unsigned long func_021685CC(unsigned long max);
extern char *func_02198620(unsigned int ip, unsigned short port, char *string);
extern int func_02195AB4(void **socket, char *localAddress, int outgoingBufferSize, int incomingBufferSize, void *callback);
extern int func_0216BE00(int result);
extern void func_02195B20(int *p, int v);
extern void func_02195E68(int *p, int v);
extern void func_0216C7A8(void *socket);
extern void func_0216E5B0();
extern int func_0216E4C0(int unused, unsigned int ip, unsigned short port, unsigned char *message, int len);
extern int func_02195E78(const int *p);
int DWC_GetNumConnectionHost(void);
unsigned char func_0216B838(void);
int func_0216B880(unsigned char **out);
int func_0216B908(void);
int func_0216B94C(unsigned char aid);
int func_0216B994(void);
unsigned char func_0216B9B0(void);
int func_0216BA08(void);
int func_0216BA4C(void);
int func_0216BAF4(int aid);
int func_0216BB54(const int *a0);
extern struct DwcGlobal g_021AA878;
extern unsigned char g_021AA880[];
extern int g_021AA8A0[];


int DWC_GetNumConnectionHost(void)
{
    int num;

    if (*(char **)(((char *)&g_021AA878) + 4) == 0 || func_0216C82C() == 0) {
        num = 0;
    } else {
        num = func_0217603C();
    }
    return num;
}


/*
 * DWC_GetMyAID: this host's aid, or 0xff when none is valid.
 */
unsigned char func_0216B838(void)
{
    unsigned char *node;

    if (*(char **)(((char *)&g_021AA878) + 4) == 0 || func_0216C82C() == 0) {
        return 0xff;
    }
    node = (unsigned char *)func_021763AC(*(int *)(*(char **)(((char *)&g_021AA878) + 4) + 0x64));
    if (node == 0) {
        return 0xff;
    }
    return node[0x16];
}


/*
 * DWC_GetAIDList: fills the static aid list from the node list and returns the node count.
 */
int func_0216B880(unsigned char **out)
{
    int i;

    if (*(int *)(((char *)&g_021AA878) + 4) == 0 || func_0216C82C() == 0) {
        return 0;
    }
    MI_CpuFill8(g_021AA880, 0, 0x20);
    for (i = 0; i < func_0217603C(); i++) {
        g_021AA880[i] = func_0217637C(i)[0x16];
    }
    *out = g_021AA880;
    return func_0217603C();
}


/*
 * DWC_GetAIDBitmap: the bitmap of every aid in the current node list.
 */
int func_0216B908(void)
{
    unsigned char *list;
    int n;

    if (*(int *)(((char *)&g_021AA878) + 4) == 0 || func_0216C82C() == 0) {
        return 0;
    }
    n = func_0216B880(&list);
    return func_0216BCD0(list, n);
}


/*
 * sdk:      DWC_IsValidAID (libdwcmatch.TWL.HYB.a(dwc_main.o))
 */
int func_0216B94C(unsigned char aid)
{
	if (*(int *)(((char *)&g_021AA878) + 4) == 0)
		return 0;
	if (aid == func_0216B838())
		return 0;
	if (func_02176410(aid))
		return 1;
	return 0;
}


int func_0216B994(void)
{
    int *p = *(int **)(((char *)&g_021AA878) + 4);

    return p != 0 ? *(int *)((char *)p + 0x24) : 0;
}


/*
 * DWC_GetServerAID: the aid of node 0 while a match is running, else 0xff.
 */
unsigned char func_0216B9B0(void)
{
    char *p = *(char **)(((char *)&g_021AA878) + 4);
    unsigned char *node;

    if (p == 0 || *(int *)(p + 0x96c) == 0 || *(int *)(p + 0x96c) == 9 ||
        *(int *)(p + 0x96c) == 10 || *(int *)(p + 0x96c) == 11 ||
        *(unsigned char *)(p + 0x35d) == 0 || *(unsigned char *)(p + 0x366) == 0) {
        return 0xff;
    }
    node = (unsigned char *)func_0217637C(0);
    if (node == 0) {
        return 0xff;
    }
    return node[0x16];
}


int func_0216BA08(void)
{
    if (*(char **)(((char *)&g_021AA878) + 4) == 0) {
        return 0;
    }
    if (func_0216B9B0() == 0xff) {
        return 0;
    }
    return *(unsigned char *)(*(char **)(((char *)&g_021AA878) + 4) + 0x366) == 2;
}


/*
 * sdk:      DWCi_GT2Startup (libdwcmatch.TWL.HYB.a(dwc_main.o))
 */
int func_0216BA4C(void)
{
	int gt2Result;
	unsigned short baseport;

	if (((DwcState *)g_021AA878.st)->gt2Socket != 0)
		return 0;
	baseport = func_021685CC(0x4000) + 0xc000;
	gt2Result = func_02195AB4(&((DwcState *)g_021AA878.st)->gt2Socket, func_02198620(0, baseport, 0), ((DwcState *)g_021AA878.st)->outSize, ((DwcState *)g_021AA878.st)->inSize, func_0216C7A8);
	if (func_0216BE00(gt2Result))
		return gt2Result;
	func_02195B20(((DwcState *)g_021AA878.st)->gt2Socket, (int)func_0216E5B0);
	func_02195E68(((DwcState *)g_021AA878.st)->gt2Socket, (int)func_0216E4C0);
	return gt2Result;
}


/*
 * DWCi_GetGT2Connection: the connection whose aid matches, or zero.
 */
int func_0216BAF4(int aid)
{
    int i;

    if (*(int *)(((char *)&g_021AA878) + 4) == 0) {
        return 0;
    }
    for (i = 0; i < 0x20; i++) {
        if (g_021AA8A0[i] != 0 && aid == ((unsigned char *)func_02195E78((const int *)g_021AA8A0[i]))[1]) {
            return g_021AA8A0[i];
        }
    }
    return 0;
}


/*
 * Byte at +1 of the block, or 0xff when there is none.
 */
int func_0216BB54(const int *a0)
{
    unsigned char *p = (unsigned char *)func_02195E78(a0);

    return p ? *(unsigned char *)(p + 1) : 0xff;
}
