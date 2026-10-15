/*
 * function: INTRO_GRAPHIC_Delete
 * address: 0x021BDAE4
 * packet: pkt_ov204_021BDAE4
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   INTRO_PARTICLE_Delete 0x021BFCD0 thumb ov204
 *   INTRO_MCSS_Delete 0x021BF5E0 thumb ov204
 *   INTRO_G3D_Delete 0x021BF9D0 thumb ov204
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   INTRO_CMD_Delete 0x021BEF74 thumb ov204
 *   INTRO_GRAPHIC_DeleteDisplay 0x021BDCF0 thumb ov204
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov067_id 0x00000043 data
 */
#include "../include/Obj03918.h"
struct Rec; struct Proc;
extern void INTRO_PARTICLE_Delete(char *);
typedef unsigned char  u8;
extern void INTRO_MCSS_Delete(u8 *p);
extern void INTRO_G3D_Delete(char *);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
typedef unsigned int   u32;
extern u32 GF_FONT_Delete(void *ptr);
extern void INTRO_CMD_Delete(u8 *p);
extern void INTRO_GRAPHIC_DeleteDisplay(unsigned char *);
extern void func_020315D4(struct Proc *);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
typedef signed int     s32;
extern void func_02034A5C(s32 handle);
extern const char ov067_id[];
int INTRO_GRAPHIC_Delete(struct Proc *owner, int unused1, int unused2, char *p)
{
    unsigned short heap;
    INTRO_PARTICLE_Delete(*(char * *)&((struct Obj03918 *)p)->f20);
    INTRO_MCSS_Delete((u8 *)(*(char * *)&((struct Obj03918 *)p)->f18));
    INTRO_G3D_Delete(*(char * *)&((struct Obj03918 *)p)->f1C);
    MSGDATA_Delete(*(struct Rec * *)&((struct Obj03918 *)p)->f10);
    GF_FONT_Delete(((struct Obj03918 *)p)->fC);
    INTRO_CMD_Delete((u8 *)(*(char * *)&((struct Obj03918 *)p)->f14));
    INTRO_GRAPHIC_DeleteDisplay(*(unsigned char * *)&((struct Obj03918 *)p)->f8);
    heap = ((struct Obj03918 *)p)->f0;
    func_020315D4(owner);
    GFL_HEAP_DeleteChecked((unsigned)heap);
    func_02034A5C((unsigned)ov067_id);
    return 1;
}
