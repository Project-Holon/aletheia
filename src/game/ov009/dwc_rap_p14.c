/*
 * file:     dwc_rap_p14.c
 * unit:     yes
 * function: func_021563D0, func_021563EC, func_02156400
 * address:  0x021563D0
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021A8264  0x021A8264  data
 *   func_021AF13C  0x021AF13C  thumb  ov013
 *   d_021A8264 0x021A8264 data ov009 a4
 *   func_021AF1A0 0x021AF1A0 thumb ov013
 */
#include "../../matched/include/Obj18651.h"
#include "../../matched/include/G__anon_Work.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern void func_021AF1A0(void);
void func_021563D0(void);
int func_021563EC(void);
void func_02156400(void);
extern char *d_021A8264;


/*
 * Calls the ov013 routine when the word at +0x76c of the module pointer is set.
 */
void func_021563D0(void)
{
    extern struct _anon_Work *g_021A8264;
    void func_021AF13C(void);
    if (((struct Obj18651 *)((char *)g_021A8264))->f76C) func_021AF13C();
}

/*
 * Unlabelled accessor blocking owned ov099 caller 021BFDA8.
 */
int func_021563EC(void) {
 return *(int *)(d_021A8264+0x76c);
}

void func_02156400(void)
{
    func_021AF1A0();
    if (d_021A8264) {
        *(int *)(d_021A8264 + 0x76C) = 0;
        *(int *)(d_021A8264 + 0x768) = 0;
        *(u16 *)(d_021A8264 + 0x794) = 0;
    }
}
