/*
 * function: DEMO3D_DATA_BgmFadeMain
 * address: 0x021BEEF8
 * packet: pkt_ov203_021BEEF8
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   GFL_USE_SetBgmPaused 0x02005DE4 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   TCBL_DeleteTask 0x02031194 arm
 */
typedef struct Task {char *owner;unsigned reserved;unsigned char done,a,b,mode;int channel,start,end;} Task;
struct TcblNode;
extern int GFL_USE_IsBgmFading(void);
extern void GFL_USE_SetBgmPaused(void *);
extern int GFL_USE_PushBgm(void),GFL_USE_PopBgm(void);
typedef unsigned int   u32;
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern void GFL_USE_CancelChangeAndPlayBgm(int,int);
extern void GFL_USE_FadeInBgmFull(u32 a);
extern void TCBL_DeleteTask(struct TcblNode *);
void DEMO3D_DATA_BgmFadeMain(struct TcblNode *node,Task *t)
{
    switch(t->done){
    case 0:
        if(GFL_USE_IsBgmFading()!=0)return;
        ++t->done;
    case 1:
        if(t->a){
            if((unsigned char)t->owner[25]==0){GFL_USE_SetBgmPaused((void *)1);GFL_USE_PushBgm();t->owner[25]=1;}
        }else {GFL_USE_CancelChangeAndStopBgm();if(t->mode==1)break;}
        if(t->b){
            if((unsigned char)t->owner[25]!=0){GFL_USE_PopBgm();GFL_USE_SetBgmPaused(0);t->owner[25]=0;}
        }else {GFL_USE_CancelChangeAndPlayBgm(t->channel,0xffff);}
        if(t->end!=0)GFL_USE_FadeInBgmFull((unsigned short)t->end);
        break;
    }
    TCBL_DeleteTask(node);
}
