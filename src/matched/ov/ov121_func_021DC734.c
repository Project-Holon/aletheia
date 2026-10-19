/*
 * function: MYSTERY_ALBUM_InfoHandler
 * address: 0x021DC734
 * packet: pkt_ov121_021DC734
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: int coordinate locals retain table loads before SDK window plane writes; u8 locals were 4 bytes short.
 * volatile: display control 021DC82C/838/950/958; window registers 021DC84E..892.
 * symbols:
 *   MYSTERY_UTIL_SetMenuMessage 0x021D9F08 thumb ov121
 *   MYSTERY_UTIL_GetMenuState 0x021D9FF8 thumb ov121
 *   MYSTERY_UTIL_CreateMenu 0x021DA038 thumb ov121
 *   MYSTERY_UTIL_UpdateMenu 0x021DA178 thumb ov121
 *   MYSTERY_UTIL_DeleteMenu 0x021DA148 thumb ov121
 *   MYSTERY_UTIL_DeleteMenuWindow 0x021D9E04 thumb ov121
 *   MYSTERY_ALBUM_RemoveCard 0x021DBC08 thumb ov121
 *   MYSTERY_ALBUM_DeleteSlotActors 0x021DB528 thumb ov121
 *   MYSTERY_ALBUM_SetCursor 0x021DB478 thumb ov121
 *   MYSTERY_UTIL_ClearListWindow 0x021DA2F0 thumb ov121
 *   MYSTERY_UTIL_SetTaskHandler 0x021DA8B0 thumb ov121
 *   MYSTERY_UTIL_UpdateMenuWindow 0x021D9E50 thumb ov121
 *   MYSTERY_ALBUM_SelectHandler 0x021DC08C thumb ov121
 *   MI_CpuFill8 0x02082BCC arm
 *   MYSTERY_DATA_HasAnyCard 0x0200A170 thumb
 *   G2x_SetBlendBrightness_ 0x0207D658 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021DF86E 0x021DF86E data a1
 *   d_021DF86F 0x021DF86F data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 v[7];u16 a,b,c,d;} Desc;
extern void MYSTERY_UTIL_SetMenuMessage(u8 *,int,int,int);
extern unsigned MYSTERY_UTIL_GetMenuState(u8 *p);
extern void *MYSTERY_UTIL_CreateMenu(const u8 *,u16);
extern int MYSTERY_UTIL_UpdateMenu(char *);
extern void MYSTERY_UTIL_DeleteMenu(u8 *p);
extern void MYSTERY_UTIL_DeleteMenuWindow(u8 *);
struct Obj;
extern void MYSTERY_ALBUM_RemoveCard(struct Obj *o, int idx);
extern void MYSTERY_ALBUM_DeleteSlotActors(char *,int);
extern void MYSTERY_ALBUM_SetCursor(char *,int,int,int,u16);
extern void MYSTERY_UTIL_ClearListWindow(u8 *p, u32 i);
extern void MYSTERY_UTIL_SetTaskHandler(u32 *p, u32 a);
extern void MYSTERY_UTIL_UpdateMenuWindow(u8 *);
extern void MYSTERY_ALBUM_SelectHandler(void *task, u32 *state, char *p);
extern void MI_CpuFill8(void *,int,int);
extern int MYSTERY_DATA_HasAnyCard(char *p);
extern void G2x_SetBlendBrightness_(u32,int,int);
extern u8 d_021DF86E[],d_021DF86F[];
#define W(k) (*(u32 *)(p+(k)))
#define P(k) (*(u8 **)(p+(k)))
#define H(k) (*(u16 *)(p+(k)))
static inline void window0(int x,int y,int xx,int yy)
{
    *(volatile u16 *)0x04000040=((x<<8)&0xff00)|(xx&255);
    *(volatile u16 *)0x04000044=((y<<8)&0xff00)|(yy&255);
}
static inline void inside(int planes,int effect)
{
    u32 v=(*(volatile u16 *)0x04000048&~0x3f)|(u32)planes;
    if(effect) v|=32;
    *(volatile u16 *)0x04000048=v;
}
static inline void outside(int planes,int effect)
{
    u32 v=(*(volatile u16 *)0x0400004a&~0x3f)|(u32)planes;
    if(effect) v|=32;
    *(volatile u16 *)0x0400004a=v;
}
void MYSTERY_ALBUM_InfoHandler(void *task,u32 *state,char *p)
{
    Desc d;
    u32 index=W(0xac8)*4+W(0xacc);
    int result;
    int x,y;
    switch(*state) {
    case 0:MYSTERY_UTIL_SetMenuMessage(P(0xabc),W(28),123,1);*state=1;break;
    case 1:
        if(MYSTERY_UTIL_GetMenuState(P(0xabc))) {
            MI_CpuFill8(&d,0,36);
            d.v[0]=W(28);d.v[1]=W(16);d.v[2]=W(20);
            d.v[3]=124;d.v[4]=125;d.v[6]=2;
            d.a=0;d.b=15;d.c=13;d.d=1;
            P(0xac0)=MYSTERY_UTIL_CreateMenu((const u8 *)&d,H(36));
            *state=2;
        }
        break;
    case 2:
        result=MYSTERY_UTIL_UpdateMenu((char *)P(0xac0));
        H(0xbac)=0x7fff;
        if(result!=-1) {
            MYSTERY_UTIL_DeleteMenu(P(0xac0));P(0xac0)=0;
            if(!result) *state=3;
            else {
                if(P(0xabc)) {MYSTERY_UTIL_DeleteMenuWindow(P(0xabc));P(0xabc)=0;}
                MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_ALBUM_SelectHandler);
            }
        }
        break;
    case 3:
        *(volatile u32 *)0x04000000=(*(volatile u32 *)0x04000000&~0xe000)|0x2000;
        x=d_021DF86E[(u8)(index&3)*8];
        y=d_021DF86F[(u8)(index&3)*8];
        inside(30,1);
        window0(x*8,y*8,(x+12)*8,(y+7)*8);
        outside(30,0);*state=4;break;
    case 4:
        G2x_SetBlendBrightness_(0x04000050,30,W(0xae8)*16/30);
        if(W(0xae8)++>30) {W(0xae8)=0;*state=5;}
        break;
    case 5:
        MYSTERY_ALBUM_RemoveCard((struct Obj *)p, index);
        MYSTERY_ALBUM_DeleteSlotActors(p,1);
        MYSTERY_ALBUM_SetCursor(p,1,0,W(0xac8),H(36));
        W(0xa78)=1;*state=6;break;
    case 6:
        G2x_SetBlendBrightness_(0x04000050,30,16-W(0xae8)*16/30);
        if(W(0xae8)++>30) {W(0xae8)=0;*state=7;}
        break;
    case 7:
        if(!MYSTERY_DATA_HasAnyCard((char *)P(12))) MYSTERY_UTIL_ClearListWindow(P(0xab8),1);
        *(volatile u32 *)0x04000000 &= ~0xe000;
        *state=8;break;
    case 8:MYSTERY_UTIL_SetMenuMessage(P(0xabc),W(28),121,1);*state=9;break;
    case 9:if(MYSTERY_UTIL_GetMenuState(P(0xabc))) *state=10;break;
    case 10:
        if(P(0xabc)) {MYSTERY_UTIL_DeleteMenuWindow(P(0xabc));P(0xabc)=0;}
        MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_ALBUM_SelectHandler);break;
    }
    if(P(0xabc)) MYSTERY_UTIL_UpdateMenuWindow(P(0xabc));
}
