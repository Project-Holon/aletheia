/*
 * function: func_02184D70
 * address: 0x02184D70
 * packet: pkt_ov219_02184D70
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 02045CAC at +0048 lacks a code-start witness; integrator-owned unit_02045C44.c omits MSGDATA_ReadString from function:. Required singleton TU finds no viable cut. No overlay leaves filed while ARM9 blocked.
 * blocker-C: 02045CAC verified EXACT, 344B, scratch arm9-blocker.log;
 * copied unchanged from unit_02045C44.c, using dsi/1.1p1 -O4,p --arm.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned int u32;
 * struct MsgEntry { u32 off; u16 len; u16 pad_06; };
 * struct MsgFile {
 *     u16 langCount; u16 count; u32 unk_04; u32 unk_08; u32 langOff[1];
 * };
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void *base;
 *     struct MsgEntry cache;
 *     u32 origin;
 *     void *stream;
 *     u16 heapId;
 *     u8 langIndex;
 *     u8 resident;
 * };
 * extern char MSGDATA_AllocSite[];
 * extern void *GFL_HEAP_Alloc(u32,u32,int,const char *,u16);
 * extern void func_020307B0(void *);
 * extern void ARC_TOOL_ReadHandle(void *,u32,void *);
 * extern void func_0204960C(void *,u32);
 * extern void STRBUF_Clear(void *);
 * extern void STRBUF_SetChars(void *,const void *,u16);
 * extern void func_02045E04(void *,u32);
 * extern void func_02046180(struct MsgBank *);
 * void MSGDATA_ReadString(struct MsgBank *bank,u32 index,void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *     if (index >= bank->file->count) {
 *         STRBUF_Clear(dest);
 *         return;
 *     }
 *     func_02046180(bank);
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *         func_0204960C(bank->stream,pos + (index * 8 + 4));
 *         ARC_TOOL_ReadHandle(bank->stream,8,&bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *     if (bank->resident == 0) {
 *         void *buf;
 *         size = e->len * 2;
 *         buf = GFL_HEAP_Alloc((u16)((bank->heapId & 0x7fff) | 0x8000),size,
 *                            0,MSGDATA_AllocSite,0xd6);
 *         if (buf != 0) {
 *             func_0204960C(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             ARC_TOOL_ReadHandle(bank->stream,size,buf);
 *             STRBUF_SetChars(dest,buf,e->len);
 *             func_020307B0(buf);
 *         }
 *     } else {
 *         STRBUF_SetChars(dest,(u8 *)bank->base + e->off,e->len);
 *     }
 *     func_02045E04(dest,index);
 * }

 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   STRBUF_Create 0x020457B0 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   APP_KEYCURSOR_Update 0x020286C4 thumb
 *   KEY_GetCont 0x0203630C arm
 *   PRINTSYS_PrintStreamShortWait 0x0201CE5C thumb
 *   PRINTSYS_PrintStreamReleasePause 0x0201CE38 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 * prototype: 0201CCE4's legacy void return is live r0 stored to p+C074; retain u32 return. Heap truncation at call sites uses u16.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;struct CharBuf;struct U16Vec;struct MsgBank;struct Ctx;struct Rec;struct Rec3;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *,u8);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void MSGDATA_ReadString(struct MsgBank *,u32,void *);
extern signed char MSG_SPEED_GetWait(void);
extern u32 PRINTSYS_PrintStream(u32,u32,u32,u32,u32,u32,u32,u32,u16,u16);
extern u32 PRINTSYS_PrintStreamGetState(void *);
extern void APP_KEYCURSOR_Update(struct Ctx *,void *,void *);
extern u32 KEY_GetCont(void);
extern void PRINTSYS_PrintStreamShortWait(struct Rec *,int);
extern void PRINTSYS_PrintStreamReleasePause(void *);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void STRBUF_Delete(struct U16Vec *);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *);
int func_02184D70(char *p,u32 message,int force)
{
    int result;
    u32 mode;
    result=0;
    switch(*(u32 *)(p+0xC0B0)) {
    case 0:
        BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor **)(p+0xC01C)),15);
        *(struct U16Vec **)(p+0xC0AC)=STRBUF_Create(1024,(u16)(*(u32 *)p));
        MSGDATA_ReadString(*(struct MsgBank **)(p+0xC070),message,*(struct U16Vec **)(p+0xC0AC));
        *(u32 *)(p+0xC074)=PRINTSYS_PrintStream(*(u32 *)(p+0xC01C),0,0,*(u32 *)(p+0xC0AC),*(u32 *)(p+0xC06C),MSG_SPEED_GetWait(),*(u32 *)(p+0xC0A4),0,*(u32 *)p,15);
        *(u32 *)(p+0xC0B0)=1;
        break;
    case 1:
        mode=PRINTSYS_PrintStreamGetState(*(void **)(p+0xC074));
        APP_KEYCURSOR_Update(*(struct Ctx **)(p+0xC088),*(void **)(p+0xC074),*(void **)(p+0xC01C));
        switch(mode) {
        case 0:
            if(KEY_GetCont()&1)PRINTSYS_PrintStreamShortWait(*(struct Rec **)(p+0xC074),0);
            break;
        case 1:
            if((*(u32 *)(p+0xC354)&1)||(*(u32 *)(p+0xC354)&2)) {
                PRINTSYS_PrintStreamReleasePause(*(void **)(p+0xC074));
                GFL_USE_PlaySeDefaultVolume(0x547);
            }
            break;
        case 2: *(u32 *)(p+0xC0B0)=2;break;
        }
        break;
    case 2:
        if(force!=0 || (*(u32 *)(p+0xC354)&1)) {
            STRBUF_Delete(*(struct U16Vec **)(p+0xC0AC));
            PRINTSYS_PrintStreamDelete(*(struct Rec3 **)(p+0xC074));
            *(u32 *)(p+0xC0B0)=0;
            result=1;
        }
        break;
    }
    return result;
}
