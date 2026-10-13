/*
 * file:     scenesetselectway_1.c
 * function: DWCi_SceneSetSelectWay
 * address:  0x021CC998
 * packet:   pkt_ov016_021CC998
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SceneSetSelectWay (libdwcutil.TWL.HYB.a scenesetselectwa)
 * symbols:
 *   DWCi_SETTIGNlGet                 0x021CF404  arm
 *   DWCi_Language                    0x021C0EC8  arm
 *   initGraphics                     0x021CCAC0  arm   ov016
 *   DWCi_HLlLoadSet                  0x021BD6D4  arm
 *   DWCi_COMMENTlDispEx              0x021BD060  arm
 *   DWCi_CMNlStep                    0x021BD214  arm
 *   DWCi_Flag                        0x021C0EF0  arm
 *   DWCi_FOCUSlDisp4                 0x021BD4C8  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   g_021DE614                       0x021DE614  data
 *   g_021DA7D8                       0x021DA7D8  data
 *   g_021DA858                       0x021DA858  data
 *   g_021DA85C                       0x021DA85C  data
 *   g_021DA85A                       0x021DA85A  data
 *   g_021DA85E                       0x021DA85E  data
 *   procInit                         0x021CCBA4  arm   ov016
 */

#include "../../matched/include/G_FocusState.h"
#include "../../matched/include/G_021DA85C.h"
#include "../../matched/include/G_tagRECT4.h"
#include "../../matched/include/G_021DA85E.h"

typedef _Bool bool;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

struct tagSETTINGINFO {
    u8 pad[0xf4];
    u8 page;
};

extern struct FocusState g_021DE614;
extern s8 g_021DA7D8[7];
extern struct tagRECT4 g_021DA858[4][4];
extern struct G_021DA85C g_021DA85C[4][4];
extern struct tagRECT4 g_021DA85A[4][4];
extern struct G_021DA85E g_021DA85E[4][4];

extern struct tagSETTINGINFO *DWCi_SETTIGNlGet(void);
extern int DWCi_Language(void);
extern void DWCi_HLlLoadSet(void);
extern bool DWCi_COMMENTlDispEx(int messageId, int n, int num);
extern void DWCi_CMNlStep(int step);
extern bool DWCi_Flag(unsigned long flag);
extern void DWCi_FOCUSlDisp4(int x0, int x1, int y0, int y1);
extern void DWCi_ChangeScene(void (*scene)());

static void initGraphics(void);
static void procInit(void);

void DWCi_SceneSetSelectWay(void)
{
    struct tagSETTINGINFO *info;

    info = DWCi_SETTIGNlGet();
    g_021DE614.flag = 0;
    if (g_021DE614.last == 0)
        g_021DE614.last = 1;
    if (DWCi_Language() != 0) {
        if (g_021DE614.cur == 2)
            g_021DE614.cur = 0;
        if (g_021DE614.last == 2)
            g_021DE614.last = 1;
    }
    initGraphics();
    DWCi_HLlLoadSet();
    DWCi_COMMENTlDispEx(0x32, g_021DA7D8[DWCi_Language()], info->page + 1);
    DWCi_CMNlStep(1);
    DWCi_FOCUSlDisp4(g_021DA858[DWCi_Flag(1)][g_021DE614.cur].v[0],
                     g_021DA85C[DWCi_Flag(1)][g_021DE614.cur].v[0],
                     g_021DA85A[DWCi_Flag(1)][g_021DE614.cur].v[0],
                     g_021DA85E[DWCi_Flag(1)][g_021DE614.cur].v[0]);
    DWCi_ChangeScene(procInit);
}
