/*
 * function: MYSTERY_ALBUM_Update
 * address: 0x021DAEF0
 * packet: pkt_ov121_021DAEF0
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: index field reread at 021DAF26 and 021DAF30 with no intervening store.
 * symbols:
 *   MYSTERY_UTIL_DispatchTask 0x021DA898 thumb ov121
 *   MYSTERY_ALBUM_UpdateSlotWork 0x021DD240 thumb ov121
 *   MYSTERY_ALBUM_ResetIntro 0x021DDF84 thumb ov121
 *   MYSTERY_ALBUM_IsEntryValid 0x021DBF04 thumb ov121
 *   MYSTERY_ALBUM_RequestSetup 0x021DE0AC thumb ov121
 *   MYSTERY_ALBUM_HideScreen 0x021DE0DC thumb ov121
 *   MYSTERY_ALBUM_UpdateIconSprite 0x021DCFA4 thumb ov121
 */
#include "../include/Obj01153.h"
typedef unsigned short u16;
typedef struct Item { char raw[0xdc]; } Item;
typedef struct Obj { char pad[0x28]; Item items[12]; char tail[0xacc-0x28-12*0xdc]; volatile int index; } Obj;
extern void MYSTERY_UTIL_DispatchTask(char *);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int MYSTERY_ALBUM_UpdateSlotWork(void **p);
extern void MYSTERY_ALBUM_ResetIntro(char *);
extern int MYSTERY_ALBUM_IsEntryValid(int *p);
extern void MYSTERY_ALBUM_RequestSetup(u8 *p, u32 b);
extern void MYSTERY_ALBUM_HideScreen(char *p);
extern void MYSTERY_ALBUM_UpdateIconSprite(u8 *p, int b, int c, u16 d);
void MYSTERY_ALBUM_Update(Obj *obj)
{
    char *p=(char *)obj;
    int flag;
    u16 old;
    int angle;
    MYSTERY_UTIL_DispatchTask(*(char * *)&((struct Obj01153 *)p)->fAC4);
    MYSTERY_ALBUM_UpdateSlotWork(((struct Obj01153 *)p)->fAB0);
    if(((struct Obj01153 *)p)->fA78) {
        flag=0;
        if(*(char * *)&((struct Obj01153 *)p)->fAAC) {
            MYSTERY_ALBUM_ResetIntro(*(char * *)&((struct Obj01153 *)p)->fAAC);
            *(char * *)&((struct Obj01153 *)p)->fAAC=0;
        }
        if(obj->index<4 && MYSTERY_ALBUM_IsEntryValid((int *)(&obj->items[obj->index+((struct Obj01153 *)p)->fAC8*4]))) {
            flag=1;
            MYSTERY_ALBUM_RequestSetup(*(void **)(p+0xa7c+(((struct Obj01153 *)p)->fACC+((struct Obj01153 *)p)->fAC8*4)*4),1);
        }
        if(flag==0) MYSTERY_ALBUM_HideScreen(((struct Obj01153 *)p)->fAB0);
        ((struct Obj01153 *)p)->fA78=0;
    }
    old=((struct Obj01153 *)p)->fBAC;
    angle=old+0x400;
    if(angle>=0x10000)
        ((struct Obj01153 *)p)->fBAC=old-0xfc00;
    else
        ((struct Obj01153 *)p)->fBAC=angle;
    MYSTERY_ALBUM_UpdateIconSprite((u8 *)(p+0xbae),14,0,((struct Obj01153 *)p)->fBAC);
    MYSTERY_ALBUM_UpdateIconSprite((u8 *)(p+0xc0e),14,2,((struct Obj01153 *)p)->fBAC);
}
