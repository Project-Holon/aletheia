/*
 * function: MYSTERY_ALBUM_SetupTask
 * address: 0x021DE024
 * packet: pkt_ov121_021DE024
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding after the return.
 * symbols:
 *   MYSTERY_ALBUM_LoadBgWithTilemap 0x021DDC58 thumb ov121
 *   MYSTERY_ALBUM_LoadBgPalette 0x021DDCF8 thumb ov121
 *   MYSTERY_ALBUM_SetupIcons 0x021DDD64 thumb ov121
 *   func_021DA4A8 0x021DA4A8 thumb ov121
 *   func_021DA318 0x021DA318 thumb ov121
 *   func_02040588 0x02040588 arm
 */
#include "../include/Obj01931.h"
#include "../include/Obj22910.h"
#include "../include/Obj22911.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void MYSTERY_ALBUM_LoadBgWithTilemap(const unsigned *,void *,u16);
extern void MYSTERY_ALBUM_LoadBgPalette(unsigned *,void *,u16);
typedef unsigned int   u32;
extern void MYSTERY_ALBUM_SetupIcons(char *p, char *q, u16 heap);
extern void func_021DA4A8(u8 *p);
extern void func_021DA318(u8 *p);
extern void func_02040588(unsigned char which, unsigned char enable);
void MYSTERY_ALBUM_SetupTask(void *unused,char *p)
{
    if (((struct Obj01931 *)p)->f12C) return;
    ((struct Obj01931 *)p)->f12C=1;
    switch (((struct Obj01931 *)p)->f130) {
    case 0: MYSTERY_ALBUM_LoadBgWithTilemap((unsigned *)(*(char * *)&((struct Obj01931 *)p)->f11C+0xa0),p,((struct Obj01931 *)p)->f118); break;
    case 1: MYSTERY_ALBUM_LoadBgPalette((unsigned *)(*(char * *)&((struct Obj01931 *)p)->f11C+0xa0),p,((struct Obj01931 *)p)->f118); break;
    }
    MYSTERY_ALBUM_SetupIcons(p,((struct Obj01931 *)p)->f11C,((struct Obj01931 *)p)->f118);
    func_021DA4A8(((struct Obj01931 *)p)->f144);
    func_021DA318(**(void ** *)&((struct Obj01931 *)p)->f11C);
    func_02040588((u8)(((struct Obj22910 *)(*(char * *)&((struct Obj01931 *)p)->f11C))->f96),(int)1);
    func_02040588((u8)(((struct Obj22911 *)(*(char * *)&((struct Obj01931 *)p)->f11C))->f94),(int)1);
}
