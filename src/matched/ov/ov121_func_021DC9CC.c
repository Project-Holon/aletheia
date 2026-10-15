/*
 * function: MYSTERY_ALBUM_MoveHandler
 * address: 0x021DC9CC
 * packet: pkt_ov121_021DC9CC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: index read through a two-field struct, but the row field is re-read as a plain int in the cases (a different type stops the CSE across the switch); previous-cell value shifted unsigned; col declared before row for the slot order. Twin shape: ov121 021DC734.
 * note: 2026-10-05 recoup P23L5: 8 B DIFF first form (asrs for lsrs and row/col slots swapped), then EXACT. Real extent 792 B, not the 46 B of the lane list.
 * volatile: display control 04000000, window registers 04000040..4A.
 * symbols:
 *   MYSTERY_UTIL_DeleteMenuWindow 0x021D9E04 thumb ov121
 *   MYSTERY_UTIL_SetTaskHandler 0x021DA8B0 thumb ov121
 *   MYSTERY_ALBUM_SelectHandler 0x021DC08C thumb ov121
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   func_0207D658 0x0207D658 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   MYSTERY_ALBUM_SwapCards 0x021DBCC8 thumb ov121
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   MYSTERY_ALBUM_DeleteSlotActor 0x021DB938 thumb ov121
 *   MYSTERY_ALBUM_SetupSlot 0x021DB54C thumb ov121
 *   BG_SYS_PushTile 0x020409B4 arm
 *   d_021DF86E 0x021DF86E data a1
 *   d_021DF86F 0x021DF86F data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MYSTERY_UTIL_DeleteMenuWindow(u8 *);
extern void MYSTERY_UTIL_SetTaskHandler(u32 *,u32);
extern void MYSTERY_ALBUM_SelectHandler(void *,u32 *,char *);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void func_0207D658(u32,int,int);
extern void MYSTERY_ALBUM_SwapCards(struct Obj *o, u32 a, u32 b);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void MYSTERY_ALBUM_DeleteSlotActor(char *,int,u16);
extern void MYSTERY_ALBUM_SetupSlot(char *,int,int,int,u16,u16);
extern void BG_SYS_PushTile(u32);
extern u8 d_021DF86E[],d_021DF86F[];
typedef struct { u8 pad[0xAC8]; u32 row; u32 col; } Cur;
#define W(k) (*(u32 *)(p+(k)))
#define P(k) (*(u8 **)(p+(k)))
#define H(k) (*(u16 *)(p+(k)))
static inline void window0(int x,int y,int xx,int yy)
{
    *(volatile u16 *)0x04000040=((x<<8)&0xff00)|(xx&255);
    *(volatile u16 *)0x04000044=((y<<8)&0xff00)|(yy&255);
}
static inline void window1(int x,int y,int xx,int yy)
{
    *(volatile u16 *)0x04000042=((x<<8)&0xff00)|(xx&255);
    *(volatile u16 *)0x04000046=((y<<8)&0xff00)|(yy&255);
}
static inline void inside0(int planes,int effect)
{
    u32 v=(*(volatile u16 *)0x04000048&~0x3f)|(u32)planes;
    if(effect) v|=32;
    *(volatile u16 *)0x04000048=v;
}
static inline void inside1(int planes,int effect)
{
    u32 v=(*(volatile u16 *)0x04000048&~0x3f00)|((u32)planes<<8);
    if(effect) v|=32<<8;
    *(volatile u16 *)0x04000048=v;
}
static inline void outside(int planes,int effect)
{
    u32 v=(*(volatile u16 *)0x0400004a&~0x3f)|(u32)planes;
    if(effect) v|=32;
    *(volatile u16 *)0x0400004a=v;
}
void MYSTERY_ALBUM_MoveHandler(void *task,u32 *state,char *p)
{
    u32 index=((Cur *)p)->col+((Cur *)p)->row*4;
    int here,there,mask;
    int x,y;
    u8 now,old;
    int col,row;
    switch(*state) {
    case 0:
        if(P(0xabc)) {MYSTERY_UTIL_DeleteMenuWindow(P(0xabc));P(0xabc)=0;}
        W(0xae0)=0;
        if(index==H(0xade)) {
            CLACT_SetActorDrawEnable((struct Obj *)P(0xaf0),0);
            MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_ALBUM_SelectHandler);
            return;
        }
        *state=1;break;
    case 1:
        now=index&3;
        old=H(0xade)%4;
        here=((*(int *)(p+0xac8))==(index>>2));
        there=((*(int *)(p+0xac8))==((u32)H(0xade)>>2));
        mask=0;if(here) mask|=1;if(there) mask|=2;
        *(volatile u32 *)0x04000000=(*(volatile u32 *)0x04000000&~0xe000)|(mask<<13);
        if(here) {
            x=d_021DF86E[now*8];y=d_021DF86F[now*8];
            inside0(30,1);window0(x*8,y*8,(x+12)*8,(y+7)*8);
        }
        if(there) {
            x=d_021DF86E[old*8];y=d_021DF86F[old*8];
            inside1(30,1);window1(x*8,y*8,(x+12)*8,(y+7)*8);
        }
        outside(30,0);*state=2;break;
    case 2:
        func_0207D658(0x04000050,30,W(0xae8)*16/30);
        if(W(0xae8)++>30) {W(0xae8)=0;*state=3;}break;
    case 3:
        MYSTERY_ALBUM_SwapCards((struct Obj *)p,index,H(0xade));GFL_USE_PlaySeDefaultVolume(0x670);
        row=(u32)H(0xade)>>2;col=H(0xade)%4;
        there=((*(int *)(p+0xac8))==row);
        here=((*(int *)(p+0xac8))==(index>>2));
        if(here) {
            MYSTERY_ALBUM_DeleteSlotActor(p,1,W(0xacc));
            MYSTERY_ALBUM_SetupSlot(p,1,0,(*(int *)(p+0xac8)),W(0xacc),H(36));
        }
        if(there) {
            MYSTERY_ALBUM_DeleteSlotActor(p,1,col);
            MYSTERY_ALBUM_SetupSlot(p,1,0,row,col,H(36));
        }
        BG_SYS_PushTile(3);W(0xa78)=1;*state=4;break;
    case 4:
        func_0207D658(0x04000050,30,16-W(0xae8)*16/30);
        if(W(0xae8)++>30) {W(0xae8)=0;*state=5;}break;
    case 5:*(volatile u32 *)0x04000000 &=~0xe000;*state=6;break;
    case 6:
        W(0xae0)=0;CLACT_SetActorDrawEnable((struct Obj *)P(0xaf0),0);
        if(P(0xabc)) {MYSTERY_UTIL_DeleteMenuWindow(P(0xabc));P(0xabc)=0;}
        MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_ALBUM_SelectHandler);break;
    }
}
