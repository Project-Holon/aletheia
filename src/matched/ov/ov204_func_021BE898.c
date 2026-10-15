/*
 * function: func_021BE898
 * address: 0x021BE898
 * packet: pkt_ov204_021BE898
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: load the case-2 object once before q[1]'s comparison and reuse
 *   it in both arms; repeated arm loads gave 220 bytes/80 different.
 * symbols:
 *   INTRO_G3D_SetAnimMode 0x021BFAE8 thumb ov204
 *   INTRO_G3D_UpdateAnimMode 0x021BFB2C thumb ov204
 *   KEY_GetTrg 0x020362DC arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_0200854C 0x0200854C thumb
 */
#include "../include/Obj03920.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void INTRO_G3D_SetAnimMode(char *,u32);
extern int INTRO_G3D_UpdateAnimMode(char *);
extern u32 KEY_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(u32);
struct Sub0200852CObj;
extern void func_0200854C(struct Sub0200852CObj *obj, u8 value);
int func_021BE898(char *p,u32 *q)
{
    void *obj;
    switch (*q) {
    case 0:
        INTRO_G3D_SetAnimMode(*(char * *)&((struct Obj03920 *)p)->fC,0);
        *q=4;
        break;
    case 1:
        if (KEY_GetTrg()&16) {
            if (q[1]!=1) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                INTRO_G3D_SetAnimMode(*(char * *)&((struct Obj03920 *)p)->fC,2);
                q[1]=1;
                *q=4;
            }
        } else if (KEY_GetTrg()&32) {
            if (q[1]!=0) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                INTRO_G3D_SetAnimMode(*(char * *)&((struct Obj03920 *)p)->fC,1);
                q[1]=0;
                *q=4;
            }
        } else if (KEY_GetTrg()&1) {
            GFL_USE_PlaySeDefaultVolume(0x54D);
            (*q)++;
        }
        break;
    case 2:
        obj=**(void ** *)&((struct Obj03920 *)p)->f4;
        if (q[1]==0) {
            func_0200854C(obj,0);
            INTRO_G3D_SetAnimMode(*(char * *)&((struct Obj03920 *)p)->fC,3);
        } else {
            func_0200854C(obj,1);
            INTRO_G3D_SetAnimMode(*(char * *)&((struct Obj03920 *)p)->fC,4);
        }
        (*q)++;
        break;
    case 3:
        if (INTRO_G3D_UpdateAnimMode(*(char * *)&((struct Obj03920 *)p)->fC)!=0) return 1;
        break;
    case 4:
        if (INTRO_G3D_UpdateAnimMode(*(char * *)&((struct Obj03920 *)p)->fC)!=0) *q=1;
        break;
    }
    return 0;
}
