/*
 * function: BTL_REC_SEL_Main
 * packet: pkt_ov214_021B9834
 * note 2026-10-05: no default label (the dispatch bhi lands on case 3's own break stub);
 * the finish call (18,3,0,16,2,0) is written inline in case 15 and again in case 17, never by goto;
 * case 5 writes its own cancel copy (no goto into case 6); side and index are int; c = 0 is set
 * before the first BATTLE_REC_GetHeaderParam call; case 12 stores p+0x64 = 120 in both arms.
 * address: 0x021B9834
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 * GAME_DATA_GetSaveControl 0x02012EBC thumb
 * KEY_GetTrg 0x020362DC arm
 * FADE_Start 0x0204E720 arm
 * FADE_IsActive 0x0204E804 arm
 * BTL_REC_SEL_PrintEntry 0x021BA108 thumb ov214
 * BTL_REC_SEL_WaitPrint 0x021BA16C thumb ov214
 * BTL_REC_SEL_CreateYesNo 0x021BA3A0 thumb ov214
 * BMP_MENU_ProcessYesNo 0x0201FEBC thumb
 * BMP_MENU_DeleteYesNo 0x0201FEF4 thumb
 * func_020355D8 0x020355D8 arm
 * BATTLE_REC_CheckSaved 0x0200B5CC thumb
 * BTL_REC_SEL_StartFade 0x021B9EB8 thumb ov214
 * BTL_REC_SEL_ResetTimer 0x021BA6F0 thumb ov214
 * BTL_REC_SEL_StartEntryA 0x021B9ED4 thumb ov214
 * BATTLE_REC_LoadAlloc 0x0200B5A4 thumb
 * BTL_REC_SEL_ClearLayer 0x021BAD08 thumb ov214
 * BTL_REC_SEL_ClearWindowWhite 0x021BA0B0 thumb ov214
 * BATTLE_REC_GetHeaderOf 0x0200B934 thumb
 * BATTLE_REC_GetHeaderParam 0x0200B98C thumb
 * BTL_REC_SEL_SetMode 0x021BABB8 thumb ov214
 * BTL_REC_SEL_PrintList 0x021BA5C8 thumb ov214
 * BTL_REC_SEL_InitCells 0x021BA8DC thumb ov214
 * BTL_REC_SEL_InitBgGfx2 0x021BAC90 thumb ov214
 * BTL_REC_SEL_InitBgGfx3 0x021BACCC thumb ov214
 * BTL_REC_SEL_SetEntryA 0x021B9EF0 thumb ov214
 * BATTLE_REC_Delete 0x0200B438 thumb
 * BTL_REC_SEL_ClearList 0x021BA650 thumb ov214
 * BTL_REC_SEL_DeleteCellActors 0x021BAAB0 thumb ov214
 * BTL_REC_SEL_ClearWindowClear 0x021BA0DC thumb ov214
 * BTL_REC_SEL_DrawWindowBorder 0x021BA0A4 thumb ov214
 * BTL_REC_SEL_PrintQueEntry 0x021BA254 thumb ov214
 * BTL_REC_SEL_IsEntryShown 0x021BA2B8 thumb ov214
 * func_020056BC 0x020056BC thumb
 * TIME_ICON_Create 0x0202EE30 thumb
 * BATTLE_REC_Save 0x0200B6E0 thumb
 * BATTLE_REC_DecodeWork 0x0200B490 thumb
 * TIME_ICON_Delete 0x0202F038 thumb
 * GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 * BTL_REC_SEL_StartEntryB 0x021B9EFC thumb ov214
 * GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 * GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 * func_0200FB24 0x0200FB24 thumb
 * GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 * BTL_REC_SEL_MainTcbl 0x021BA058 thumb ov214
 * BTL_REC_SEL_TickTimer 0x021BA45C thumb ov214
 * BTL_REC_SEL_ShowWindows 0x021BA4E8 thumb ov214
 * BTL_REC_SEL_FadeMain 0x021BAF64 thumb ov214
 * PRINTSYS_QUE_Main 0x0201C4E4 thumb
 * BTL_REC_SEL_GRAPHIC_Draw 0x021BB27C thumb ov214
 * BTL_REC_SEL_GRAPHIC_Draw3d 0x021BB290 thumb ov214
 * BTL_REC_SEL_GRAPHIC_DrawEnd 0x021BB29C thumb ov214
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct BattleRec;
struct Big;
struct Entry;
struct Link;
struct ObjC4;
struct PrintSys;
struct S;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u32 KEY_GetTrg(void);
extern void FADE_Start(u32,int,int,int);
extern int FADE_IsActive(void);
extern void BTL_REC_SEL_PrintEntry(int,char*,u32,int);
extern int BTL_REC_SEL_WaitPrint(int,char*);
extern void BTL_REC_SEL_CreateYesNo(int unused, u8 *p);
extern u32 BMP_MENU_ProcessYesNo(u8*);
extern void BMP_MENU_DeleteYesNo(u8 *o);
extern void func_020355D8(u8);
extern u32 BATTLE_REC_CheckSaved(void*,u32,u32*,u32);
extern void BTL_REC_SEL_StartFade(char*,int,char*,int,int,int,int,int,int);
extern void BTL_REC_SEL_ResetTimer(void*,char*);
extern void BTL_REC_SEL_StartEntryA(u32*,void*,char*,u32,u32,u32);
extern struct BattleRec *BATTLE_REC_LoadAlloc(void *a, u32 heap, u32 *dp, u32 id);
extern void BTL_REC_SEL_ClearLayer(void*,char*),BTL_REC_SEL_ClearWindowWhite(int,char*);
extern u8 *BATTLE_REC_GetHeaderOf(struct ObjC4 *p);
extern unsigned long long BATTLE_REC_GetHeaderParam(u8 *p, int selector, int index);
extern void BTL_REC_SEL_SetMode(int,char*);
extern void BTL_REC_SEL_PrintList(void*,char*);
extern void BTL_REC_SEL_InitCells(void *unused, struct S *p);
extern void BTL_REC_SEL_InitBgGfx2(int unused, u8 *p);
extern void BTL_REC_SEL_InitBgGfx3(int unused, u8 *p);
extern void BTL_REC_SEL_SetEntryA(void*,char*,u32,u32,u32),BATTLE_REC_Delete(void*);
extern void BTL_REC_SEL_ClearList(int,char*),BTL_REC_SEL_DeleteCellActors(int,int),BTL_REC_SEL_ClearWindowClear(int,char*),BTL_REC_SEL_DrawWindowBorder(int,char*);
extern void BTL_REC_SEL_PrintQueEntry(void*,char*,u32);
extern u32 BTL_REC_SEL_IsEntryShown(int unused, u8 *p);
extern u32 func_020056BC(void);
extern u8 *TIME_ICON_Create(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
extern u32 BATTLE_REC_Save(void*,u16,u32,u32,u32,u16*,u16*);
extern void BATTLE_REC_DecodeWork(void),TIME_ICON_Delete(u8*),GFL_USE_PlaySeDefaultVolume(u32);
extern void BTL_REC_SEL_StartEntryB(int*,int,int,int,int);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *p, u32 lo, u32 hi);
extern u32 func_0200FB24(void);
extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct Link *p, u32 lo, u32 hi);
extern void BTL_REC_SEL_MainTcbl(int,char*);
extern void BTL_REC_SEL_TickTimer(void*,char*);
extern void BTL_REC_SEL_ShowWindows(void *unused, struct S *p);
extern void BTL_REC_SEL_FadeMain(void *unused, struct S *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void BTL_REC_SEL_GRAPHIC_Draw(u8*),BTL_REC_SEL_GRAPHIC_Draw3d(u8*),BTL_REC_SEL_GRAPHIC_DrawEnd(char*);
int BTL_REC_SEL_Main(void *unused,u32 *state,const char *obj,char *p)
{
    void *owner,*record;
    u32 result;
    int done;
    int side,index;
    long i;
    u32 status0,status1,a,b,c;
    u32 addr;
    owner=GAME_DATA_GetSaveControl(*(void**)obj);
    KEY_GetTrg();
    switch(*state){
    case 0:
        if((*(u32*)(p+0x54))){*state=18;break;}
        if((*(u32*)(p+0x30))==1){if((*(u32*)(p+0x24))==0)(*(u32*)(p+0x2e4))=2;else (*(u32*)(p+0x2e4))=1;}
        else FADE_Start((*(u32*)(p+0x20)),(*(u32*)(p+0x24)),(*(u32*)(p+0x28)),(*(u32*)(p+0x2c)));
        *state=1;break;
    case 1:
        done=0;
        if((*(u32*)(p+0x30))==1){if((*(u32*)(p+0x2e8))==0||(*(u32*)(p+0x2e8))==2)done=1;}
        else if(!FADE_IsActive())done=1;
        if(done){(*(u32*)(p+0xb4))=0;*state=(*(u32*)(p+0x1c));}break;
    case 2:BTL_REC_SEL_PrintEntry((int)obj,p,(*(u32*)(p+0x38)),0);*state=3;break;
    case 3:
        if(!BTL_REC_SEL_WaitPrint((int)obj,p))break;
        BTL_REC_SEL_CreateYesNo((int)obj,(u8 *)p);*state=(*(u32*)(p+0x34));break;
    case 4:BTL_REC_SEL_PrintEntry((int)obj,p,(*(u32*)(p+0x44)),0);*state=(*(u32*)(p+0x40));break;
    case 5:
        result=BMP_MENU_ProcessYesNo((u8*)(*(u32*)(p+0x88)));
        if(result!=0xffffffff){
            func_020355D8(0);
            if(result==0){
                if(BATTLE_REC_CheckSaved(owner,*(u16*)p,&status0,0)){
                    (*(u32*)(p+0xb4))=1;BTL_REC_SEL_StartFade((char*)state,(int)obj,p,8,1,0,16,-2,1);break;
                }else{BTL_REC_SEL_ResetTimer((void*)obj,p);*state=10;}
            }else BTL_REC_SEL_StartEntryA(state,(void*)obj,p,6,3,1);
        }else if((*(u32*)(p+0xb8))){BMP_MENU_DeleteYesNo((void*)(*(u32*)(p+0x88)));*state=15;}
        break;
    case 6:
        result=BMP_MENU_ProcessYesNo((u8*)(*(u32*)(p+0x88)));
        if(result!=0xffffffff){
            func_020355D8(0);
            if(result==0){BTL_REC_SEL_ResetTimer((void*)obj,p);*state=15;}
            else BTL_REC_SEL_StartEntryA(state,(void*)obj,p,5,0,1);
        }else if((*(u32*)(p+0xb8))){BMP_MENU_DeleteYesNo((void*)(*(u32*)(p+0x88)));*state=15;}
        break;
    case 7:
        result=BMP_MENU_ProcessYesNo((u8*)(*(u32*)(p+0x88)));
        if(result!=0xffffffff){
            func_020355D8(0);
            if(result==0)(*(u32*)(p+0x48))=10;else (*(u32*)(p+0x48))=15;
            BTL_REC_SEL_ResetTimer((void*)obj,p);
            BTL_REC_SEL_StartFade((char*)state,(int)obj,p,9,1,0,16,-2,1);break;
        }else if((*(u32*)(p+0xb8))){
            BMP_MENU_DeleteYesNo((void*)(*(u32*)(p+0x88)));(*(u32*)(p+0x48))=15;
            BTL_REC_SEL_StartFade((char*)state,(int)obj,p,9,1,0,16,-2,1);break;
        }
        break;
    case 8:
        (*(u32*)(p+0x2ac))=(u32)BATTLE_REC_LoadAlloc(owner,*(u16*)p,&status1,0);
        BTL_REC_SEL_ClearLayer((void*)obj,p);BTL_REC_SEL_ClearWindowWhite((int)obj,p);
        if(status1==1){
            record=BATTLE_REC_GetHeaderOf((void*)(*(u32*)(p+0x2ac)));
            (*(u32*)(p+0x2b0))=BATTLE_REC_GetHeaderParam(record,3,0);
            BTL_REC_SEL_SetMode((int)obj,p);
            for(i=0;i<12;i++){
                b=0;c=0;a=BATTLE_REC_GetHeaderParam(record,0,i);
                if(a){b=BATTLE_REC_GetHeaderParam(record,1,i);c=BATTLE_REC_GetHeaderParam(record,6,i);}
                if((*(u32*)(p+0x2a8))){
                    if(i<6){
                        addr=(u32)p+(u32)(i%6)*40;
                        *(u32*)(addr+0x1b4)=a;*(u32*)(addr+0x1b8)=b;*(u32*)(addr+0x1bc)=c;
                    }else{
                        addr=(u32)p+(u32)(i%6)*40;
                        *(u32*)(addr+0xc4)=a;*(u32*)(addr+0xc8)=b;*(u32*)(addr+0xcc)=c;
                    }
                }else{
                    if(i<3){side=1;index=i;}
                    else if(i<6){side=0;index=i-3;}
                    else if(i<9){side=1;index=i-3;}
                    else{side=0;index=i-6;}
                    addr=(u32)p+(u32)side*240+(u32)index*40;
                    *(u32*)(addr+0xc4)=a;*(u32*)(addr+0xc8)=b;*(u32*)(addr+0xcc)=c;
                }
            }
            BTL_REC_SEL_PrintList((void*)obj,p);BTL_REC_SEL_InitCells((void*)obj,(struct S *)p);
            if((*(u32*)(p+0x2a8)))BTL_REC_SEL_InitBgGfx2((int)obj,(u8 *)p);else BTL_REC_SEL_InitBgGfx3((int)obj,(u8 *)p);
            BTL_REC_SEL_StartFade((char*)state,(int)obj,p,2,1,16,0,-2,1);
            BTL_REC_SEL_SetEntryA((void*)obj,p,7,6,0);
        }else BTL_REC_SEL_StartFade((char*)state,(int)obj,p,10,1,16,0,-2,1);
        BATTLE_REC_Delete((void*)(*(u32*)(p+0x2ac)));break;
    case 9:
        BTL_REC_SEL_ClearList((int)obj,p);BTL_REC_SEL_DeleteCellActors((int)obj,(int)p);BTL_REC_SEL_ClearLayer((void*)obj,p);
        BTL_REC_SEL_StartFade((char*)state,(int)obj,p,(*(u32*)(p+0x48)),1,16,0,-2,1);
        BTL_REC_SEL_ClearWindowWhite((int)obj,p);
        if((*(u32*)(p+0x48))==15 && (*(u32*)(p+0x50)) && (*(u32*)(obj+4)) && !(*(u32*)(obj+8))){BTL_REC_SEL_ClearWindowClear((int)obj,p);BTL_REC_SEL_DrawWindowBorder((int)obj,p);}
        BTL_REC_SEL_ResetTimer((void*)obj,p);break;
    case 10:BTL_REC_SEL_PrintQueEntry((void*)obj,p,9);*state=11;break;
    case 11:
        if(BTL_REC_SEL_IsEntryShown((int)obj,(u8 *)p)){
            (*(u32*)(p+0x2ec))=(u32)TIME_ICON_Create((void *)func_020056BC(),(void*)(*(u32*)(p+0x6c)),15,16,*(u16*)p);
            (*(u32*)(p+0x2b4))=0;*(u16*)(p+0x2b8)=0;*(u16*)(p+0x2ba)=0;(*(u32*)(p+0x2bc))=0;
            *state=12;
        }break;
    case 12:
        if((*(u32*)(p+0x2bc))!=2 && (*(u32*)(p+0x2bc))!=3)(*(u32*)(p+0x2bc))=BATTLE_REC_Save(*(void**)obj,*(u16*)p,(*(u32*)(obj+0x10)),(*(u32*)(obj+0x14)),0,(u16*)(p+0x2b8),(u16*)(p+0x2ba));
        if((u32)((*(u32*)(p+0x2bc))-2)<=1){
            BATTLE_REC_DecodeWork();TIME_ICON_Delete((u8*)(*(u32*)(p+0x2ec)));
            if((*(u32*)(p+0x2bc))==2){GFL_USE_PlaySeDefaultVolume(0x558);BTL_REC_SEL_StartEntryB((int*)state,(int)obj,(int)p,13,10);(*(u32*)(p+0x64))=120;}
            else if((*(u32*)(p+0x2bc))==3){BTL_REC_SEL_StartEntryB((int*)state,(int)obj,(int)p,14,11);(*(u32*)(p+0x64))=120;}
        }break;
    case 13:if(BTL_REC_SEL_WaitPrint((int)obj,p))*state=15;break;
    case 14:if(BTL_REC_SEL_WaitPrint((int)obj,p))*state=15;break;
    case 15:
        if((*(u32*)(p+0x50))){
            if((*(u32*)(obj+0xc))){
                if((*(u32*)(obj+4))){
                    if((*(u32*)(obj+8)))a=12;
                    else{BTL_REC_SEL_StartFade((char*)state,(int)obj,p,18,3,0,16,2,0);break;}
                }else if((*(u32*)(obj+8)))a=13;else a=14;
            }else a=15;
        }else if((*(u32*)(obj+8)))a=12;else{*state=18;break;}
        if((*(u32*)(obj+8)))BTL_REC_SEL_PrintQueEntry((void*)obj,p,a);else BTL_REC_SEL_PrintEntry((int)obj,p,a,1);
        *state=16;break;
    case 16:
        done=0;
        if((*(u32*)(obj+8))){if(BTL_REC_SEL_IsEntryShown((int)obj,(u8 *)p))done=1;}
        else if(BTL_REC_SEL_WaitPrint((int)obj,p))done=1;
        if(done){
            if((*(u32*)(obj+8))){
                GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),150,43);
                (*(u32*)(p+0x2ec))=(u32)TIME_ICON_Create((void *)func_020056BC(),(void*)(*(u32*)(p+0x6c)),15,16,*(u16*)p);
            }
            *state=17;
        }break;
    case 17:
        done=1;
        if((*(u32*)(obj+8))){
            if(!func_0200FB24())done=GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),150,43);
            if(done)TIME_ICON_Delete((u8*)(*(u32*)(p+0x2ec)));
        }
        if(done)BTL_REC_SEL_StartFade((char*)state,(int)obj,p,18,3,0,16,2,0);
        break;
    case 18:return 1;
    }
    BTL_REC_SEL_MainTcbl((int)obj,p);BTL_REC_SEL_TickTimer((void*)obj,p);BTL_REC_SEL_ShowWindows((void*)obj,(struct S *)p);BTL_REC_SEL_FadeMain((void*)obj,(struct S *)p);
    PRINTSYS_QUE_Main((void*)(*(u32*)(p+0xc)));PRINTSYS_QUE_Main((void*)(*(u32*)(p+0x10)));PRINTSYS_QUE_Main((void*)(*(u32*)(p+0x14)));PRINTSYS_QUE_Main((void*)(*(u32*)(p+0x18)));
    BTL_REC_SEL_GRAPHIC_Draw((u8*)(*(u32*)(p+4)));BTL_REC_SEL_GRAPHIC_Draw3d((u8*)(*(u32*)(p+4)));BTL_REC_SEL_GRAPHIC_DrawEnd((char*)(*(u32*)(p+4)));
    return 0;
}
