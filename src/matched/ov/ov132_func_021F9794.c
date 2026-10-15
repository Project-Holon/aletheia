/*
 * function: func_021F9794
 * address: 0x021F9794
 * packet: pkt_ov132_021F9794
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: slots[count] = i; count++; keeps the byte store before the increment; if/else field stores preserve the shared flag-store block.
 * symbols:
 *   func_021F9A48 0x021F9A48 thumb ov132
 *   func_021FD8C4 0x021FD8C4 thumb ov132
 *   func_021F79A8 0x021F79A8 thumb ov112
 *   func_021F9AD8 0x021F9AD8 thumb ov132
 *   func_02005728 0x02005728 thumb
 *   STA_SLOT_GetCurrentKey 0x021FD9FC thumb ov132
 *   STA_SLOT_GetStateByKey 0x021FD9A0 thumb ov132
 *   STA_SLOT_ClearCurrent 0x021FDA18 thumb ov132
 *   STA_SLOT_ResetStateByKey 0x021FD9D0 thumb ov132
 *   func_021F99F4 0x021F99F4 thumb ov132
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GFL_NET_IsParentAid 0x0203D378 arm
 *   STA_SLOT_PushRecord 0x021FDA24 thumb ov132
 */
#include "../include/Obj00159.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021F9A48(char *);
extern int func_021FD8C4(void *, int);
extern void func_021F79A8(char *, char *, int);
extern void func_021F9AD8(char *p, int mode, u8 slot);
extern u32 func_02005728(u32);
extern int STA_SLOT_GetCurrentKey(char *p);
extern int STA_SLOT_GetStateByKey(void *, unsigned);
extern void STA_SLOT_ClearCurrent(unsigned char *p);
extern void STA_SLOT_ResetStateByKey(unsigned char *p, unsigned char key);
extern int func_021F99F4(char *, unsigned, unsigned);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern u32 GFL_NET_IsParentAid(void);
extern void STA_SLOT_PushRecord(void *, u32, u32, u32);
void func_021F9794(char *p)
{
    u8 count = 0;
    u8 slots[4];
    u8 i;
    int action;
    int index;
    int result;
    func_021F9A48(p);
    if (**(void ** *)&((struct Obj00159 *)p)->f30 && ((struct Obj00159 *)p)->f15C == 1) {
        if (func_021FD8C4(**(void ** *)&((struct Obj00159 *)p)->f30, (u8)((struct Obj00159 *)p)->f160) == 1)
            ((struct Obj00159 *)p)->f15C = 0;
    }
    if (!**(void ** *)&((struct Obj00159 *)p)->f30) {
        for (i = 0; i < 4; i++) {
            if (*(int *)(p + i * 4 + 0xFC) == 1) {
                func_021F79A8(*(char * *)&((struct Obj00159 *)p)->f40, *(char **)(p + i * 4 + 0x44), *(int *)(p + i * 4 + 0x10C));
                slots[count] = i;
                count++;
                *(int *)(p + i * 4 + 0xFC) = 0;
                if (*(int *)(p + i * 4 + 0x10C) == 7) *(int *)(p + i * 8 + 0x13C) = 1;
                else if (*(int *)(p + i * 4 + 0x10C) == 8) *(int *)(p + i * 8 + 0x140) = 1;
                func_021F9AD8(p, 2, i);
            }
        }
        if (count != 0) {
            if (((struct Obj00159 *)p)->f11C == 4) ((struct Obj00159 *)p)->f120 = 1;
            else ((struct Obj00159 *)p)->f120 = 0;
            ((struct Obj00159 *)p)->f11E = 180;
            ((struct Obj00159 *)p)->f11C = slots[func_02005728(count)];
            ((struct Obj00159 *)p)->f11D = *(int *)(p + ((struct Obj00159 *)p)->f11C * 4 + 0x10C);
            ((struct Obj00159 *)p)->fEC = 1;
        }
    } else {
        index = STA_SLOT_GetCurrentKey(**(void ** *)&((struct Obj00159 *)p)->f30);
        if ((unsigned)index < 4) {
            if (((struct Obj00159 *)p)->f11C == 4) ((struct Obj00159 *)p)->f120 = 1;
            else ((struct Obj00159 *)p)->f120 = 0;
            ((struct Obj00159 *)p)->f11E = 180;
            ((struct Obj00159 *)p)->f11C = index;
            ((struct Obj00159 *)p)->f11D = STA_SLOT_GetStateByKey(**(void ** *)&((struct Obj00159 *)p)->f30, index);
            ((struct Obj00159 *)p)->fEC = 1;
            STA_SLOT_ClearCurrent(**(void ** *)&((struct Obj00159 *)p)->f30);
        }
        for (i = 0; i < 4; i++) {
            action = STA_SLOT_GetStateByKey(**(void ** *)&((struct Obj00159 *)p)->f30, i);
            if (action != 10) {
                func_021F79A8(*(char * *)&((struct Obj00159 *)p)->f40, *(char **)(p + i * 4 + 0x44), action);
                STA_SLOT_ResetStateByKey(**(void ** *)&((struct Obj00159 *)p)->f30, i);
                if (action == 7) *(int *)(p + i * 8 + 0x13C) = 1;
                else if (action == 8) *(int *)(p + i * 8 + 0x140) = 1;
                func_021F9AD8(p, 2, i);
            }
        }
    }
    if (((struct Obj00159 *)p)->f11E != 0) {
        if (((struct Obj00159 *)p)->f11E > ((struct Obj00159 *)p)->f1E8) {
            ((struct Obj00159 *)p)->f11E -= (u16)((struct Obj00159 *)p)->f1E8;
            return;
        }
        ((struct Obj00159 *)p)->f11E = 0;
        if (((struct Obj00159 *)p)->f120 == 1) {
            if (!**(void ** *)&((struct Obj00159 *)p)->f30) {
                result = func_021F99F4(p, ((struct Obj00159 *)p)->f11C, ((struct Obj00159 *)p)->f11D);
                *(int *)(*(char **)(*(char * *)&((struct Obj00159 *)p)->f30 + ((struct Obj00159 *)p)->f11C * 4 + 4) + ((struct Obj00159 *)p)->f11D * 4 + 0x54) = 1;
                GFL_USE_PlaySeDefaultVolume(result);
            } else if (GFL_NET_IsParentAid() == 1) {
                result = func_021F99F4(p, ((struct Obj00159 *)p)->f11C, ((struct Obj00159 *)p)->f11D);
                if (result == 1580) STA_SLOT_PushRecord(**(void ** *)&((struct Obj00159 *)p)->f30, ((struct Obj00159 *)p)->f11C, ((struct Obj00159 *)p)->f11D, 1);
                else STA_SLOT_PushRecord(**(void ** *)&((struct Obj00159 *)p)->f30, ((struct Obj00159 *)p)->f11C, ((struct Obj00159 *)p)->f11D, 2);
            }
        }
        ((struct Obj00159 *)p)->f11C = 4;
        ((struct Obj00159 *)p)->fEC = 1;
    }
}
