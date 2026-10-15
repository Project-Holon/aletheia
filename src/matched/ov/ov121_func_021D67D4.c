/*
 * function: func_021D67D4
 * address: 0x021D67D4
 * packet: pkt_ov121_021D67D4
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D9228 0x021D9228 thumb ov121
 *   MYSTERY_NET_Delete 0x021DE2F0 thumb ov121
 *   func_021D9E04 0x021D9E04 thumb ov121
 *   func_021DA890 0x021DA890 thumb ov121
 *   func_021D6C28 0x021D6C28 thumb ov121
 *   func_021D6948 0x021D6948 thumb ov121
 *   func_021D96C4 0x021D96C4 thumb ov121
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   OS_ResetSystem 0x02087BCC arm
 *   func_02034A5C 0x02034A5C arm
 *   ov_id 0x00000072 data
 *   GFL_USE_CancelChangeAndStopBgm  0x02005D28  thumb  arm9
 *   GAME_DATA_Delete  0x02012704  thumb  arm9
 *   MYSTERY_DATA_Delete  0x0200A338  thumb  arm9
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb  arm9
 */
#include "../include/Obj02176.h"
extern void func_021D9228(void *);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct PrintSys;
struct Rec;
struct S020315D4;
struct WordSet;
extern void MYSTERY_NET_Delete(u8 *p);
extern void func_021D9E04(u8 *p);
extern void func_021DA890(void *);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void func_021D6C28(u8 *p);
extern void func_021D6948(void *);
extern void func_021D96C4(u8 *p);
extern void MYSTERY_DATA_Delete(void *);
extern void GAME_DATA_Delete(u8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int);
extern void OS_ResetSystem(u32 parameter);
extern void func_02034A5C(int);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern char ov_id[];
int func_021D67D4(void *a, int b, int c, char *p)
{
    func_021D9228(p + 0x138);
    MYSTERY_NET_Delete(((struct Obj02176 *)p)->f3B0);
    if (((struct Obj02176 *)p)->f284) func_021D9E04(((struct Obj02176 *)p)->f284);
    func_021DA890(((struct Obj02176 *)p)->f290);
    func_0201ED04(((struct Obj02176 *)p)->f3A8);
    MSGDATA_Delete(((struct Obj02176 *)p)->f3A0);
    MSGDATA_Delete(((struct Obj02176 *)p)->f3A4);
    PRINTSYS_QUE_Delete(((struct Obj02176 *)p)->f39C);
    GF_FONT_Delete(((struct Obj02176 *)p)->f398);
    func_021D6C28((u8 *)(p + 0x294));
    func_021D6948(p + 0x390);
    func_021D96C4(((struct Obj02176 *)p)->f394);
    MYSTERY_DATA_Delete(((struct Obj02176 *)p)->f3BC);
    GAME_DATA_Delete(((struct Obj02176 *)p)->f3B8);
    func_020315D4(a);
    func_020306F0(29);
    OS_ResetSystem(0);
    func_02034A5C((int)ov_id);
    GFL_USE_CancelChangeAndStopBgm();
    return 1;
}
