/*
 * unit: yes
 * function: func_021BDF7C, func_021BE028
 * address: 0x021BDF7C
 * packet: pkt_ov099_021BDF7C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021BB42C 0x021BB42C thumb ov099
 *   func_021BB4D0 0x021BB4D0 thumb ov099
 *   func_021BB4EC 0x021BB4EC thumb ov099
 *   func_021B96CC 0x021B96CC thumb ov099
 *   func_021BE26C 0x021BE26C thumb ov099
 *   func_021C1A44 0x021C1A44 thumb ov099
 *   func_021C1AC0 0x021C1AC0 thumb ov099
 *   func_021BE384 0x021BE384 thumb ov099
 *   CLACT_DeleteRenderer 0x0204B084 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   func_021BB0B4 0x021BB0B4 thumb ov099
 *   func_021BE538 0x021BE538 thumb ov099
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   CLACT_VBlankSystem 0x0204A648 arm
 */
#include "../include/Obj00008.h"
struct Bank;
struct Node;
struct Rec;
struct WordSet;
extern void func_02030EAC(struct Node *n);
extern void func_021BB42C(void *p);
extern void func_021BB4D0(char *p);
extern void func_021BB4EC(void *p);
extern int func_021B96CC(int *p);
extern void func_021BE26C(char *p);
extern int func_021C1A44(char *p);
extern void func_021C1AC0(char *p);
extern void func_021BE384(void *p);
extern void CLACT_DeleteRenderer(void *p);
extern unsigned int CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void func_021BB0B4(char *p);
extern void func_021BE538(char *p);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern unsigned int func_0201ED04(struct WordSet *p);
typedef unsigned int   u32;
extern u32 GF_FONT_Delete(void *ptr);
extern void CLACT_VBlankSystem(void);
void func_021BDF7C(char *p)
{
    if (((struct Obj00008 *)p)->f0 != 0) func_02030EAC(((struct Obj00008 *)p)->f0);
    func_021BB42C(p);
    func_021BB4D0(p);
    func_021BB4EC(p);
    if (func_021B96CC((int *)(p + 0x274)) == 1) func_021BE26C(p);
    if (func_021C1A44(p) == 1) func_021C1AC0(p);
    func_021BE384(p + 0x898);
    CLACT_DeleteRenderer(((struct Obj00008 *)p)->f114);
    CLACT_DeleteUnit(((struct Obj00008 *)p)->f110);
    CLACT_ExitSystem();
    func_021BB0B4(p);
    func_021BE538(p);
    BMP_WIN_Exit();
    func_0203F9B4();
    MSGDATA_Delete(((struct Obj00008 *)p)->fE4);
    MSGDATA_Delete(((struct Obj00008 *)p)->fE0);
    func_0201ED04(((struct Obj00008 *)p)->fDC);
    GF_FONT_Delete(((struct Obj00008 *)p)->fEC);
    GF_FONT_Delete(((struct Obj00008 *)p)->fE8);
}
void func_021BE028(void)
{
    CLACT_VBlankSystem();
}
