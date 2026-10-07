/*
 * file:     unit_0216AB20_p08.c
 * unit:     yes
 * function: func_0216BEA4, func_0216BF38, func_0216BF98
 * address:  0x0216BEA4
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
 *   g_021AA878  0x021AA878  data
 *   func_02059F38  0x02059F38  arm
 *   func_0216BAF4  0x0216BAF4  arm  ov009
 *   func_02176410  0x02176410  arm  ov009
 *   func_0216C230  0x0216C230  arm  ov009
 *   func_02195DC4  0x02195DC4  arm  ov009
 *   func_0216BC84  0x0216BC84  arm  ov009
 *   func_0216909C  0x0216909C  arm  ov009
 */
#include "../../matched/include/G_DwcGlobal.h"

struct GTI2Connection;
typedef struct DwcState {
	unsigned char pad0[0x24];
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

extern int func_02059F38(void);
extern int func_0216BAF4(int aid);
extern char *func_02176410(unsigned char aid);
extern void func_0216C230(struct GTI2Connection *connection, int reason, int isPseudClose, unsigned char closeAid);
extern void func_02195DC4(int conn);
extern void func_0216BC84(int state);
extern void func_0216909C(void);
int func_0216BEA4(unsigned char aid);
void func_0216BF38(int error, int profileID);
void DWCi_UpdateServersCallback(int error, int isChanged);
extern struct DwcGlobal g_021AA878;


/*
 * DWCi_CloseConnectionHard: closes an aid's connection, or runs the closed path for a node with none.
 */
int func_0216BEA4(unsigned char aid)
{
    int conn;
    unsigned char *node;

    if (*(char **)(((char *)&g_021AA878) + 4) == 0 || func_02059F38() != 0 ||
        (*(int *)(*(char **)(((char *)&g_021AA878) + 4) + 0x24) != 4 &&
         *(int *)(*(char **)(((char *)&g_021AA878) + 4) + 0x24) != 5)) {
        return -1;
    }
    conn = func_0216BAF4(aid);
    if (conn == 0) {
        node = (unsigned char *)func_02176410(aid);
        if (node == 0) {
            return -2;
        }
        func_0216C230(0, 0, 1, node[0x16]);
        return 0;
    }
    func_02195DC4(conn);
    return 0;
}


void func_0216BF38(int error, int profileID)
{
	if (error == 0) {
		((DwcState *)g_021AA878.st)->profileID = profileID;
		func_0216BC84(3);
		func_0216909C();
	} else {
		func_0216BC84(0);
	}
	if (((DwcState *)g_021AA878.st)->loginCallback != 0)
		((DwcState *)g_021AA878.st)->loginCallback(error, profileID, ((DwcState *)g_021AA878.st)->loginParam);
}


void DWCi_UpdateServersCallback(int error, int isChanged)
{
    char *p = *(char **)(((char *)&g_021AA878) + 4);

    ((void (*)(int, int, int))*(void **)(p + 0x78))(error, isChanged,
        *(int *)(p + 0x7c));
}
