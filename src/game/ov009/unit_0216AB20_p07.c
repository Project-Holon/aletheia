/*
 * file:     unit_0216AB20_p07.c
 * unit:     yes
 * function: DWCi_GT2SocketErrorCallback, func_0216C7E0, func_0216C800, func_0216C82C
 * address:  0x0216C7A8
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
 *   func_02195E60  0x02195E60  arm  ov009
 *   func_0217ED54  0x0217ED54  arm  ov009
 *   func_02059F54  0x02059F54  arm
 *   g_021AA878     0x021AA878  data
 *   func_0216B9B0  0x0216B9B0  arm  ov009
 *   func_0217637C  0x0217637C  arm  ov009
 */
#include "../../matched/include/G_DwcGlobal.h"

extern int func_02195E60(const int *p);
extern int func_0217ED54(void);
extern void func_02059F54(int error, int errorCode);
extern unsigned char func_0216B9B0(void);
extern char *func_0217637C(int index);
void DWCi_GT2SocketErrorCallback(void *socket);
/* * Writes the mode byte at +0x365 and clears the word at +0xae8 of the * current object. */ void func_0216C7E0(unsigned char v);
unsigned char DWCi_GetServerOrSubServerAID(void);
/* * 1 unless the current object is in mode 2 (always 1) or carries a zero * byte at +0x35d with a mode other than 2. */ int func_0216C82C(void);
extern char g_021AA878[];


void DWCi_GT2SocketErrorCallback(void *socket)
{
    func_02195E60(socket);
    *(int *)g_021AA878 = func_0217ED54();
    func_02059F54(9, (int)0xfffe8515);
    *(int *)(*(char **)(g_021AA878 + 4)) = 0;
}



/*
 * Writes the mode byte at +0x365 and clears the word at +0xae8 of the
 * current object.
 */
void func_0216C7E0(unsigned char v)
{
    char *p = *(char **)(((char *)&g_021AA878) + 4);

    *(unsigned char *)(p + 0x365) = v;
    p = *(char **)(((char *)&g_021AA878) + 4);
    *(int *)(p + 0xae8) = 0;
}



unsigned char DWCi_GetServerOrSubServerAID(void)
{
    unsigned char aid = func_0216B9B0();
    if (aid == 0xff) {
        char *info = func_0217637C(0);
        if (info != 0) aid = info[0x16];
    }
    return aid;
}



/*
 * 1 unless the current object is in mode 2 (always 1) or carries a zero
 * byte at +0x35d with a mode other than 2.
 */
int func_0216C82C(void)
{
    int r = 1;
    char *p = *(char **)(((char *)&g_021AA878) + 4);

    if (*(unsigned char *)(p + 0x365) != 2)
        if (*(unsigned char *)(p + 0x35d) == 0) r = 0;
    return r;
}
